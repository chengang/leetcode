#include <stdio.h>
#include <stdlib.h>

int strLen ( char *str) {
	int i = 0;
	while(*(str+i) != '\0') {
		i++;
	}
	return i;
}

int max (int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

char * addBinary(char *a, char *b) {
	int ptrA = strLen(a) - 1;
	int ptrB = strLen(b) - 1;
	char reg = '0';
	int resultLen = 0;
	int resultLenMax = max(ptrA, ptrB) + 1 + 1 + 1;
	char * resultReserve = calloc(resultLenMax, 1);
	while(1) {
		if (ptrA < 0 && ptrB < 0 && reg == '0')
			break;
		else if (ptrA < 0 && ptrB < 0 && reg != '0') {
			resultReserve[resultLen] = '1';
			resultLen++;
			break;
		}

		char tmpA;
		char tmpB;
		char tmpRes;

		if(ptrA >= 0) {
			tmpA = a[ptrA];
			ptrA--;
		} else {
			tmpA = '0';
		}

		if(ptrB >= 0) {
			tmpB = b[ptrB];
			ptrB--;
		} else {
			tmpB = '0';
		}

		if (tmpA == '0' && tmpB == '0' && reg == '0') {
			tmpRes = '0';
			reg = '0';
		} else if (tmpA == '1' && tmpB == '0' && reg == '0') {
			tmpRes = '1';
			reg = '0';
		} else if (tmpA == '0' && tmpB == '1' && reg == '0') {
			tmpRes = '1';
			reg = '0';
		} else if (tmpA == '1' && tmpB == '1' && reg == '0') {
			tmpRes = '0';
			reg = '1';
		} else if (tmpA == '0' && tmpB == '0' && reg == '1') {
			tmpRes = '1';
			reg = '0';
		} else if (tmpA == '1' && tmpB == '0' && reg == '1') {
			tmpRes = '0';
			reg = '1';
		} else if (tmpA == '0' && tmpB == '1' && reg == '1') {
			tmpRes = '0';
			reg = '1';
		} else if (tmpA == '1' && tmpB == '1' && reg == '1') {
			tmpRes = '1';
			reg = '1';
		}
		resultReserve[resultLen] = tmpRes;
		resultLen++;
	}
	resultReserve[resultLen] = '\0';

	//printf("%d %d %s %d\n", resultLen, resultLenMax, resultReserve, strLen(resultReserve));
	char * result = calloc(resultLen + 1, 1);
	int i;
	for(i=0;i<resultLen;i++) {
		result[i] = resultReserve[resultLen - 1 - i];
	}
	result[resultLen] = '\0';
	free(resultReserve);
	return result;
}

int main () {
	//char * a = "11110011001011110111110001010000111110011110101100011111010010001000001101111001000111";
	//char * b = "111001011011111010001001111001100000101010000101100010101100010010010011011000";
	
	//char * a = "111";
	//char * b = "1";
	
	//char * a = "0";
	//char * b = "0";
	
	//char * a = "1111011001010001111100100011101110011101100101110011001000110000111001010010100";
	//char * b = "1101001000101110000000001001001111011111000111101101100000110001110101000011001101111100";

	char * a = "1011111111110101010111111100100100011101000010001010001";
	char * b = "1110101001110001001111100010001101011111110111011000101";

	//printf("%d\n", strLen(a));
	printf("%s\n", addBinary(a, b));

	return 0;
}
