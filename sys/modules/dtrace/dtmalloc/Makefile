# $FreeBSD: releng/9.3/sys/modules/dtrace/dtmalloc/Makefile 254704 2013-08-23 14:17:45Z avg $

.PATH: ${.CURDIR}/../../../cddl/dev/dtmalloc

KMOD=		dtmalloc
SRCS=		dtmalloc.c
SRCS+=		vnode_if.h

CFLAGS+=	-I${.CURDIR}/../../../cddl/compat/opensolaris \
		-I${.CURDIR}/../../../cddl/contrib/opensolaris/uts/common \
		-I${.CURDIR}/../../..

.include <bsd.kmod.mk>

CFLAGS+=	-include ${.CURDIR}/../../../cddl/compat/opensolaris/sys/debug_compat.h
