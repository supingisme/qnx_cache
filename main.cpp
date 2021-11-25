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
        usleep(200 * 1000);
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
        double ipc_value;
        uint64_t cpu_cycles, evt_value[6];
        int n;

        cpu_cycles = getPMUCount();
	    for(n = 0; n<6; n++){
		    evt_value[n] = getEvtCount(n) + (g_evt_over_flow[n] << 31);
	    }
	    ipc_value = (double)evt_value[0]/(double)cpu_cycles ;
	    printf("\n=======\ncpu cycles: %ld\n",  cpu_cycles);

		printf("inst_retired:      %lld\n", evt_value[0]);
		printf("l1d cache:         %lld\n",  evt_value[1]);
		printf("l1d cache refill:  %lld\n",  evt_value[2]);
		printf("l2d cache:         %lld\n",  evt_value[3]);
		printf("l2d cache refill:  %lld\n", evt_value[4]);
		printf("BR miss:           %lld\n", evt_value[5]);

	    printf("L1_MISS rate:%.3f \n", (double)evt_value[2]/(double)(evt_value[1]));
	    printf("L2_MISS rate:%.3f \n", (double)evt_value[4]/(double)(evt_value[3]));
	    printf("Mispredicted branch:%ld \n", evt_value[5]);
	    printf("ipc = %.3f\n", ipc_value);
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

void test1(){
    uint64_t sum = 0, a = 0, b = 0, c = 0, d = 0, i = 0;
    sum = 0;a = 0; b = 0; c = 0; d = 0;
    for (i = 0; i < 0x300000000; i += 4) {
        /* sum += i; */
        a += i; b += i; c += i; d += i;
    }
    sum = a + b + c +d ;
}


int main()
{
	double seconds; 
	struct timeval start,end;
    init_pmu();
        while(1){
        gettimeofday(&start,NULL);
        start_pmu();
        sleep(1);
        print_pmu();
	    gettimeofday(&end,NULL);
        stop_pmu();
	    seconds = (end.tv_sec - start.tv_sec)+1.0e-6 * (end.tv_usec - start.tv_usec);
	    printf("cost:%.3f s\n", seconds);
    }
    return 0;
}

