
CC	= gcc
CXX	= g++
CFLAGS	= -Wall -g
SYS	= $(shell uname -s)
LDFLAGS	=

ifeq ($(SYS),Linux)
LDFLAGS +=
endif

PROGS	= unixdgram_srvp unixdgram_srv unixdgram_cli

all: $(PROGS)

%: %.c
	$(CC) -o $@ $(CFLAGS) $< $(LDFLAGS)

%: %.cpp
	$(CXX) -o $@ $(CFLAGS) $< $(LDFLAGS)

clean:
	rm -f *.o *~ $(PROGS)

