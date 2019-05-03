#include <stdio.h>
#include <unistd.h>

int main() {
	printf("%d %d\n", geteuid(), getegid());
	return 0;
}
