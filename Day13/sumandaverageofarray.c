#include <stdio.h>

int main(void)
{
    int n;
    double sum = 0.0;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    double arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        if (scanf("%lf", &arr[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
        sum += arr[i];
    }

    printf("Sum = %.2f\n", sum);
    printf("Average = %.2f\n", sum / n);

    return 0;
}
