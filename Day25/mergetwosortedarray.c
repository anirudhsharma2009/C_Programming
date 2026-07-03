// Program to merge two sorted arrays
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    if (n < 0 || m < 0) return 0;

    int *a = malloc(n * sizeof(int));
    int *b = malloc(m * sizeof(int));
    if (!a || !b) return 0;

    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) scanf("%d", &b[i]);

    int *c = malloc((n + m) * sizeof(int));
    if (!c) return 0;

    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j]) c[k++] = a[i++];
        else c[k++] = b[j++];
    }
    while (i < n) c[k++] = a[i++];
    while (j < m) c[k++] = b[j++];

    for (int t = 0; t < n + m; ++t) {
        if (t) putchar(' ');
        printf("%d", c[t]);
    }
    putchar('\n');

    free(a); free(b); free(c);
    return 0;
}
