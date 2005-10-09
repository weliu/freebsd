/****************************************************************

The author of this software is David M. Gay.

Copyright (C) 1998 by Lucent Technologies
All Rights Reserved

Permission to use, copy, modify, and distribute this software and
its documentation for any purpose and without fee is hereby
granted, provided that the above copyright notice appear in all
copies and that both that the copyright notice and this
permission notice and warranty disclaimer appear in supporting
documentation, and that the name of Lucent or any of its entities
not be used in advertising or publicity pertaining to
distribution of the software without specific, written prior
permission.

LUCENT DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS.
IN NO EVENT SHALL LUCENT OR ANY OF ITS ENTITIES BE LIABLE FOR ANY
SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER
IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF
THIS SOFTWARE.

****************************************************************/

/* Please send bug reports to
	David M. Gay
	Bell Laboratories, Room 2C-463
	600 Mountain Avenue
	Murray Hill, NJ 07974-0636
	U.S.A.
	dmg@bell-labs.com
 */

#include "gdtoaimp.h"

 int
#ifdef KR_headers
strtoIf(s, sp, f0, f1) CONST char *s; char **sp; float *f0, *f1;
#else
strtoIf(CONST char *s, char **sp, float *f0, float *f1)
#endif
{
	static FPI fpi = { 24, 1-127-24+1,  254-127-24+1, 1, SI };
	Long exp[2];
	Bigint *B[2];
	int k, rv[2];

	B[0] = Balloc(0);
	B[0]->wds = 1;
	k = strtoIg(s, sp, &fpi, exp, B, rv);
	ULtof((ULong*)f0, B[0]->x, exp[0], rv[0]);
	Bfree(B[0]);
	if (B[1]) {
		ULtof((ULong*)f1, B[1]->x, exp[1], rv[1]);
		Bfree(B[1]);
		}
	else
		*(ULong*)f1 = *(ULong*)f0;
	return k;
	}
