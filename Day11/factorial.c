#include <stdio.h>

unsigned long long factorial(int n)
{
    if (n < 0)
        return 0;
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i)
        result *= i;
    return result;
}

int main(void)
{
    int n;

    printf("Enter a non-negative integer: ");
    if (scanf("%d", &n) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }

    if (n < 0)
    {
        printf("Factorial is not defined for negative integers.\n");
        return 1;
    }

    printf("Factorial of %d is %llu\n", n, factorial(n));
    return 0;
}
