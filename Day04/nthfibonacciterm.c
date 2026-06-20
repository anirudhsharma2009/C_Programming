#include <stdio.h>

int main(void)
{
    int n;
    unsigned long long a = 0, b = 1, next;

    if (scanf("%d", &n) != 1) {
        return 1;
    }

    if (n <= 0) {
        printf("0\n");
        return 0;
    }

    if (n == 1) {
        printf("%llu\n", a);
        return 0;
    }

    for (int i = 2; i <= n; i++) {
        next = a + b;
        a = b;
        b = next;
    }

    printf("%llu\n", a);
    return 0;
}
