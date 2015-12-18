# $MirOS: src/usr.sbin/mtree/Makefile,v 1.3 2005/04/13 20:30:16 tg Exp $
# $OpenBSD: Makefile,v 1.7 2004/05/02 17:55:53 millert Exp $

PROG=	mtree
#CPPFLAGS+=-DDEBUG
MAN=	mtree.8
SRCS=	compare.c crc.c create.c misc.c mtree.c spec.c verify.c

CPPFLAGS+=	$(INCS)
LDADD+=		$(LIBS)

.include <bsd.prog.mk>
