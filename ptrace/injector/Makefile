
CC	= gcc
CXX	= g++
CFLAGS	= -Wall -g -fPIC
LDFLAGS =
LDL	= -ldl

ASM64	= yasm -f elf64 -DYASM -D__x86_64__
#ASM64	= nasm -f elf64 -DNASM -D__x86_64__

PROGS	= tick64 sample64.so injector64 \
	  tick32 sample32.so injector32 \
	  testmem

all: $(PROGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $<

%.o: %.cpp
	$(CXX) -c $(CFLAGS) $<

%.o: %.asm
	$(ASM64) $< -o $@

%: %.o
	$(CC) -o $@ $^ $(LDFLAGS)

tick32: tick.c
	$(CC) -o $@ $^ -m32 $(CFLAGS) $(LDFLAGS)

tick64: tick.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

sample32.so: sample.c
	$(CC) -o $@ -m32 $(CFLAGS) -shared $^

sample64.so: sample.c
	$(CC) -o $@ $(CFLAGS) -shared $^

injector64: injector.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(LDL)

injector32: injector.c
	$(CC) -o $@ $^ -m32 $(CFLAGS) $(LDFLAGS) $(LDL)

clean:
	rm -f *.o *~ $(PROGS)

