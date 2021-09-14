#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    while (1) {
        char *input = malloc(sizeof(char));
        size_t bufsize = 256;
        getline(&input, &bufsize, stdin);
        system(input);
    }
}
