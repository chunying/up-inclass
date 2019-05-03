
CC	= gcc
CXX	= g++
CFLAGS	= -Wall -g
LDFLAGS	=

PROGS	= buffer simple exec echobin fig8.20-exec2 zombie shell

all: $(PROGS)

%: %.c
	$(CC) -o $@ $(CFLAGS) $< $(LDFLAGS)

%: %.cpp
	$(CXX) -o $@ $(CFLAGS) $< $(LDFLAGS)

clean:
	rm -f *~ $(PROGS)

