#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main(void)
{
    int num;
    printf("Enter a number: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (isPrime(num))
        printf("%d is prime.\n", num);
    else
        printf("%d is not prime.\n", num);

    return 0;
}
