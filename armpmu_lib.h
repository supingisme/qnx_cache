#ifndef ARMV8_PMU_EVENT_H
#define ARMV8_PMU_EVENT_H


#include <stdint.h>
/* At least one of the following is required. */

#define ARMV8_PMUV3_PERFCTR_INST_RETIRED			0x08
#define ARMV8_PMUV3_PERFCTR_INST_SPEC				0x1B

/* Common architectural events. */
#define ARMV8_PMUV3_PERFCTR_LD_RETIRED				0x06
#define ARMV8_PMUV3_PERFCTR_ST_RETIRED				0x07
#define ARMV8_PMUV3_PERFCTR_EXC_TAKEN				0x09
#define ARMV8_PMUV3_PERFCTR_EXC_RETURN				0x0A
#define ARMV8_PMUV3_PERFCTR_CID_WRITE_RETIRED			0x0B
#define ARMV8_PMUV3_PERFCTR_PC_WRITE_RETIRED			0x0C
#define ARMV8_PMUV3_PERFCTR_BR_IMMED_RETIRED			0x0D
#define ARMV8_PMUV3_PERFCTR_BR_RETURN_RETIRED			0x0E
#define ARMV8_PMUV3_PERFCTR_UNALIGNED_LDST_RETIRED		0x0F
#define ARMV8_PMUV3_PERFCTR_UNALIGNED_BR_MIS_PRED		0x10
#define ARMV8_PMUV3_PERFCTR_TTBR_WRITE_RETIRED			0x1C
#define ARMV8_PMUV3_PERFCTR_CHAIN				0x1E
#define ARMV8_PMUV3_PERFCTR_BR_RETIRED				0x21

/* Common microarchitectural events. */
#define ARMV8_PMUV3_PERFCTR_L1I_CACHE_REFILL			0x01
#define ARMV8_PMUV3_PERFCTR_L1I_TLB_REFILL			0x02
#define ARMV8_PMUV3_PERFCTR_L1D_TLB_REFILL			0x05
#define ARMV8_PMUV3_PERFCTR_MEM_ACCESS				0x13
#define ARMV8_PMUV3_PERFCTR_L1I_CACHE				0x14
#define ARMV8_PMUV3_PERFCTR_L1D_CACHE_WB			0x15
#define ARMV8_PMUV3_PERFCTR_L2D_CACHE				0x16
#define ARMV8_PMUV3_PERFCTR_L2D_CACHE_REFILL			0x17
#define ARMV8_PMUV3_PERFCTR_L2D_CACHE_WB			0x18
#define ARMV8_PMUV3_PERFCTR_BUS_ACCESS				0x19
#define ARMV8_PMUV3_PERFCTR_MEMORY_ERROR			0x1A
#define ARMV8_PMUV3_PERFCTR_BUS_CYCLES				0x1D
#define ARMV8_PMUV3_PERFCTR_L1D_CACHE_ALLOCATE			0x1F
#define ARMV8_PMUV3_PERFCTR_L2D_CACHE_ALLOCATE			0x20
#define ARMV8_PMUV3_PERFCTR_BR_MIS_PRED_RETIRED			0x22
#define ARMV8_PMUV3_PERFCTR_STALL_FRONTEND			0x23
#define ARMV8_PMUV3_PERFCTR_STALL_BACKEND			0x24
#define ARMV8_PMUV3_PERFCTR_L1D_TLB				0x25
#define ARMV8_PMUV3_PERFCTR_L1I_TLB				0x26
#define ARMV8_PMUV3_PERFCTR_L2I_CACHE				0x27
#define ARMV8_PMUV3_PERFCTR_L2I_CACHE_REFILL			0x28
#define ARMV8_PMUV3_PERFCTR_L3D_CACHE_ALLOCATE			0x29
#define ARMV8_PMUV3_PERFCTR_L3D_CACHE_REFILL			0x2A
#define ARMV8_PMUV3_PERFCTR_L3D_CACHE				0x2B
#define ARMV8_PMUV3_PERFCTR_L3D_CACHE_WB			0x2C
#define ARMV8_PMUV3_PERFCTR_L2D_TLB_REFILL			0x2D
#define ARMV8_PMUV3_PERFCTR_L2I_TLB_REFILL			0x2E
#define ARMV8_PMUV3_PERFCTR_L2D_TLB				0x2F
#define ARMV8_PMUV3_PERFCTR_L2I_TLB				0x30
#define ARMV8_PMUV3_PERFCTR_LL_CACHE_MISS_RD    0x37


