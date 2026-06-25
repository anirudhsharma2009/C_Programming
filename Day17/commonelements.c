#include <stdio.h>

int main(void)
{
    int n1, n2, i, j;

    printf("Enter size of first array: ");
    if (scanf("%d", &n1) != 1 || n1 <= 0) {
        return 0;
    }

    int arr1[n1];
    printf("Enter %d elements of first array:\n", n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of second array: ");
    if (scanf("%d", &n2) != 1 || n2 <= 0) {
        return 0;
    }

    int arr2[n2];
    printf("Enter %d elements of second array:\n", n2);
    for (j = 0; j < n2; j++) {
        scanf("%d", &arr2[j]);
    }

    printf("Common elements:\n");
    int found = 0;

    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                int duplicate = 0;
                for (int k = 0; k < i; k++) {
                    if (arr1[k] == arr1[i]) {
                        duplicate = 1;
                        break;
                    }
                }
                if (!duplicate) {
                    printf("%d ", arr1[i]);
                    found = 1;
                }
                break;
            }
        }
    }

    if (!found) {
        printf("None");
    }
    printf("\n");

    return 0;
}
