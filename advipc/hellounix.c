#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/socket.h>

#define	MESSAGE1 "hello, "
#define	MESSAGE2 "world!\n"
#define err_sys(m) { perror(m); exit(-1); }

int main() {
	int status, len, fd[2];
	pid_t pid;
	char buf[1024];
	if(socketpair(AF_UNIX, SOCK_STREAM, 0, fd) < 0)
		err_sys("socketpair");
	if((pid = fork()) < 0)
		err_sys("fork");
	if(pid != 0) {	/* parent */
		if((len = write(fd[0], MESSAGE1, strlen(MESSAGE1))) < 0)
			err_sys("parent/write");
		if((len = read(fd[0], buf, sizeof(buf))) < 0)
			err_sys("parent/read");
		write(1, buf, len);
		wait(&status);
	} else {	/* child */
		if((len = read(fd[1], buf, sizeof(buf))) < 0)
			err_sys("child/read");
		write(1, buf, len);
		if((len = write(fd[1], MESSAGE2, strlen(MESSAGE2))) < 0)
			err_sys("child/write");
	}
	return 0;
}

