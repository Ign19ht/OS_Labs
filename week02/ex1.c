#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;
    printf("Integer: %d\nSizeof integer: %llu\n", a, sizeof(a));
    printf("Float: %f\nSizeof float: %llu\n", b, sizeof(b));
    printf("Double: %f\nSizeof double: %llu\n", c, sizeof(c));
    return 0;
}
