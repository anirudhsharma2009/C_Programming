#include <stdio.h>

int main(void)
{
    int rows;
    char ch;

    printf("Enter character: ");
    if (scanf(" %c", &ch) != 1)
        return 1;

    printf("Enter number of rows: ");
    if (scanf("%d", &rows) != 1 || rows <= 0)
        return 1;

    for (int i = 1; i <= rows; ++i)
    {
        for (int j = 0; j < i; ++j)
            putchar(ch);
        putchar('\n');
    }

    return 0;
}
