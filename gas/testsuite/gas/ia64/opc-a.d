# objdump: -d
# name: ia64 opc-a

.*: +file format .*

Disassembly of section \.text:

0+000 <_start>:
   0:	00 28 9b cf 00 60 	\[MII\]       add r101=r102,r103
   6:	80 4e ab 01 40 60 	      \(p01\) add r104=r105,r106
   c:	cd 6e 07 80       	            add r107=r108,r109,1
  10:	40 70 bf e1 01 20 	\[MII\] \(p02\) add r110=r111,r112,1
  16:	40 01 28 00 c2 a0 	            mov r20=r10
  1c:	12 50 00 84       	      \(p01\) adds r21=1,r10
  20:	00 b0 fc 15 3f 23 	\[MII\]       adds r22=-1,r10
  26:	70 01 28 00 46 01 	            adds r23=-8192,r10
  2c:	f3 57 fc 84       	      \(p02\) adds r24=8191,r10
  30:	00 f0 00 02 00 24 	\[MII\]       addl r30=0,r1
  36:	f0 09 04 00 c8 00 	            addl r31=1,r1
  3c:	f4 ef ff 9f       	      \(p01\) addl r32=-1,r1
  40:	00 08 01 fa c0 27 	\[MII\]       addl r33=-8192,r1
  46:	20 fa 07 7e 48 60 	            addl r34=8191,r1
  4c:	04 08 00 98       	            addl r35=-2097152,r1
  50:	00 20 fd fb ff 25 	\[MII\]       addl r36=2097151,r1
  56:	b0 00 28 00 42 80 	            mov r11=r10
  5c:	41 53 90 84       	            adds r12=4660,r10
  60:	00 68 d0 02 24 24 	\[MII\]       addl r13=4660,r1
  66:	e0 28 16 8c 48 80 	            addl r14=74565,r1
  6c:	32 50 20 80       	            addp4 r20=r3,r10
  70:	20 a8 04 14 80 21 	\[MII\] \(p01\) addp4 r21=1,r10
  76:	60 f9 2b 7e 47 a0 	            addp4 r22=-1,r10
  7c:	6c 3e 17 80       	            sub r101=r102,r103
  80:	40 70 bf e1 04 20 	\[MII\] \(p02\) sub r110=r111,r112,1
  86:	80 07 0c 4a 40 20 	            sub r120=0,r3
  8c:	1f 18 94 80       	            sub r121=1,r3
  90:	00 d0 ff 07 25 22 	\[MII\]       sub r122=-1,r3
  96:	b0 07 0c 4a 44 80 	            sub r123=-128,r3
  9c:	ff 1f 94 80       	            sub r124=127,r3
  a0:	00 40 24 14 0c e0 	\[MII\]       and r8=r9,r10
  a6:	b0 00 30 58 44 02 	      \(p03\) and r11=-128,r12
  ac:	91 50 38 80       	      \(p04\) or r8=r9,r10
  b0:	00 58 00 18 2e 22 	\[MII\]       or r11=-128,r12
  b6:	80 48 28 1e 40 60 	            xor r8=r9,r10
  bc:	01 60 bc 88       	            xor r11=-128,r12
  c0:	00 40 24 14 0d 20 	\[MII\]       andcm r8=r9,r10
  c6:	b0 00 30 5a 44 00 	            andcm r11=-128,r12
  cc:	e1 f9 40 80       	            shladd r8=r30,1,r31
  d0:	00 48 78 3e 11 20 	\[MII\]       shladd r9=r30,2,r31
  d6:	a0 f0 7c 24 40 60 	            shladd r10=r30,3,r31
  dc:	e1 f9 4c 80       	            shladd r11=r30,4,r31
  e0:	00 40 78 3e 18 20 	\[MII\]       shladdp4 r8=r30,1,r31
  e6:	90 f0 7c 32 40 40 	            shladdp4 r9=r30,2,r31
  ec:	e1 f9 68 80       	            shladdp4 r10=r30,3,r31
  f0:	00 58 78 3e 1b 20 	\[MII\]       shladdp4 r11=r30,4,r31
  f6:	a0 f0 7c 00 41 60 	            padd1 r10=r30,r31
  fc:	e1 f9 04 82       	            padd1\.sss r11=r30,r31
 100:	00 60 78 3e 83 20 	\[MII\]       padd1\.uus r12=r30,r31
 106:	d0 f0 7c 04 41 c0 	            padd1\.uuu r13=r30,r31
 10c:	e1 f9 00 83       	            padd2 r14=r30,r31
 110:	00 78 78 3e c1 20 	\[MII\]       padd2\.sss r15=r30,r31
 116:	00 f1 7c 86 41 20 	            padd2\.uus r16=r30,r31
 11c:	e2 f9 08 83       	            padd2\.uuu r17=r30,r31
 120:	00 90 78 3e 80 22 	\[MII\]       padd4 r18=r30,r31
 126:	a0 f0 7c 08 41 60 	            psub1 r10=r30,r31
 12c:	e1 f9 14 82       	            psub1\.sss r11=r30,r31
 130:	00 60 78 3e 87 20 	\[MII\]       psub1\.uus r12=r30,r31
 136:	d0 f0 7c 0c 41 c0 	            psub1\.uuu r13=r30,r31
 13c:	e1 f9 10 83       	            psub2 r14=r30,r31
 140:	00 78 78 3e c5 20 	\[MII\]       psub2\.sss r15=r30,r31
 146:	00 f1 7c 8e 41 20 	            psub2\.uus r16=r30,r31
 14c:	e2 f9 18 83       	            psub2\.uuu r17=r30,r31
 150:	00 90 78 3e 84 22 	\[MII\]       psub4 r18=r30,r31
 156:	a0 f0 7c 14 41 40 	            pavg1 r10=r30,r31
 15c:	e1 f9 2c 82       	            pavg1\.raz r10=r30,r31
 160:	00 50 78 3e ca 20 	\[MII\]       pavg2 r10=r30,r31
 166:	a0 f0 7c 96 41 40 	            pavg2\.raz r10=r30,r31
 16c:	e1 f9 38 82       	            pavgsub1 r10=r30,r31
 170:	00 50 78 3e ce 20 	\[MII\]       pavgsub2 r10=r30,r31
 176:	a0 f0 7c 48 41 40 	            pcmp1\.eq r10=r30,r31
 17c:	e1 f9 90 83       	            pcmp2\.eq r10=r30,r31
 180:	00 50 78 3e a4 22 	\[MII\]       pcmp4\.eq r10=r30,r31
 186:	a0 f0 7c 4a 41 40 	            pcmp1\.gt r10=r30,r31
 18c:	e1 f9 94 83       	            pcmp2\.gt r10=r30,r31
 190:	00 50 78 3e a5 22 	\[MII\]       pcmp4\.gt r10=r30,r31
 196:	a0 58 30 a0 41 40 	            pshladd2 r10=r11,1,r12
 19c:	b1 60 48 83       	            pshladd2 r10=r11,3,r12
 1a0:	00 50 2c 18 d8 20 	\[MII\]       pshradd2 r10=r11,1,r12
 1a6:	a0 58 30 b2 41 40 	            pshradd2 r10=r11,2,r12
 1ac:	30 20 0c e0       	            cmp\.eq p2,p3=r3,r4
 1b0:	00 10 0c 08 03 39 	\[MII\]       cmp\.eq p2,p3=3,r4
 1b6:	30 18 10 04 70 60 	            cmp\.eq p3,p2=r3,r4
 1bc:	30 20 08 e4       	            cmp\.eq p3,p2=3,r4
 1c0:	00 10 0c 08 03 30 	\[MII\]       cmp\.lt p2,p3=r3,r4
 1c6:	20 18 10 06 62 60 	            cmp\.lt p2,p3=3,r4
 1cc:	40 18 08 c0       	            cmp\.lt p3,p2=r4,r3
 1d0:	00 10 08 08 03 31 	\[MII\]       cmp\.lt p2,p3=2,r4
 1d6:	20 20 0c 06 60 60 	            cmp\.lt p2,p3=r4,r3
 1dc:	20 20 08 c4       	            cmp\.lt p3,p2=2,r4
 1e0:	00 18 0c 08 02 30 	\[MII\]       cmp\.lt p3,p2=r3,r4
 1e6:	30 18 10 04 62 40 	            cmp\.lt p3,p2=3,r4
 1ec:	30 20 0c d0       	            cmp\.ltu p2,p3=r3,r4
 1f0:	00 10 0c 08 03 35 	\[MII\]       cmp\.ltu p2,p3=3,r4
 1f6:	30 20 0c 04 68 40 	            cmp\.ltu p3,p2=r4,r3
 1fc:	20 20 0c d4       	            cmp\.ltu p2,p3=2,r4
 200:	00 10 10 06 03 34 	\[MII\]       cmp\.ltu p2,p3=r4,r3
 206:	30 10 10 04 6a 60 	            cmp\.ltu p3,p2=2,r4
 20c:	30 20 08 d0       	            cmp\.ltu p3,p2=r3,r4
 210:	00 18 0c 08 02 35 	\[MII\]       cmp\.ltu p3,p2=3,r4
 216:	20 1c 10 06 70 40 	            cmp\.eq\.unc p2,p3=r3,r4
 21c:	38 20 0c e4       	            cmp\.eq\.unc p2,p3=3,r4
 220:	00 18 0e 08 02 38 	\[MII\]       cmp\.eq\.unc p3,p2=r3,r4
 226:	30 1c 10 04 72 40 	            cmp\.eq\.unc p3,p2=3,r4
 22c:	38 20 0c c0       	            cmp\.lt\.unc p2,p3=r3,r4
 230:	00 10 0e 08 03 31 	\[MII\]       cmp\.lt\.unc p2,p3=3,r4
 236:	30 24 0c 04 60 40 	            cmp\.lt\.unc p3,p2=r4,r3
 23c:	28 20 0c c4       	            cmp\.lt\.unc p2,p3=2,r4
 240:	00 10 12 06 03 30 	\[MII\]       cmp\.lt\.unc p2,p3=r4,r3
 246:	30 14 10 04 62 60 	            cmp\.lt\.unc p3,p2=2,r4
 24c:	38 20 08 c0       	            cmp\.lt\.unc p3,p2=r3,r4
 250:	00 18 0e 08 02 31 	\[MII\]       cmp\.lt\.unc p3,p2=3,r4
 256:	20 1c 10 06 68 40 	            cmp\.ltu\.unc p2,p3=r3,r4
 25c:	38 20 0c d4       	            cmp\.ltu\.unc p2,p3=3,r4
 260:	00 18 12 06 02 34 	\[MII\]       cmp\.ltu\.unc p3,p2=r4,r3
 266:	20 14 10 06 6a 40 	            cmp\.ltu\.unc p2,p3=2,r4
 26c:	48 18 0c d0       	            cmp\.ltu\.unc p2,p3=r4,r3
 270:	00 18 0a 08 02 35 	\[MII\]       cmp\.ltu\.unc p3,p2=2,r4
 276:	30 1c 10 04 68 60 	            cmp\.ltu\.unc p3,p2=r3,r4
 27c:	38 20 08 d4       	            cmp\.ltu\.unc p3,p2=3,r4
 280:	00 10 0c 08 43 30 	\[MII\]       cmp\.eq\.and p2,p3=r3,r4
 286:	20 18 10 86 62 40 	            cmp\.eq\.and p2,p3=3,r4
 28c:	30 20 0c d1       	            cmp\.eq\.or p2,p3=r3,r4
 290:	00 10 0c 08 43 35 	\[MII\]       cmp\.eq\.or p2,p3=3,r4
 296:	20 18 10 86 70 40 	            cmp\.eq\.or\.andcm p2,p3=r3,r4
 29c:	30 20 0c e5       	            cmp\.eq\.or\.andcm p2,p3=3,r4
 2a0:	00 10 0e 08 43 34 	\[MII\]       cmp\.ne\.or p2,p3=r3,r4
 2a6:	20 1c 10 86 6a 40 	            cmp\.ne\.or p2,p3=3,r4
 2ac:	38 20 0c c1       	            cmp\.ne\.and p2,p3=r3,r4
 2b0:	00 10 0e 08 43 31 	\[MII\]       cmp\.ne\.and p2,p3=3,r4
 2b6:	30 1c 10 84 70 60 	            cmp\.ne\.or\.andcm p3,p2=r3,r4
 2bc:	38 20 08 e5       	            cmp\.ne\.or\.andcm p3,p2=3,r4
 2c0:	00 10 0e 08 43 30 	\[MII\]       cmp\.ne\.and p2,p3=r3,r4
 2c6:	20 1c 10 86 62 40 	            cmp\.ne\.and p2,p3=3,r4
 2cc:	38 20 0c d1       	            cmp\.ne\.or p2,p3=r3,r4
 2d0:	00 10 0e 08 43 35 	\[MII\]       cmp\.ne\.or p2,p3=3,r4
 2d6:	20 1c 10 86 70 40 	            cmp\.ne\.or\.andcm p2,p3=r3,r4
 2dc:	38 20 0c e5       	            cmp\.ne\.or\.andcm p2,p3=3,r4
 2e0:	00 10 0c 08 43 34 	\[MII\]       cmp\.eq\.or p2,p3=r3,r4
 2e6:	20 18 10 86 6a 40 	            cmp\.eq\.or p2,p3=3,r4
 2ec:	30 20 0c c1       	            cmp\.eq\.and p2,p3=r3,r4
 2f0:	00 10 0c 08 43 31 	\[MII\]       cmp\.eq\.and p2,p3=3,r4
 2f6:	30 18 10 84 70 60 	            cmp\.eq\.or\.andcm p3,p2=r3,r4
 2fc:	30 20 08 e5       	            cmp\.eq\.or\.andcm p3,p2=3,r4
 300:	00 10 00 08 43 30 	\[MII\]       cmp\.eq\.and p2,p3=r0,r4
 306:	20 20 00 86 60 40 	            cmp\.eq\.and p2,p3=r4,r0
 30c:	00 20 0c d1       	            cmp\.eq\.or p2,p3=r0,r4
 310:	00 10 10 00 43 34 	\[MII\]       cmp\.eq\.or p2,p3=r4,r0
 316:	20 00 10 86 70 40 	            cmp\.eq\.or\.andcm p2,p3=r0,r4
 31c:	40 00 0c e1       	            cmp\.eq\.or\.andcm p2,p3=r4,r0
 320:	00 10 02 08 43 34 	\[MII\]       cmp\.ne\.or p2,p3=r0,r4
 326:	20 24 00 86 68 40 	            cmp\.ne\.or p2,p3=r4,r0
 32c:	08 20 0c c1       	            cmp\.ne\.and p2,p3=r0,r4
 330:	00 10 12 00 43 30 	\[MII\]       cmp\.ne\.and p2,p3=r4,r0
 336:	30 04 10 84 70 60 	            cmp\.ne\.or\.andcm p3,p2=r0,r4
 33c:	48 00 08 e1       	            cmp\.ne\.or\.andcm p3,p2=r4,r0
 340:	00 10 02 08 43 30 	\[MII\]       cmp\.ne\.and p2,p3=r0,r4
 346:	20 24 00 86 60 40 	            cmp\.ne\.and p2,p3=r4,r0
 34c:	08 20 0c d1       	            cmp\.ne\.or p2,p3=r0,r4
 350:	00 10 12 00 43 34 	\[MII\]       cmp\.ne\.or p2,p3=r4,r0
 356:	20 04 10 86 70 40 	            cmp\.ne\.or\.andcm p2,p3=r0,r4
 35c:	48 00 0c e1       	            cmp\.ne\.or\.andcm p2,p3=r4,r0
 360:	00 10 00 08 43 34 	\[MII\]       cmp\.eq\.or p2,p3=r0,r4
 366:	20 20 00 86 68 40 	            cmp\.eq\.or p2,p3=r4,r0
 36c:	00 20 0c c1       	            cmp\.eq\.and p2,p3=r0,r4
 370:	00 10 10 00 43 30 	\[MII\]       cmp\.eq\.and p2,p3=r4,r0
 376:	30 00 10 84 70 60 	            cmp\.eq\.or\.andcm p3,p2=r0,r4
 37c:	40 00 08 e1       	            cmp\.eq\.or\.andcm p3,p2=r4,r0
 380:	00 10 02 08 43 32 	\[MII\]       cmp\.lt\.and p2,p3=r0,r4
 386:	20 00 10 06 64 40 	            cmp\.gt\.and p2,p3=r0,r4
 38c:	08 20 0c d9       	            cmp\.lt\.or p2,p3=r0,r4
 390:	00 10 00 08 03 36 	\[MII\]       cmp\.gt\.or p2,p3=r0,r4
 396:	20 04 10 86 74 40 	            cmp\.lt\.or\.andcm p2,p3=r0,r4
 39c:	00 20 0c e8       	            cmp\.gt\.or\.andcm p2,p3=r0,r4
 3a0:	00 10 00 08 43 36 	\[MII\]       cmp\.ge\.or p2,p3=r0,r4
 3a6:	20 04 10 06 6c 40 	            cmp\.le\.or p2,p3=r0,r4
 3ac:	00 20 0c c9       	            cmp\.ge\.and p2,p3=r0,r4
 3b0:	00 10 02 08 03 32 	\[MII\]       cmp\.le\.and p2,p3=r0,r4
 3b6:	30 00 10 84 74 60 	            cmp\.ge\.or\.andcm p3,p2=r0,r4
 3bc:	08 20 08 e8       	            cmp\.le\.or\.andcm p3,p2=r0,r4
 3c0:	00 10 02 08 03 32 	\[MII\]       cmp\.le\.and p2,p3=r0,r4
 3c6:	20 00 10 86 64 40 	            cmp\.ge\.and p2,p3=r0,r4
 3cc:	08 20 0c d8       	            cmp\.le\.or p2,p3=r0,r4
 3d0:	00 10 00 08 43 36 	\[MII\]       cmp\.ge\.or p2,p3=r0,r4
 3d6:	20 04 10 06 74 40 	            cmp\.le\.or\.andcm p2,p3=r0,r4
 3dc:	00 20 0c e9       	            cmp\.ge\.or\.andcm p2,p3=r0,r4
 3e0:	00 10 00 08 03 36 	\[MII\]       cmp\.gt\.or p2,p3=r0,r4
 3e6:	20 04 10 86 6c 40 	            cmp\.lt\.or p2,p3=r0,r4
 3ec:	00 20 0c c8       	            cmp\.gt\.and p2,p3=r0,r4
 3f0:	00 10 02 08 43 32 	\[MII\]       cmp\.lt\.and p2,p3=r0,r4
 3f6:	30 00 10 04 74 60 	            cmp\.gt\.or\.andcm p3,p2=r0,r4
 3fc:	08 20 08 e9       	            cmp\.lt\.or\.andcm p3,p2=r0,r4
 400:	00 10 00 08 03 32 	\[MII\]       cmp\.gt\.and p2,p3=r0,r4
 406:	20 04 10 86 64 40 	            cmp\.lt\.and p2,p3=r0,r4
 40c:	00 20 0c d8       	            cmp\.gt\.or p2,p3=r0,r4
 410:	00 10 02 08 43 36 	\[MII\]       cmp\.lt\.or p2,p3=r0,r4
 416:	20 00 10 06 74 40 	            cmp\.gt\.or\.andcm p2,p3=r0,r4
 41c:	08 20 0c e9       	            cmp\.lt\.or\.andcm p2,p3=r0,r4
 420:	00 10 02 08 03 36 	\[MII\]       cmp\.le\.or p2,p3=r0,r4
 426:	20 00 10 86 6c 40 	            cmp\.ge\.or p2,p3=r0,r4
 42c:	08 20 0c c8       	            cmp\.le\.and p2,p3=r0,r4
 430:	00 10 00 08 43 32 	\[MII\]       cmp\.ge\.and p2,p3=r0,r4
 436:	30 04 10 04 74 60 	            cmp\.le\.or\.andcm p3,p2=r0,r4
 43c:	00 20 08 e9       	            cmp\.ge\.or\.andcm p3,p2=r0,r4
 440:	00 10 00 08 43 32 	\[MII\]       cmp\.ge\.and p2,p3=r0,r4
 446:	20 04 10 06 64 40 	            cmp\.le\.and p2,p3=r0,r4
 44c:	00 20 0c d9       	            cmp\.ge\.or p2,p3=r0,r4
 450:	00 10 02 08 03 36 	\[MII\]       cmp\.le\.or p2,p3=r0,r4
 456:	20 00 10 86 74 40 	            cmp\.ge\.or\.andcm p2,p3=r0,r4
 45c:	08 20 0c e8       	            cmp\.le\.or\.andcm p2,p3=r0,r4
 460:	00 10 02 08 43 36 	\[MII\]       cmp\.lt\.or p2,p3=r0,r4
 466:	20 00 10 06 6c 40 	            cmp\.gt\.or p2,p3=r0,r4
 46c:	08 20 0c c9       	            cmp\.lt\.and p2,p3=r0,r4
 470:	00 10 00 08 03 32 	\[MII\]       cmp\.gt\.and p2,p3=r0,r4
 476:	30 04 10 84 74 60 	            cmp\.lt\.or\.andcm p3,p2=r0,r4
 47c:	00 20 08 e8       	            cmp\.gt\.or\.andcm p3,p2=r0,r4
 480:	00 10 0c 08 83 38 	\[MII\]       cmp4\.eq p2,p3=r3,r4
 486:	20 18 10 06 73 60 	            cmp4\.eq p2,p3=3,r4
 48c:	30 20 08 e2       	            cmp4\.eq p3,p2=r3,r4
 490:	00 18 0c 08 82 39 	\[MII\]       cmp4\.eq p3,p2=3,r4
 496:	20 18 10 06 61 40 	            cmp4\.lt p2,p3=r3,r4
 49c:	30 20 0c c6       	            cmp4\.lt p2,p3=3,r4
 4a0:	00 18 10 06 82 30 	\[MII\]       cmp4\.lt p3,p2=r4,r3
 4a6:	20 10 10 06 63 40 	            cmp4\.lt p2,p3=2,r4
 4ac:	40 18 0c c2       	            cmp4\.lt p2,p3=r4,r3
 4b0:	00 18 08 08 82 31 	\[MII\]       cmp4\.lt p3,p2=2,r4
 4b6:	30 18 10 04 61 60 	            cmp4\.lt p3,p2=r3,r4
 4bc:	30 20 08 c6       	            cmp4\.lt p3,p2=3,r4
 4c0:	00 10 0c 08 83 34 	\[MII\]       cmp4\.ltu p2,p3=r3,r4
 4c6:	20 18 10 06 6b 60 	            cmp4\.ltu p2,p3=3,r4
 4cc:	40 18 08 d2       	            cmp4\.ltu p3,p2=r4,r3
 4d0:	00 10 08 08 83 35 	\[MII\]       cmp4\.ltu p2,p3=2,r4
 4d6:	20 20 0c 06 69 60 	            cmp4\.ltu p2,p3=r4,r3
 4dc:	20 20 08 d6       	            cmp4\.ltu p3,p2=2,r4
 4e0:	00 18 0c 08 82 34 	\[MII\]       cmp4\.ltu p3,p2=r3,r4
 4e6:	30 18 10 04 6b 40 	            cmp4\.ltu p3,p2=3,r4
 4ec:	38 20 0c e2       	            cmp4\.eq\.unc p2,p3=r3,r4
 4f0:	00 10 0e 08 83 39 	\[MII\]       cmp4\.eq\.unc p2,p3=3,r4
 4f6:	30 1c 10 04 71 60 	            cmp4\.eq\.unc p3,p2=r3,r4
 4fc:	38 20 08 e6       	            cmp4\.eq\.unc p3,p2=3,r4
 500:	00 10 0e 08 83 30 	\[MII\]       cmp4\.lt\.unc p2,p3=r3,r4
 506:	20 1c 10 06 63 60 	            cmp4\.lt\.unc p2,p3=3,r4
 50c:	48 18 08 c2       	            cmp4\.lt\.unc p3,p2=r4,r3
 510:	00 10 0a 08 83 31 	\[MII\]       cmp4\.lt\.unc p2,p3=2,r4
 516:	20 24 0c 06 61 60 	            cmp4\.lt\.unc p2,p3=r4,r3
 51c:	28 20 08 c6       	            cmp4\.lt\.unc p3,p2=2,r4
 520:	00 18 0e 08 82 30 	\[MII\]       cmp4\.lt\.unc p3,p2=r3,r4
 526:	30 1c 10 04 63 40 	            cmp4\.lt\.unc p3,p2=3,r4
 52c:	38 20 0c d2       	            cmp4\.ltu\.unc p2,p3=r3,r4
 530:	00 10 0e 08 83 35 	\[MII\]       cmp4\.ltu\.unc p2,p3=3,r4
 536:	30 24 0c 04 69 40 	            cmp4\.ltu\.unc p3,p2=r4,r3
 53c:	28 20 0c d6       	            cmp4\.ltu\.unc p2,p3=2,r4
 540:	00 10 12 06 83 34 	\[MII\]       cmp4\.ltu\.unc p2,p3=r4,r3
 546:	30 14 10 04 6b 60 	            cmp4\.ltu\.unc p3,p2=2,r4
 54c:	38 20 08 d2       	            cmp4\.ltu\.unc p3,p2=r3,r4
 550:	00 18 0e 08 82 35 	\[MII\]       cmp4\.ltu\.unc p3,p2=3,r4
 556:	20 18 10 86 61 40 	            cmp4\.eq\.and p2,p3=r3,r4
 55c:	30 20 0c c7       	            cmp4\.eq\.and p2,p3=3,r4
 560:	00 10 0c 08 c3 34 	\[MII\]       cmp4\.eq\.or p2,p3=r3,r4
 566:	20 18 10 86 6b 40 	            cmp4\.eq\.or p2,p3=3,r4
 56c:	30 20 0c e3       	            cmp4\.eq\.or\.andcm p2,p3=r3,r4
 570:	00 10 0c 08 c3 39 	\[MII\]       cmp4\.eq\.or\.andcm p2,p3=3,r4
 576:	20 1c 10 86 69 40 	            cmp4\.ne\.or p2,p3=r3,r4
 57c:	38 20 0c d7       	            cmp4\.ne\.or p2,p3=3,r4
 580:	00 10 0e 08 c3 30 	\[MII\]       cmp4\.ne\.and p2,p3=r3,r4
 586:	20 1c 10 86 63 60 	            cmp4\.ne\.and p2,p3=3,r4
 58c:	38 20 08 e3       	            cmp4\.ne\.or\.andcm p3,p2=r3,r4
 590:	00 18 0e 08 c2 39 	\[MII\]       cmp4\.ne\.or\.andcm p3,p2=3,r4
 596:	20 1c 10 86 61 40 	            cmp4\.ne\.and p2,p3=r3,r4
 59c:	38 20 0c c7       	            cmp4\.ne\.and p2,p3=3,r4
 5a0:	00 10 0e 08 c3 34 	\[MII\]       cmp4\.ne\.or p2,p3=r3,r4
 5a6:	20 1c 10 86 6b 40 	            cmp4\.ne\.or p2,p3=3,r4
 5ac:	38 20 0c e3       	            cmp4\.ne\.or\.andcm p2,p3=r3,r4
 5b0:	00 10 0e 08 c3 39 	\[MII\]       cmp4\.ne\.or\.andcm p2,p3=3,r4
 5b6:	20 18 10 86 69 40 	            cmp4\.eq\.or p2,p3=r3,r4
 5bc:	30 20 0c d7       	            cmp4\.eq\.or p2,p3=3,r4
 5c0:	00 10 0c 08 c3 30 	\[MII\]       cmp4\.eq\.and p2,p3=r3,r4
 5c6:	20 18 10 86 63 60 	            cmp4\.eq\.and p2,p3=3,r4
 5cc:	30 20 08 e3       	            cmp4\.eq\.or\.andcm p3,p2=r3,r4
 5d0:	00 18 0c 08 c2 39 	\[MII\]       cmp4\.eq\.or\.andcm p3,p2=3,r4
 5d6:	20 00 10 86 61 40 	            cmp4\.eq\.and p2,p3=r0,r4
 5dc:	40 00 0c c3       	            cmp4\.eq\.and p2,p3=r4,r0
 5e0:	00 10 00 08 c3 34 	\[MII\]       cmp4\.eq\.or p2,p3=r0,r4
 5e6:	20 20 00 86 69 40 	            cmp4\.eq\.or p2,p3=r4,r0
 5ec:	00 20 0c e3       	            cmp4\.eq\.or\.andcm p2,p3=r0,r4
 5f0:	00 10 10 00 c3 38 	\[MII\]       cmp4\.eq\.or\.andcm p2,p3=r4,r0
 5f6:	20 04 10 86 69 40 	            cmp4\.ne\.or p2,p3=r0,r4
 5fc:	48 00 0c d3       	            cmp4\.ne\.or p2,p3=r4,r0
 600:	00 10 02 08 c3 30 	\[MII\]       cmp4\.ne\.and p2,p3=r0,r4
 606:	20 24 00 86 61 60 	            cmp4\.ne\.and p2,p3=r4,r0
 60c:	08 20 08 e3       	            cmp4\.ne\.or\.andcm p3,p2=r0,r4
 610:	00 18 12 00 c2 38 	\[MII\]       cmp4\.ne\.or\.andcm p3,p2=r4,r0
 616:	20 04 10 86 61 40 	            cmp4\.ne\.and p2,p3=r0,r4
 61c:	48 00 0c c3       	            cmp4\.ne\.and p2,p3=r4,r0
 620:	00 10 02 08 c3 34 	\[MII\]       cmp4\.ne\.or p2,p3=r0,r4
 626:	20 24 00 86 69 40 	            cmp4\.ne\.or p2,p3=r4,r0
 62c:	08 20 0c e3       	            cmp4\.ne\.or\.andcm p2,p3=r0,r4
 630:	00 10 12 00 c3 38 	\[MII\]       cmp4\.ne\.or\.andcm p2,p3=r4,r0
 636:	20 00 10 86 69 40 	            cmp4\.eq\.or p2,p3=r0,r4
 63c:	40 00 0c d3       	            cmp4\.eq\.or p2,p3=r4,r0
 640:	00 10 00 08 c3 30 	\[MII\]       cmp4\.eq\.and p2,p3=r0,r4
 646:	20 20 00 86 61 60 	            cmp4\.eq\.and p2,p3=r4,r0
 64c:	00 20 08 e3       	            cmp4\.eq\.or\.andcm p3,p2=r0,r4
 650:	00 18 10 00 c2 38 	\[MII\]       cmp4\.eq\.or\.andcm p3,p2=r4,r0
 656:	20 04 10 86 65 40 	            cmp4\.lt\.and p2,p3=r0,r4
 65c:	00 20 0c ca       	            cmp4\.gt\.and p2,p3=r0,r4
 660:	00 10 02 08 c3 36 	\[MII\]       cmp4\.lt\.or p2,p3=r0,r4
 666:	20 00 10 06 6d 40 	            cmp4\.gt\.or p2,p3=r0,r4
 66c:	08 20 0c eb       	            cmp4\.lt\.or\.andcm p2,p3=r0,r4
 670:	00 10 00 08 83 3a 	\[MII\]       cmp4\.gt\.or\.andcm p2,p3=r0,r4
 676:	20 00 10 86 6d 40 	            cmp4\.ge\.or p2,p3=r0,r4
 67c:	08 20 0c da       	            cmp4\.le\.or p2,p3=r0,r4
 680:	00 10 00 08 c3 32 	\[MII\]       cmp4\.ge\.and p2,p3=r0,r4
 686:	20 04 10 06 65 60 	            cmp4\.le\.and p2,p3=r0,r4
 68c:	00 20 08 eb       	            cmp4\.ge\.or\.andcm p3,p2=r0,r4
 690:	00 18 02 08 82 3a 	\[MII\]       cmp4\.le\.or\.andcm p3,p2=r0,r4
 696:	20 04 10 06 65 40 	            cmp4\.le\.and p2,p3=r0,r4
 69c:	00 20 0c cb       	            cmp4\.ge\.and p2,p3=r0,r4
 6a0:	00 10 02 08 83 36 	\[MII\]       cmp4\.le\.or p2,p3=r0,r4
 6a6:	20 00 10 86 6d 40 	            cmp4\.ge\.or p2,p3=r0,r4
 6ac:	08 20 0c ea       	            cmp4\.le\.or\.andcm p2,p3=r0,r4
 6b0:	00 10 00 08 c3 3a 	\[MII\]       cmp4\.ge\.or\.andcm p2,p3=r0,r4
 6b6:	20 00 10 06 6d 40 	            cmp4\.gt\.or p2,p3=r0,r4
 6bc:	08 20 0c db       	            cmp4\.lt\.or p2,p3=r0,r4
 6c0:	00 10 00 08 83 32 	\[MII\]       cmp4\.gt\.and p2,p3=r0,r4
 6c6:	20 04 10 86 65 60 	            cmp4\.lt\.and p2,p3=r0,r4
 6cc:	00 20 08 ea       	            cmp4\.gt\.or\.andcm p3,p2=r0,r4
 6d0:	00 18 02 08 c2 3a 	\[MII\]       cmp4\.lt\.or\.andcm p3,p2=r0,r4
 6d6:	20 00 10 06 65 40 	            cmp4\.gt\.and p2,p3=r0,r4
 6dc:	08 20 0c cb       	            cmp4\.lt\.and p2,p3=r0,r4
 6e0:	00 10 00 08 83 36 	\[MII\]       cmp4\.gt\.or p2,p3=r0,r4
 6e6:	20 04 10 86 6d 40 	            cmp4\.lt\.or p2,p3=r0,r4
 6ec:	00 20 0c ea       	            cmp4\.gt\.or\.andcm p2,p3=r0,r4
 6f0:	00 10 02 08 c3 3a 	\[MII\]       cmp4\.lt\.or\.andcm p2,p3=r0,r4
 6f6:	20 04 10 06 6d 40 	            cmp4\.le\.or p2,p3=r0,r4
 6fc:	00 20 0c db       	            cmp4\.ge\.or p2,p3=r0,r4
 700:	00 10 02 08 83 32 	\[MII\]       cmp4\.le\.and p2,p3=r0,r4
 706:	20 00 10 86 65 60 	            cmp4\.ge\.and p2,p3=r0,r4
 70c:	08 20 08 ea       	            cmp4\.le\.or\.andcm p3,p2=r0,r4
 710:	00 18 00 08 c2 3a 	\[MII\]       cmp4\.ge\.or\.andcm p3,p2=r0,r4
 716:	20 00 10 86 65 40 	            cmp4\.ge\.and p2,p3=r0,r4
 71c:	08 20 0c ca       	            cmp4\.le\.and p2,p3=r0,r4
 720:	00 10 00 08 c3 36 	\[MII\]       cmp4\.ge\.or p2,p3=r0,r4
 726:	20 04 10 06 6d 40 	            cmp4\.le\.or p2,p3=r0,r4
 72c:	00 20 0c eb       	            cmp4\.ge\.or\.andcm p2,p3=r0,r4
 730:	00 10 02 08 83 3a 	\[MII\]       cmp4\.le\.or\.andcm p2,p3=r0,r4
 736:	20 04 10 86 6d 40 	            cmp4\.lt\.or p2,p3=r0,r4
 73c:	00 20 0c da       	            cmp4\.gt\.or p2,p3=r0,r4
 740:	00 10 02 08 c3 32 	\[MII\]       cmp4\.lt\.and p2,p3=r0,r4
 746:	20 00 10 06 65 60 	            cmp4\.gt\.and p2,p3=r0,r4
 74c:	08 20 08 eb       	            cmp4\.lt\.or\.andcm p3,p2=r0,r4
 750:	01 18 00 08 82 3a 	\[MII\]       cmp4\.gt\.or\.andcm p3,p2=r0,r4
 756:	00 00 00 02 00 00 	            nop\.i 0x0
 75c:	00 00 04 00       	            nop\.i 0x0;;
