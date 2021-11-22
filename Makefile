CC=aarch64-unknown-nto-qnx7.0.0-gcc
CFLAGS += -O2 -fomit-frame-pointer -fno-strength-reduce 

qnx_pmu:
	$(CC) $(CFLAGS)  armpmu_lib.cpp  main.cpp qnx_lib.cpp  -o qnx_pmu 


clean:
	-rm -f *.o
	-rm -f qnx_pmu 
