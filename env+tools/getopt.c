#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int i, ch;

	while((ch = getopt(argc, argv, "ac:vi:")) != -1) {
		switch(ch) {
		case 'a':
			printf("option a\n");
			break;
		case 'c':
			printf("option c: %s\n", optarg);
			break;
		case 'v':
			printf("option v\n");
			break;
		case 'i':
			printf("option i: %s\n", optarg);
			break;
		case '?':
		case ':':
		default:
			printf("bad option: %c\n", ch);
			break;
		}
	}

	argc -= optind;
	argv += optind;

	for(i = 0; i < argc; i++) {
		printf("argv[%d] = %s\n", optind + i, argv[i]);
	}

	return 0;
}

