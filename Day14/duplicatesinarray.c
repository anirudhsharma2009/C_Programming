#include <stdio.h>

int main(void)
{
    int n;
    int arr[100];
    int i, j;
    int found = 0;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 100) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Duplicate elements in the array:\n");
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                int k;
                int already_printed = 0;
                for (k = 0; k < i; k++) {
                    if (arr[k] == arr[i]) {
                        already_printed = 1;
                        break;
                    }
                }
                if (!already_printed) {
                    printf("%d\n", arr[i]);
                    found = 1;
                }
                break;
            }
        }
    }

    if (!found) {
        printf("No duplicates found\n");
    }

    return 0;
}
