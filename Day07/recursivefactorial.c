#include <stdio.h>
#include <stdlib.h>

unsigned long long factorial(int n) {
    if (n <= 1) return 1ULL;
    return (unsigned long long)n * factorial(n - 1);
}

int main(void) {
    int n;
    printf("Enter a non-negative integer: ");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }
    if (n < 0) {
        fprintf(stderr, "Factorial is not defined for negative numbers\n");
        return 1;
    }
    if (n > 20) {
        // 20! fits in 64-bit unsigned long long, warn for larger values
        fprintf(stderr, "Warning: values greater than 20 may overflow 64-bit result\n");
    }
    unsigned long long result = factorial(n);
    printf("%d! = %llu\n", n, result);
    return 0;
}
