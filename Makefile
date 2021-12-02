CC=aarch64-unknown-nto-qnx7.0.0-gcc
# CFLAGS += -fomit-frame-pointer -fno-strength-reduce 
CFLAGS += -O0

qnx_pmu:
	$(CC) $(CFLAGS)  armpmu_lib.cpp   test.cpp main.cpp qnx_lib.cpp  -o qnx_pmu 


clean:
	-rm -f *.o
	-rm -f qnx_pmu 
