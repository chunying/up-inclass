
SYS	= $(shell uname -s)
CC	= gcc
CXX	= g++
CFLAGS	= -Wall -g
LDFLAGS	= -pthread -lm

PROGS	= minimal guard cancel sigwait \
	  jobqueue jobqueue-id jobqueue-order jobqueue-ido \
	  block1 block2 block3 fork1 fork2

ifneq ($(SYS),Darwin)
PROGS	+= barrier_off barrier_on
endif

all: $(PROGS)

%: %.c
	$(CC) -o $@ $(CFLAGS) $< $(LDFLAGS)

%: %.cpp
	$(CXX) -o $@ $(CFLAGS) $< $(LDFLAGS)

%.o: $.c
	$(CC) -c $@ $(CFLAGS) $<

%.o: $.cpp
	$(CXX) -c $@ $(CFLAGS) $<

barrier_off: barrier.c
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $<

barrier_on: barrier.c
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) -DHAS_BARRIER $<

jobqueue-id.o: jobqueue.cpp
	$(CXX) -c -o $@ $(CFLAGS) -DASSIGNID $<

jobqueue-order.o: jobqueue.cpp
	$(CXX) -c -o $@ $(CFLAGS) -DORDERED $<

jobqueue-ido.o: jobqueue.cpp
	$(CXX) -c -o $@ $(CFLAGS) -DASSIGNID -DORDERED $<

jobqueue: job.o jobqueue.o
	$(CXX) -o $@ $^ $(LDFLAGS)

jobqueue-id: job.o jobqueue-id.o
	$(CXX) -o $@ $^ $(LDFLAGS)

jobqueue-order: job.o jobqueue-order.o
	$(CXX) -o $@ $^ $(LDFLAGS)

jobqueue-ido: job.o jobqueue-ido.o
	$(CXX) -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.o *~ $(PROGS)

