#include <stdio.h>

int main(void) {
    char ch;

    printf("Enter a lowercase character: ");
    scanf("%c", &ch);

    if (ch >= 'a' && ch <= 'z') {
        ch = ch - ('a' - 'A');
    }

    printf("Uppercase character: %c\n", ch);
    return 0;
}
