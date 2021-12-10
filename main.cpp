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
        cpu_cycles_clock_rate = (double)evt_value[1]/(double)clocks ;
	    printf("\n=======\ncpu clocks:%lld  cpu_cycles_clock_rate:%.3f\n",  clocks, cpu_cycles_clock_rate);

		printf("inst_retired:       %lld\n", evt_value[0]);
		printf("cpu cycles:         %lld\n", evt_value[1]);
		printf("L1D cache:          %lld\n", evt_value[2]);
		printf("L1D cache miss :    %lld\n", evt_value[3]);
		printf("L2D cache:          %lld\n", evt_value[4]);
		printf("L2D cache miss :    %lld\n", evt_value[5]);

        /* Speculative  accuracy =  INST_RETIRED / INST_SPEC */
	    printf("L1 Miss rate:           %.3f \n", (double)evt_value[3]/(double)(evt_value[2]));
	    printf("L2 Miss rate:           %.3f \n", (double)evt_value[5]/(double)(evt_value[4]));
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
extern void multMat1(int n, float *A,float *B,float *C);
extern void multMat2(int n, float *A,float *B,float *C);
extern void multMat3(int n, float *A,float *B,float *C);
extern void multMat4(int n, float *A,float *B,float *C);
extern void multMat5(int n, float *A,float *B,float *C);
extern void multMat6(int n, float *A,float *B,float *C);

void roworder( int * A, int x, int y) {
    int row, col;
    for (row=0; row<x; row++) {
        for (col=0; col< y; col++) {
	    A[row*y + col] = 0;
        }
    }
}


void colorder( int * A, int x, int y) {
    int row, col;
    for (col=0; col< y; col++) {
        for (row=0; row<x; row++) {
	    A[row*y + col] = 0;
        }
    }
}

int main(int argc, char **argv) {

	double seconds; 
	struct timeval start,end;

    /* int i, x=1024, y=1024; */
    /* int length = 64 * 1024 * 1024; */ 
    /* int * arr = (int *)malloc(length*sizeof(int)); */  
    /* for(i = 0; i< length; i++) */
    /*     arr[i] = rand(); */
     
    /* if (argc==3) { */
	/* x=atoi(argv[1]); */
	/* y=atoi(argv[2]); */
    /* } */
    int i, nmax = 1024;
    if (argc==2) {
	nmax=atoi(argv[1]);
    }

	//函数指针数组，存放6个函数指针，分别对应着按照6种不同的顺序执行矩阵相乘的函数
	void (*orderings[])(int,float *,float *,float *)
	= {&multMat1,&multMat2,&multMat3,&multMat4,&multMat5,&multMat6};
	
	char *names[] = {"ijk","ikj","jik","jki","kij","kji"};
	
	//声明了三个浮点类型指针变量A,B,C
	float *A = (float *)malloc(nmax*nmax * sizeof(float));
	float *B = (float *)malloc(nmax*nmax * sizeof(float));
	float *C = (float *)malloc(nmax*nmax * sizeof(float));

    void (*test[])(void) = {test1, test2, test3, test4, test5} ;
    init_pmu();
        for(i=0; i< 6; i++){
        gettimeofday(&start,NULL);
        start_pmu();
        /* sleep(1); */
        /* test[i](); */
            /* if(i == 0) colorder(arr, x, y); */
            /* if(i == 1) roworder(arr, x, y); */
		(*orderings[i])(nmax,A,B,C);
        print_pmu();
	    gettimeofday(&end,NULL);
        stop_pmu();
	    seconds = (end.tv_sec - start.tv_sec)+1.0e-6 * (end.tv_usec - start.tv_usec);
	    /* printf(" test case%d cost:%.3f s\n", i, seconds); */
	    printf("%s\t row or col = %d bytes cost:%.3f s\n",names[i], nmax*sizeof(float),  seconds);
        }
    return 0;
}

