#include <stdio.h>

int main(void)
{
    int rows, cols;
    if (scanf("%d %d", &rows, &cols) != 2)
        return 0;

    int matrix[100][100];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int j = 0; j < cols; j++) {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            sum += matrix[i][j];
        }
        printf("%d", sum);
        if (j < cols - 1)
            printf(" ");
    }
    printf("\n");

    return 0;
}
