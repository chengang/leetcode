#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

int numLen(int x) {
	int i = 1;
	while(x / 10 >= 1) {
		x /= 10;
		i++;
	}
	return i;
}

int tenPower(int x) {
	int result = 1;
	while( x > 0 ) {
		result *= 10;
		x--;
	}
	return result;
}

int getDigital(int num, int pos) {
	if ( pos < 0 )
		return num;

	while(pos) {
		num = num / 10;
		pos--;
	}
	return num % 10;
}

bool isPalindrome(int x) {
	if( x < 0 ) 
		return false;

	int len = numLen(x);
	int i;
	for(i=0;i<=len/2;i++) {
		int highDigital = getDigital(x, len - i - 1);
		int lowDigital = getDigital(x, i);
		if( highDigital != lowDigital )
			return false;
	}
	
	return true;
}

int main() {
	if(isPalindrome(-2147447412)) {
		printf("true\n");
	} else {
		printf("false\n");
	}
	return 0;
}
