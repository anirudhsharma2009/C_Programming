#include <stdio.h>

int main(void)
{
    int n, reversed = 0, remainder, sign = 1;

    printf("Enter an integer: ");
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    if (n < 0) {
        sign = -1;
        n = -n;
    }

    while (n != 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    reversed *= sign;
    printf("Reversed number: %d\n", reversed);

    return 0;
}
