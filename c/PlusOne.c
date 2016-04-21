#include <stdio.h>
#include <stdlib.h>

void print_r(int *arr, int len) {
	int i;
	for(i=0;i<len;i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}


int *plusOne(int *digits, int len, int *newLen) {
	int * resultReverse = calloc(len + 1, sizeof(int));
	int reg = 1;
	int i;
	int resultLen = 0;
	for(i = len - 1;i >= 0; i--) {
		int digit = digits[i];
		int add = reg + digit;
		//printf("%d = %d + %d\n", add, reg, digit);
		if (add > 9) {
			resultReverse[resultLen] = add % 10;
			reg = 1;
		} else {
			resultReverse[resultLen] = add;
			reg = 0;
		}
		resultLen++;
	}

	if(reg == 1) {
		resultReverse[resultLen] = 1;
		reg = 0;
		resultLen++;
	}

	*newLen = resultLen;
	int * result = calloc(resultLen, sizeof(int));
	for(i=0;i<resultLen;i++) {
		result[i] = resultReverse[resultLen - 1 - i];
	}
	free(resultReverse);
	return result;
}

int main() {
	//int digits[] = {9, 8, 7, 6};
	int digits[] = {0};
	print_r(plusOne(digits,1,digits), 1);
	return 0;
}
