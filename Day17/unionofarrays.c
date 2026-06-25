#include <stdio.h>

int main(void)
{
    int n, m;
    int a[100], b[100], u[200];
    int len = 0;

    printf("Enter size of first array: ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 100) {
        return 1;
    }

    printf("Enter elements of first array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter size of second array: ");
    if (scanf("%d", &m) != 1 || m < 0 || m > 100) {
        return 1;
    }

    printf("Enter elements of second array:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < len; j++) {
            if (u[j] == a[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            u[len++] = a[i];
        }
    }

    for (int i = 0; i < m; i++) {
        int found = 0;
        for (int j = 0; j < len; j++) {
            if (u[j] == b[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            u[len++] = b[i];
        }
    }

    printf("Union of arrays:\n");
    for (int i = 0; i < len; i++) {
        printf("%d ", u[i]);
    }
    printf("\n");

    return 0;
}
