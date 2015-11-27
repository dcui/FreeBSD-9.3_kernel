# $FreeBSD: releng/9.3/sys/modules/dtrace/systrace_linux32/Makefile 254704 2013-08-23 14:17:45Z avg $

.PATH: ${.CURDIR}/../../../cddl/dev/systrace

.if ${MACHINE} == "amd64"
KMOD=		systrace_linux32
.else
KMOD=		systrace_linux
.endif

SRCS=		systrace.c
SRCS+=		vnode_if.h

CFLAGS+=	-I${.CURDIR}/../../../cddl/compat/opensolaris \
		-I${.CURDIR}/../../../cddl/contrib/opensolaris/uts/common \
		-I${.CURDIR}/../../.. -DLINUX_SYSTRACE

.include <bsd.kmod.mk>

CFLAGS+=	-include ${.CURDIR}/../../../cddl/compat/opensolaris/sys/debug_compat.h
