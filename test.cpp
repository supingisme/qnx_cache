#include <stdio.h>
void test1(){
    unsigned long sum = 0, i = 0;
    for (i = 0; i < 0x10000000; i += 1) {
        sum += i;
    }
    printf("sum = %ld\n", sum);
}

void test2(){
    unsigned long sum = 0, a = 0, b = 0, c = 0, d = 0, i = 0;
    for (i = 0; i < 0x10000000; i += 4) {
        a += i; b += i + 1; c += i + 2; d += i + 3;
    }
    sum = a + b + c + d;
    printf("sum = %ld\n", sum);
}

void test3(){
    unsigned long sum = 0, a = 0, b = 0, c = 0, d = 0;
    register unsigned long i = 0;
    for (i = 0; i < 0x10000000; i += 4) {
        a += i; b += i + 1; c += i + 2; d += i + 3;
    }
    sum = a + b + c + d;
    printf("sum = %ld\n", sum);
}

void test4(){
    register unsigned long sum = 0, a = 0, b = 0, c = 0, d = 0;
    register unsigned long i = 0;
    for (i = 0; i < 0x10000000; i += 4) {
        a += i; b += i + 1; c += i + 2; d += i + 3;
    }
    sum = a + b + c + d;
    printf("sum = %ld\n", sum);
}

void test5(){
    register unsigned long int i = 0;
    while(i++ < 0x100000){
        __asm__ ("nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
              	"nop\n\t"
                "nop");
    }
}
//ijk
void multMat1(int n, float *A,float *B,float *C)
{
	int i,j,k;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				C[i+j*n] += A[i+k*n]*B[k+j*n];
			}
		}
	}
}
//ikj
void multMat2(int n, float *A,float *B,float *C)
{
	int i,j,k;
	for(i=0;i<n;i++){
		for(k=0;k<n;k++)
		{
			for(j=0;j<n;j++)
			{
				C[i+j*n] += A[i+k*n]*B[k+j*n];
			}
		}
	}
}
//jik
void multMat3(int n, float *A,float *B,float *C)
{
	int i,j,k;
	for(j=0;j<n;j++){
		for(i=0;i<n;i++)
		{
			for(k=0;k<n;k++)
			{
				C[i+j*n] += A[i+k*n]*B[k+j*n];
			}
		}
	}
}
//jki
void multMat4(int n, float *A,float *B,float *C)
{
	int i,j,k;
	for(j=0;j<n;j++){
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				C[i+j*n] += A[i+k*n]*B[k+j*n];
			}
		}
	}
}
//kij
void multMat5(int n, float *A,float *B,float *C)
{
	int i,j,k;
	for(k=0;k<n;k++){
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				C[i+j*n] += A[i+k*n]*B[k+j*n];
			}
		}
	}
}
//kji
void multMat6(int n, float *A,float *B,float *C)
{
	int i,j,k;
	for(k=0;k<n;k++){
		for(j=0;j<n;j++)
		{
			for(i=0;i<n;i++)
			{
				C[i+j*n] += A[i+k*n]*B[k+j*n];
			}
		}
	}
}

