
CC	= gcc
CXX	= g++
CFLAGS	= -Wall -g
LDFLAGS =

ASM64	= yasm -f elf64 -DYASM -D__x86_64__
#ASM64	= nasm -f elf64 -DNASM -D__x86_64__

PROGS	= hello hidden sigtrap empty

all: $(PROGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $<

%.o: %.cpp
	$(CXX) -c $(CFLAGS) $<

%.o: %.asm
	$(ASM64) $< -o $@

hello: hello.o
	$(LD) -o $@ $^

hidden: hidden.o
	$(LD) -o $@ $^

sigtrap: sigtrap.o
	$(LD) -o $@ $^

%: %.o
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.o *~ $(PROGS)

