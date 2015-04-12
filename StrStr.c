#include <stdio.h>
#include <stdlib.h>

int strLen(char *s) {
	int i = 0;
	while(*s != '\0') {
		s++;
		i++;
	}
	return i;
}

int strStr(char *haystack, char *needle) {
	if(*needle == '\0')
		return 0;

	int result = 1;
	int lenHaystack = strLen(haystack);
	int lenNeedle = strLen(needle);

	int ptrHaystack = 0;

	while(*(haystack + ptrHaystack) != '\0') {
		if(lenHaystack - ptrHaystack < lenNeedle)
			break;

		if(*(haystack + ptrHaystack) != *needle) {
			ptrHaystack++;
			continue;
		}

		int ptrNeedle = 0;
		int isEq = 1;
		while(*(needle + ptrNeedle) != '\0') {
			if(*(needle + ptrNeedle) != *(haystack + ptrHaystack + ptrNeedle)) 
				isEq = 0;
			ptrNeedle++;
		}

		if(isEq) 
			return ptrHaystack;

		ptrHaystack++;
	}
	return -1;
}

int main() {
	//int index = strStr("mississippi", "issip");
	int index = strStr("mississippi", "issip");
	printf("%d\n", index);
	return 0;
}
