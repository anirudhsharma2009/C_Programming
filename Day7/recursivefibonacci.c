#include <stdio.h>
#include <stdlib.h>

long long fib(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fib(n-1) + fib(n-2);
}

int main(void) {
    int n;
    if (printf("Enter number of terms: ") < 0) return 1;
    if (scanf("%d", &n) != 1) return 1;
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }
    printf("Fibonacci sequence (first %d terms):\n", n);
    for (int i = 0; i < n; ++i) {
        printf("%lld", fib(i));
        if (i + 1 < n) putchar(' ');
    }
    putchar('\n');
    return 0;
}
