#include <stdio.h>

int factorial(int n) {
    int f = 1;
    for (int i = 2; i <= n; ++i) f *= i;
    return f;
}

int main(void) {
    long num, temp;
    int digit;
    long sum = 0;

    printf("Enter a positive integer: ");
    if (scanf("%ld", &num) != 1) return 0;
    if (num < 0) num = -num;

    temp = num;
    if (temp == 0) sum = factorial(0);
    while (temp > 0) {
        digit = temp % 10;
        sum += factorial(digit);
        temp /= 10;
    }

    if (sum == num)
        printf("%ld is a Strong number.\n", num);
    else
        printf("%ld is not a Strong number.\n", num);

    return 0;
}
