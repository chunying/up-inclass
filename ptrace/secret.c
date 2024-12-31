#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>

static char secret[] = "$5$chuang.cs$dzOgp6GTmuUMqCOJayKyTiLvuzqTk6xZnaZs8O5Je21";

int main() {
	char *passwd = getpass("Show me the key: ");
	if(strcmp(secret, crypt(passwd, secret)) == 0) {
		printf("Bingo!\n");
		// do something secret ...
	} else {
		printf("No no no ...\n");
	}
	return 0;
}

