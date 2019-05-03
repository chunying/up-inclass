#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
	pid_t pid;
	int fd, status;
	printf("mypid = %u\n", getpid());
	printf("myppid = %u\n", getppid());

	setpgid(0, getppid());

	printf("pid %u sid %u pgrp %u\n",
		getpid(), getsid(0), getpgrp());

	if((pid = setsid()) < 0) {
		perror("setsid");
		return -1;
	}

	printf("setsid success: pid %u sid %u pgrp %u\n",
		getpid(), getsid(0), getpgrp());

	if((fd = open("/dev/tty", O_RDONLY)) < 0) { perror("open"); }
	else { close(fd); }
	pause();
	return 0;
}

