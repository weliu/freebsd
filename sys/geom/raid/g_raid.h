/*-
 * Copyright (c) 2010 Alexander Motin <mav@FreeBSD.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD$
 */

#ifndef	_G_RAID_H_
#define	_G_RAID_H_

#include <sys/param.h>
#include <sys/kobj.h>
#include <sys/bio.h>

#define	G_RAID_CLASS_NAME	"RAID"

#define	G_RAID_MAGIC		"GEOM::RAID"

#define	G_RAID_VERSION		0

struct g_raid_md_object;
struct g_raid_tr_object;

#define	G_RAID_DEVICE_FLAG_NOAUTOSYNC	0x0000000000000001ULL
#define	G_RAID_DEVICE_FLAG_NOFAILSYNC	0x0000000000000002ULL
#define	G_RAID_DEVICE_FLAG_MASK	(G_RAID_DEVICE_FLAG_NOAUTOSYNC | \
					 G_RAID_DEVICE_FLAG_NOFAILSYNC)

#ifdef _KERNEL
extern u_int g_raid_aggressive_spare;
extern u_int g_raid_debug;
extern u_int g_raid_start_timeout;
extern struct g_class g_raid_class;

#define	G_RAID_DEBUG(lvl, fmt, ...)	do {				\
	if (g_raid_debug >= (lvl)) {					\
		if (g_raid_debug > 0) {					\
			printf("GEOM_RAID[%u]: " fmt "\n",		\
			    lvl, ## __VA_ARGS__);			\
		} else {						\
			printf("GEOM_RAID: " fmt "\n",			\
			    ## __VA_ARGS__);				\
		}							\
	}								\
} while (0)
#define	G_RAID_LOGREQ(lvl, bp, fmt, ...)	do {			\
	if (g_raid_debug >= (lvl)) {					\
		if (g_raid_debug > 0) {					\
			printf("GEOM_RAID[%u]: " fmt " ",		\
			    lvl, ## __VA_ARGS__);			\
		} else							\
			printf("GEOM_RAID: " fmt " ", ## __VA_ARGS__);	\
		g_print_bio(bp);					\
		printf("\n");						\
	}								\
} while (0)

/*
 * Flags we use to distinguish I/O initiated by the TR layer to maintain
 * the volume's characteristics, fix subdisks, extra copies of data, etc.
 *
 * G_RAID_BIO_FLAG_SYNC		I/O to update an extra copy of the data
 *				for RAID volumes that maintain extra data
 *				and need to rebuild that data.
 * G_RAID_BIO_FLAG_REMAP	I/O done to try to provoke a subdisk into
 *				doing some desirable action such as bad
 *				block remapping after we detect a bad part
 *				of the disk.
 *
 * and the following meta item:
 * G_RAID_BIO_FLAG_SPECIAL	And of the I/O flags that need to make it
 *				through the range locking which would
 *				otherwise defer the I/O until after that
 *				range is unlocked.
 */
#define	G_RAID_BIO_FLAG_SYNC		0x01
#define	G_RAID_BIO_FLAG_REMAP		0x02
#define G_RAID_BIO_FLAG_SPECIAL \
		(G_RAID_BIO_FLAG_SYNC|G_RAID_BIO_FLAG_REMAP)

#define G_RAID_LOCK_PENDING	0x1
struct g_raid_lock {
	off_t			 l_offset;
	off_t			 l_length;
	void			*l_callback_arg;
	int			 l_flags;
	LIST_ENTRY(g_raid_lock)	 l_next;
};

#define	G_RAID_EVENT_WAIT	0x01
#define	G_RAID_EVENT_VOLUME	0x02
#define	G_RAID_EVENT_SUBDISK	0x04
#define	G_RAID_EVENT_DISK	0x08
#define	G_RAID_EVENT_DONE	0x10
struct g_raid_event {
	void			*e_tgt;
	int			 e_event;
	int			 e_flags;
	int			 e_error;
	TAILQ_ENTRY(g_raid_event) e_next;
};
#define G_RAID_DISK_S_NONE		0x00	/* State is unknown. */
#define G_RAID_DISK_S_OFFLINE		0x01	/* Missing disk placeholder. */
#define G_RAID_DISK_S_FAILED		0x02	/* Failed. */
#define G_RAID_DISK_S_STALE_FAILED	0x03	/* Old failed. */
#define G_RAID_DISK_S_SPARE		0x04	/* Hot-spare. */
#define G_RAID_DISK_S_STALE		0x05	/* Old disk, unused now. */
#define G_RAID_DISK_S_ACTIVE		0x06	/* Operational. */

#define G_RAID_DISK_E_DISCONNECTED	0x01

struct g_raid_disk {
	struct g_raid_softc	*d_softc;	/* Back-pointer to softc. */
	struct g_consumer	*d_consumer;	/* GEOM disk consumer. */
	void			*d_md_data;	/* Disk's metadata storage. */
	struct g_kerneldump	 d_kd;		/* Kernel dumping method/args. */
	u_int			 d_state;	/* Disk state. */
	uint64_t		 d_flags;	/* Additional flags. */
	u_int			 d_load;	/* Disk average load. */
	off_t			 d_last_offset;	/* Last head offset. */
	TAILQ_HEAD(, g_raid_subdisk)	 d_subdisks; /* List of subdisks. */
	TAILQ_ENTRY(g_raid_disk)	 d_next;	/* Next disk in the node. */
};

#define G_RAID_SUBDISK_S_NONE		0x00	/* Absent. */
#define G_RAID_SUBDISK_S_FAILED		0x01	/* Failed. */
#define G_RAID_SUBDISK_S_NEW		0x02	/* Blank. */
#define G_RAID_SUBDISK_S_STALE		0x03	/* Dirty. */
#define G_RAID_SUBDISK_S_REBUILD	0x04	/* Blank + rebuild. */
#define G_RAID_SUBDISK_S_RESYNC		0x05	/* Dirty + check/repair. */
#define G_RAID_SUBDISK_S_ACTIVE		0x06	/* Usable. */

#define G_RAID_SUBDISK_E_NEW		0x01	/* A new subdisk has arrived */
#define G_RAID_SUBDISK_E_FAILED		0x02	/* A subdisk failed, but remains in volume */
#define G_RAID_SUBDISK_E_DISCONNECTED	0x03	/* A subdisk removed from volume. */
#define G_RAID_SUBDISK_E_FIRST_TR_PRIVATE 0x80	/* translation private events */

struct g_raid_subdisk {
	struct g_raid_softc	*sd_softc;	/* Back-pointer to softc. */
	struct g_raid_disk	*sd_disk;	/* Where this subdisk lives. */
	struct g_raid_volume	*sd_volume;	/* Volume, sd is a part of. */
	off_t			 sd_offset;	/* Offset on the disk. */
	off_t			 sd_size;	/* Size on the disk. */
	u_int			 sd_pos;	/* Position in volume. */
	u_int			 sd_state;	/* Subdisk state. */
	off_t			 sd_rebuild_pos; /* Rebuild position. */
	int			 sd_read_errs;  /* Count of the read errors */
	TAILQ_ENTRY(g_raid_subdisk)	 sd_next; /* Next subdisk on disk. */
};

#define G_RAID_MAX_SUBDISKS	16
#define G_RAID_MAX_VOLUMENAME	16

#define G_RAID_VOLUME_S_STARTING	0x00
#define G_RAID_VOLUME_S_BROKEN		0x01
#define G_RAID_VOLUME_S_DEGRADED	0x02
#define G_RAID_VOLUME_S_SUBOPTIMAL	0x03
#define G_RAID_VOLUME_S_OPTIMAL		0x04
#define G_RAID_VOLUME_S_UNSUPPORTED	0x05
#define G_RAID_VOLUME_S_STOPPED		0x06

#define G_RAID_VOLUME_S_ALIVE(s)			\
    ((s) == G_RAID_VOLUME_S_DEGRADED ||			\
     (s) == G_RAID_VOLUME_S_SUBOPTIMAL ||		\
     (s) == G_RAID_VOLUME_S_OPTIMAL)

#define G_RAID_VOLUME_E_DOWN		0x00
#define G_RAID_VOLUME_E_UP		0x01
#define G_RAID_VOLUME_E_START		0x10

#define G_RAID_VOLUME_RL_RAID0		0x00
#define G_RAID_VOLUME_RL_RAID1		0x01
#define G_RAID_VOLUME_RL_RAID3		0x03
#define G_RAID_VOLUME_RL_RAID4		0x04
#define G_RAID_VOLUME_RL_RAID5		0x05
#define G_RAID_VOLUME_RL_RAID6		0x06
#define G_RAID_VOLUME_RL_RAID10		0x0a
#define G_RAID_VOLUME_RL_RAID1E		0x11
#define G_RAID_VOLUME_RL_SINGLE		0x0f
#define G_RAID_VOLUME_RL_CONCAT		0x1f
#define G_RAID_VOLUME_RL_RAID5E		0x15
#define G_RAID_VOLUME_RL_RAID5EE	0x25
#define G_RAID_VOLUME_RL_UNKNOWN	0xff

#define G_RAID_VOLUME_RLQ_NONE		0x00
#define G_RAID_VOLUME_RLQ_UNKNOWN	0xff

struct g_raid_volume;
typedef void (*g_raid_volume_timeout_t)(struct g_raid_volume *, void *);

struct g_raid_volume {
	struct g_raid_softc	*v_softc;	/* Back-pointer to softc. */
	struct g_provider	*v_provider;	/* GEOM provider. */
	struct g_raid_subdisk	 v_subdisks[G_RAID_MAX_SUBDISKS];
						/* Subdisks of this volume. */
	void			*v_md_data;	/* Volume's metadata storage. */
	struct g_raid_tr_object	*v_tr;		/* Transformation object. */
	char			 v_name[G_RAID_MAX_VOLUMENAME];
						/* Volume name. */
	u_int			 v_state;	/* Volume state. */
	u_int			 v_raid_level;	/* Array RAID level. */
	u_int			 v_raid_level_qualifier; /* RAID level det. */
	u_int			 v_disks_count;	/* Number of disks in array. */
	u_int			 v_strip_size;	/* Array strip size. */
	u_int			 v_sectorsize;	/* Volume sector size. */
	off_t			 v_mediasize;	/* Volume media size.  */
	struct bio_queue_head	 v_inflight;	/* In-flight write requests. */
	struct bio_queue_head	 v_locked;	/* Blocked I/O requests. */
	LIST_HEAD(, g_raid_lock) v_locks;	 /* List of locked regions. */
	int			 v_pending_lock; /* writes to locked region */
	int			 v_idle;	/* DIRTY flags removed. */
	time_t			 v_last_write;	/* Time of the last write. */
	u_int			 v_writes;	/* Number of active writes. */
	struct root_hold_token	*v_rootmount;	/* Root mount delay token. */
	struct callout		 v_start_co;	/* STARTING state timer. */
	int			 v_starting;	/* STARTING state timer armed */
	int			 v_stopping;	/* Volume is stopping */
	int			 v_provider_open; /* Number of opens. */
	int			 v_global_id;	/* Global volume ID (rX). */
	g_raid_volume_timeout_t  v_timeout;	/* Timeout function, if any */ 
	void			*v_to_arg;	/* Arg to timeout function */
	TAILQ_ENTRY(g_raid_volume)	 v_next; /* List of volumes entry. */
	LIST_ENTRY(g_raid_volume)	 v_global_next; /* Global list entry. */
};

#define G_RAID_NODE_E_START	0x01

struct g_raid_softc {
	struct g_raid_md_object	*sc_md;		/* Metadata object. */
	struct g_geom		*sc_geom;	/* GEOM class instance. */
	uint64_t		 sc_flags;	/* Additional flags. */
	TAILQ_HEAD(, g_raid_volume)	 sc_volumes;	/* List of volumes. */
	TAILQ_HEAD(, g_raid_disk)	 sc_disks;	/* List of disks. */
	struct sx		 sc_lock;	/* Main node lock. */
	struct proc		*sc_worker;	/* Worker process. */
	struct mtx		 sc_queue_mtx;	/* Worker queues lock. */
	TAILQ_HEAD(, g_raid_event) sc_events;	/* Worker events queue. */
	struct bio_queue_head	 sc_queue;	/* Worker I/O queue. */
	int			 sc_stopping;	/* Node is stopping */
};
#define	sc_name	sc_geom->name

/*
 * KOBJ parent class of metadata processing modules.
 */
struct g_raid_md_class {
	KOBJ_CLASS_FIELDS;
	int		 mdc_priority;
	LIST_ENTRY(g_raid_md_class) mdc_list;
};

/*
 * KOBJ instance of metadata processing module.
 */
struct g_raid_md_object {
	KOBJ_FIELDS;
	struct g_raid_md_class	*mdo_class;
	struct g_raid_softc	*mdo_softc;	/* Back-pointer to softc. */
};

int g_raid_md_modevent(module_t, int, void *);

#define	G_RAID_MD_DECLARE(name)					\
    static moduledata_t name##_mod = {				\
	#name,							\
	g_raid_md_modevent,					\
	&name##_class						\
    };								\
    DECLARE_MODULE(name, name##_mod, SI_SUB_DRIVERS, SI_ORDER_SECOND);	\
    MODULE_DEPEND(name, geom_raid, 0, 0, 0)

/*
 * KOBJ parent class of data transformation modules.
 */
struct g_raid_tr_class {
	KOBJ_CLASS_FIELDS;
	int		 trc_priority;
	LIST_ENTRY(g_raid_tr_class) trc_list;
};

/*
 * KOBJ instance of data transformation module.
 */
struct g_raid_tr_object {
	KOBJ_FIELDS;
	struct g_raid_tr_class	*tro_class;
	struct g_raid_volume 	*tro_volume;	/* Back-pointer to volume. */
};

int g_raid_tr_modevent(module_t, int, void *);

#define	G_RAID_TR_DECLARE(name)					\
    static moduledata_t name##_mod = {				\
	#name,							\
	g_raid_tr_modevent,					\
	&name##_class						\
    };								\
    DECLARE_MODULE(name, name##_mod, SI_SUB_DRIVERS, SI_ORDER_FIRST);	\
    MODULE_DEPEND(name, geom_raid, 0, 0, 0)

const char * g_raid_volume_level2str(int level, int qual);
int g_raid_volume_str2level(const char *str, int *level, int *qual);

struct g_raid_softc * g_raid_create_node(struct g_class *mp,
    const char *name, struct g_raid_md_object *md);
int g_raid_create_node_format(const char *format, struct g_geom **gp);
struct g_raid_volume * g_raid_create_volume(struct g_raid_softc *sc,
    const char *name);
struct g_raid_disk * g_raid_create_disk(struct g_raid_softc *sc);

int g_raid_start_volume(struct g_raid_volume *vol);

int g_raid_destroy_node(struct g_raid_softc *sc, int worker);
int g_raid_destroy_volume(struct g_raid_volume *vol);
int g_raid_destroy_disk(struct g_raid_disk *disk);

void g_raid_iodone(struct bio *bp, int error);
void g_raid_subdisk_iostart(struct g_raid_subdisk *sd, struct bio *bp);
int g_raid_subdisk_kerneldump(struct g_raid_subdisk *sd,
    void *virtual, vm_offset_t physical, off_t offset, size_t length);

void g_raid_kill_consumer(struct g_raid_softc *sc, struct g_consumer *cp);

void g_raid_report_disk_state(struct g_raid_disk *disk);
void g_raid_change_disk_state(struct g_raid_disk *disk, int state);
void g_raid_change_subdisk_state(struct g_raid_subdisk *sd, int state);
void g_raid_change_volume_state(struct g_raid_volume *vol, int state);

void g_raid_write_metadata(struct g_raid_softc *sc, struct g_raid_volume *vol,
    struct g_raid_subdisk *sd, struct g_raid_disk *disk);
void g_raid_fail_disk(struct g_raid_softc *sc,
    struct g_raid_subdisk *sd, struct g_raid_disk *disk);

int g_raid_tr_kerneldump_common(struct g_raid_tr_object *tr,
    void *virtual, vm_offset_t physical, off_t offset, size_t length);

u_int g_raid_ndisks(struct g_raid_softc *sc, int state);
u_int g_raid_nsubdisks(struct g_raid_volume *vol, int state);
#define	G_RAID_DESTROY_SOFT		0
#define	G_RAID_DESTROY_DELAYED	1
#define	G_RAID_DESTROY_HARD		2
int g_raid_destroy(struct g_raid_softc *sc, int how);
int g_raid_event_send(void *arg, int event, int flags);
int g_raid_lock_range(struct g_raid_volume *vol, off_t off, off_t len, void *argp);
int g_raid_unlock_range(struct g_raid_volume *vol, off_t off, off_t len);

g_ctl_req_t g_raid_ctl;
#endif	/* _KERNEL */

#endif	/* !_G_RAID_H_ */
