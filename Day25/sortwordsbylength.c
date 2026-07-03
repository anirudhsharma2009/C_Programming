#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_len(const void *a, const void *b) {
    const char *const *pa = a;
    const char *const *pb = b;
    size_t la = strlen(*pa);
    size_t lb = strlen(*pb);
    if (la < lb) return -1;
    if (la > lb) return 1;
    return strcmp(*pa, *pb); // tie-breaker: lexicographic
}

int main(void) {
    char line[10000];
    if (!fgets(line, sizeof line, stdin)) return 0;

    // Tokenize on whitespace
    char *words[1000];
    int count = 0;
    char *p = strtok(line, " \t\r\n");
    while (p && count < (int)(sizeof words / sizeof words[0])) {
        words[count++] = strdup(p);
        p = strtok(NULL, " \t\r\n");
    }

    if (count == 0) return 0;

    qsort(words, count, sizeof words[0], cmp_len);

    for (int i = 0; i < count; ++i) {
        if (i) putchar(' ');
        fputs(words[i], stdout);
        free(words[i]);
    }
    putchar('\n');
    return 0;
}
