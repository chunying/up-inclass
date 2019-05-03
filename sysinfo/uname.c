#include <stdio.h>
#include <sys/utsname.h>

int main() {
	struct utsname un;
	if(uname(&un) >= 0) {
		printf("sys: %s\n", un.sysname);
		printf("node: %s\n", un.nodename);
		printf("release: %s\n", un.release);
		printf("version: %s\n", un.version);
		printf("machine: %s\n", un.machine);
	} else {
		perror("uname");
	}
	return 0;
}
