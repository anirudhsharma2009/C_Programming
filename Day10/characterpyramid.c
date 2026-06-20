#include <stdio.h>

int main(void)
{
    int rows = 5;
    char ch = 'A';

    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= rows - i; ++j) {
            putchar(' ');
        }

        char current = ch;
        for (int j = 1; j <= i; ++j) {
            putchar(current);
            current++;
        }

        current -= 2;
        for (int j = 1; j < i; ++j) {
            putchar(current);
            current--;
        }

        putchar('\n');
    }

    return 0;
}
