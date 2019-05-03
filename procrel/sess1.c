#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t pid;
	printf("mypid = %u\n", getpid());
	if((pid = setsid()) < 0) {
		perror("setsid");
		return -1;
	}
	printf("setsid success: pid %u sid %u pgrp %u\n",
		getpid(), getsid(0), getpgrp());
	pause();
	return 0;
}

