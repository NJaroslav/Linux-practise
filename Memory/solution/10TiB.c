// in shell
//sysctl -w vm.overcommit_memory=1

#include <stdlib.h>
#include <stdio.h>

#define SIZE (2ULL << 40)

int main() {
    char* ptr = malloc(SIZE * sizeof(char));
    getchar();
    free(ptr);
    exit(EXIT_SUCCESS);
}
