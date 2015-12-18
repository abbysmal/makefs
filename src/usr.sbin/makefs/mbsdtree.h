/*	$MirOS: src/usr.sbin/makefs/mbsdtree.h,v 1.3 2009/07/23 19:32:24 tg Exp $	*/
/*	$OpenBSD: util.h,v 1.26 2004/07/13 21:09:48 millert Exp $	*/
/*	$NetBSD: util.h,v 1.2 1996/05/16 07:00:22 thorpej Exp $	*/

/*-
 * Copyright (c) 2009
 *	Thorsten Glaser <tg@mirbsd.org>
 * Copyright (c) 1995
 *	The Regents of the University of California.  All rights reserved.
 * Portions Copyright (c) 1996, Jason Downs.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef MBSDTREE_H
#define MBSDTREE_H

#include <sys/types.h>

__BEGIN_DECLS


/* lib/libc/stdlib/strsuftoll.c */

long long strsuftoll(const char *, const char *,
    long long, long long);
long long strsuftollx(const char *, const char *,
    long long, long long, char *, size_t)
#if defined(__GNUC__) && (defined(__OpenBSD__) || defined(__MirBSD__))
    __attribute__((bounded (string, 5, 6)))
#endif
    ;

#ifndef DEBIAN
/* lib/libutil/stat_flags.c */

char *flags_to_string(u_long, const char *);
int string_to_flags(char **, u_long *, u_long *);
#endif

#ifdef DEBIAN
/*
 * fparseln() specific operation flags.
 */
#define FPARSELN_UNESCESC	0x01
#define FPARSELN_UNESCCONT	0x02
#define FPARSELN_UNESCCOMM	0x04
#define FPARSELN_UNESCREST	0x08
#define FPARSELN_UNESCALL	0x0f

char   *fparseln(FILE *, size_t *, size_t *, const char[3], int);
#endif


__END_DECLS

#endif
