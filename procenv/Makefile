
SYS	= $(shell uname -s)
CC	= gcc
CXX	= g++
CFLAGS	= -Wall -g
LDFLAGS	=
LDL	= -ldl

ifeq ($(SYS),FreeBSD)
LDL	=
endif

PROGS	= guess h1 getuid got got2 inject1.so inject2.so inject3.so randomso.so segment setjmp libc_dlopen find_dlopen doublefree1 doublefree2 \
	  freehook

ifneq ($(SYS),Darwin)	# apple does not support static linkage ...
PROGS	+= h2 getuid_s
endif

all: $(PROGS)

got: got.c
	$(CC) -o $@ $(CFLAGS) $< $(LDFLAGS) -z lazy # -no-pie

got2: got2.c
	$(CC) -o $@ $(CFLAGS) $< $(LDFLAGS) -z lazy # -no-pie

h2: h2.c
	$(CC) -o $@ $(CFLAGS) $< $(LDFLAGS) -static

# -fno-stack-protector: no stack protection & no var reorderign
guess: guess.c
	$(CC) -o $@ $(CFLAGS) -fno-stack-protector $< $(LDFLAGS) 
	objdump -D guess -M intel > guess.s

find_dlopen: find_dlopen.c
	$(CC) -o $@ $(CFLAGS) $< $(LDFLAGS) $(LDL)

%.so: %.c
	$(CC) -o $@ -shared -fPIC $^ $(LDL)

getuid_s: getuid.c
	$(CC) -o $@ $(CFLAGS) $< $(LDFLAGS) -static

segment: segment.c
	$(CC) -o $@ $(CFLAGS) $< $(LDFLAGS) $(LDL)

%: %.c
	$(CC) -o $@ $(CFLAGS) $< $(LDFLAGS)

%: %.cpp
	$(CXX) -o $@ $(CFLAGS) $< $(LDFLAGS)

clean:
	rm -f *~ $(PROGS)

