#include <sys/param.h>
#include <libgen.h>
#include <libutil.h>
#include <inttypes.h>
#include <errno.h>

#include <fstab.h>
#include <libgeom.h>
#include <dialog.h>
#include <dlg_keys.h>

#include "diskeditor.h"
#include "partedit.h"

struct pmetadata_head part_metadata;

static int apply_changes(struct gmesh *mesh);
static struct partedit_item *read_geom_mesh(struct gmesh *mesh, int *nitems);
static void add_geom_children(struct ggeom *gp, int recurse,
    struct partedit_item **items, int *nitems);
static void init_fstab_metadata(void);
static void get_mount_points(struct partedit_item *items, int nitems);
static int validate_setup(void);

int
main(int argc, const char **argv) {
	struct partition_metadata *md;
	const char *prompt;
	struct partedit_item *items;
	struct gmesh mesh;
	int i, op, nitems, nscroll;
	int error;

	TAILQ_INIT(&part_metadata);

	init_fstab_metadata();

	init_dialog(stdin, stdout);
	if (strcmp(basename(argv[0]), "sade") != 0)
		dialog_vars.backtitle = __DECONST(char *, "FreeBSD Installer");
	dialog_vars.item_help = TRUE;
	nscroll = i = 0;

	if (strcmp(basename(argv[0]), "autopart") == 0) { /* Guided */
		prompt = "Please review the disk setup. When complete, press "
		    "the Finished button.";
		part_wizard();
	} else {
		prompt = "Create partitions for FreeBSD. No changes will be "
		    "made until you select Finished.";
	}

	/* Show the part editor either immediately, or to confirm wizard */
	while (1) {
		error = geom_gettree(&mesh);
		items = read_geom_mesh(&mesh, &nitems);
		get_mount_points(items, nitems);
		dlg_clear();
		dlg_put_backtitle();

		if (i >= nitems)
			i = nitems - 1;
		op = diskeditor_show("Partition Editor", prompt,
		    items, nitems, &i, &nscroll);

		switch (op) {
		case 0: /* Create */
			gpart_create((struct gprovider *)(items[i].cookie),
			    NULL, NULL, NULL, NULL, 1);
			break;
		case 1: /* Delete */
			gpart_delete((struct gprovider *)(items[i].cookie));
			break;
		case 2: /* Edit */
			gpart_edit((struct gprovider *)(items[i].cookie));
			break;
		case 3: /* Revert */
			gpart_revert_all(&mesh);
			while ((md = TAILQ_FIRST(&part_metadata)) != NULL) {
				if (md->fstab != NULL) {
					free(md->fstab->fs_spec);
					free(md->fstab->fs_file);
					free(md->fstab->fs_vfstype);
					free(md->fstab->fs_mntops);
					free(md->fstab->fs_type);
					free(md->fstab);
				}
				if (md->newfs != NULL)
					free(md->newfs);
				free(md->name);

				TAILQ_REMOVE(&part_metadata, md, metadata);
				free(md);
			}
			init_fstab_metadata();
			break;
		}

		error = 0;
		if (op == 4 && validate_setup()) { /* Finished */
			dialog_vars.extra_button = TRUE;
			dialog_vars.extra_label =
			    __DECONST(char *, "Abort");
			dialog_vars.ok_label = __DECONST(char *, "Save");
			op = dialog_yesno("Confirmation", "Your changes will "
			    "now be written to disk. If you have chosen to "
			    "overwrite existing data, it will be PERMANENTLY "
			    "ERASED. Are you sure you want to proceed?", 0, 0);
			dialog_vars.extra_button = FALSE;
			dialog_vars.ok_label = NULL;

			if (op == 0) { /* Save */
				error = apply_changes(&mesh);
				break;
			} else if (op == 3) { /* Don't save => Quit */
				gpart_revert_all(&mesh);
				error =	-1;
				break;
			}
		}

		geom_deletetree(&mesh);
		free(items);
	}
	

	geom_deletetree(&mesh);
	free(items);
	end_dialog();

	return (error);
}

struct partition_metadata *
get_part_metadata(const char *name, int create)
{
	struct partition_metadata *md;

	TAILQ_FOREACH(md, &part_metadata, metadata) 
		if (md->name != NULL && strcmp(md->name, name) == 0)
			break;

	if (md == NULL && create) {
		md = calloc(1, sizeof(*md));
		md->name = strdup(name);
		TAILQ_INSERT_TAIL(&part_metadata, md, metadata);
	}

	return (md);
}
	
