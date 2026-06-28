#include <stdio.h>

#define MAX 100

int main() {
    int n, i, j;
    int matrix[MAX][MAX];
    int isSymmetric = 1;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    printf("Enter the matrix elements:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check if matrix is symmetric
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if (!isSymmetric) {
            break;
        }
    }

    if (isSymmetric) {
        printf("The matrix is SYMMETRIC\n");
    } else {
        printf("The matrix is NOT SYMMETRIC\n");
    }

    return 0;
}
