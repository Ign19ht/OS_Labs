#include <stdio.h>

int main(int argc, char *argv[]) {
    int n;
    if (argc < 2) {
        printf("You must put N as the first argument of the program");
        return 0;
    }
    sscanf(argv[1], "%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) printf(" ");
        for (int j = 0; j < i * 2 - 1; j++) printf("*");
        for (int j = 0; j <= n - i; j++) printf(" ");
        printf("\n");
    }
    return 0;
}
