#if 0
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#else
#include "libmini.h"
#endif

int main(int argc, char *argv[]) {
	int fd = 0, rlen;
	char buf[4096];
	if(argc > 1) {
		if((fd = open(argv[1], O_RDONLY)) < 0) {
			perror("open");
			return -1;
		}
	}
	while((rlen = read(fd, buf, sizeof(buf))) > 0) {
		if(write(1, buf, rlen) < 0) {
			perror("write");
			return -2;
		}
	}
	close(fd);
	return 0;
}

