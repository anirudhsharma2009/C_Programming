#include <stdio.h>

int main(void)
{
    int rows, cols;
    int i, j;

    printf("Enter number of rows: ");
    if (scanf("%d", &rows) != 1 || rows <= 0) {
        printf("Invalid number of rows.\n");
        return 1;
    }

    printf("Enter number of columns: ");
    if (scanf("%d", &cols) != 1 || cols <= 0) {
        printf("Invalid number of columns.\n");
        return 1;
    }

    int a[rows][cols];
    int b[rows][cols];
    int c[rows][cols];

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("b[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }

    printf("Result of matrix subtraction (A - B):\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
