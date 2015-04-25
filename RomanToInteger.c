#include <stdio.h>
#include <stdlib.h>

int charToInt(char c) {
	if( c == 'I' )
		return 1;
	else if ( c == 'V' )
		return 5;
	else if ( c == 'X' )
		return 10;
	else if ( c == 'L' )
		return 50;
	else if ( c == 'C' )
		return 100;
	else if ( c == 'D' )
		return 500;
	else if ( c == 'M' )
		return 1000;
	return 0;
}

int isAllowLeft(char c) {
	if (c == 'I' || c == 'X' || c == 'C')
		return 1;
	return 0;
}

int isBigNumber(char left, char right) {
	if ( left== 'I' && ( right == 'V' || right == 'X') )
		return 1;
	if ( left== 'X' && ( right == 'L' || right == 'C') )
		return 1;
	if ( left== 'C' && ( right == 'D' || right == 'M') )
		return 1;
	return 0;
}

int romanToInt(char* s) {
	int result = 0;
	
	while( *s != '\0') {
		//printf(" %c %c : ", *s, *(s+1));
		if(isAllowLeft(*s) && isBigNumber(*s, *(s+1))) {
			//printf("-%d\n", charToInt(*s));
			result = result - charToInt(*s);
		} else {
			//printf("+%d\n", charToInt(*s));
			result = result + charToInt(*s);
		}
		s++;
	}
	return result;
}

int main () {
	char * s = "MCMXCVI";
	printf("%s = %d\n", s, romanToInt(s));
	return 0;
}
