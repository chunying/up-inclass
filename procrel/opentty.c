#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	int fd;
	if((fd = open("/dev/tty", O_RDONLY)) < 0) {
		perror("open");
	} else {
		write(1, "ok\n", 3);
		close(fd);
	}
	return 0;
}