/* ARMv8 recommended implementation defined event types */
#define ARMV8_IMPDEF_PERFCTR_L1D_CACHE_RD			0x40
#define ARMV8_IMPDEF_PERFCTR_L1D_CACHE_WR			0x41
#define ARMV8_IMPDEF_PERFCTR_L1D_CACHE_REFILL_RD		0x42
#define ARMV8_IMPDEF_PERFCTR_L1D_CACHE_REFILL_WR		0x43
#define ARMV8_IMPDEF_PERFCTR_L1D_CACHE_REFILL_INNER		0x44
#define ARMV8_IMPDEF_PERFCTR_L1D_CACHE_REFILL_OUTER		0x45
#define ARMV8_IMPDEF_PERFCTR_L1D_CACHE_WB_VICTIM		0x46
#define ARMV8_IMPDEF_PERFCTR_L1D_CACHE_WB_CLEAN			0x47
#define ARMV8_IMPDEF_PERFCTR_L1D_CACHE_INVAL			0x48

#define ARMV8_IMPDEF_PERFCTR_L1D_TLB_REFILL_RD			0x4C
#define ARMV8_IMPDEF_PERFCTR_L1D_TLB_REFILL_WR			0x4D
#define ARMV8_IMPDEF_PERFCTR_L1D_TLB_RD				0x4E
#define ARMV8_IMPDEF_PERFCTR_L1D_TLB_WR				0x4F
#define ARMV8_IMPDEF_PERFCTR_L2D_CACHE_RD			0x50
#define ARMV8_IMPDEF_PERFCTR_L2D_CACHE_WR			0x51
#define ARMV8_IMPDEF_PERFCTR_L2D_CACHE_REFILL_RD		0x52
#define ARMV8_IMPDEF_PERFCTR_L2D_CACHE_REFILL_WR		0x53

#define ARMV8_IMPDEF_PERFCTR_L2D_CACHE_WB_VICTIM		0x56
#define ARMV8_IMPDEF_PERFCTR_L2D_CACHE_WB_CLEAN			0x57
#define ARMV8_IMPDEF_PERFCTR_L2D_CACHE_INVAL			0x58

#define ARMV8_IMPDEF_PERFCTR_L2D_TLB_REFILL_RD			0x5C
#define ARMV8_IMPDEF_PERFCTR_L2D_TLB_REFILL_WR			0x5D
#define ARMV8_IMPDEF_PERFCTR_L2D_TLB_RD				0x5E
#define ARMV8_IMPDEF_PERFCTR_L2D_TLB_WR				0x5F

#define ARMV8_IMPDEF_PERFCTR_BUS_ACCESS_RD			0x60
#define ARMV8_IMPDEF_PERFCTR_BUS_ACCESS_WR			0x61
#define ARMV8_IMPDEF_PERFCTR_BUS_ACCESS_SHARED			0x62
#define ARMV8_IMPDEF_PERFCTR_BUS_ACCESS_NOT_SHARED		0x63
#define ARMV8_IMPDEF_PERFCTR_BUS_ACCESS_NORMAL			0x64
#define ARMV8_IMPDEF_PERFCTR_BUS_ACCESS_PERIPH			0x65

#define ARMV8_IMPDEF_PERFCTR_MEM_ACCESS_RD			0x66
#define ARMV8_IMPDEF_PERFCTR_MEM_ACCESS_WR			0x67
#define ARMV8_IMPDEF_PERFCTR_UNALIGNED_LD_SPEC			0x68
#define ARMV8_IMPDEF_PERFCTR_UNALIGNED_ST_SPEC			0x69
#define ARMV8_IMPDEF_PERFCTR_UNALIGNED_LDST_SPEC		0x6A

