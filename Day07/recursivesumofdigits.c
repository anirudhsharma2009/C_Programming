
#include <stdio.h>
#include <stdlib.h>

int recursive_sum_of_digits(int n) {
	if (n < 0) n = -n;
	if (n < 10) return n;
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return recursive_sum_of_digits(sum);
}

int main(void) {
	long long x;
	if (printf("Enter an integer: ") < 0) return 1;
	if (scanf("%lld", &x) != 1) return 1;
	int result = recursive_sum_of_digits((int)x);
	printf("Recursive sum of digits: %d\n", result);
	return 0;
}
