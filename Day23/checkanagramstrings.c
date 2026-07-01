#include <stdio.h>
#include <string.h>
#include <ctype.h>

void normalize(const char *src, char *dst) {
    int j = 0;
    for (int i = 0; src[i]; i++) {
        if (!isspace((unsigned char)src[i])) {
            dst[j++] = tolower((unsigned char)src[i]);
        }
    }
    dst[j] = '\0';
}

int compare_chars(const void *a, const void *b) {
    return (*(const char *)a - *(const char *)b);
}

int main(void) {
    char s1[256], s2[256];
    char t1[256], t2[256];

    printf("Enter first string: ");
    if (!fgets(s1, sizeof(s1), stdin))
        return 0;

    printf("Enter second string: ");
    if (!fgets(s2, sizeof(s2), stdin))
        return 0;

    s1[strcspn(s1, "\n")] = '\0';
    s2[strcspn(s2, "\n")] = '\0';

    normalize(s1, t1);
    normalize(s2, t2);

    if (strlen(t1) != strlen(t2)) {
        printf("Not anagrams\n");
        return 0;
    }

    qsort(t1, strlen(t1), sizeof(char), compare_chars);
    qsort(t2, strlen(t2), sizeof(char), compare_chars);

    if (strcmp(t1, t2) == 0)
        printf("Anagrams\n");
    else
        printf("Not anagrams\n");

    return 0;
}