void
delete_part_metadata(const char *name) {
	struct partition_metadata *md;

	TAILQ_FOREACH(md, &part_metadata, metadata) {
		if (md->name != NULL && strcmp(md->name, name) == 0) {
			if (md->fstab != NULL) {
				free(md->fstab->fs_spec);
				free(md->fstab->fs_file);
				free(md->fstab->fs_vfstype);
				free(md->fstab->fs_mntops);
				free(md->fstab->fs_type);
				free(md->fstab);
			}
			if (md->newfs != NULL)
				free(md->newfs);
			free(md->name);

			TAILQ_REMOVE(&part_metadata, md, metadata);
			free(md);
			break;
		}
	}
}

static int
validate_setup(void)
{
	struct partition_metadata *md;
	int root_found = FALSE;

	TAILQ_FOREACH(md, &part_metadata, metadata) {
		if (md->fstab != NULL && strcmp(md->fstab->fs_file, "/") == 0)
			root_found = TRUE;

		/* XXX: Check for duplicate mountpoints */
	}

	if (!root_found) {
		dialog_msgbox("Error", "No root partition was found. "
		    "The root FreeBSD partition must have a mountpoint of '/'.",
		0, 0, TRUE);
		return (FALSE);
	}

	return (TRUE);
}

static int
apply_changes(struct gmesh *mesh)
{
	struct partition_metadata *md;
	char message[512];
	int i, nitems, error;
	const char **items;
	const char *fstab_path;
	FILE *fstab;

	nitems = 1; /* Partition table changes */
	TAILQ_FOREACH(md, &part_metadata, metadata) {
		if (md->newfs != NULL)
			nitems++;
	}
	items = calloc(nitems * 2, sizeof(const char *));
	items[0] = "Writing partition tables";
	items[1] = "7"; /* In progress */
	i = 1;
	TAILQ_FOREACH(md, &part_metadata, metadata) {
		if (md->newfs != NULL) {
			char *item;
			item = malloc(255);
			sprintf(item, "Initializing %s", md->name);
			items[i*2] = item;
			items[i*2 + 1] = "Pending";
			i++;
		}
	}

	i = 0;
	dialog_mixedgauge("Initializing",
	    "Initializing file systems. Please wait.", 0, 0, i*100/nitems,
	    nitems, __DECONST(char **, items));
	gpart_commit(mesh);
	items[i*2 + 1] = "3";
	i++;

	if (getenv("BSDINSTALL_LOG") == NULL) 
		setenv("BSDINSTALL_LOG", "/dev/null", 1);

	TAILQ_FOREACH(md, &part_metadata, metadata) {
		if (md->newfs != NULL) {
			items[i*2 + 1] = "7"; /* In progress */
			dialog_mixedgauge("Initializing",
			    "Initializing file systems. Please wait.", 0, 0,
			    i*100/nitems, nitems, __DECONST(char **, items));
			sprintf(message, "(echo %s; %s) >>%s 2>>%s",
			    md->newfs, md->newfs, getenv("BSDINSTALL_LOG"),
			    getenv("BSDINSTALL_LOG"));
			error = system(message);
			items[i*2 + 1] = (error == 0) ? "3" : "1";
			i++;
		}
	}
	dialog_mixedgauge("Initializing",
	    "Initializing file systems. Please wait.", 0, 0,
	    i*100/nitems, nitems, __DECONST(char **, items));

	for (i = 1; i < nitems; i++)
		free(__DECONST(char *, items[i*2]));
	free(items);

	if (getenv("PATH_FSTAB") != NULL)
		fstab_path = getenv("PATH_FSTAB");
	else
		fstab_path = "/etc/fstab";
	fstab = fopen(fstab_path, "w+");
	if (fstab == NULL) {
		sprintf(message, "Cannot open fstab file %s for writing (%s)\n",
		    getenv("PATH_FSTAB"), strerror(errno));
		dialog_msgbox("Error", message, 0, 0, TRUE);
		return (-1);
	}
	fprintf(fstab, "# Device\tMountpoint\tFStype\tOptions\tDump\tPass#\n");
	TAILQ_FOREACH(md, &part_metadata, metadata) {
		if (md->fstab != NULL)
			fprintf(fstab, "%s\t%s\t%s\t%s\t%d\t%d\n",
			    md->fstab->fs_spec, md->fstab->fs_file,
			    md->fstab->fs_vfstype, md->fstab->fs_mntops,
			    md->fstab->fs_freq, md->fstab->fs_passno);
	}
	fclose(fstab);

	return (0);
}

