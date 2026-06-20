#include <stdio.h>

int main(void)
{
    int n, i, j;

    if (scanf("%d", &n) != 1 || n <= 0)
        return 0;

    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= n; ++j) {
            if (i == 1 || i == n || j == 1 || j == n)
                putchar('*');
            else
                putchar(' ');
        }
        putchar('\n');
    }

    return 0;
}
