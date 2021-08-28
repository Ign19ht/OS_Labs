#include <stdio.h>
#define TYPES_INFO "Types of printing:\n1:Right Triangle\n2:Isosceles triangle\n3:Square"

int print_right_triangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int print_isosceles_triangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    for (int i = n - 1; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int print_square(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    int n, type;
    if (argc < 3) {
        printf("You must put N as the 1st argument of the program and Type of printing as the 2nd\n");
        printf(TYPES_INFO);
        return 0;
    }
    sscanf(argv[1], "%d", &n);
    sscanf(argv[2], "%d", &type);
    switch (type) {
        case 1: print_right_triangle(n); break;
        case 2: print_isosceles_triangle(n); break;
        case 3: print_square(n); break;
        default: printf("type of printing must be from 1 to 3\n");
            printf(TYPES_INFO);
    }
    return 0;
}

