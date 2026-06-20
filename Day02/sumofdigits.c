#include <stdio.h>

int main(void)
{
    int n, original, sum = 0;

    printf("Enter an integer: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    original = n;
    if (n < 0) {
        n = -n;
    }

    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    printf("Sum of digits of %d is %d\n", original, sum);
    return 0;
}
