#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1024];

    if (fgets(str, sizeof str, stdin) == NULL)
        return 0;

    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[--len] = '\0';

    for (size_t i = len; i > 0; i--)
        putchar(str[i - 1]);

    putchar('\n');
    return 0;
}
