#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	int fd = -1;
	char name[1024];

	fprintf(stderr, "mypid = %d\n", getpid());

	fprintf(stderr, "tmpnam = %s\n", tmpnam(name));
	// XXX: open the file by yourself

	snprintf(name, sizeof(name), "/tmp/file-XXXXXX");
	fd = mkstemp(name);
	if(fd >= 0) {
		char fdpath[1024];
		fprintf(stderr, "mkstemp = (%d,%s)\n", fd, name);

		// XXX: get file name from /dev/fd ...
		snprintf(fdpath, sizeof(fdpath), "/dev/fd/%d", fd);
		readlink(fdpath, name, sizeof(name));
		fprintf(stderr, "mkstemp = (%d,%s)\n", fd, name);
	}

	fprintf(stderr, "sleeping ...\n");
	sleep(1000);

	if(fd >= 0) close(fd);

	return 0;
}

