#include <stdio.h>
#include <unistd.h>

#define	PRINT_TTY(fd)	\
	printf("fd %d: %s\n", fd, \
		isatty(fd) ? ttyname(fd) : "not a tty"); 

int main() {
	char buf[L_ctermid];
	printf("termid %s\n", ctermid(buf));
	PRINT_TTY(0);
	PRINT_TTY(1);
	PRINT_TTY(2);
	return 0;
}

