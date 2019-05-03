#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void myerror(const char *msg) { perror(msg); exit(-1); }

int main() {
	int fd;
	fd = open("large.bin", O_WRONLY|O_CREAT|O_TRUNC|O_LARGEFILE, 0644);
	if(fd < 0) myerror("open");
	if(lseek(fd, 8LL*1024*1024*1024, SEEK_SET) < 0) myerror("lseek");
	if(write(fd, "\nhello!\n", 8) < 0) myerror("write");
	close(fd);
	return 0;
}

