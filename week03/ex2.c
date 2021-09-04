#include <stdio.h>

void bubble_sort(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int t = array[j];
                array[j] = array[j + 1];
                array[j + 1] = t;
            }
        }
    }
}

int main(){
    int n;
    printf("Input the array size:\n");
    scanf("%d", &n);
    int array[n];
    printf("Input the array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    bubble_sort(array, n);
    printf("Array after sort: ");
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    return 0;
}

