#include <stdio.h>
#include <unistd.h>

int main() {
	printf("my pid %u sid %u pgrp %u\n",
		getpid(), getsid(0), getpgrp());
	printf("foreground group is %u\n", tcgetpgrp(0));
	return 0;
}

