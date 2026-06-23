#include <stdio.h>

int main(void)
{
    int n;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != 0) {
            arr[count++] = arr[i];
        }
    }

    while (count < n) {
        arr[count++] = 0;
    }

    printf("Result: ");
    for (int i = 0; i < n; ++i) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
