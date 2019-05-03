#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void walk(int depth) {
        int *p = 0;
        printf("%d\n", depth);
        if(rand()%5==0) *p = depth;
        else            walk(depth+1);
        return;
}

int main() {
        srand(time(0) ^ getpid());
        walk(0);
        return 0;
}

