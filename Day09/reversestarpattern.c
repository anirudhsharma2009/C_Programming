#include <stdio.h>

int main(void)
{
    int n, i, j;

    printf("Enter number of rows: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    for (i = n; i >= 1; --i) {
        for (j = 0; j < i; ++j) {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}
