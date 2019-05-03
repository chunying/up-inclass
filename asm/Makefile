
CC	= gcc
CXX	= g++
ASM32	= yasm -f elf32 -DYASM
ASM64	= yasm -f elf64 -DYASM -D__x86_64__ -DPIC
#ASM32	= nasm -f elf32 -DNASM
#ASM64	= nasm -f elf64 -DNASM -D__x86_64__ -DPIC

CFLAGS	= -g -Wall -masm=intel -fno-stack-protector

PROGS	= fun1 fun2 hello_sys hello_libc2 swap swap1 swap2 swap3 \
	  dup2 frame_x64 frame_x86 conv_x86 conv_x86.s \
	  hello_x86 hello_x64 libme.so callext \
	  libasm64.a testasm_x64 testlink_x64 \
	  libmini64.a libmini64.so testmini_x64 cat1 cat1s

all: $(PROGS)

# default is x86_64
%.o: %.asm
	$(ASM64) $< -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $<

%: %.asm
	$(ASM64) $< -o $@.o
	ld -m elf_x86_64 -o $@ $@.o
	
%_x86: %_x86.asm
	$(ASM32) $< -o $@.o
	ld -m elf_i386 -o $@ $@.o

%_x64: %_x64.asm
	$(ASM64) $< -o $@.o
	ld -m elf_x86_64 -o $@ $@.o

%_x86.s: %_x86.c
	$(CC) $(CFLAGS) -m32 -S $<

%_x86: %_x86.c
	$(CC) $(CFLAGS) -m32 $< -o $@

%_x64: %_x64.c
	$(CC) $(CFLAGS) $< -o $@

%: %.c
	$(CC) -o $@ $(CFLAGS) $<

%: %.cpp
	$(CXX) -o $@ $(CFLAGS) $<

%: %.cc
	$(CXX) -o $@ $(CFLAGS) $<

swap: swap.c
	$(CC) -o $@ $(CFLAGS) $<

swap3.o: swap3.asm
	$(ASM64) $< -o $@

swap%: swapmain.o swap%.o
	$(CC) -o $@ $^ $(LDFLAGS)

dup2: dup2.c
	$(CC) -o $@ $(CFLAGS) $<

libme.so: libme.c
	$(CC) $(CFLAGS) -shared $< -o $@

callext: callext.c libme.so
	$(CC) $(CFLAGS) -o $@ $< libme.so

hello_libc2: hello_libc.o
	$(CC) -o $@ $^

libasm64.a: libasm64.asm
	$(ASM64) $< -o libasm64.o
	ar rc libasm64.a libasm64.o

testasm_x64: testasm_x64.asm libasm64.a
	$(ASM64) $< -o testasm_x64.o
	ld -m elf_x86_64 -o $@ $@.o libasm64.a

testlink_x64: testlink_x64.c libasm64.a
	gcc -o $@ $(CFLAGS) $^

libmini64.a: libmini64.asm libmini.c
	$(CC) -c $(CFLAGS) -fPIC -nostdlib libmini.c
	$(ASM64) $< -o libmini64.o
	ar rc libmini64.a libmini64.o libmini.o

libmini64.so: libmini64.a
	ld -shared libmini64.o libmini.o -o libmini64.so

testmini_x64: testmini.o start.o
	ld -m elf_x86_64 --dynamic-linker /lib64/ld-linux-x86-64.so.2 -o $@ $^ -L. -lmini64

cat1: cat1.o libmini64.a start.o
	ld -m elf_x86_64 -o $@ $^

cat1s: start.o cat1.o
	ld -m elf_x86_64 --dynamic-linker /lib64/ld-linux-x86-64.so.2 -o $@ $^ -L. -lmini64

clean:
	rm -f a.out *.o $(PROGS) peda-*

