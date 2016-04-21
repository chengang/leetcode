#include <stdio.h>
#include <stdlib.h>

char * onePass(char * str) {
	char * result = calloc(10240, sizeof(char));
	char c = *str;
	int len = 0;
	int resultLen = 0;
	while(*str != '\0') {
		if(*str != c) {
			result[resultLen] = len + '0';
			resultLen++;
			result[resultLen] = c;
			resultLen++;

			len = 1;
			c = *str;
		} else {
			len++;
		}
		str++;
	}
	result[resultLen] = len + '0';
	resultLen++;
	result[resultLen] = c;
	resultLen++;
	result[resultLen] = '\0';

	return result;
}

char *countAndSay(int n) {
	char * ping = calloc(1, sizeof(char));
	*ping = '1';
	char * pong;

	int i;
	for(i=0;i<n-1;i++) {
		pong = onePass(ping);
		free(ping);
		ping = pong;
	}

	return ping;
}

int main() {
	printf("%s\n", onePass("111221"));
	printf("%s\n", countAndSay(30));
	return 0;
}
