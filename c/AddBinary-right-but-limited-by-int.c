#include <stdio.h>
#include <stdlib.h>

int strLen ( char *str) {
	int i = 0;
	while(*(str+i) != '\0') {
		i++;
	}
	return i;
}

int mypow ( int di, int mi) {
	int result = 1;
	for(mi=mi;mi>0;mi--) {
		result = result * di;
	}
	return result;
}

int str2int ( char *str) {
	int len = strLen(str);
	int i = 0;
	int result = 0;
	for (len=len-1;len>=0;len--) {
		result += ( *(str+len) - '0' ) * mypow(2, i); 
		i++;
	}
	return result;
}

char * int2str (int n) {
	int resultLen = 0;
	int n2 = n;
	while(n2 != 0) {
		n2 = n2 / 2;
		resultLen++;
	}

	char * result = calloc(1, resultLen);
	for(resultLen=resultLen; resultLen>=0; resultLen-- ) {
		result[resultLen-1] = (n % 2) + '0';
		n = n / 2;
	}

	//int intResult;
	//sscanf(result, "%d", &intResult);
	//sprintf(result, "%d", intResult);
	return result;
}

char * addBinary(char *a, char *b) {
	int sum = str2int(a) + str2int(b);
	return int2str(sum);
}

int main () {
	char * a = "11110011";
	char * b = "111001011";

	//printf("%d\n", mypow(2, 4));
	//printf("%d\n", strLen(a));
	//printf("%d\n", str2int(a));
	printf("%s\n", addBinary(a, b));

	return 0;
}
