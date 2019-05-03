#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#include <list>
#include <string>
using namespace std;

#define	err_sys(m) { perror(m); exit(-1); }

char *search_dir(list<string>& dirlist, unsigned major_n, unsigned minor_n) {
	DIR *dir;
	struct dirent *d;
	struct stat st;
	char fullname[8192];
	//
	while(dirlist.size() > 0) {
		string name = dirlist.front();
		dirlist.pop_front();
		if((dir = opendir(name.c_str())) == NULL)
			continue;
		while((d = readdir(dir)) != NULL) {
			if(strcmp(d->d_name, ".") == 0)	     continue;
			if(strcmp(d->d_name, "..") == 0)     continue;
			snprintf(fullname, sizeof(fullname), "%s/%s", name.c_str(), d->d_name);
			if(strcmp(fullname, "/dev/fd") == 0) continue;
			if(lstat(fullname, &st) != 0)
				continue;
			if(S_ISDIR(st.st_mode)) {
				dirlist.push_back(fullname);
				continue;
			}
			if(S_ISCHR(st.st_mode) == 0)
				continue;
			if(major(st.st_rdev) == major_n
			&& minor(st.st_rdev) == minor_n) {
				closedir(dir);	
				return strdup(fullname);
			}
		}
		closedir(dir);
	}
	return NULL;
}

char *ttyname_x(int fd) {
	struct stat st;
	list<string> dirlist;
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
	dirlist.push_back("/dev");
	return search_dir(dirlist, major(st.st_rdev), minor(st.st_rdev));
}

int main() {
	printf("ttyname %s\n", ttyname_x(0));
	return 0;
}

