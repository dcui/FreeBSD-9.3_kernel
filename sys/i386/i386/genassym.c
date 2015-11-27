/*-
 * Copyright (c) 1982, 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * William Jolitz.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	from: @(#)genassym.c	5.11 (Berkeley) 5/10/91
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD: releng/9.3/sys/i386/i386/genassym.c 235796 2012-05-22 17:44:01Z iwasaki $");

#include "opt_apic.h"
#include "opt_compat.h"
#include "opt_hwpmc_hooks.h"
#include "opt_kstack_pages.h"

#include <sys/param.h>
#include <sys/systm.h>
#include <sys/assym.h>
#include <sys/bio.h>
#include <sys/buf.h>
#ifdef	HWPMC_HOOKS
#include <sys/pmckern.h>
#endif
#include <sys/proc.h>
#include <sys/errno.h>
#include <sys/mount.h>
#include <sys/mutex.h>
#include <sys/socket.h>
#include <sys/resourcevar.h>
#include <sys/signalvar.h>
#include <sys/ucontext.h>
#include <machine/bootinfo.h>
#include <machine/tss.h>
#include <sys/vmmeter.h>
#include <vm/vm.h>
#include <vm/vm_param.h>
#include <vm/pmap.h>
#include <vm/vm_map.h>
#include <sys/proc.h>
#include <net/if.h>
#include <netinet/in.h>
#include <nfs/nfsproto.h>
#include <nfsclient/nfs.h>
#include <nfs/nfsdiskless.h>
#ifdef DEV_APIC
#include <x86/apicreg.h>
#endif
#include <machine/cpu.h>
#include <machine/pcb.h>
#include <machine/sigframe.h>
#include <machine/vm86.h>
#include <machine/proc.h>

ASSYM(P_VMSPACE, offsetof(struct proc, p_vmspace));
ASSYM(VM_PMAP, offsetof(struct vmspace, vm_pmap));
ASSYM(PM_ACTIVE, offsetof(struct pmap, pm_active));

ASSYM(TD_FLAGS, offsetof(struct thread, td_flags));
ASSYM(TD_LOCK, offsetof(struct thread, td_lock));
ASSYM(TD_PCB, offsetof(struct thread, td_pcb));
ASSYM(TD_PFLAGS, offsetof(struct thread, td_pflags));
ASSYM(TD_PROC, offsetof(struct thread, td_proc));
ASSYM(TD_MD, offsetof(struct thread, td_md));
ASSYM(TD_TID, offsetof(struct thread, td_tid));

ASSYM(TDP_CALLCHAIN, TDP_CALLCHAIN);

ASSYM(P_MD, offsetof(struct proc, p_md));
ASSYM(MD_LDT, offsetof(struct mdproc, md_ldt));

ASSYM(TDF_ASTPENDING, TDF_ASTPENDING);
ASSYM(TDF_NEEDRESCHED, TDF_NEEDRESCHED);

ASSYM(V_TRAP, offsetof(struct vmmeter, v_trap));
ASSYM(V_SYSCALL, offsetof(struct vmmeter, v_syscall));
ASSYM(V_INTR, offsetof(struct vmmeter, v_intr));
/* ASSYM(UPAGES, UPAGES);*/
ASSYM(KSTACK_PAGES, KSTACK_PAGES);
ASSYM(PAGE_SIZE, PAGE_SIZE);
ASSYM(NPTEPG, NPTEPG);
ASSYM(NPDEPG, NPDEPG);
ASSYM(NPDEPTD, NPDEPTD);
ASSYM(NPGPTD, NPGPTD);
ASSYM(PDESIZE, sizeof(pd_entry_t));
ASSYM(PTESIZE, sizeof(pt_entry_t));
ASSYM(PDESHIFT, PDESHIFT);
ASSYM(PTESHIFT, PTESHIFT);
ASSYM(PAGE_SHIFT, PAGE_SHIFT);
ASSYM(PAGE_MASK, PAGE_MASK);
ASSYM(PDRSHIFT, PDRSHIFT);
ASSYM(PDRMASK, PDRMASK);
ASSYM(USRSTACK, USRSTACK);
ASSYM(VM_MAXUSER_ADDRESS, VM_MAXUSER_ADDRESS);
ASSYM(KERNBASE, KERNBASE);
ASSYM(KERNLOAD, KERNLOAD);
ASSYM(MCLBYTES, MCLBYTES);
ASSYM(PCB_CR0, offsetof(struct pcb, pcb_cr0));
ASSYM(PCB_CR2, offsetof(struct pcb, pcb_cr2));
ASSYM(PCB_CR3, offsetof(struct pcb, pcb_cr3));
ASSYM(PCB_CR4, offsetof(struct pcb, pcb_cr4));
ASSYM(PCB_EDI, offsetof(struct pcb, pcb_edi));
ASSYM(PCB_ESI, offsetof(struct pcb, pcb_esi));
ASSYM(PCB_EBP, offsetof(struct pcb, pcb_ebp));
ASSYM(PCB_ESP, offsetof(struct pcb, pcb_esp));
ASSYM(PCB_EBX, offsetof(struct pcb, pcb_ebx));
ASSYM(PCB_EIP, offsetof(struct pcb, pcb_eip));
ASSYM(TSS_ESP0, offsetof(struct i386tss, tss_esp0));

