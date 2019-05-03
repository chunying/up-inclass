#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>

int main(int argc, char *argv[]) {
	struct passwd *ppwd;

	if(argc < 2) {
		fprintf(stderr, "usage: %s id\n", argv[0]);
		return -1;
	}

	if((ppwd = getpwnam(argv[1])) == NULL) {
		fprintf(stderr, "invalid id: %s\n", argv[1]);
		return -1;
	}

	printf("%s:%s:%u:%u:%s:%s:%s\n",
		ppwd->pw_name, ppwd->pw_passwd, ppwd->pw_uid, ppwd->pw_gid,
		ppwd->pw_gecos, ppwd->pw_dir, ppwd->pw_shell);

	return 0;
}
