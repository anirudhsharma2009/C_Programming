#include <stdio.h>

int main(void)
{
    unsigned int n;
    unsigned int count = 0;

    printf("Enter a number: ");
    if (scanf("%u", &n) != 1) {
        return 1;
    }

    while (n) {
        count += n & 1u;
        n >>= 1;
    }

    printf("Number of set bits: %u\n", count);
    return 0;
}
