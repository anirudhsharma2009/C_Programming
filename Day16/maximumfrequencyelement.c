#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

int main(void) {
    int n;
    if (printf("Enter number of elements: ") < 0) return 0;
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size\n");
        return 1;
    }

    int *a = malloc(sizeof(int) * n);
    if (!a) return 1;

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &a[i]) != 1) {
            free(a);
            printf("Invalid input\n");
            return 1;
        }
    }

    qsort(a, n, sizeof(int), cmp_int);

    int max_elem = a[0];
    int max_count = 1;
    int cur_elem = a[0];
    int cur_count = 1;

    for (int i = 1; i < n; ++i) {
        if (a[i] == cur_elem) {
            cur_count++;
        } else {
            if (cur_count > max_count) {
                max_count = cur_count;
                max_elem = cur_elem;
            }
            cur_elem = a[i];
            cur_count = 1;
        }
    }
    if (cur_count > max_count) {
        max_count = cur_count;
        max_elem = cur_elem;
    }

    printf("Element with maximum frequency: %d\nFrequency: %d\n", max_elem, max_count);

    free(a);
    return 0;
}