ASSYM(PCB_DS, offsetof(struct pcb, pcb_ds));
ASSYM(PCB_ES, offsetof(struct pcb, pcb_es));
ASSYM(PCB_FS, offsetof(struct pcb, pcb_fs));
ASSYM(PCB_GS, offsetof(struct pcb, pcb_gs));
ASSYM(PCB_SS, offsetof(struct pcb, pcb_ss));
ASSYM(PCB_DR0, offsetof(struct pcb, pcb_dr0));
ASSYM(PCB_DR1, offsetof(struct pcb, pcb_dr1));
ASSYM(PCB_DR2, offsetof(struct pcb, pcb_dr2));
ASSYM(PCB_DR3, offsetof(struct pcb, pcb_dr3));
ASSYM(PCB_DR6, offsetof(struct pcb, pcb_dr6));
ASSYM(PCB_DR7, offsetof(struct pcb, pcb_dr7));
ASSYM(PCB_USERFPU, offsetof(struct pcb, pcb_user_save));
ASSYM(PCB_PSL, offsetof(struct pcb, pcb_psl));
ASSYM(PCB_DBREGS, PCB_DBREGS);
ASSYM(PCB_EXT, offsetof(struct pcb, pcb_ext));

ASSYM(PCB_FSD, offsetof(struct pcb, pcb_fsd));
ASSYM(PCB_GSD, offsetof(struct pcb, pcb_gsd));
ASSYM(PCB_VM86, offsetof(struct pcb, pcb_vm86));
ASSYM(PCB_FLAGS, offsetof(struct pcb, pcb_flags));
ASSYM(PCB_SAVEFPU, offsetof(struct pcb, pcb_save));
ASSYM(PCB_SAVEFPU_SIZE, sizeof(union savefpu));
ASSYM(PCB_ONFAULT, offsetof(struct pcb, pcb_onfault));

ASSYM(PCB_SIZE, sizeof(struct pcb));
ASSYM(PCB_VM86CALL, PCB_VM86CALL);

ASSYM(PCB_GDT, offsetof(struct pcb, pcb_gdt));
ASSYM(PCB_IDT, offsetof(struct pcb, pcb_idt));
ASSYM(PCB_LDT, offsetof(struct pcb, pcb_ldt));
ASSYM(PCB_TR, offsetof(struct pcb, pcb_tr));

