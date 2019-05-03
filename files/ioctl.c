#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#define	DEVFILE	"/dev/hello_dev"

int main() {
	int fd;
	char buf[64];
	if((fd = open(DEVFILE, O_RDWR)) < 0) {
		perror("open");
		return -1;
	}

	read(fd, buf, sizeof(buf));
	write(fd, buf, sizeof(buf));
	ioctl(fd, 0x1234);
	ioctl(fd, 0x5678, 0xabcd);
	close(fd);

	return 0;
}

