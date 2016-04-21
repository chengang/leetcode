#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int my_strlen(char *s) {
	int i = 0;
	while(*s != '\0') {
		s++;
		i++;
	}
	return i;
}

bool isPairChar(char a, char b) {
	if(a == ')' && b == '(') 
		return true;
	if(a == ']' && b == '[') 
		return true;
	if(a == '}' && b == '{') 
		return true;

	return false;
}

bool isStartChar(char c) {
	if(c == '(' || c == '[' || c == '{') 
		return true;

	return false;
}

bool isValid(char *s) {
	int len = my_strlen(s);
	if(len == 0)
		return true;
	if(len == 1)
		return false;

	char * stack = calloc(len, sizeof(char));
	int ptrStack = 0;
	stack[ptrStack] = *s;
	s++;
	ptrStack++;

	while(*s != '\0') {
		//printf("%c : %c ", *s, stack[ptrStack-1]);
		if (isStartChar(*s)) {
		//printf("case 1");
			stack[ptrStack] = *s;
			ptrStack++;
		} else if (isPairChar(*s, stack[ptrStack-1])) {
		//printf("case 2");
			ptrStack--;
		} else {
		//printf("case 3");
			return false;
		}
		s++;
		//printf("\n");
	}

	if (ptrStack == 0)
		return true;
	else 
		return false;
}

int main() {
	//char *s = "{}{()[()]}";
	char *s = "(()";
	if(isValid(s))
		printf("yes\n");
	else
		printf("no\n");

	return 0;
}
