#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, d;
    if (scanf("%d", &n) != 1) return 0;
    if (n <= 0) return 0;
    int *a = malloc(n * sizeof(int));
    if (!a) return 0;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    if (scanf("%d", &d) != 1) d = 1;
    d = d % n;
    if (d < 0) d += n;

    // print array rotated left by d
    for (int i = 0; i < n; ++i) {
        if (i) printf(" ");
        printf("%d", a[(i + d) % n]);
    }
    printf("\n");

    free(a);
    return 0;
}
