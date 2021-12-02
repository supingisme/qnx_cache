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
