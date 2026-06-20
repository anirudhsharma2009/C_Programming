#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main(void) {
    int start, end;

    printf("Enter the start of the range: ");
    if (scanf("%d", &start) != 1) return 1;
    printf("Enter the end of the range: ");
    if (scanf("%d", &end) != 1) return 1;

    if (start > end) {
        int temp = start;
        start = end;
        end = temp;
    }

    printf("Prime numbers between %d and %d:\n", start, end);
    for (int n = start; n <= end; n++) {
        if (is_prime(n)) {
            printf("%d\n", n);
        }
    }

    return 0;
}
