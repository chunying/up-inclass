#include <stdio.h>
#include <unistd.h>

int main() {
	printf("%s\n", getlogin());
	return 0;
}
