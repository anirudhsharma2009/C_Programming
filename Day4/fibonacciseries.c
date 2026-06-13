#include <stdio.h>

int main(void)
{
    int n, i;
    long long a = 0, b = 1, next;

    printf("Enter number of terms: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    printf("Fibonacci series:");
    for (i = 1; i <= n; i++) {
        if (i == 1) {
            printf(" %lld", a);
        } else if (i == 2) {
            printf(" %lld", b);
        } else {
            next = a + b;
            printf(" %lld", next);
            a = b;
            b = next;
        }
    }
    printf("\n");

    return 0;
}
