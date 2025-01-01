
SYS		= $(shell uname -s)
PWD		= $(shell pwd)
BASE	= $(shell basename $(PWD))
MAKE	= make
DIRS	= env+tools sysinfo procenv procctl procrel \
		  threads daemon advio classipc netipc advipc \
		  signal termio files ipc asm ptrace

DATESTR		= $(shell date "+%Y%m%d")
INCLASS_TGZ	= inclass-$(DATESTR).tar.gz

ifeq ($(SYS),FreeBSD)
MAKE		= gmake
endif

all:
	for d in $(DIRS); do $(MAKE) -C $$d || exit 1; done

clean:
	for d in $(DIRS); do $(MAKE) -C $$d clean; done
	find . -name core -exec rm {} \;
	find . -name '.gdb*' -exec rm {} \;
	find . -name 'peda-session-*' -exec rm {} \;

