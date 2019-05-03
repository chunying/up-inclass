#include <stdio.h>
#include <unistd.h>

int main() {
	printf("%s\n", ttyname(1));
	return 0;
}
