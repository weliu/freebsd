/*
 * Mach Operating System
 * Copyright (c) 1991,1990 Carnegie Mellon University
 * All Rights Reserved.
 *
 * Permission to use, copy, modify and distribute this software and its
 * documentation is hereby granted, provided that both the copyright
 * notice and this permission notice appear in all copies of the
 * software, derivative works or modified versions, and any portions
 * thereof, and that both notices appear in supporting documentation.
 *
 * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"
 * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR
 * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.
 *
 * Carnegie Mellon requests users of this software to return to
 *
 *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU
 *  School of Computer Science
 *  Carnegie Mellon University
 *  Pittsburgh PA 15213-3890
 *
 * any improvements or extensions that they make and grant Carnegie Mellon
 * the rights to redistribute these changes.
 *
 * $FreeBSD$
 */

#ifndef _MACHINE_DB_MACHDEP_H_
#define	_MACHINE_DB_MACHDEP_H_

/*
 * Machine-dependent defines for new kernel debugger.
 */

/* #include <mach/i386/vm_types.h> */
/* #include <mach/i386/vm_param.h> */
#include <vm/vm_prot.h>
#include <vm/vm_param.h>
#include <vm/vm_inherit.h>
#include <vm/lock.h>
/* #include <i386/thread.h> */		/* for thread_status */
#include <machine/frame.h>		/* for struct trapframe */
/* #include <i386/eflags.h> */
#include <machine/psl.h>
/* #include <i386/trap.h> */
#include <machine/trap.h>

#define i386_saved_state trapframe

typedef	vm_offset_t	db_addr_t;	/* address - unsigned */
typedef	int		db_expr_t;	/* expression - signed */

typedef struct i386_saved_state db_regs_t;
extern db_regs_t	ddb_regs;	/* register state */
#define	DDB_REGS	(&ddb_regs)

#define	PC_REGS(regs)	(((regs)->tf_cs & 0xfffc) == 0x08 \
			 ? (db_addr_t)(regs)->tf_eip : 0)

#define	BKPT_INST	0xcc		/* breakpoint instruction */
#define	BKPT_SIZE	(1)		/* size of breakpoint inst */
#define	BKPT_SET(inst)	(BKPT_INST)

#define	FIXUP_PC_AFTER_BREAK	ddb_regs.tf_eip -= 1;

#define	db_clear_single_step(regs)	((regs)->tf_eflags &= ~PSL_T)
#define	db_set_single_step(regs)	((regs)->tf_eflags |=  PSL_T)

#define	IS_BREAKPOINT_TRAP(type, code)	((type) == T_BPTFLT)
/*
 * Watchpoints are not supported.  The debug exception type is in %dr6
 * and not yet in the args to this macro.
 */
#define IS_WATCHPOINT_TRAP(type, code)	0

#define	I_CALL		0xe8
#define	I_CALLI		0xff
#define	I_RET		0xc3
#define	I_IRET		0xcf

#define	inst_trap_return(ins)	(((ins)&0xff) == I_IRET)
#define	inst_return(ins)	(((ins)&0xff) == I_RET)
#define	inst_call(ins)		(((ins)&0xff) == I_CALL || \
				 (((ins)&0xff) == I_CALLI && \
				  ((ins)&0x3800) == 0x1000))
#define inst_load(ins)		0
#define inst_store(ins)		0

/* access capability and access macros */

#define DB_ACCESS_LEVEL		2	/* access any space */
#define DB_CHECK_ACCESS(addr,size,task)				\
	db_check_access(addr,size,task)
#define DB_PHYS_EQ(task1,addr1,task2,addr2)			\
	db_phys_eq(task1,addr1,task2,addr2)
#define DB_VALID_KERN_ADDR(addr)				\
	((addr) >= VM_MIN_KERNEL_ADDRESS && 			\
	 (addr) < VM_MAX_KERNEL_ADDRESS)
#define DB_VALID_ADDRESS(addr,user)				\
	((!(user) && DB_VALID_KERN_ADDR(addr)) ||		\
	 ((user) && (addr) < VM_MIN_KERNEL_ADDRESS))

boolean_t 	db_check_access(/* vm_offset_t, int, task_t */);
boolean_t	db_phys_eq(/* task_t, vm_offset_t, task_t, vm_offset_t */);

/* macros for printing OS server dependent task name */

#define DB_TASK_NAME(task)	db_task_name(task)
#define DB_TASK_NAME_TITLE	"COMMAND                "
#define DB_TASK_NAME_LEN	23
#define DB_NULL_TASK_NAME	"?                      "

void		db_task_name(/* task_t */);

/* macro for checking if a thread has used floating-point */

#define db_thread_fp_used(thread)	((thread)->pcb->ims.ifps != 0)

#endif /* !_MACHINE_DB_MACHDEP_H_ */
