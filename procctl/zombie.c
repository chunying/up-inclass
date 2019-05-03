#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	pid_t pid;

	if((pid = fork()) < 0) {
		perror("fork");
		exit(-1);
	} else if(pid == 0) {	// child
		printf("child terminated, pid = %d.\n", getpid());
		exit(0);
	} else {		// parent
		char cmd[128];
		snprintf(cmd, sizeof(cmd),
			"ps -uwp %d",
			pid);
		printf("sleeping for 2 seconds ...\n");
		sleep(2);
		system(cmd);
		printf("press Ctrl-C to break ...\n");
		pause();
	}
	return 0;
}

