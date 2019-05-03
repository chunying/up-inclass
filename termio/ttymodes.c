#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <termios.h>
#include <errno.h>

static int save_fd =1;
static struct termios save_termios;

#define err_sys(m) { perror(m); exit(-1); }

int
tty_cbreak(int fd) {	/* put terminal into a cbreak mode */
	struct termios	buf;

	if (tcgetattr(fd, &buf) < 0)
		return -1;
	buf.c_lflag &= ~(ECHO | ICANON);
	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;
	if (tcsetattr(fd, TCSAFLUSH, &buf) < 0)
		return -1;

	if (tcgetattr(fd, &buf) < 0)
		return -1;
	if ((buf.c_lflag & (ECHO | ICANON))
	||   buf.c_cc[VMIN] != 1 || buf.c_cc[VTIME] != 0)
		return -1;

	return 0;
}

int
tty_raw(int fd)	{	/* put terminal into a raw mode */
	struct termios	buf;

	if (tcgetattr(fd, &buf) < 0)
		return -1;
	buf.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	buf.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	buf.c_cflag &= ~(CSIZE | PARENB);
	buf.c_cflag |= CS8;
	buf.c_oflag &= ~(OPOST);
	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;
	if (tcsetattr(fd, TCSAFLUSH, &buf) < 0)
		return -1;

	if (tcgetattr(fd, &buf) < 0)
		return -1;
	if ((buf.c_lflag & (ECHO | ICANON | IEXTEN | ISIG)) ||
	    (buf.c_iflag & (BRKINT | ICRNL | INPCK | ISTRIP | IXON)) ||
	    (buf.c_cflag & (CSIZE | PARENB | CS8)) != CS8 ||
	    (buf.c_oflag & OPOST) ||
	     buf.c_cc[VMIN] != 1 || buf.c_cc[VTIME] != 0)
		return -1;

	return 0;
}

int
tty_backup(int fd, struct termios *t) {
	if (fd < 0)
		return -1;
	if (tcgetattr(fd, t) < 0)
		return -1;
	return fd;
}

int
tty_restore(int fd, struct termios *t) {
	if (fd < 0)
		return -1;
	if (tcsetattr(fd, TCSAFLUSH, t) < 0)
		return -1;
	return fd;
}

void
tty_atexit(void)		/* can be set up by atexit(tty_atexit) */
{
	tty_restore(save_fd, &save_termios);
}

struct termios *
tty_termios(void)		/* let caller see original tty state */
{
	return(&save_termios);
}

static void
handler(int s) {
	printf("signal caught\n");
	exit(0);
}

int
main() {
	int i, c;

	save_fd = tty_backup(0, &save_termios);
	atexit(tty_atexit);

	if (signal(SIGINT, handler) == SIG_ERR)  err_sys("signal(SIGINT) error");
	if (signal(SIGQUIT, handler) == SIG_ERR) err_sys("signal(SIGQUIT) error");
	if (signal(SIGTERM, handler) == SIG_ERR) err_sys("signal(SIGTERM) error");

	if (tty_raw(0) < 0)	err_sys("tty_raw error");
	printf("Enter raw mode characters, terminate with DELETE\n");
	while ((i = read(0, &c, 1)) == 1) {
		if ((c &= 255) == 0177 /* ASCII DELETE */)
			break;
		printf("%x\n", c);
	}

	if (tty_restore(0, &save_termios) < 0)  err_sys("tty_reset error");
	if (i <= 0)                             err_sys("read error");
	if (tty_cbreak(0) < 0)                  err_sys("tty_cbreak error");
	printf("\nEnter cbreak mode characters, terminate with SIGINT\n");
	while ((i = read(0, &c, 1)) == 1) {
		printf("%x\n", c & 255);
	}
	if (tty_restore(0, &save_termios) < 0)  err_sys("tty_reset error");
	if (i <= 0)                             err_sys("read error");

	return 0;
}

