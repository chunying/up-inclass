
CC	= gcc
CXX	= g++
CFLAGS	= -Wall -g

PROGS	= dup tmpnam ioctl uid vbuf large lchmod share1 share2 share3 setvbuf1 setvbuf2 race1 race2

all: $(PROGS)

%: %.c
	$(CC) -o $@ $(CFLAGS) $< $(LDFLAGS)

%: %.cpp
	$(CXX) -o $@ $(CFLAGS) $< $(LDFLAGS)

large: large.c
	$(CC) -o $@ $(CFLAGS) -D_LARGEFILE64_SOURCE -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 $< $(LDFLAGS)

share2: share2.c
	$(CC) -o $@ $(CFLAGS) $< $(LDFLAGS) -pthread

share3: share3.c
	$(CC) -o $@ $(CFLAGS) $< $(LDFLAGS) -pthread

clean:
	rm -f *~ $(PROGS) large.bin share.txt

