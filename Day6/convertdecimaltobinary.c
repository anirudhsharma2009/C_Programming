#include <stdio.h>
#include <stdlib.h>

int main(void) {
    long long n;
    if (printf("Enter a decimal integer: ") < 0) return 1;
    if (scanf("%lld", &n) != 1) return 1;

    if (n == 0) {
        printf("Binary: 0\n");
        return 0;
    }

    int negative = 0;
    unsigned long long value;
    if (n < 0) {
        negative = 1;
        value = (unsigned long long)(-n);
    } else {
        value = (unsigned long long)n;
    }

    char buf[65]; // enough for 64-bit + NUL
    buf[64] = '\0';
    int idx = 64;
    while (value > 0) {
        buf[--idx] = (value & 1) ? '1' : '0';
        value >>= 1;
    }

    if (negative) putchar('-');
    printf("Binary: %s\n", &buf[idx]);
    return 0;
}
