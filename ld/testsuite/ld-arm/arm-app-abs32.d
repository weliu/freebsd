
tmpdir/arm-app-abs32:     file format elf32-littlearm
architecture: arm, flags 0x00000112:
EXEC_P, HAS_SYMS, D_PAGED
start address .*

Disassembly of section .plt:

.* <.plt>:
    .*:	e52de004 	str	lr, \[sp, #-4\]!
    .*:	e59fe004 	ldr	lr, \[pc, #4\]	; .* <.plt\+0x10>
    .*:	e08fe00e 	add	lr, pc, lr
    .*:	e5bef008 	ldr	pc, \[lr, #8\]!
    .*:	.* 	.*
    .*:	e28fc6.* 	add	ip, pc, #.*	; .*
    .*:	e28cca.* 	add	ip, ip, #.*	; .*
    .*:	e5bcf.* 	ldr	pc, \[ip, #.*\]!
Disassembly of section .text:

.* <_start>:
    .*:	e1a0c00d 	mov	ip, sp
    .*:	e92dd800 	stmdb	sp!, {fp, ip, lr, pc}
    .*:	e59f0004 	ldr	r0, \[pc, #4\]	; .* <.text\+0x14>
    .*:	e89d6800 	ldmia	sp, {fp, sp, lr}
    .*:	e12fff1e 	bx	lr
    .*:	.* 	.*

.* <app_func2>:
    .*:	e12fff1e 	bx	lr