static struct partedit_item *
read_geom_mesh(struct gmesh *mesh, int *nitems) {
	struct gclass *classp;
	struct ggeom *gp;
	struct partedit_item *items;

	*nitems = 0;
	items = NULL;

	/*
	 * Build the device table. First add all disks (and CDs).
	 */
	
	LIST_FOREACH(classp, &mesh->lg_class, lg_class) {
		if (strcmp(classp->lg_name, "DISK") != 0 &&
		     strcmp(classp->lg_name, "MD") != 0)
			continue;

		/* Now recurse into all children */
		LIST_FOREACH(gp, &classp->lg_geom, lg_geom) 
			add_geom_children(gp, 0, &items, nitems);
	}

	return (items);
}

static void
add_geom_children(struct ggeom *gp, int recurse, struct partedit_item **items,
    int *nitems) {
	struct gconsumer *cp;
	struct gprovider *pp;
	struct gconfig *gc;

	if (strcmp(gp->lg_class->lg_name, "PART") == 0 &&
	    !LIST_EMPTY(&gp->lg_config)) {
		LIST_FOREACH(gc, &gp->lg_config, lg_config) {
			if (strcmp(gc->lg_name, "scheme") == 0)
				(*items)[*nitems-1].type = gc->lg_val;
		}
	}

	if (LIST_EMPTY(&gp->lg_provider)) 
		return;

	LIST_FOREACH(pp, &gp->lg_provider, lg_provider) {
		if (strcmp(gp->lg_class->lg_name, "LABEL") == 0)
			continue;

		/* Skip WORM media */
		if (strncmp(pp->lg_name, "cd", 2) == 0)
			continue;

		*items = realloc(*items,
		    (*nitems+1)*sizeof(struct partedit_item));
		(*items)[*nitems].indentation = recurse;
		(*items)[*nitems].name = pp->lg_name;
		(*items)[*nitems].size = pp->lg_mediasize;
		(*items)[*nitems].mountpoint = NULL;
		(*items)[*nitems].type = "";
		(*items)[*nitems].cookie = pp;

		LIST_FOREACH(gc, &pp->lg_config, lg_config) {
			if (strcmp(gc->lg_name, "type") == 0)
				(*items)[*nitems].type = gc->lg_val;
		}

		/* Skip swap-backed MD devices */
		if (strcmp(gp->lg_class->lg_name, "MD") == 0 &&
		    strcmp((*items)[*nitems].type, "swap") == 0)
			continue;

		(*nitems)++;

		LIST_FOREACH(cp, &pp->lg_consumers, lg_consumers)
			add_geom_children(cp->lg_geom, recurse+1, items,
			    nitems);

		/* Only use first provider for acd */
		if (strcmp(gp->lg_class->lg_name, "ACD") == 0)
			break;
	}
}

static void
init_fstab_metadata(void)
{
	struct fstab *fstab;
	struct partition_metadata *md;

	setfsent();
	while ((fstab = getfsent()) != NULL) {
		md = calloc(1, sizeof(struct partition_metadata));

		md->name = NULL;
		if (strncmp(fstab->fs_spec, "/dev/", 5) == 0)
			md->name = strdup(&fstab->fs_spec[5]);

		md->fstab = malloc(sizeof(struct fstab));
		md->fstab->fs_spec = strdup(fstab->fs_spec);
		md->fstab->fs_file = strdup(fstab->fs_file);
		md->fstab->fs_vfstype = strdup(fstab->fs_vfstype);
		md->fstab->fs_mntops = strdup(fstab->fs_mntops);
		md->fstab->fs_type = strdup(fstab->fs_type);
		md->fstab->fs_freq = fstab->fs_freq;
		md->fstab->fs_passno = fstab->fs_passno;

		md->newfs = NULL;
		
		TAILQ_INSERT_TAIL(&part_metadata, md, metadata);
	}
}

static void
get_mount_points(struct partedit_item *items, int nitems)
{
	struct partition_metadata *md;
	int i;
	
	for (i = 0; i < nitems; i++) {
		TAILQ_FOREACH(md, &part_metadata, metadata) {
			if (md->name != NULL && md->fstab != NULL &&
			    strcmp(md->name, items[i].name) == 0) {
				items[i].mountpoint = md->fstab->fs_file;
				break;
			}
		}
	}
}
