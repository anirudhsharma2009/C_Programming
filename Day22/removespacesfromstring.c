#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[256];
    int i, j;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL)
        return 1;

    /* Remove trailing newline if present */
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';

    j = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';

    printf("String without spaces: %s\n", str);
    return 0;
}
