#include <stdio.h>

int main(void)
{
    int rows, i, j;

    printf("Enter number of rows: ");
    if (scanf("%d", &rows) != 1 || rows <= 0) {
        return 0;
    }

    for (i = 1; i <= rows; i++) {
        for (j = 0; j < rows - i; j++) {
            putchar(' ');
        }
        for (j = 0; j < 2 * i - 1; j++) {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}
