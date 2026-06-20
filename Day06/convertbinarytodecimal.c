#include <stdio.h>
#include <string.h>

int main(void)
{
    char binary[65];
    unsigned long long decimal = 0;

    if (printf("Enter a binary number: ") < 0) {
        return 1;
    }
    if (scanf("%64s", binary) != 1) {
        return 1;
    }

    for (size_t i = 0; binary[i] != '\0'; i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            printf("Invalid binary number.\n");
            return 1;
        }
        decimal = decimal * 2 + (binary[i] - '0');
    }

    printf("Decimal value: %llu\n", decimal);
    return 0;
}
