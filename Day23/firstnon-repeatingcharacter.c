#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1000];

    if (fgets(str, sizeof str, stdin) == NULL)
        return 0;

    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[--len] = '\0';
    }

    int freq[256] = {0};
    for (size_t i = 0; i < len; ++i) {
        freq[(unsigned char)str[i]]++;
    }

    int first_non_repeating = -1;
    for (size_t i = 0; i < len; ++i) {
        if (freq[(unsigned char)str[i]] == 1) {
            first_non_repeating = (unsigned char)str[i];
            break;
        }
    }

    if (first_non_repeating != -1) {
        printf("%c\n", first_non_repeating);
    } else {
        printf("No non-repeating character\n");
    }

    return 0;
}
