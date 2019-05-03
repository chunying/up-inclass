#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

#define	err_sys(m) { perror(m); exit(-1); }

void
sig_io(int s) {
	int rlen;
	char buf[8192];
	if((rlen = read(0, buf, sizeof(buf))) > 0)
		write(1, buf, rlen);
}

int
main() {
	int flag;
	signal(SIGIO, sig_io);
#ifndef __APPLE__
	if(fcntl(STDIN_FILENO, F_SETOWN, getpid()) < 0)
		err_sys("fcntl(F_SETOWN)");
#endif
	if((flag = fcntl(STDIN_FILENO, F_GETFL)) < 0)
		err_sys("fcntl(F_GETFL)");
	if(fcntl(STDIN_FILENO, F_SETFL, flag | O_ASYNC) < 0)
		err_sys("fcntl(F_SETFL)");
	for(;;) pause();
	return 0;
}

