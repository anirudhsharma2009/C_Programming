#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i, key, found = 0;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0)
        return 0;

    int *arr = malloc(n * sizeof *arr);
    if (arr == NULL)
        return 0;

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter key to search: ");
    if (scanf("%d", &key) != 1) {
        free(arr);
        return 0;
    }

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Key found at index %d.\n", i);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Key not found.\n");

    free(arr);
    return 0;
}
