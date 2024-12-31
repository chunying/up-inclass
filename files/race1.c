#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define	err_quit(s)	{ perror(s); exit(-1); }

void do_write(int fd, int offset, char *buf, int len) {
	if(lseek(fd, offset, SEEK_SET) < 0) err_quit("child:seek");
	if(write(fd, buf, len) < 0) err_quit("child:write");
	exit(0);
}

int main() {
	int i, j, fd, c1, c2, st, len;
	char buf[4096];
	char mem[4096];

	memset(mem, 0, sizeof(mem));

	for(i = 0; i < 1000; i++) {
		memset(buf, 0, sizeof(buf));

		fd = open("race.txt", O_CREAT|O_TRUNC|O_RDWR, 0644);
		if(fd < 0) err_quit("open");
		if(write(fd, buf, 10) < 0) err_quit("write");

		if((c1 = fork()) < 0) err_quit("fork1");
		if(c1 == 0) { do_write(fd, 0, "AAAAA", 5); }

		if((c2 = fork()) < 0) err_quit("fork2");
		if(c2 == 0) { do_write(fd, 5, "BBBBB", 5); }

		if(waitpid(c1, &st, 0) < 0) err_quit("wait1");
		if(waitpid(c2, &st, 0) < 0) err_quit("wait2");

		if(lseek(fd, 0, SEEK_SET) < 0) err_quit("seek");
		if((len = read(fd, buf, sizeof(buf)-1)) < 0) err_quit("read");
		buf[len] = '\0';
		close(fd);

		if(memcmp(buf, mem, sizeof(buf)) != 0) {
			memcpy(mem, buf, sizeof(buf));
			fprintf(stderr, "iter #%d differs: (%d)", i, len);
			for(j = 0; j < len; j++) fprintf(stderr, " %2.2x", mem[j]);
			fprintf(stderr, "\n");
		}
	}

	return 0;
}

