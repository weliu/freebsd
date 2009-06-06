/*
 * System call switch table.
 *
 * DO NOT EDIT-- this file is automatically generated.
 * $FreeBSD$
 * created from FreeBSD: head/sys/i386/ibcs2/syscalls.master 191919 2009-05-08 20:06:37Z ed 
 */

#include <sys/param.h>
#include <sys/sysent.h>
#include <sys/sysproto.h>
#include <i386/ibcs2/ibcs2_types.h>
#include <i386/ibcs2/ibcs2_signal.h>
#include <i386/ibcs2/ibcs2_proto.h>

#define AS(name) (sizeof(struct name) / sizeof(register_t))

/* The casts are bogus but will do for now. */
struct sysent ibcs2_sysent[] = {
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },		/* 0 = syscall */
	{ AS(sys_exit_args), (sy_call_t *)sys_exit, AUE_EXIT, NULL, 0, 0, 0 },	/* 1 = exit */
	{ 0, (sy_call_t *)fork, AUE_FORK, NULL, 0, 0, 0 },		/* 2 = fork */
	{ AS(ibcs2_read_args), (sy_call_t *)ibcs2_read, AUE_NULL, NULL, 0, 0, 0 },	/* 3 = ibcs2_read */
	{ AS(write_args), (sy_call_t *)write, AUE_NULL, NULL, 0, 0, 0 },	/* 4 = write */
	{ AS(ibcs2_open_args), (sy_call_t *)ibcs2_open, AUE_OPEN_RWTC, NULL, 0, 0, 0 },	/* 5 = ibcs2_open */
	{ AS(close_args), (sy_call_t *)close, AUE_CLOSE, NULL, 0, 0, 0 },	/* 6 = close */
	{ AS(ibcs2_wait_args), (sy_call_t *)ibcs2_wait, AUE_WAIT4, NULL, 0, 0, 0 },	/* 7 = ibcs2_wait */
	{ AS(ibcs2_creat_args), (sy_call_t *)ibcs2_creat, AUE_CREAT, NULL, 0, 0, 0 },	/* 8 = ibcs2_creat */
	{ AS(link_args), (sy_call_t *)link, AUE_LINK, NULL, 0, 0, 0 },	/* 9 = link */
	{ AS(ibcs2_unlink_args), (sy_call_t *)ibcs2_unlink, AUE_UNLINK, NULL, 0, 0, 0 },	/* 10 = ibcs2_unlink */
	{ AS(ibcs2_execv_args), (sy_call_t *)ibcs2_execv, AUE_EXECVE, NULL, 0, 0, 0 },	/* 11 = ibcs2_execv */
	{ AS(ibcs2_chdir_args), (sy_call_t *)ibcs2_chdir, AUE_CHDIR, NULL, 0, 0, 0 },	/* 12 = ibcs2_chdir */
	{ AS(ibcs2_time_args), (sy_call_t *)ibcs2_time, AUE_NULL, NULL, 0, 0, 0 },	/* 13 = ibcs2_time */
	{ AS(ibcs2_mknod_args), (sy_call_t *)ibcs2_mknod, AUE_MKNOD, NULL, 0, 0, 0 },	/* 14 = ibcs2_mknod */
	{ AS(ibcs2_chmod_args), (sy_call_t *)ibcs2_chmod, AUE_CHMOD, NULL, 0, 0, 0 },	/* 15 = ibcs2_chmod */
	{ AS(ibcs2_chown_args), (sy_call_t *)ibcs2_chown, AUE_CHOWN, NULL, 0, 0, 0 },	/* 16 = ibcs2_chown */
	{ AS(obreak_args), (sy_call_t *)obreak, AUE_NULL, NULL, 0, 0, 0 },	/* 17 = obreak */
	{ AS(ibcs2_stat_args), (sy_call_t *)ibcs2_stat, AUE_STAT, NULL, 0, 0, 0 },	/* 18 = ibcs2_stat */
	{ AS(ibcs2_lseek_args), (sy_call_t *)ibcs2_lseek, AUE_LSEEK, NULL, 0, 0, 0 },	/* 19 = ibcs2_lseek */
	{ 0, (sy_call_t *)getpid, AUE_NULL, NULL, 0, 0, 0 },		/* 20 = getpid */
	{ AS(ibcs2_mount_args), (sy_call_t *)ibcs2_mount, AUE_MOUNT, NULL, 0, 0, 0 },	/* 21 = ibcs2_mount */
	{ AS(ibcs2_umount_args), (sy_call_t *)ibcs2_umount, AUE_UMOUNT, NULL, 0, 0, 0 },	/* 22 = ibcs2_umount */
	{ AS(ibcs2_setuid_args), (sy_call_t *)ibcs2_setuid, AUE_SETUID, NULL, 0, 0, 0 },	/* 23 = ibcs2_setuid */
	{ 0, (sy_call_t *)getuid, AUE_GETUID, NULL, 0, 0, 0 },		/* 24 = getuid */
	{ AS(ibcs2_stime_args), (sy_call_t *)ibcs2_stime, AUE_SETTIMEOFDAY, NULL, 0, 0, 0 },	/* 25 = ibcs2_stime */
	{ AS(ptrace_args), (sy_call_t *)ptrace, AUE_PTRACE, NULL, 0, 0, 0 },	/* 26 = ptrace */
	{ AS(ibcs2_alarm_args), (sy_call_t *)ibcs2_alarm, AUE_NULL, NULL, 0, 0, 0 },	/* 27 = ibcs2_alarm */
	{ AS(ibcs2_fstat_args), (sy_call_t *)ibcs2_fstat, AUE_FSTAT, NULL, 0, 0, 0 },	/* 28 = ibcs2_fstat */
	{ 0, (sy_call_t *)ibcs2_pause, AUE_NULL, NULL, 0, 0, 0 },	/* 29 = ibcs2_pause */
	{ AS(ibcs2_utime_args), (sy_call_t *)ibcs2_utime, AUE_NULL, NULL, 0, 0, 0 },	/* 30 = ibcs2_utime */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 31 = ibcs2_stty */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 32 = ibcs2_gtty */
	{ AS(ibcs2_access_args), (sy_call_t *)ibcs2_access, AUE_ACCESS, NULL, 0, 0, 0 },	/* 33 = ibcs2_access */
	{ AS(ibcs2_nice_args), (sy_call_t *)ibcs2_nice, AUE_NICE, NULL, 0, 0, 0 },	/* 34 = ibcs2_nice */
	{ AS(ibcs2_statfs_args), (sy_call_t *)ibcs2_statfs, AUE_STATFS, NULL, 0, 0, 0 },	/* 35 = ibcs2_statfs */
	{ 0, (sy_call_t *)sync, AUE_NULL, NULL, 0, 0, 0 },		/* 36 = sync */
	{ AS(ibcs2_kill_args), (sy_call_t *)ibcs2_kill, AUE_KILL, NULL, 0, 0, 0 },	/* 37 = ibcs2_kill */
	{ AS(ibcs2_fstatfs_args), (sy_call_t *)ibcs2_fstatfs, AUE_FSTATFS, NULL, 0, 0, 0 },	/* 38 = ibcs2_fstatfs */
	{ AS(ibcs2_pgrpsys_args), (sy_call_t *)ibcs2_pgrpsys, AUE_NULL, NULL, 0, 0, 0 },	/* 39 = ibcs2_pgrpsys */
	{ AS(ibcs2_xenix_args), (sy_call_t *)ibcs2_xenix, AUE_NULL, NULL, 0, 0, 0 },	/* 40 = ibcs2_xenix */
	{ AS(dup_args), (sy_call_t *)dup, AUE_NULL, NULL, 0, 0, 0 },	/* 41 = dup */
	{ 0, (sy_call_t *)pipe, AUE_PIPE, NULL, 0, 0, 0 },		/* 42 = pipe */
	{ AS(ibcs2_times_args), (sy_call_t *)ibcs2_times, AUE_NULL, NULL, 0, 0, 0 },	/* 43 = ibcs2_times */
	{ AS(profil_args), (sy_call_t *)profil, AUE_PROFILE, NULL, 0, 0, 0 },	/* 44 = profil */
	{ AS(ibcs2_plock_args), (sy_call_t *)ibcs2_plock, AUE_NULL, NULL, 0, 0, 0 },	/* 45 = ibcs2_plock */
	{ AS(ibcs2_setgid_args), (sy_call_t *)ibcs2_setgid, AUE_SETGID, NULL, 0, 0, 0 },	/* 46 = ibcs2_setgid */
	{ 0, (sy_call_t *)getgid, AUE_GETGID, NULL, 0, 0, 0 },		/* 47 = getgid */
	{ AS(ibcs2_sigsys_args), (sy_call_t *)ibcs2_sigsys, AUE_NULL, NULL, 0, 0, 0 },	/* 48 = ibcs2_sigsys */
	{ AS(ibcs2_msgsys_args), (sy_call_t *)ibcs2_msgsys, AUE_MSGSYS, NULL, 0, 0, 0 },	/* 49 = ibcs2_msgsys */
	{ AS(ibcs2_sysi86_args), (sy_call_t *)ibcs2_sysi86, AUE_NULL, NULL, 0, 0, 0 },	/* 50 = ibcs2_sysi86 */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 51 = ibcs2_acct */
	{ AS(ibcs2_shmsys_args), (sy_call_t *)ibcs2_shmsys, AUE_SHMSYS, NULL, 0, 0, 0 },	/* 52 = ibcs2_shmsys */
	{ AS(ibcs2_semsys_args), (sy_call_t *)ibcs2_semsys, AUE_SEMSYS, NULL, 0, 0, 0 },	/* 53 = ibcs2_semsys */
	{ AS(ibcs2_ioctl_args), (sy_call_t *)ibcs2_ioctl, AUE_IOCTL, NULL, 0, 0, 0 },	/* 54 = ibcs2_ioctl */
	{ AS(ibcs2_uadmin_args), (sy_call_t *)ibcs2_uadmin, AUE_NULL, NULL, 0, 0, 0 },	/* 55 = ibcs2_uadmin */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 56 = nosys */
	{ AS(ibcs2_utssys_args), (sy_call_t *)ibcs2_utssys, AUE_NULL, NULL, 0, 0, 0 },	/* 57 = ibcs2_utssys */
	{ AS(fsync_args), (sy_call_t *)fsync, AUE_FSYNC, NULL, 0, 0, 0 },	/* 58 = fsync */
	{ AS(ibcs2_execve_args), (sy_call_t *)ibcs2_execve, AUE_EXECVE, NULL, 0, 0, 0 },	/* 59 = ibcs2_execve */
	{ AS(umask_args), (sy_call_t *)umask, AUE_UMASK, NULL, 0, 0, 0 },	/* 60 = umask */
	{ AS(chroot_args), (sy_call_t *)chroot, AUE_CHROOT, NULL, 0, 0, 0 },	/* 61 = chroot */
	{ AS(ibcs2_fcntl_args), (sy_call_t *)ibcs2_fcntl, AUE_FCNTL, NULL, 0, 0, 0 },	/* 62 = ibcs2_fcntl */
	{ AS(ibcs2_ulimit_args), (sy_call_t *)ibcs2_ulimit, AUE_NULL, NULL, 0, 0, 0 },	/* 63 = ibcs2_ulimit */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 64 = reserved for unix/pc */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 65 = reserved for unix/pc */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 66 = reserved for unix/pc */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 67 = reserved for unix/pc */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 68 = reserved for unix/pc */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 69 = reserved for unix/pc */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 70 = obsolete rfs_advfs */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 71 = obsolete rfs_unadvfs */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 72 = obsolete rfs_rmount */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 73 = obsolete rfs_rumount */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 74 = obsolete rfs_rfstart */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 75 = obsolete rfs_sigret */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 76 = obsolete rfs_rdebug */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 77 = obsolete rfs_rfstop */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 78 = rfs_rfsys */
	{ AS(ibcs2_rmdir_args), (sy_call_t *)ibcs2_rmdir, AUE_RMDIR, NULL, 0, 0, 0 },	/* 79 = ibcs2_rmdir */
	{ AS(ibcs2_mkdir_args), (sy_call_t *)ibcs2_mkdir, AUE_MKDIR, NULL, 0, 0, 0 },	/* 80 = ibcs2_mkdir */
	{ AS(ibcs2_getdents_args), (sy_call_t *)ibcs2_getdents, AUE_GETDIRENTRIES, NULL, 0, 0, 0 },	/* 81 = ibcs2_getdents */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 82 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 83 = nosys */
	{ AS(ibcs2_sysfs_args), (sy_call_t *)ibcs2_sysfs, AUE_NULL, NULL, 0, 0, 0 },	/* 84 = ibcs2_sysfs */
	{ AS(ibcs2_getmsg_args), (sy_call_t *)ibcs2_getmsg, AUE_GETMSG, NULL, 0, 0, 0 },	/* 85 = ibcs2_getmsg */
	{ AS(ibcs2_putmsg_args), (sy_call_t *)ibcs2_putmsg, AUE_PUTMSG, NULL, 0, 0, 0 },	/* 86 = ibcs2_putmsg */
	{ AS(poll_args), (sy_call_t *)poll, AUE_POLL, NULL, 0, 0, 0 },	/* 87 = poll */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 88 = nosys */
	{ AS(ibcs2_secure_args), (sy_call_t *)ibcs2_secure, AUE_NULL, NULL, 0, 0, 0 },	/* 89 = ibcs2_secure */
	{ AS(ibcs2_symlink_args), (sy_call_t *)ibcs2_symlink, AUE_SYMLINK, NULL, 0, 0, 0 },	/* 90 = ibcs2_symlink */
	{ AS(ibcs2_lstat_args), (sy_call_t *)ibcs2_lstat, AUE_LSTAT, NULL, 0, 0, 0 },	/* 91 = ibcs2_lstat */
	{ AS(ibcs2_readlink_args), (sy_call_t *)ibcs2_readlink, AUE_READLINK, NULL, 0, 0, 0 },	/* 92 = ibcs2_readlink */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 93 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 94 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 95 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 96 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 97 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 98 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 99 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 100 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 101 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 102 = nosys */
	{ AS(sigreturn_args), (sy_call_t *)sigreturn, AUE_NULL, NULL, 0, 0, 0 },	/* 103 = sigreturn */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 104 = nosys */
	{ 0, (sy_call_t *)ibcs2_isc, AUE_NULL, NULL, 0, 0, 0 },		/* 105 = ibcs2_isc */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 106 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 107 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 108 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 109 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 110 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 111 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 112 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 113 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 114 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 115 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 116 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 117 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 118 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 119 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 120 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 121 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 122 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 123 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 124 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 125 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 126 = nosys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0 },			/* 127 = nosys */
};
