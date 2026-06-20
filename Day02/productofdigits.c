#include <stdio.h>

int main(void)
{
    long long n;
    if (scanf("%lld", &n) != 1)
        return 0;

    long long num = n < 0 ? -n : n;
    long long product = 1;

    if (num == 0)
        product = 0;

    while (num > 0) {
        product *= num % 10;
        num /= 10;
    }

    printf("%lld", product);
    return 0;
}
