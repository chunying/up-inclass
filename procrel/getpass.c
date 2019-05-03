#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <signal.h>
#include <sys/types.h>

int main() {
	int fd, rlen;
	char buf[1024];
	struct termios t, oldt;
	sigset_t set, oset;
	
	if((fd = open(ctermid(NULL)/*"/dev/tty"*/, O_RDWR)) < 0) {
		perror("open(/dev/tty)");
		return -1;
	}

	sigemptyset(&set);
	sigaddset(&set, SIGINT);  /* block SIGINT */
	sigaddset(&set, SIGTSTP); /* block SIGTSTP */
	sigprocmask(SIG_BLOCK, &set, &oset);

	if(write(fd, "Password: ", 10) < 0) {
		perror("write");
		return -1;
	}
	
	if(tcgetattr(fd, &t) < 0) {
		perror("tcgetattr");
		return -1;
	}
	oldt = t;
	t.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL);
	if(tcsetattr(fd, TCSANOW, &t) < 0) {
		perror("tcsetattr");
		return -1;
	}

	if((rlen = read(fd, buf, sizeof(buf))) < 0) {
		perror("read");
		return -1;
	}

	if(tcsetattr(fd, TCSANOW, &oldt) < 0) {
		perror("tcsetattr");
	}
	close(fd);

	buf[rlen-1] = '\0';	/* overwritten the '\n' */
	printf("\nYour password is: %s\n", buf);

	sigprocmask(SIG_SETMASK, &oset, NULL);

	return 0;
}

