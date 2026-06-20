#include <stdio.h>
#include <math.h>

int countDigits(int n) {
    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

int power(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        result *= base;
        exp--;
    }
    return result;
}

int isArmstrong(int num) {
    int original = num;
    int digits = countDigits(num);
    int sum = 0;

    while (num > 0) {
        int digit = num % 10;
        sum += power(digit, digits);
        num /= 10;
    }

    return sum == original;
}

int main(void) {
    int start, end;

    printf("Enter the range start: ");
    if (scanf("%d", &start) != 1) {
        return 1;
    }

    printf("Enter the range end: ");
    if (scanf("%d", &end) != 1) {
        return 1;
    }

    if (start > end) {
        int temp = start;
        start = end;
        end = temp;
    }

    printf("Armstrong numbers between %d and %d:\n", start, end);
    for (int i = start; i <= end; i++) {
        if (i >= 0 && isArmstrong(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}
