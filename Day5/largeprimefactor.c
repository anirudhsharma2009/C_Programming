#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned long long n;
    unsigned long long maxFactor = 0;

    printf("Enter a positive integer: ");
    if (scanf("%llu", &n) != 1 || n < 2) {
        printf("Please enter an integer greater than 1.\n");
        return 1;
    }

    while ((n % 2ULL) == 0ULL) {
        maxFactor = 2ULL;
        n /= 2ULL;
    }

    for (unsigned long long factor = 3ULL; factor * factor <= n; factor += 2ULL) {
        while ((n % factor) == 0ULL) {
            maxFactor = factor;
            n /= factor;
        }
    }

    if (n > 1ULL) {
        maxFactor = n;
    }

    printf("Largest prime factor: %llu\n", maxFactor);
    return 0;
}