ASSYM(TF_TRAPNO, offsetof(struct trapframe, tf_trapno));
ASSYM(TF_ERR, offsetof(struct trapframe, tf_err));
ASSYM(TF_EIP, offsetof(struct trapframe, tf_eip));
ASSYM(TF_CS, offsetof(struct trapframe, tf_cs));
ASSYM(TF_EFLAGS, offsetof(struct trapframe, tf_eflags));
ASSYM(SIGF_HANDLER, offsetof(struct sigframe, sf_ahu.sf_handler));
#ifdef COMPAT_43
ASSYM(SIGF_SC, offsetof(struct osigframe, sf_siginfo.si_sc));
#endif
ASSYM(SIGF_UC, offsetof(struct sigframe, sf_uc));
#ifdef COMPAT_FREEBSD4
ASSYM(SIGF_UC4, offsetof(struct sigframe4, sf_uc));
#endif
#ifdef COMPAT_43
ASSYM(SC_PS, offsetof(struct osigcontext, sc_ps));
ASSYM(SC_FS, offsetof(struct osigcontext, sc_fs));
ASSYM(SC_GS, offsetof(struct osigcontext, sc_gs));
ASSYM(SC_TRAPNO, offsetof(struct osigcontext, sc_trapno));
#endif
#ifdef COMPAT_FREEBSD4
ASSYM(UC4_EFLAGS, offsetof(struct ucontext4, uc_mcontext.mc_eflags));
ASSYM(UC4_GS, offsetof(struct ucontext4, uc_mcontext.mc_gs));
#endif
ASSYM(UC_EFLAGS, offsetof(ucontext_t, uc_mcontext.mc_eflags));
ASSYM(UC_GS, offsetof(ucontext_t, uc_mcontext.mc_gs));
ASSYM(ENOENT, ENOENT);
ASSYM(EFAULT, EFAULT);
ASSYM(ENAMETOOLONG, ENAMETOOLONG);
ASSYM(MAXCOMLEN, MAXCOMLEN);
ASSYM(MAXPATHLEN, MAXPATHLEN);
ASSYM(BOOTINFO_SIZE, sizeof(struct bootinfo));
ASSYM(BI_VERSION, offsetof(struct bootinfo, bi_version));
ASSYM(BI_KERNELNAME, offsetof(struct bootinfo, bi_kernelname));
ASSYM(BI_NFS_DISKLESS, offsetof(struct bootinfo, bi_nfs_diskless));
ASSYM(BI_ENDCOMMON, offsetof(struct bootinfo, bi_endcommon));
ASSYM(NFSDISKLESS_SIZE, sizeof(struct nfs_diskless));
ASSYM(BI_SIZE, offsetof(struct bootinfo, bi_size));
ASSYM(BI_SYMTAB, offsetof(struct bootinfo, bi_symtab));
ASSYM(BI_ESYMTAB, offsetof(struct bootinfo, bi_esymtab));
ASSYM(BI_KERNEND, offsetof(struct bootinfo, bi_kernend));
ASSYM(PC_SIZEOF, sizeof(struct pcpu));
ASSYM(PC_PRVSPACE, offsetof(struct pcpu, pc_prvspace));
ASSYM(PC_CURTHREAD, offsetof(struct pcpu, pc_curthread));
ASSYM(PC_FPCURTHREAD, offsetof(struct pcpu, pc_fpcurthread));
ASSYM(PC_IDLETHREAD, offsetof(struct pcpu, pc_idlethread));
ASSYM(PC_CURPCB, offsetof(struct pcpu, pc_curpcb));
ASSYM(PC_COMMON_TSS, offsetof(struct pcpu, pc_common_tss));
ASSYM(PC_COMMON_TSSD, offsetof(struct pcpu, pc_common_tssd));
ASSYM(PC_TSS_GDT, offsetof(struct pcpu, pc_tss_gdt));
ASSYM(PC_FSGS_GDT, offsetof(struct pcpu, pc_fsgs_gdt));
ASSYM(PC_CURRENTLDT, offsetof(struct pcpu, pc_currentldt));
ASSYM(PC_CPUID, offsetof(struct pcpu, pc_cpuid));
ASSYM(PC_CURPMAP, offsetof(struct pcpu, pc_curpmap));
ASSYM(PC_PRIVATE_TSS, offsetof(struct pcpu, pc_private_tss));

#ifdef DEV_APIC
ASSYM(LA_VER, offsetof(struct LAPIC, version));
ASSYM(LA_TPR, offsetof(struct LAPIC, tpr));
ASSYM(LA_EOI, offsetof(struct LAPIC, eoi));
ASSYM(LA_SVR, offsetof(struct LAPIC, svr));
ASSYM(LA_ICR_LO, offsetof(struct LAPIC, icr_lo));
ASSYM(LA_ICR_HI, offsetof(struct LAPIC, icr_hi));
ASSYM(LA_ISR, offsetof(struct LAPIC, isr0));
#endif

ASSYM(KCSEL, GSEL(GCODE_SEL, SEL_KPL));
ASSYM(KDSEL, GSEL(GDATA_SEL, SEL_KPL));
ASSYM(KPSEL, GSEL(GPRIV_SEL, SEL_KPL));

ASSYM(BC32SEL, GSEL(GBIOSCODE32_SEL, SEL_KPL));
ASSYM(GPROC0_SEL, GPROC0_SEL);
ASSYM(VM86_FRAMESIZE, sizeof(struct vm86frame));

#ifdef PC98
#include <machine/bus.h>

ASSYM(BUS_SPACE_HANDLE_BASE, offsetof(struct bus_space_handle, bsh_base));
ASSYM(BUS_SPACE_HANDLE_IAT, offsetof(struct bus_space_handle, bsh_iat));
#endif

#ifdef XEN
#include <xen/hypervisor.h>
ASSYM(PC_CR3, offsetof(struct pcpu, pc_cr3));
ASSYM(HYPERVISOR_VIRT_START, __HYPERVISOR_VIRT_START);
#endif

#ifdef	HWPMC_HOOKS
ASSYM(PMC_FN_USER_CALLCHAIN, PMC_FN_USER_CALLCHAIN);
#endif