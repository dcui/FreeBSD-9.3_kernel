# $FreeBSD: releng/9.3/sys/modules/dtrace/sdt/Makefile 256109 2013-10-07 12:57:27Z pluknet $

.PATH: ${.CURDIR}/../../../cddl/dev/sdt

KMOD=		sdt
SRCS=		sdt.c
SRCS+=		vnode_if.h opt_kdtrace.h

CFLAGS+=	-I${.CURDIR}/../../../cddl/compat/opensolaris \
		-I${.CURDIR}/../../../cddl/contrib/opensolaris/uts/common \
		-I${.CURDIR}/../../..

.include <bsd.kmod.mk>

CFLAGS+=	-include ${.CURDIR}/../../../cddl/compat/opensolaris/sys/debug_compat.h
