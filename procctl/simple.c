#include <stdio.h>
#include <unistd.h>

int main() {
	printf("before exec ...\n");
	execl("/bin/ls", "ls", NULL);
	printf("after exec ...\n");
	return 0;
}

