#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter the value of n (array contains numbers from 1 to n with one missing): ");
    if (scanf("%d", &n) != 1 || n <= 1) {
        printf("Invalid input. n must be greater than 1.\n");
        return 1;
    }

    int size = n - 1;
    int arr[size];

    printf("Enter %d numbers from 1 to %d with one missing:\n", size, n);
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    int expected_sum = n * (n + 1) / 2;
    int actual_sum = 0;
    for (int i = 0; i < size; i++) {
        actual_sum += arr[i];
    }

    int missing = expected_sum - actual_sum;
    printf("Missing number: %d\n", missing);

    return 0;
}
