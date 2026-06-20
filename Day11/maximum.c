#include <stdio.h>

int maximum(int a, int b, int c)
{
    int max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;
    return max;
}

int main(void)
{
    int x, y, z;

    printf("Enter three integers: ");
    if (scanf("%d %d %d", &x, &y, &z) != 3) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Maximum: %d\n", maximum(x, y, z));
    return 0;
}
