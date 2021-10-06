#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main(void) {
    int *n[10];
    size_t size = 10*1024*1024;
    struct rusage usage;
    for (int i = 0; i < 10; i++) {
        n[i] = malloc(size);
        memset(n[i], 0, size);
        getrusage(RUSAGE_SELF, &usage);
        printf("After %d iteration\n", i);
        printf("ru_stime: %ld\n", usage.ru_stime.tv_usec);
        printf("ru_maxrss: %ld\n", usage.ru_maxrss);
        printf("ru_ixrss: %ld\n", usage.ru_isrss);
        printf("ru_idrss: %ld\n", usage.ru_idrss);
        printf("ru_isrss: %ld\n", usage.ru_isrss);
        sleep(1);
    }
    printf("Done\n");
}