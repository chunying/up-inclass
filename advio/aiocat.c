#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <aio.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define	err_sys(m) { perror(m); exit(-1); }

static void aio_completed(union sigval param);

static char buf[8192];
static struct aiocb cb = {
	.aio_buf = buf,
	.aio_nbytes = sizeof(buf),
	.aio_sigevent.sigev_notify = SIGEV_THREAD,
	.aio_sigevent.sigev_notify_function = aio_completed
};

int
main(int argc, char *argv[]) {
	if(argc < 2)	cb.aio_fildes = 0;
	else		cb.aio_fildes = open(argv[1], O_RDONLY);
	if(cb.aio_fildes < 0)
		err_sys("open");
	if(aio_read(&cb) < 0)
		err_sys("main/aio_read");
	for(;;) pause();
	return 0;
}

void
aio_completed(union sigval param) {
	int err, len;
	off_t off;
	if((err = aio_error(&cb)) != 0) {
		if(err == -1)		err_sys("error");
		if(err == EINPROGRESS)	return;
		fprintf(stderr, "error: %s\n", strerror(err));
		exit(-1);
	}
	len = aio_return(&cb);
	write(1, (char*) cb.aio_buf, len);
	if((off = lseek(cb.aio_fildes, 0, SEEK_CUR)) >= 0)
		cb.aio_offset = off;
	if(off >= 0 && len != cb.aio_nbytes)
		exit(0);
	if(aio_read(&cb) < 0)
		err_sys("handler/aio_read");
}

