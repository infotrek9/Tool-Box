CFLAGS = -g -O2
#CFLAGS += -DHWY_STATIC_TARGET=HWY_AVX-512
CFLAGS += -mavx2
all:
	g++ $(CFLAGS) main.cc -o test -l:libhwy.a
