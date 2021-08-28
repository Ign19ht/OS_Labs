#include <stdio.h>

int swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int main() {
    int a, b;
    printf("Write 1st number:\n");
    scanf("%d", &a);
    printf("Write 2nd number:\n");
    scanf("%d", &b);
    printf("Before swap: a -> %d, b -> %d\n", a, b);
    swap(&a, &b);
    printf("After swap: a -> %d, b -> %d\n", a, b);
    return 0;
}
