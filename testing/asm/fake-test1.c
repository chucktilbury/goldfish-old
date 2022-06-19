
#include <stdio.h>

int main(int argc , char ** argv) {
    printf("HOW DA! %s\n", argv[1]);
    fopen("test.file", "w");
    return 0;
}