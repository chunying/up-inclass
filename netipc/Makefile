
CC	= gcc
CXX	= g++
CFLAGS	= -Wall -g
SYS	= $(shell uname -s)
LDFLAGS	=

ifeq ($(SYS),Linux)
LDFLAGS +=
endif

PROGS	= addr \
	  gethostent getprotoent getservent \
	  getaddrinfo getnameinfo echosrv \
	  unix_ss unix_sc unix_ds unix_dc \
	  raw_icmp raw_ip raw_packet \
	  raw_sping1 raw_sping2 raw_sping3 \
	  ping

all: $(PROGS)

%: %.c
	$(CC) -o $@ $(CFLAGS) $< $(LDFLAGS)

%: %.cpp
	$(CXX) -o $@ $(CFLAGS) $< $(LDFLAGS)

raw_%: raw_%.o hexdump.o
	$(CC) -o $@ $(LDFLAGS) $^

clean:
	rm -f *.o *~ $(PROGS)

