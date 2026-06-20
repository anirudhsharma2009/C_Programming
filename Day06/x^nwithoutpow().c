#include <stdio.h>

int main(void)
{
    double x;
    int n;
    double result = 1.0;
    int i;

    printf("Enter x and n: ");
    if (scanf("%lf %d", &x, &n) != 2) {
        return 1;
    }

    if (n >= 0) {
        for (i = 0; i < n; ++i) {
            result *= x;
        }
    } else {
        for (i = 0; i < -n; ++i) {
            result *= x;
        }
        if (result != 0.0) {
            result = 1.0 / result;
        }
    }

    printf("%.6g^%d = %.6g\n", x, n, result);
    return 0;
}
