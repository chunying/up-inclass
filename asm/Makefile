
CC64	= x86_64-linux-gnu-gcc
CXX64	= x86_64-linux-gnu-g++
LD64	= x86_64-linux-gnu-ld

CC32	= i686-linux-gnu-gcc
CXX32	= i686-linux-gnu-g++
LD32	= i686-linux-gnu-ld

ASM32	= yasm -f elf32 -DYASM
ASM64	= yasm -f elf64 -DYASM -D__x86_64__ -DPIC
#ASM32	= nasm -f elf32 -DNASM
#ASM64	= nasm -f elf64 -DNASM -D__x86_64__ -DPIC

CFLAGS	= -g -Wall -masm=intel -fno-stack-protector

PROGS	= fun1 fun2 hello_sys hello_libc2 swap swap1 swap2 swap3 \
	  dup2 frame_x64 frame_x86 conv_x86 conv_x86.s \
	  hello_x86 hello_x64 libme.so callext \
	  libasm64.a testasm_x64 testlink_x64 \
	  libmini64.a libmini64.so testmini_x64 cat1 cat1s errno \
	  disp

all: $(PROGS)

# default is x86_64
%.o: %.asm
	$(ASM64) $< -o $@

%.o: %.c
	$(CC64) -c $(CFLAGS) $<

%: %.asm
	$(ASM64) $< -o $@.o
	$(LD64) -m elf_x86_64 -o $@ $@.o
	
%_x86: %_x86.asm
	$(ASM32) $< -o $@.o
	$(LD32) -m elf_i386 -o $@ $@.o

%_x64: %_x64.asm
	$(ASM64) $< -o $@.o
	$(LD64) -m elf_x86_64 -o $@ $@.o

%_x86.s: %_x86.c
	$(CC32) $(CFLAGS) -m32 -S $<

%_x86: %_x86.c
	$(CC32) $(CFLAGS) -m32 $< -o $@

%_x64: %_x64.c
	$(CC64) $(CFLAGS) $< -o $@

%: %.c
	$(CC64) -o $@ $(CFLAGS) $<

%: %.cpp
	$(CXX64) -o $@ $(CFLAGS) $<

%: %.cc
	$(CXX64) -o $@ $(CFLAGS) $<

minimal: minimal.asm
	$(ASM64) $< -o $@.o
	$(LD64) -m elf_x86_64 -o $@ $@.o

swap: swap.c
	$(CC64) -o $@ $(CFLAGS) $<

swap3.o: swap3.asm
	$(ASM64) $< -o $@

swap%: swapmain.o swap%.o
	$(CC64) -o $@ $^ $(LDFLAGS)

dup2: dup2.c
	$(CC64) -o $@ $(CFLAGS) $<

libme.so: libme.c
	$(CC64) $(CFLAGS) -shared $< -o $@

callext: callext.c libme.so
	$(CC64) $(CFLAGS) -o $@ $< libme.so

hello_libc2: hello_libc.o
	$(CC64) -o $@ $^

hello_libc3: hello_libc.o
	$(LD64) -m elf_x86_64 -o $@ -dynamic-linker /lib64/ld-linux-x86-64.so.2 -pie -z now /usr/lib/x86_64-linux-gnu/Scrt1.o /usr/lib/x86_64-linux-gnu/crti.o /usr/lib/gcc/x86_64-linux-gnu/?/crtbeginS.o /usr/lib/gcc/x86_64-linux-gnu/?/crtendS.o /usr/lib/x86_64-linux-gnu/crtn.o $^ -L/lib -L/lib/x86_64-linux-gnu -L$(shell echo /usr/lib/gcc/x86_64-linux-gnu/?) -lc -lgcc

libasm64.a: libasm64.asm
	$(ASM64) $< -o libasm64.o
	ar rc libasm64.a libasm64.o

testasm_x64: testasm_x64.asm libasm64.a
	$(ASM64) $< -o testasm_x64.o
	$(LD64) -m elf_x86_64 -o $@ $@.o libasm64.a

testlink_x64: testlink_x64.c libasm64.a
	$(CC64) -o $@ $(CFLAGS) $^

libmini64.a: libmini64.asm libmini.c
	$(CC64) -c $(CFLAGS) -fPIC -nostdlib libmini.c
	$(ASM64) $< -o libmini64.o
	ar rc libmini64.a libmini64.o libmini.o

libmini64.so: libmini64.a
	$(LD64) -z noexecstack -shared libmini64.o libmini.o -o libmini64.so

testmini_x64: testmini.o start.o
	$(LD64) -z noexecstack -m elf_x86_64 --dynamic-linker /lib64/ld-linux-x86-64.so.2 -o $@ $^ -L. -lmini64

cat1: cat1.o libmini64.a start.o
	$(LD64) -z noexecstack -m elf_x86_64 -o $@ $^

cat1s: start.o cat1.o
	$(LD64) -z noexecstack -m elf_x86_64 --dynamic-linker /lib64/ld-linux-x86-64.so.2 -o $@ $^ -L. -lmini64

errno: start.o errno.o
	$(LD64) -z noexecstack -m elf_x86_64 --dynamic-linker /lib64/ld-linux-x86-64.so.2 -o $@ $^ -L. -lmini64

disp: start.o disp.o
	$(LD64) -z noexecstack -m elf_x86_64 --dynamic-linker /lib64/ld-linux-x86-64.so.2 -o $@ $^ -L. -lmini64

clean:
	rm -f a.out *.o $(PROGS) peda-*

