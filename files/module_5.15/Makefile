
obj-m     += hellomod.o
ccflags-y += -DEXPORT_SYMTAB

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

