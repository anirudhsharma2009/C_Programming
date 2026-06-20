#include <stdio.h>
#include <stdlib.h>

int main(void) {
    long long n;
    printf("Enter an integer: ");
    if (scanf("%lld", &n) != 1) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    if (n == 0) {
        printf("Every non-zero integer is a factor of 0\n");
        return 0;
    }

    long long absn = llabs(n);
    printf("Factors of %lld:\n", n);
    for (long long i = 1; i <= absn; ++i) {
        if (absn % i == 0) {
            if (n < 0)
                printf("%lld ", i);
            else
                printf("%lld ", i);
        }
    }
    printf("\n");
    return 0;
}
