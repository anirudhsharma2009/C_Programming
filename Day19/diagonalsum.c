#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter matrix size: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    int matrix[n][n];
    printf("Enter %d elements:\n", n * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int mainSum = 0;
    int secondarySum = 0;
    for (int i = 0; i < n; i++) {
        mainSum += matrix[i][i];
        secondarySum += matrix[i][n - 1 - i];
    }

    printf("Main diagonal sum: %d\n", mainSum);
    printf("Secondary diagonal sum: %d\n", secondarySum);
    printf("Total diagonal sum: %d\n", mainSum + secondarySum);

    return 0;
}
