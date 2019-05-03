#include <stdio.h>

int
main() {
        int i;
        char hello[] = "Hello, World!\n";
        char *ph = hello;
        for(i = 0; ph[i]!='\0'; i++) {
                putchar(ph[i]);
        }
        return 0;
}
