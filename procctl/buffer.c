#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t pid;
	printf("hello, world\n");
	pid = fork();
	if(pid < 0) printf("Something wrong ...\n");
	else if(pid == 0) printf("I am parent\n");
	else if(pid  > 0) printf("I am child\n");
	return 0;
}

