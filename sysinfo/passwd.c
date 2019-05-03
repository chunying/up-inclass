#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#ifdef __linux__
#include <crypt.h>
#endif

void output(const char *prefix, char *encrypted, int saltlen) {
	if(encrypted == NULL)
		printf("%7s: Not available\n", prefix);
	printf("%7s: %2d %s\n", prefix, strlen(encrypted) - saltlen, encrypted);
	return;
}

char *
salt(int n, char *salt) {
	int i;
	static char ch[] =
		"abcdefghijklmnopqrstuvwxyz"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"1234567890./";
	if(salt == NULL)
		return salt;
	for(i = 0; i < n; i++) {
		salt[i] = ch[rand() % sizeof(ch)];
	}
	return salt;
}

int
main(int argc, char *argv[]) {
	char *ptr, p[64];
	char *p_des, s_des[64] = "";
	char *p_md5, s_md5[64] = "$1$";
	char *p_sha256, s_sha256[64] = "$5$";
	char *p_sha512, s_sha512[64] = "$6$";

	srand(time(0) ^ getpid());

	printf("Password Demo\n");
	if((ptr = getpass("Enter your password: ")) == NULL) {
		perror("getpass");
		return -1;
	}

	strncpy(p, ptr, sizeof(p));
	printf("Your password is: [%s]\n", p);

	if(argc > 1) {
		strncpy(s_des, argv[1], 2);
		strncat(s_md5, argv[1], 8);
		strncat(s_sha256, argv[1], 8);
		strncat(s_sha512, argv[1], 8);
	} else {
		char s[16];
		strncpy(s_des, salt(2, s), 2);
		strncat(s_md5, salt(8, s), 8);
		strncat(s_sha256, salt(8, s), 8);
		strncat(s_sha512, salt(8, s), 8);
	}
	strcat(s_md5, "$");
	strcat(s_sha256, "$");
	strcat(s_sha512, "$");

	p_des = strdup(crypt(p, s_des));
	p_md5 = strdup(crypt(p, s_md5));
	p_sha256 = strdup(crypt(p, s_sha256));
	p_sha512 = strdup(crypt(p, s_sha512));

	output("DES", p_des, 2);
	output("MD5", p_md5, 12);
	output("SHA256", p_sha256, 12);
	output("SHA512", p_sha512, 12);

	return 0;
}

