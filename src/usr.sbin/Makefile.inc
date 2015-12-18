# $MirOS: src/usr.sbin/Makefile.inc,v 1.4 2009/07/23 19:32:22 tg Exp $
# $OpenBSD: Makefile.inc,v 1.2 1997/09/21 11:43:04 deraadt Exp $

.ifndef _MODSRC_USR_SBIN_MAKEFILE_INC
_MODSRC_USR_SBIN_MAKEFILE_INC=1

BINDIR?=	/usr/sbin
.ifndef DEBIAN
LDFLAGS+=	-Wl,-rpath -Wl,/usr/lib
.endif

.endif
