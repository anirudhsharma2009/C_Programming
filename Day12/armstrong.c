#include <stdio.h>

int power(int base, int exp)
{
    int result = 1;
    while (exp > 0) {
        result *= base;
        exp--;
    }
    return result;
}

int isArmstrong(int n)
{
    int original = n;
    int sum = 0;
    int digits = 0;
    int temp = n;

    if (n == 0) {
        return 1;
    }

    while (temp > 0) {
        digits++;
        temp /= 10;
    }
    temp = n;

    while (temp > 0) {
        int digit = temp % 10;
        sum += power(digit, digits);
        temp /= 10;
    }

    return sum == original;
}

int main(void)
{
    int number;

    if (printf("Enter a number: ") < 0) {
        return 1;
    }
    if (scanf("%d", &number) != 1) {
        return 1;
    }

    if (isArmstrong(number)) {
        printf("%d is an Armstrong number.\n", number);
    } else {
        printf("%d is not an Armstrong number.\n", number);
    }

    return 0;
}
