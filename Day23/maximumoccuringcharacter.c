#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1000];

    if (fgets(str, sizeof(str), stdin) == NULL)
        return 0;

    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[--len] = '\0';

    int freq[256] = {0};
    for (size_t i = 0; i < len; i++) {
        unsigned char c = (unsigned char)str[i];
        freq[c]++;
    }

    int max = 0;
    unsigned char ch = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > max) {
            max = freq[i];
            ch = (unsigned char)i;
        }
    }

    if (max > 0)
        printf("%c\n", ch);

    return 0;
}
