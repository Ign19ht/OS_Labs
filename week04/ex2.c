#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
    for (int i = 0; i < 3; i++) {
        fork();
        sleep(5);
    }
    return 0;
}

