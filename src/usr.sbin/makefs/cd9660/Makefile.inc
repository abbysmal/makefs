#	$MirOS: src/usr.sbin/makefs/cd9660/Makefile.inc,v 1.2 2010/03/06 21:29:06 tg Exp $
#	$NetBSD: Makefile.inc,v 1.1 2009/01/16 19:39:52 pooka Exp $
#

.PATH:	${.CURDIR}/cd9660 ${NETBSDSRCDIR}/sys/fs/cd9660

CPPFLAGS+=-I${NETBSDSRCDIR}/sys/fs/cd9660

SRCS+=	cd9660_strings.c cd9660_debug.c cd9660_eltorito.c
SRCS+=	cd9660_write.c cd9660_conversion.c iso9660_rrip.c cd9660_archimedes.c
