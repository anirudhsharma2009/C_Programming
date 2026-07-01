#include <stdio.h>
#include <string.h>

int main(void) {
    char s[1000];
    if (!fgets(s, sizeof s, stdin)) return 0;
    size_t n = strlen(s);
    if (n && s[n-1] == '\n') s[--n] = '\0';

    int seen[256] = {0};
    int first_repeating_index = -1;
    for (size_t i = 0; i < n; ++i) {
        unsigned char c = (unsigned char)s[i];
        if (seen[c]) { first_repeating_index = (int)i; break; }
        seen[c] = 1;
    }

    if (first_repeating_index >= 0) {
        printf("First repeating character: %c at index %d\n", s[first_repeating_index], first_repeating_index);
    } else {
        printf("No repeating character found\n");
    }
    return 0;
}
