#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	int fd;
	pid_t pid;
	printf("mypid = %u\n", getpid());
	if((pid = fork()) < 0) {
		perror("fork");
		return -1;
	}
	// parent
	if(pid > 0) {
		return 0;
	}
	// child
	if((pid = setsid()) < 0) {
		perror("child/setsid");
		return -1;
	}
	printf("child/setsid success: pid %u sid %u pgrp %u\n",
		getpid(), getsid(0), getpgrp());
	if((fd = open("/dev/tty", O_RDONLY)) < 0) { perror("open"); }
	else { close(fd); }
	pause();
	return 0;
}

