
CC	= gcc
CXX	= g++
CFLAGS	= -Wall -g
SYS	= $(shell uname -s)
LDFLAGS	=

ifeq ($(SYS),Linux)
LDFLAGS += 
CFLAGS	+= -D_GNU_SOURCE
endif

PROGS	= hellounix unixsrv1 unixcli1 unixsrv2 unixcli2 \
	  cmsgsrv cmsgcli cmsgsrv2 cmsgcli2 \
	  echoprefork1

all: $(PROGS)

%: %.c
	$(CC) -o $@ $(CFLAGS) $< $(LDFLAGS)

%: %.cpp
	$(CXX) -o $@ $(CFLAGS) $< $(LDFLAGS)

echoprefork1: echoprefork1.o
	$(CXX) -o $@ $(CFLAGS) $< $(LDFLAGS) -pthread

clean:
	rm -f *.o *~ $(PROGS)

