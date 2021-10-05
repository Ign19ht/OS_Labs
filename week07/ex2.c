#include <stdio.h>
#include <malloc.h>

int main(void) {
    int n;
    printf("Enter size N:");
    scanf("%d", &n);
    int *array = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        *(array + i) = i;
    }
    for (int i = 0; i < n; i++) {
        printf("ptr[%d]==%d\n", i, *(array + i));
    }
    free(array);
}