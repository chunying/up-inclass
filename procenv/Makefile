
SYS	= $(shell uname -s)
CC	= gcc
CXX	= g++
CFLAGS	= -Wall -g
LDFLAGS	=
LDL	= -ldl

ifeq ($(SYS),FreeBSD)
LDL	=
endif

PROGS	= guess h1 getuid inject1.so inject2.so inject3.so random.so segment setjmp

ifneq ($(SYS),Darwin)	# apple does not support static linkage ...
PROGS	+= h2 getuid_s
endif

all: $(PROGS)

h2: h2.c
	$(CC) -o $@ $(CFLAGS) $< $(LDFLAGS) -static

guess: guess.c
	$(CC) -o $@ $(CFLAGS) $< $(LDFLAGS) 
	objdump -D guess -M intel > guess.s

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

