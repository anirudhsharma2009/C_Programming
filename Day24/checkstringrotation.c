#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isRotation(const char *s1, const char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 != len2)
        return 0;

    if (len1 == 0)
        return 1;

    char *concat = malloc(len1 * 2 + 1);
    if (!concat)
        return 0;

    strcpy(concat, s1);
    strcat(concat, s1);

    int result = strstr(concat, s2) != NULL;
    free(concat);
    return result;
}

static void trimNewline(char *s)
{
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n')
        s[len - 1] = '\0';
}

int main(void)
{
    char s1[256];
    char s2[256];

    printf("Enter first string: ");
    if (!fgets(s1, sizeof(s1), stdin))
        return 1;
    printf("Enter second string: ");
    if (!fgets(s2, sizeof(s2), stdin))
        return 1;

    trimNewline(s1);
    trimNewline(s2);

    if (isRotation(s1, s2))
        printf("The second string is a rotation of the first.\n");
    else
        printf("The second string is not a rotation of the first.\n");

    return 0;
}
