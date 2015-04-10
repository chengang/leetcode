#include <stdio.h>
#include <stdlib.h>

int climbStairs(int n) {
	if ( n == 1 )
		return 1;
	if ( n == 2 )
		return 2;

	int deTwo = 1;
	int deOne = 2;
	int result;

	int i;
	for(i=3;i<=n;i++) {
		result = deTwo + deOne;

		int tmp;
		tmp = deOne;
		deOne = result;
		deTwo = tmp;
	}
	return result;
}

int main() {
	printf("%d\n", climbStairs(16));

	return 0;
}
