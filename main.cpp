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

#include "armpmu_lib.h"

int enable_access_qnx_register();

int start_pmu(){

    enable_access_qnx_register();
    enableUser();
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
		    evt_value[n] = getEvtCount(n);
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
}

int main()
{
	double seconds; 
	struct timeval start,end;
    while(1){
        start_pmu();
        gettimeofday(&start,NULL);
        sleep(1);
	    gettimeofday(&end,NULL);
        print_pmu();
        stop_pmu();
	    seconds = (end.tv_sec - start.tv_sec)+1.0e-6 * (end.tv_usec - start.tv_usec);
	    printf("cost:%.3f s\n", seconds);
    }
    return 0;
}

