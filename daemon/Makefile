
CC	= gcc
CXX	= g++
CFLAGS	= -Wall -g
LDFLAGS	=

PROGS	= lock

all: $(PROGS)

%: %.c
	$(CC) -o $@ $(CFLAGS) $< $(LDFLAGS)

%: %.cpp
	$(CXX) -o $@ $(CFLAGS) $< $(LDFLAGS)

clean:
	rm -f *~ $(PROGS)

