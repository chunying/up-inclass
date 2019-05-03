#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int fd;

void myerror(const char *msg) { perror(msg); exit(-1); }

void * seek_and_write(void *args) {
	long id = (long) args;
	char buf[2] = { 'a' + id };
	usleep(1);
	printf("P%ld writes @ %ld\n", id+1, id * 5 % 10);
	usleep(1);
	lseek(fd, id * 5 % 10, SEEK_SET);
	usleep(1);
	write(fd, buf, 1);
	return NULL;
}

int main() {
	int pid;
	fd = open("share.txt", O_WRONLY|O_CREAT|O_TRUNC, 0644);
	if(fd < 0) myerror("open");
	if(write(fd, "..........\n", 11) < 0) myerror("write");

	pid = fork();
	if(pid < 0) myerror("fork");
	if(pid > 0) { // P1
		seek_and_write((void*) 0);
	} else {      // P2
		seek_and_write((void*) 1);
		exit(0);
	}
	close(fd);
	sleep(1);
	system("cat share.txt");
	return 0;
}

