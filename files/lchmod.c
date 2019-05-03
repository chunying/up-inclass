#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	char cwd[256];
	char fullname[1024];

	if(argc < 2) {
		fprintf(stderr, "usage: %s name\n", argv[0]);
		return -1;
	}

	printf("cwd = %s\n", getcwd(cwd, sizeof(cwd)));
	snprintf(fullname, sizeof(fullname), "%s/%s", cwd, argv[1]);
	printf("fullname = %s\n", fullname);

	if(fchmodat(AT_FDCWD, fullname, 0644, AT_SYMLINK_NOFOLLOW) < 0)
		perror("fchmodat");

	return 0;
}

