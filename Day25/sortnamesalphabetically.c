#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Enter number of names: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    getchar(); /* consume newline */

    char **names = malloc(n * sizeof(char*));
    if (!names) return 0;

    for (int i = 0; i < n; ++i) {
        char buf[512];
        if (!fgets(buf, sizeof(buf), stdin)) buf[0] = '\0';
        /* remove trailing newline */
        size_t len = strlen(buf);
        if (len && buf[len-1] == '\n') buf[len-1] = '\0';
        names[i] = malloc(strlen(buf) + 1);
        if (!names[i]) return 0;
        strcpy(names[i], buf);
    }

    /* simple bubble sort using strcmp */
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-1-i; ++j) {
            if (strcmp(names[j], names[j+1]) > 0) {
                char *tmp = names[j];
                names[j] = names[j+1];
                names[j+1] = tmp;
            }
        }
    }

    printf("\nSorted names:\n");
    for (int i = 0; i < n; ++i) {
        printf("%s\n", names[i]);
        free(names[i]);
    }
    free(names);
    return 0;
}
