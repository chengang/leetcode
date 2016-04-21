#include <stdio.h>
#include <stdlib.h>

int myStrLen(char * s) {
	int i = 0;
	while(*s != '\0') {
		i++;
		s++;
	}
	return i;
}

char* longestCommonPrefix(char** strs, int strsSize) {
	int i;
	int maxStrLen = 0;
	for(i=0;i<strsSize;i++) {
		int nowStrLen = myStrLen(strs[i]);
		if(nowStrLen > maxStrLen)
			maxStrLen = nowStrLen;
	}
	char * result = calloc(maxStrLen, sizeof(char));
	
	int strsNum;
	int charNum;
	for(charNum=0;charNum<maxStrLen;charNum++) {
		char nowChar = strs[0][charNum];
		if(nowChar == '\0') {
			return result;
		}
		for(strsNum=0;strsNum<strsSize;strsNum++) {
			if(strs[strsNum][charNum] == '\0') {
				return result;
			}
			if(strs[strsNum][charNum] != nowChar) {
				return result;
			}
		}
		*(result+charNum) = nowChar;
	}
	return result;
}

int main() {
	char * a = "abcdefg";
	char * b = "abcd";
	char * c = "abcdef";

	char *strs[] = {a, b, c};

	printf("%s\n", longestCommonPrefix(strs, 3));
	return 0;
}
