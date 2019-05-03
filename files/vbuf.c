#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	int fd, a, b, c;
	FILE *fp;

	if((fd = open("/tmp/out", O_RDONLY)) < 0) {
		perror("open");
		return -1;
	}
	if((fp = fdopen(fd, "rt")) == NULL) {
		perror("fdopen");
		return -2;
	}

	fscanf(fp, "%d %d %d", &a, &b, &c);
	printf("%d %d %d\n", a, b, c);

	return 0;
}


