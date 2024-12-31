
CC	= gcc
CXX	= g++
CFLAGS	= -Wall -g
LDFLAGS =

ASM64	= yasm -f elf64 -DYASM -D__x86_64__
#ASM64	= nasm -f elf64 -DNASM -D__x86_64__

PROGS	= sizes32 sizes64 guess secret minimal attach counter syscall1 syscall2 dump1 dump2 flow1 flow2 autodbg segs sigtrap

all: $(PROGS)
	make -C tests

%.o: %.c
	$(CC) -c $(CFLAGS) $<

%.o: %.cpp
	$(CXX) -c $(CFLAGS) $<

%.o: %.asm
	$(ASM64) $< -o $@

sizes32: sizes.c
	$(CC) -o $@ -m32 $^

sizes64: sizes.c
	$(CC) -o $@ $^

secret: secret.c
	$(CC) -o $@ $(CFLAGS) $^ -lcrypt

dump1: dump1.o 
	$(CC) -o $@ $^ $(LDFLAGS)

dump2: dump2.o ptools.o
	$(CXX) -o $@ $^ $(LDFLAGS) -lcapstone

autodbg: autodbg.o ptools.o
	$(CXX) -o $@ $^ $(LDFLAGS)

syscall2: systbl.o systbl_x86_64.o syscall2.o
	$(CC) -o $@ $^ $(LDFLAGS)

setuid: shadow
	sudo chown root:root shadow
	sudo chmod 4755 shadow

%: %.o
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.o *~ $(PROGS)
	make -C tests clean

