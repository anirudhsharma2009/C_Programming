#include <stdio.h>

int main(void)
{
    int r1, c1, r2, c2;

    printf("Enter rows and columns of first matrix: ");
    if (scanf("%d %d", &r1, &c1) != 2) {
        return 1;
    }

    printf("Enter rows and columns of second matrix: ");
    if (scanf("%d %d", &r2, &c2) != 2) {
        return 1;
    }

    if (c1 != r2) {
        printf("Matrix multiplication not possible\n");
        return 0;
    }

    int a[r1][c1];
    int b[r2][c2];
    int result[r1][c2];

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("Result matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
