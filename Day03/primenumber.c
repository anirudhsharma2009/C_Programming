
#include <stdio.h>
#include <math.h>

int is_prime(long n) {
	if (n <= 1) return 0;
	if (n <= 3) return 1;
	if (n % 2 == 0) return 0;
	long r = (long)sqrt((double)n);
	for (long i = 3; i <= r; i += 2) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main(void) {
	long n;
	if (printf("Enter an integer: "), fflush(stdout), scanf("%ld", &n) != 1) return 1;
	if (is_prime(n))
		printf("%ld is a prime number.\n", n);
	else
		printf("%ld is not a prime number.\n", n);
	return 0;
}
