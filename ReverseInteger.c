#include <stdio.h>
#include <stdlib.h>

int reverse(int a) {
	int negative = 1;
	unsigned long long x;
	if(a < 0) {
		negative = -1;
		x = 0 - a;
	} else {
		x = a;
	}

	long long result = 0;
	while(x) {
		//printf("%lld\n", result);
		result = result * 10 + (x % 10);
		x /= 10;

		if(!negative && result > 2147483647)
			return 0;
		if(negative && result > 2147483648)
			return 0;
	}
	return result * negative;
}

int main() {
	printf("%d\n", reverse(-2147483648));
	printf("%d\n", reverse(-123));
	return 0;
}
