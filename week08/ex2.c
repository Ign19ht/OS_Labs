#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    int *n[10];
    size_t size = 10*1024*1024;
    for (int i = 0; i < 10; i++) {
//        printf("Memory allocated\n");
        n[i] = malloc(size);
        memset(n[i], 0, size);
        sleep(1);
    }
    printf("Done\n");
}

/*
 * Ex2:
 * After each iteration free memory is decreasing but si and so aren't changing
 *
 * Ex3:
 * After each iteration Virt and Res memory are increasing
 */