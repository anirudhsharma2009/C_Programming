#include <stdio.h>

int isPerfect(int n)
{
    if (n <= 1)
        return 0;

    int sum = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            int j = n / i;
            if (j != i)
                sum += j;
        }
    }

    return sum == n;
}

int main(void)
{
    int num;

    printf("Enter a number: ");
    if (scanf("%d", &num) != 1)
        return 0;

    if (isPerfect(num))
        printf("%d is a perfect number.\n", num);
    else
        printf("%d is not a perfect number.\n", num);

    return 0;
}
