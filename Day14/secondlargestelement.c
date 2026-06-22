#include <stdio.h>
#include <limits.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1 || n <= 1) {
        printf("Enter a count greater than 1\n");
        return 1;
    }

    int largest = INT_MIN;
    int second = INT_MIN;
    for (int i = 0; i < n; i++) {
        int value;
        if (scanf("%d", &value) != 1) {
            printf("Invalid input\n");
            return 1;
        }
        if (value > largest) {
            second = largest;
            largest = value;
        } else if (value > second && value < largest) {
            second = value;
        }
    }

    if (second == INT_MIN) {
        printf("No second largest element\n");
    } else {
        printf("Second largest element: %d\n", second);
    }

    return 0;
}
