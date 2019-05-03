
CC	= gcc
CXX	= g++
CFLAGS	= -Wall -g

PROGS	= rusage hello return args testtime getopt bug bug2 \
	  gdbcall errno

all: $(PROGS)

%: %.c
	$(CC) -o $@ $(CFLAGS) $< $(LDFLAGS)

%: %.cpp
	$(CXX) -o $@ $(CFLAGS) $< $(LDFLAGS)

clean:
	rm -f *~ $(PROGS)

