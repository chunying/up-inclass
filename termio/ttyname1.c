#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#define	err_sys(m) { perror(m); exit(-1); }

char *recursive_find(const char *path, unsigned major_n, unsigned minor_n) {
	char *ret = NULL;
	char fullname[8192];
	char entrybuf[sizeof(struct dirent)+1024];
	DIR *d;
	struct dirent *result, *entryp = (struct dirent*) entrybuf;
	//
	if((d = opendir(path)) == NULL)
		goto quit;
	while(readdir_r(d, entryp, &result) == 0) {
		struct stat st;
		if(result == NULL)
			break;
		// skip . and ..
		if(strcmp(result->d_name, ".") == 0)	continue;
		if(strcmp(result->d_name, "..") == 0)	continue;
		// check major and minor
		snprintf(fullname, sizeof(fullname), "%s/%s", path, result->d_name);
		if(lstat(fullname, &st) != 0)
			continue;
		if(S_ISCHR(st.st_mode)) {
			if(major(st.st_rdev) == major_n
			&& minor(st.st_rdev) == minor_n) {
				ret = strdup(fullname);
				goto quit;
			}
		} else if(S_ISDIR(st.st_mode)) {
			if((ret = recursive_find(fullname, major_n, minor_n)) != NULL)
				goto quit;
		}
	}
	closedir(d);
quit:
	return ret;
}

char *ttyname_x(int fd) {
	struct stat st;
	if(isatty(fd) == 0) {
		fprintf(stderr, "# not a tty\n");
		return NULL;
	}
	if(fstat(0, &st) < 0) {
		perror("# fstat");
		return NULL;
	}
	if(S_ISCHR(st.st_mode) == 0) {
		fprintf(stderr, "# not a charater device\n");
		return NULL;
	}
	fprintf(stderr, "# major %u minor %u\n", major(st.st_rdev), minor(st.st_rdev));
	return recursive_find("/dev", major(st.st_rdev), minor(st.st_rdev));
}

int main() {
	printf("ttyname %s\n", ttyname_x(0));
	return 0;
}

