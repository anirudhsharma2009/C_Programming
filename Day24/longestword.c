#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char line[1000];
    if (fgets(line, sizeof line, stdin) == NULL) {
        return 0;
    }

    char longest[1000] = "";
    char current[1000] = "";
    size_t longest_len = 0;
    size_t cur_len = 0;

    for (size_t i = 0; ; i++) {
        char c = line[i];
        if (c == '\0' || isspace((unsigned char)c)) {
            if (cur_len > 0) {
                current[cur_len] = '\0';
                if (cur_len > longest_len) {
                    longest_len = cur_len;
                    strcpy(longest, current);
                }
                cur_len = 0;
            }
            if (c == '\0') {
                break;
            }
        } else {
            if (cur_len + 1 < sizeof current) {
                current[cur_len++] = c;
            }
        }
    }

    if (longest_len > 0) {
        printf("%s\n", longest);
    } else {
        printf("No words found\n");
    }

    return 0;
}
