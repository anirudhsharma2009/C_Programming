#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, m;
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    int *a = malloc(n * sizeof(int));
    if (!a) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    if (scanf("%d", &m) != 1 || m <= 0) {
        free(a);
        return 0;
    }

    int *b = malloc(m * sizeof(int));
    if (!b) {
        free(a);
        return 1;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    int size = n < m ? n : m;
    int *intersection = malloc(size * sizeof(int));
    if (!intersection) {
        free(a);
        free(b);
        return 1;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                int exists = 0;
                for (int k = 0; k < count; k++) {
                    if (intersection[k] == a[i]) {
                        exists = 1;
                        break;
                    }
                }
                if (!exists) {
                    intersection[count++] = a[i];
                }
                break;
            }
        }
    }

    if (count == 0) {
        printf("No intersection\n");
    } else {
        for (int i = 0; i < count; i++) {
            printf("%d", intersection[i]);
            if (i + 1 < count) {
                printf(" ");
            }
        }
        printf("\n");
    }

    free(a);
    free(b);
    free(intersection);
    return 0;
}
