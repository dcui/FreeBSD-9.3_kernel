# $FreeBSD: releng/9.3/sys/modules/dtrace/dtrace_test/Makefile 260820 2014-01-17 11:13:45Z avg $

.PATH: ${.CURDIR}/../../../cddl/dev/dtrace

KMOD=		dtrace_test
SRCS=		dtrace_test.c

SRCS+=		opt_kdtrace.h
SRCS+=		vnode_if.h

CFLAGS+=	-I${.CURDIR}/../../..

CFLAGS+=	-D_KERNEL

.include <bsd.kmod.mk>

CFLAGS+=	-include ${.CURDIR}/../../../cddl/compat/opensolaris/sys/debug_compat.h
