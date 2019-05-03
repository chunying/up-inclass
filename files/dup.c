#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	if(argc > 1) {
		int fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC|O_EXCL, 0644);
		if(fd != 1) {
			dup2(fd, 1);
			close(fd);
		}
	}
	printf("hello, world\n");
	return 0;
}

