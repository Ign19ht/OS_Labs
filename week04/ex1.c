#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
    pid_t pid = fork();
    int n = 5;
    for (int i = 0; i < n; i++) {
        if (pid > 0) printf("Hello from parent [%d - %d]\n", pid, i);
        else if (pid == 0) printf("Hello from child [%d - %d]\n", pid, i);
    }
    return 0;
}

