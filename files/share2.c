#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int fd;

void myerror(const char *msg) { perror(msg); exit(-1); }

void * seek_and_write(void *args) {
	long id = (long) args;
	char buf[2] = { 'a' + id };
	usleep(1);
	printf("T%ld writes @ %ld\n", id+1, id * 5 % 10);
	usleep(1);
	lseek(fd, id * 5 % 10, SEEK_SET);
	usleep(1);
	write(fd, buf, 1);
	return NULL;
}

int main() {
	pthread_t t1, t2;
	fd = open("share.txt", O_WRONLY|O_CREAT|O_TRUNC, 0644);
	if(fd < 0) myerror("open");
	if(write(fd, "..........\n", 11) < 0) myerror("write");

	pthread_create(&t1, NULL, seek_and_write, (void*) 0);
	pthread_create(&t2, NULL, seek_and_write, (void*) 1);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	close(fd);
	system("cat share.txt");

	return 0;
}

