#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    int a[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int m = 0;
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < m; j++) {
            if (a[i] == a[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            a[m++] = a[i];
        }
    }

    printf("Array after removing duplicates:\n");
    for (int i = 0; i < m; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
