/*
 * Copyright (c) 1995, 1996, 1997 Kungliga Tekniska H�gskolan
 * (Royal Institute of Technology, Stockholm, Sweden).
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by the Kungliga Tekniska
 *      H�gskolan and its contributors.
 * 
 * 4. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include "krb_locl.h"

RCSID("$Id: k_flock.c,v 1.8 1997/04/01 08:18:30 joda Exp $");

#define K_OP_MASK (K_LOCK_SH | K_LOCK_EX | K_LOCK_UN)

int
k_flock(int fd, int operation)
{
#ifdef HAVE_FLOCK
  int op = 0;
  if (operation & K_LOCK_SH)
    op |= LOCK_SH;
  if (operation & K_LOCK_EX)
    op |= LOCK_EX;
  if (operation & K_LOCK_UN)
    op |= LOCK_UN;
  if (operation & K_LOCK_NB)
    op |= LOCK_NB;

  return flock(fd, op);
#elif defined(HAVE_FCNTL) && defined(F_SETLK)
  struct flock arg;
  int code, cmd;
  
  arg.l_whence = SEEK_SET;
  arg.l_start = 0;
  arg.l_len = 0;		/* means to EOF */

  if (operation & K_LOCK_NB)
    cmd = F_SETLK;
  else
    cmd = F_SETLKW;		/* Blocking */

  switch (operation & K_OP_MASK) {
  case K_LOCK_UN:
    arg.l_type = F_UNLCK;
    code = fcntl(fd, F_SETLK, &arg);
    break;
  case K_LOCK_SH:
    arg.l_type = F_RDLCK;
    code = fcntl(fd, cmd, &arg);
    break;
  case K_LOCK_EX:
    arg.l_type = F_WRLCK;
    code = fcntl(fd, cmd, &arg);
    break;
  default:
    errno = EINVAL;
    code = -1;
    break;
  }
  return code;
#else
  return -1;
#endif /* !HAVE_FLOCK */
}
