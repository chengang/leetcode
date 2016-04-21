#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int strLen(char *s) {
	int i = 0;
	while(*s != '\0') {
		s++;
		i++;
	}
	return i;
}

char char2low(char c) {
	if(c >= 65 && c <= 90) {
		return c + 32;
	}
	return c;
}

bool ifAlphanumeric(char c) {
	if( (c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122) ) {
		return true;
	}
	return false;
}

bool isPalindrome(char *s) {
	if(*s == '\0') {
		return true;
	}

	int ptrFront = 0;
	int ptrAfter = strLen(s) - 1;

	printf("Front: %d, After: %d\n", ptrFront, ptrAfter);

	while(ptrAfter - ptrFront >=1 ) {
		char cFront = *(s+ptrFront);
		char cAfter = *(s+ptrAfter);
		if( !ifAlphanumeric(cFront) ) {
			ptrFront++;
			continue;
		}
		if( !ifAlphanumeric(cAfter) ) {
			ptrAfter--;
			continue;
		}
		char front = char2low( *(s+ptrFront));
		char after = char2low( *(s+ptrAfter));
		printf("[%c]=[%c]\n", front, after);
		if(front != after) {
			return false;
		}
		ptrFront++;
		ptrAfter--;
	}
	return true;
}

int main() {
	char *s = ".,";
	if(isPalindrome(s))
		printf("true\n");
	else
		printf("false\n");
	return 0;
}
