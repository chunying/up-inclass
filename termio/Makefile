
SYS	= $(shell uname -s)
CC	= gcc
CXX	= g++
CFLAGS	= -Wall -g
LDFLAGS	=
LDL	=

PROGS	= ttybit6 ttybit8 termid ttyname1 ttyname2 getpass ttymodes \
	  curses

all: $(PROGS)

%: %.c
	$(CC) -o $@ $(CFLAGS) $< $(LDFLAGS)

%: %.cpp
	$(CXX) -o $@ $(CFLAGS) $< $(LDFLAGS)

curses: curses.c
	$(CC) -o $@ $(CFLAGS) $< $(LDFLAGS) -lcurses

clean:
	rm -f *~ $(PROGS)

