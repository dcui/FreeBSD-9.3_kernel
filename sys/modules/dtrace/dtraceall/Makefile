# $FreeBSD: releng/9.3/sys/modules/dtrace/dtraceall/Makefile 254704 2013-08-23 14:17:45Z avg $

KMOD=		dtraceall
SRCS=		dtraceall.c opt_compat.h

CFLAGS+=	-I${.CURDIR}/../../..

.if !defined(KERNBUILDDIR)
.if ${MACHINE_ARCH} == "amd64"
opt_compat.h:
	echo "#define COMPAT_FREEBSD32 1" >> ${.TARGET}
.endif
.endif

.include <bsd.kmod.mk>

CFLAGS+=	-include ${.CURDIR}/../../../cddl/compat/opensolaris/sys/debug_compat.h
