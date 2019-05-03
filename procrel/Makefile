
CC	= gcc
CXX	= g++
CFLAGS	= -Wall -g
LDFLAGS	= 

PROGS	= loginname ttyname getpass sess0 sess1 sess2 sess3 sess4 tpgrp opentty direct

all: $(PROGS)

%: %.c
	$(CC) -o $@ $(CFLAGS) $< $(LDFLAGS)

%: %.cpp
	$(CXX) -o $@ $(CFLAGS) $< $(LDFLAGS)

clean:
	rm -f *~ $(PROGS)

