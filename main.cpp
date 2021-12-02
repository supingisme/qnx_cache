#include <stdio.h>
#include <sys/procmgr.h>
#include <sys/neutrino.h>
#include <stdint.h>
#include <stdlib.h>
#include <forksafe_mutex.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/times.h>
#include <time.h>
#include <pthread.h>

#include "armpmu_lib.h"


int enable_access_qnx_register();
uint64_t g_evt_over_flow[6] = {0};

static void * get_over_flow_thread(void* arg)
{
    uint i;
    while(1){
        for(i = 0; i < 6; i++){
            g_evt_over_flow[i] += getEvtOverflow(i);
        }
        usleep(20 * 1000);
    }
    pthread_exit(NULL);
    return NULL;
}

int init_pmu(){
        enable_access_qnx_register();
        enableUser();
        pthread_create(NULL, NULL, &get_over_flow_thread, NULL);
}

int start_pmu(){
	enableCounter();
	enablePMU();
	enableEvtCounter();
	setEvtCount();	
	isb();
}

void print_pmu()
{
        double ipc_value, cpu_cycles_clock_rate;
        uint64_t clocks, evt_value[6];
        int n;

        clocks = getPMUCount();
	    for(n = 0; n<6; n++){
		    evt_value[n] = getEvtCount(n) + (g_evt_over_flow[n] << 31);
	    }

        /* IPC = INST_RETIRED / CPU_CYCLES */
	    ipc_value = (double)evt_value[0]/(double)evt_value[1] ;
	    cpu_cycles_clock_rate = (double)evt_value[1]/(double)clocks;
	    printf("\n=======\ncpu clocks:%lld  cpu_cycles_clock_rate:%.3f\n",  clocks, cpu_cycles_clock_rate);

		printf("inst_retired:       %lld\n", evt_value[0]);
		printf("cpu cycles:         %lld\n", evt_value[1]);
		printf("INST_SPEC:          %lld\n", evt_value[2]);
		printf("BR RETIRED :        %lld\n", evt_value[3]);
		printf("stall backend:      %lld\n", evt_value[4]);
		printf("stall frontend:     %lld\n", evt_value[5]);

        /* Speculative  accuracy =  INST_RETIRED / INST_SPEC */
	    printf("Speculative execution:  %.3f \n", (double)evt_value[2]/(double)(evt_value[0]));
	    printf("branch inst:            %.3f \n", (double)evt_value[3]/(double)(evt_value[0]));
	    printf("stall backend:          %.3f \n", (double)evt_value[4]/(double)(evt_value[0]));
	    printf("stall frontend:         %.3f \n", (double)evt_value[5]/(double)(evt_value[0]));
	    printf("ipc=                    %.3f\n", ipc_value);
}

int stop_pmu(){
	stopCounter();
	disableEvtCounter();
	disablePMU();
	isb();
    usleep(220*1000);
    for(int i = 0; i < 6; i++){
        g_evt_over_flow[i] = 0;
    }
}

extern void test1();
extern void test2();
extern void test3();
extern void test4();
extern void test5();
int main()
{
	double seconds; 
	struct timeval start,end;

    void (*test[])(void) = {test1, test2, test3, test4, test5} ;
    init_pmu();
        for(int i=0; i< 5; i++){
        gettimeofday(&start,NULL);
        start_pmu();
        /* sleep(1); */
        test[i]();
        print_pmu();
	    gettimeofday(&end,NULL);
        stop_pmu();
	    seconds = (end.tv_sec - start.tv_sec)+1.0e-6 * (end.tv_usec - start.tv_usec);
	    printf(" test case%d cost:%.3f s\n", i, seconds);
    }
    return 0;
}

