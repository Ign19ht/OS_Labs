#include <stdio.h>
#include <malloc.h>
#include <string.h>

void *my_realloc(void *ptr, size_t new_size) {
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }
    void *new_ptr = malloc(new_size);
    if (ptr != NULL) memcpy(new_ptr, ptr, new_size);
    free(ptr);
    return new_ptr;
}

int main(void) {
    int n1 = 10, n2 = 15;
    int *array = malloc(n1*sizeof(int));
    for (int i = 0; i < n1; i++) {
        *(array + i) = i;
    }
    for (int i = 0; i < n1; i++) {
        printf("ptr[%d]==%d\n", i, *(array + i));
    }
    int *new_array = my_realloc(array, n2 * sizeof(int));
    for (int i = 0; i < n2; i++) {
        printf("new_ptr[%d]==%d\n", i, *(new_array + i));
    }
    free(array);
}