#include <stdio.h>

int sum(int a, int b) {
    return a + b;
}

int main(void) {
    int x, y;

    printf("Enter two integers: ");
    if (scanf("%d %d", &x, &y) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Sum of %d and %d is %d\n", x, y, sum(x, y));
    return 0;
}
