#include <stdio.h>
#include <stdlib.h>

int lengthOfLastWord(char *s) {
	int len = 0;
	int lastLen = 0;
	while(*s != '\0') {
		if(*s == 32) {
			len = 0;
		} else {
			len++;
			lastLen = len;
		}
		s++;
	}
	return lastLen;
}

int main() {
	char * s = "Hello World";
	//char * s = "a ";
	printf("%d\n", lengthOfLastWord(s));
	return 0;
}
