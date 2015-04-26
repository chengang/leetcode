#include <stdio.h>
#include <stdlib.h>

int myAtoi(char* str) {
	int start = 0;
	int end = 0;
	int negative = 0;
	unsigned long long result = 0;

	while(*str != '\0') {
		if( *str >= 'a' && *str <= 'z' ) 
			break;
		if(start == 1 && (*str < '0' || *str > '9'))
			break;

		if(*str == '+' && *(str+1) == '-')
			return 0;

		if(*str == '+' || *str == '-' || (*str > '0' && *str < '9'))
			start = 1;

		if(*str == '-') 
			negative = 1;

		if (start && *str != '-' && *str != '+') {
			result = result * 10 + *str - '0';
		}
		str++;

		if(result > 2147483648)
			break;
	}

	if(!start)
		return 0;

	if(!negative && result > 2147483647)
		return 2147483647;

	if(negative && result > 2147483648)
		return -2147483648;

	if(negative)
		return -result;

	return result;
}

int main() {
	printf("%d\n", myAtoi("      -11919730356x"));
	return 0;
}
