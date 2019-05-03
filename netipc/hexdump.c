#include <ctype.h>
#include <stdio.h>

void hexdump(unsigned char *s, int len) {
	int i, j;
	printf("hexdump: %d bytes dumped\n", len);
	for(i = 0; i < len; i += 16) {
		printf("0x%04x:  ", i);
		for(j = 0; j < 16; j++) {
			if(i + j < len) printf(" %02x", s[i+j]);
			else            printf("   ");
		}
		printf("    ");
		for(j = 0; j < 16; j++) {
			if(i + j < len) printf("%c", isprint(s[i+j]) ? s[i+j] : '.');
			else            printf(" ");
		}
		printf("\n");
	}
	return;
}

// Ref: http://www.faqs.org/rfcs/rfc1071.html
unsigned short cksum(unsigned char *data, int len) {
	long sum = 0;  /* assume 32 bit long, 16 bit short */

	while(len > 1) {
		sum += *((unsigned short*) data);
		if(sum & 0x80000000)   /* if high order bit set, fold */
			sum = (sum & 0xFFFF) + (sum >> 16);
		data += 2;
		len -= 2;
	}

	if(len)       /* take care of left over byte */
		sum += (unsigned short) *data;

	while(sum>>16)
		sum = (sum & 0xFFFF) + (sum >> 16);

	return ~sum;
}