#define ARMV8_IMPDEF_PERFCTR_LDREX_SPEC				0x6C
#define ARMV8_IMPDEF_PERFCTR_STREX_PASS_SPEC			0x6D
#define ARMV8_IMPDEF_PERFCTR_STREX_FAIL_SPEC			0x6E
#define ARMV8_IMPDEF_PERFCTR_STREX_SPEC				0x6F
#define ARMV8_IMPDEF_PERFCTR_LD_SPEC				0x70
#define ARMV8_IMPDEF_PERFCTR_ST_SPEC				0x71
#define ARMV8_IMPDEF_PERFCTR_LDST_SPEC				0x72
#define ARMV8_IMPDEF_PERFCTR_DP_SPEC				0x73
#define ARMV8_IMPDEF_PERFCTR_ASE_SPEC				0x74
#define ARMV8_IMPDEF_PERFCTR_VFP_SPEC				0x75
#define ARMV8_IMPDEF_PERFCTR_PC_WRITE_SPEC			0x76
#define ARMV8_IMPDEF_PERFCTR_CRYPTO_SPEC			0x77
#define ARMV8_IMPDEF_PERFCTR_BR_IMMED_SPEC			0x78
#define ARMV8_IMPDEF_PERFCTR_BR_RETURN_SPEC			0x79
#define ARMV8_IMPDEF_PERFCTR_BR_INDIRECT_SPEC			0x7A

#define ARMV8_IMPDEF_PERFCTR_ISB_SPEC				0x7C
#define ARMV8_IMPDEF_PERFCTR_DSB_SPEC				0x7D
#define ARMV8_IMPDEF_PERFCTR_DMB_SPEC				0x7E

#define ARMV8_IMPDEF_PERFCTR_EXC_UNDEF				0x81
#define ARMV8_IMPDEF_PERFCTR_EXC_SVC				0x82
#define ARMV8_IMPDEF_PERFCTR_EXC_PABORT				0x83
#define ARMV8_IMPDEF_PERFCTR_EXC_DABORT				0x84

#define ARMV8_IMPDEF_PERFCTR_EXC_IRQ				0x86
#define ARMV8_IMPDEF_PERFCTR_EXC_FIQ				0x87
#define ARMV8_IMPDEF_PERFCTR_EXC_SMC				0x88

#define ARMV8_IMPDEF_PERFCTR_EXC_HVC				0x8A
#define ARMV8_IMPDEF_PERFCTR_EXC_TRAP_PABORT			0x8B
#define ARMV8_IMPDEF_PERFCTR_EXC_TRAP_DABORT			0x8C
#define ARMV8_IMPDEF_PERFCTR_EXC_TRAP_OTHER			0x8D
#define ARMV8_IMPDEF_PERFCTR_EXC_TRAP_IRQ			0x8E
#define ARMV8_IMPDEF_PERFCTR_EXC_TRAP_FIQ			0x8F
#define ARMV8_IMPDEF_PERFCTR_RC_LD_SPEC				0x90
#define ARMV8_IMPDEF_PERFCTR_RC_ST_SPEC				0x91

#define ARMV8_PMUV3_PERFCTR_SW_INCR				0x00
#define ARMV8_PMUV3_PERFCTR_L1D_CACHE_REFILL			0x03
#define ARMV8_PMUV3_PERFCTR_L1D_CACHE				0x04
#define ARMV8_PMUV3_PERFCTR_BR_MIS_PRED				0x10
#define ARMV8_PMUV3_PERFCTR_CPU_CYCLES				0x11
#define ARMV8_PMUV3_PERFCTR_BR_PRED				0x12

/* long-latency read miss events */
#define	ARMV8_PMUV3_PERFCTR_L1I_CACHE_LMISS			0x4006
#define	ARMV8_PMUV3_PERFCTR_L2D_CACHE_LMISS_RD			0x4009
#define	ARMV8_PMUV3_PERFCTR_L2I_CACHE_LMISS			0x400A
#define	ARMV8_PMUV3_PERFCTR_L3D_CACHE_LMISS_RD			0x400B



/*
 * Per-CPU PMCR: config reg
 */
#define ARMV8_PMU_PMCR_E	(1 << 0) /* Enable all counters */
#define ARMV8_PMU_PMCR_P	(1 << 1) /* Reset all counters */
#define ARMV8_PMU_PMCR_C	(1 << 2) /* Cycle counter reset */
#define ARMV8_PMU_PMCR_D	(1 << 3) /* CCNT counts every 64th cpu cycle */
#define ARMV8_PMU_PMCR_X	(1 << 4) /* Export to ETM */
#define ARMV8_PMU_PMCR_DP	(1 << 5) /* Disable CCNT if non-invasive debug*/
#define ARMV8_PMU_PMCR_LC	(1 << 6) /* Overflow on 64 bit cycle counter */

