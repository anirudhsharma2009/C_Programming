
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	if (a == 0) return b;
	if (b == 0) return a;
	while (b != 0) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main(void) {
	long x, y;
	printf("Enter two integers: ");
	if (scanf("%ld %ld", &x, &y) != 2) {
		fprintf(stderr, "Invalid input\n");
		return 1;
	}
	int result = gcd((int)x, (int)y);
	printf("GCD(%ld, %ld) = %d\n", x, y, result);
	return 0;
}
