#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

#define	LOCKMODE	(S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)

int 
lockfile(int fd) {
	struct flock fl;
	fl.l_type = F_WRLCK;
	fl.l_start = 0;
	fl.l_whence = SEEK_SET;
	fl.l_len = 0;
	return fcntl(fd, F_SETLK, &fl);
}

int
already_running(const char *filename) {
	int fd;
	char buf[16];
	
	fd = open(filename, O_RDWR|O_CREAT, LOCKMODE);
	if (fd < 0) {
		syslog(LOG_ERR, "can't open %s: %s", filename, strerror(errno));
		exit(-2);
	}
	if (lockfile(fd) < 0) {
		if (errno == EACCES || errno == EAGAIN) {
			close(fd);
			return 1;
		}
		syslog(LOG_ERR, "can't lock %s: %s", filename, strerror(errno));
		exit(-2);
	}
	ftruncate(fd, 0);
	sprintf(buf, "%ld\n", (long) getpid());
	write(fd, buf, strlen(buf));
	return 0;
}

int main(int argc, char *argv[]) {
	pid_t pid;

	if(argc < 2) {
		fprintf(stderr, "usage: %s pidfile\n", argv[0]);
		return -1;
	}

	if((pid = fork()) < 0) {
		perror("fork");
		return -1;
	}

	if(pid == 0) {
		if(already_running(argv[1])) {
			fprintf(stderr, "daemon is running\n");
			return -1;
		}
		fprintf(stderr, "daemon %u: run in background\n", getpid());
		while(1) {
			pause();
		}
	}

	return 0;
}

