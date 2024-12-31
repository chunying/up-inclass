#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define errquit(x) { perror(x); exit(-1); }

int main() {
	int fd, rlen;
	char buf[8192];
	if((fd = open("/proc/self/maps", O_RDONLY)) < 0) errquit("open");
	while((rlen = read(fd, buf, sizeof(buf))) > 0) write(1, buf, rlen);
	close(fd);
	pause();
	return 0;
}
