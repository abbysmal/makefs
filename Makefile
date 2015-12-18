#!/usr/bin/make -f

shellescape='$(subst ','\'',$(1))'
shellexport=$(1)=$(call shellescape,${$(1)})

CC?=			gcc
EXTRA_CFLAGS+=		-Wall -Wformat
EXTRA_CPPFLAGS+=	-include /usr/include/bsd/bsd.h
EXTRA_CPPFLAGS+=	-idirafter /usr/include/bsd
EXTRA_LDFLAGS=		-Wl,--as-needed

# not yet (needs to be checked upstream)
EXTRA_CFLAGS+=		-Wno-unused-but-set-variable
EXTRA_CFLAGS+=		-Wno-unused-result

CFLAGS=			-O$(if $(findstring noopt,${DEB_BUILD_OPTIONS}),0,2) -g
CFLAGS+=		${EXTRA_CFLAGS}
CPPFLAGS+=		${EXTRA_CPPFLAGS}
LDFLAGS+=		${EXTRA_LDFLAGS}

DEFS+=	-D'__IDSTRING(x,y)=static const char x[] __attribute__((__used__)) = y'
DEFS+=	-D'__KERNEL_RCSID(x,y)=__IDSTRING(kernelrcsid_ \#\# x,y)'
DEFS+=	-D'__dead=__attribute__((__noreturn__))'
DEFS+=	-D'_DIAGASSERT(x)='

DEFS+=	-D'bswap16=__bswap_16'
DEFS+=	-D'bswap32=__bswap_32'
DEFS+=	-D'bswap64=__bswap_64'
DEFS+=	-DHAVE_STRUCT_STATVFS_F_IOSIZE=0
DEFS+=	-DHAVE_STRUCT_STAT_ST_MTIMENSEC=0
DEFS+=	-DHAVE_STRUCT_STAT_ST_FLAGS=0
DEFS+=	-DHAVE_STRUCT_STAT_ST_GEN=0

PMAKE_FLAGS:=	BSDSRCDIR="$$_topdir/builddir"
PMAKE_FLAGS+=	DEBIAN=Yes
# disable -Werror for package build (comment this out if developing)
PMAKE_FLAGS+=	NOGCCERROR=Yes

build build-arch: builddir/.build_stamp
build-indep:

builddir/.build_stamp:
	-rm -rf builddir
	mkdir builddir
	cp -r src/* builddir/
	+_topdir=$$(pwd); cd builddir/usr.sbin/makefs; \
	 for opts in '-flto=jobserver' ''; do \
		set -x; \
		$(foreach i,CC CFLAGS LDFLAGS,$(call shellexport,$i)); \
		CPPFLAGS=$(call shellescape,${CPPFLAGS} ${DEFS}); \
		CFLAGS="$$CFLAGS $$opts"; \
		LDFLAGS="$$CFLAGS $$LDFLAGS"; \
		export LC_ALL=C CC CFLAGS CPPFLAGS LDFLAGS; \
		bmake ${PMAKE_FLAGS} makefs || continue; \
		test -x makefs && exit 0; \
	done; echo >&2 Compiling failed.; exit 1
	@:>$@


binary: binary-indep binary-arch
.PHONY: binary binary-arch binary-indep build build-arch build-indep clean