/*
 * PMUSERENR: user enable reg
 */
#define ARMV8_PMU_USERENR_MASK	0xf		/* Mask for writable bits */
#define ARMV8_PMU_USERENR_EN	(1 << 0) /* PMU regs can be accessed at EL0 */
#define ARMV8_PMU_USERENR_SW	(1 << 1) /* PMSWINC can be written at EL0 */
#define ARMV8_PMU_USERENR_CR	(1 << 2) /* Cycle counter can be read at EL0 */
#define ARMV8_PMU_USERENR_ER	(1 << 3) /* Event counter can be read at EL0 */

#define ARMV8_PMCNTENSET_EL0_ENABLE 1<<31
#define ARMV8_PMEVTYPER_EVTCOUNT_MASK 0x7f

#define __stringify_1(x) #x
#define __stringify(x)  __stringify_1(x)
/*
 * Unlike read_cpuid, calls to read_sysreg are never expected to be
 * optimized away or replaced with synthetic values.
 */
#define read_sysreg(r) ({					\
	uint64_t __val;						\
	asm volatile("mrs %0, " __stringify(r) : "=r" (__val));	\
	__val;							\
})

/*
 * The "Z" constraint normally means a zero immediate, but when combined with
 * the "%x0" template means XZR.
 */
#define write_sysreg(v, r) do {					\
	uint64_t __val = (uint64_t)(v);					\
	asm volatile("msr " __stringify(r) ", %x0"		\
		     : : "rZ" (__val));				\
} while (0)
/*
 * Modify bits in a sysreg. Bits in the clear mask are zeroed, then bits in the
 * set mask are set. Other bits are left as-is.
 */
#define sysreg_clear_set(sysreg, clear, set) do {			\
	uint64_t __scs_val = read_sysreg(sysreg);				\
	uint64_t __scs_new = (__scs_val & ~(uint64_t)(clear)) | (set);		\
	if (__scs_new != __scs_val)					\
		write_sysreg(__scs_new, sysreg);			\
} while (0)

/*
 * This code is really good
 */

#define PMEVN_CASE(n, case_macro) \
	case n: case_macro(n); break

#define PMEVN_SWITCH(x, case_macro)				\
	do {							\
		switch (x) {					\
		PMEVN_CASE(0,  case_macro);			\
		PMEVN_CASE(1,  case_macro);			\
		PMEVN_CASE(2,  case_macro);			\
		PMEVN_CASE(3,  case_macro);			\
		PMEVN_CASE(4,  case_macro);			\
		PMEVN_CASE(5,  case_macro);			\
		PMEVN_CASE(6,  case_macro);			\
		PMEVN_CASE(7,  case_macro);			\
		PMEVN_CASE(8,  case_macro);			\
		PMEVN_CASE(9,  case_macro);			\
		PMEVN_CASE(10, case_macro);			\
		PMEVN_CASE(11, case_macro);			\
		PMEVN_CASE(12, case_macro);			\
		PMEVN_CASE(13, case_macro);			\
		PMEVN_CASE(14, case_macro);			\
		PMEVN_CASE(15, case_macro);			\
		PMEVN_CASE(16, case_macro);			\
		PMEVN_CASE(17, case_macro);			\
		PMEVN_CASE(18, case_macro);			\
		PMEVN_CASE(19, case_macro);			\
		PMEVN_CASE(20, case_macro);			\
		PMEVN_CASE(21, case_macro);			\
		PMEVN_CASE(22, case_macro);			\
		PMEVN_CASE(23, case_macro);			\
		PMEVN_CASE(24, case_macro);			\
		PMEVN_CASE(25, case_macro);			\
		PMEVN_CASE(26, case_macro);			\
		PMEVN_CASE(27, case_macro);			\
		PMEVN_CASE(28, case_macro);			\
		PMEVN_CASE(29, case_macro);			\
		PMEVN_CASE(30, case_macro);			\
		default: printf("Invalid PMEV* index\n");	\
		}						\
	} while (0)

#define isb() \
   asm volatile("isb");

void dump_pmu_reg();
void enableUser();
void enablePMU();
void disablePMU(); 
void enableCounter();
uint64_t getPMUCount();
void stopCounter();
void enableEvtCounter();
void setEvtCount();
uint64_t getEvtCount(uint64_t index);
void disableEvtCounter();
uint32_t getEvtOverflow(uint64_t index);

#endif
