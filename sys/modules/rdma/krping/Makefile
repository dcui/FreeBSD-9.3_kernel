# $FreeBSD: releng/9.3/sys/modules/rdma/krping/Makefile 256109 2013-10-07 12:57:27Z pluknet $

RDMA= ${.CURDIR}/../../../contrib/rdma/krping
.PATH: ${RDMA}

KMOD= krping
SRCS= krping.c krping_dev.c getopt.c
SRCS+=  bus_if.h device_if.h pci_if.h pcib_if.h vnode_if.h
SRCS+=  opt_sched.h opt_inet.h opt_inet6.h
CFLAGS+= -I${.CURDIR}/../../../ofed/include

.include <bsd.kmod.mk>
