#include <stdio.h>
#include "armpmu_lib.h"

void dump_pmu_reg()
{
	printf(" Register pmuserenr_el0:0x%lX \n", read_sysreg(pmuserenr_el0));
	printf(" Register PMCR_EL0:0x%lX \n", read_sysreg(PMCR_EL0));
	printf(" Register PMCNTENSET_EL0:0x%lX \n", read_sysreg(PMCNTENSET_EL0));
	printf(" Register PMCNTENCLR_EL0:0x%lX \n", read_sysreg(PMCNTENCLR_EL0));
	printf(" Register PMCCNTR_EL0:0x%lX \n", read_sysreg(PMCCNTR_EL0));
	printf(" Register pmevcntr0_el0:0x%lX \n", read_sysreg(pmevcntr0_el0));
	printf(" Register MIDR_EL1:0x%lX \n", read_sysreg(MIDR_EL1));
	printf(" Register PMSELR_EL0:0x%lX \n", read_sysreg(PMSELR_EL0));
}

/*Enable user-mode access to counters. */
void enableUser()
{
	sysreg_clear_set(pmuserenr_el0, 0, ARMV8_PMU_USERENR_EN|ARMV8_PMU_USERENR_ER|ARMV8_PMU_USERENR_CR);
}

/* PMCR_EL0, Performance Monitors Control Register */
/* E, bit [0] */
/* Enable. */
/* 0b0 All event counters in the range [0..(PMN-1)] and PMCCNTR_EL0, are disabled. */
/* 0b1 All event counters in the range [0..(PMN-1)] and PMCCNTR_EL0, are enabled by */
void enablePMU()
{
	sysreg_clear_set(PMCR_EL0, 0, ARMV8_PMU_PMCR_E|ARMV8_PMU_PMCR_X|ARMV8_PMU_PMCR_C);
}

void disablePMU()
{
	sysreg_clear_set(PMCR_EL0, 0<<1, 0);
}

/* PMCNTENSET_EL0, Performance Monitors Count Enable Set register */
/* C, bit [31] */
/* PMCCNTR_EL0 enable bit. Enables the cycle counter register */
void enableCounter()
{
	sysreg_clear_set(PMCNTENSET_EL0, 0, ARMV8_PMCNTENSET_EL0_ENABLE);
}

/* PMCCNTR_EL0, Performance Monitors Cycle Counter */
uint64_t getPMUCount()
{
	return read_sysreg(PMCCNTR_EL0);
}

void stopCounter()
{
	sysreg_clear_set(PMCNTENCLR_EL0, 0, ARMV8_PMCNTENSET_EL0_ENABLE);
}

void enableEvtCounter()
{
	sysreg_clear_set(PMCNTENSET_EL0, 0, 0x3f);
}

#define WRITE_PMEVTYPERN(n) \
	write_sysreg(val, pmevtyper##n##_el0)
void write_pmevtypern(int n, uint32_t val)
{
	PMEVN_SWITCH(n, WRITE_PMEVTYPERN);
}

#define RETURN_READ_PMEVCNTRN(n) \
	return read_sysreg(pmevcntr##n##_el0)
static uint64_t read_pmevcntrn(int n)
{
	PMEVN_SWITCH(n, RETURN_READ_PMEVCNTRN);
	return 0;
}

#define WRITE_PMEVCNTRN(n) 	\
	write_sysreg( val,  pmevcntr##n##_el0)		
void write_pmevcntrn(int n, uint32_t val)
{
	PMEVN_SWITCH(n, WRITE_PMEVCNTRN);
}

void setEvtCount()
{
	int i;

    	write_pmevtypern(0, ARMV8_PMUV3_PERFCTR_INST_RETIRED);
    	write_pmevtypern(1, ARMV8_PMUV3_PERFCTR_CPU_CYCLES);
    	write_pmevtypern(2, ARMV8_PMUV3_PERFCTR_L1D_CACHE);
		write_pmevtypern(3, ARMV8_PMUV3_PERFCTR_L1D_CACHE_REFILL);
    	write_pmevtypern(4, ARMV8_PMUV3_PERFCTR_L2D_CACHE);
    	write_pmevtypern(5, ARMV8_PMUV3_PERFCTR_L2D_CACHE_REFILL);

	for(i=0; i<6; i++){
		write_pmevcntrn(i, 0);
	}
}

uint64_t getEvtCount(uint64_t index)
{

	return read_pmevcntrn(index);
}

uint32_t getEvtOverflow(uint64_t index)
{

    int a = read_sysreg(PMOVSCLR_EL0);
    if(a &(1<<index))
    {
        /* printf("------------------------%llx %llx overflow\n", a, read_sysreg(PMOVSCLR_EL0)); */
        write_sysreg((1<<index), PMOVSCLR_EL0);
        return 1;
    }
        /* printf("------------------------ %llx not overflow\n", a); */
    return 0;
}

void disableEvtCounter()
{
	sysreg_clear_set(PMCNTENSET_EL0, 0x3f, 0);
}
