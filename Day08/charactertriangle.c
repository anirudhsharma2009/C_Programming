#include <stdio.h>

int main(void)
{
    char ch = 'A';
    int rows = 5;

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%c ", ch);
            ch++;
            if (ch > 'Z') {
                ch = 'A';
            }
        }
        printf("\n");
    }

    return 0;
}
