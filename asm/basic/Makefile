
CC	= gcc
CXX	= g++
ASM32	= yasm -f elf32 -DYASM
ASM64	= yasm -f elf64 -DYASM -D__x86_64__ -DPIC
#ASM32	= nasm -f elf32 -DNASM
#ASM64	= nasm -f elf64 -DNASM -D__x86_64__ -DPIC

CFLAGS	= -g -Wall -masm=intel -fno-stack-protector

PROGS	= minimal print \
	  libasm64.a testasm_x64 testlink_x64 \
	  value addsub addsub2 \
	  arith compand forloop

all: $(PROGS)

# default is x86_64
%.o: %.asm
	$(ASM64) $< -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $<

%: %.c
	$(CC) -o $@ $(CFLAGS) $<

%: %.cpp
	$(CXX) -o $@ $(CFLAGS) $<

%: %.cc
	$(CXX) -o $@ $(CFLAGS) $<

minimal: minimal.asm
	$(ASM64) $< -o $@.o
	ld -m elf_x86_64 -o $@ $@.o
	
libasm64.a: libasm64.asm
	$(ASM64) $< -o libasm64.o
	ar rc libasm64.a libasm64.o

%: %.asm libasm64.a
	$(ASM64) $< -o $@.o
	ld -m elf_x86_64 -o $@ $@.o libasm64.a

testlink_x64: testlink_x64.c libasm64.a
	gcc -o $@ $(CFLAGS) $^

clean:
	rm -f a.out *.o $(PROGS) peda-*

