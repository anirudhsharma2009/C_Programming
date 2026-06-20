#include <stdio.h>

long long fibonacci(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void)
{
    int n;

    printf("Enter the number of Fibonacci terms: ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    printf("Fibonacci sequence up to %d terms:\n", n);
    for (int i = 0; i < n; ++i) {
        printf("%lld", fibonacci(i));
        if (i < n - 1)
            printf(" ");
    }
    printf("\n");

    return 0;
}
