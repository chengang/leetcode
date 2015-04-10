#include <stdio.h>
#include <stdlib.h>

int forNTwoSteps(int stairs, int n) {
	if ( n == 1)
		return stairs - 1;

	int result = 0;
	for(stairs = stairs; stairs >= 4; stairs--) {
		result += forNTwoSteps(stairs - 2, n - 1);
	}
	return result;
}

int climbStairs(int n) {
	int result = 1;
	int twoStepTimes;

	for(twoStepTimes = 0; twoStepTimes <= n/2; twoStepTimes++) {
		result += forNTwoSteps(n, twoStepTimes);
	}
	return result;
}

int main() {
	//printf("[%d]\n", forNTwoSteps(6,2));
	printf("%d\n", climbStairs(16));

	return 0;
}
