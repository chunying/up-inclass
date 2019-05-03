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
	if((pid = fork()) < 0) {
		perror("fork");
		return -1;
	}
	// child
	if(pid == 0) {
		if(setpgid(0, getpid()) < 0) {
			perror("child/setpgid@child");
			return -1;
		}
		printf("child/pid %u sid %u pgrp %u\n",
			getpid(), getsid(0), getpgrp());
		return 0;
	}
	// parent
	if(setpgid(pid, pid) < 0) {
		perror("child/setpgid@parent");
		return -1;
	}
	if(setpgid(getpid(), pid) < 0) {
		perror("self/setpgid");
		return -1;
	}
	printf("parent/pid %u sid %u pgrp %u\n",
		getpid(), getsid(0), getpgrp());
	if(waitpid(pid, &status, 0) < 0) {
		perror("waitpid");
		return -1;
	}
	//
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

