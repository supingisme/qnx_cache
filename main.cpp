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
int main()
{
	double seconds , ipc_value, cycle2clock;
    uint64_t cpu_cycles, inst_retired, evt_value[6];
	int 	nmax = 1024,i,n; 

	struct timeval start,end;

    enable_access_qnx_register();
    //dump_pmu_reg();
    enableUser();

    while(1){
	    enableCounter();
	    enablePMU();
	    enableEvtCounter();
	    setEvtCount();	
	    isb();

        gettimeofday(&start,NULL);
        sleep(1);
	    gettimeofday(&end,NULL);
	
        cpu_cycles = getPMUCount();
	    for(n = 0; n<6; n++){
		    evt_value[n] = getEvtCount(n);
	    }
	    seconds = (end.tv_sec - start.tv_sec)+1.0e-6 * (end.tv_usec - start.tv_usec);
	    cycle2clock = (double)cpu_cycles/1000000000/seconds ;
	    ipc_value = (double)evt_value[0]/(double)cpu_cycles ;
	    printf("\n=======\ncpu cycles: %ld\n",  cpu_cycles);
        /* for(n = 0; n<6; n++){ */
		    /* printf("evt%d:%lld\n", n, evt_value[n]); */
        /* } */
	    printf("L1_MISS rate:%.3f \n", (double)evt_value[2]/(double)(evt_value[1]));
	    printf("L2_MISS rate:%.3f \n", (double)evt_value[4]/(double)(evt_value[3]));
	    printf("Mispredicted branch:%ld \n", evt_value[5]);
	    printf("%.3f s %.3f Ghz ipc = %.3f\n", seconds, cycle2clock, ipc_value);
    
	    stopCounter();
	    disableEvtCounter();
	    disablePMU();
	    isb();
	    //dump_pmu_reg();
    }

    return 0;
}

