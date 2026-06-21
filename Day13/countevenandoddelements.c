#include <stdio.h>

int main(void)
{
    int n;
    int count_even = 0;
    int count_odd = 0;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    int value;
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        if (scanf("%d", &value) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
        if (value % 2 == 0) {
            count_even++;
        } else {
            count_odd++;
        }
    }

    printf("Even elements: %d\n", count_even);
    printf("Odd elements: %d\n", count_odd);

    return 0;
}
