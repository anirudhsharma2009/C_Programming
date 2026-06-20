#include <stdio.h>

int main(void)
{
    int number, original, reversed = 0, remainder;

    printf("Enter an integer: ");
    if (scanf("%d", &number) != 1) {
        return 1;
    }

    original = number;

    while (number != 0) {
        remainder = number % 10;
        reversed = reversed * 10 + remainder;
        number /= 10;
    }

    if (original == reversed) {
        printf("%d is a palindrome.\n", original);
    } else {
        printf("%d is not a palindrome.\n", original);
    }

    return 0;
}
