#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
	int len = strlen(s);
	if(numRows <= 1 || len <= 1 || len < numRows )
		return s;

	char * result = calloc( len + 1, sizeof(char));
	int nowRow, nowCharPos;
	int lastRow = numRows - 1;
	int ptrResult = 0;

	for(nowRow=0;nowRow<numRows;nowRow++) {
		nowCharPos = nowRow;
		while(nowCharPos < len) {
			*(result+ptrResult) = *(s+nowCharPos);
			ptrResult++;
			
			if( nowRow == 0 || nowRow == lastRow)
				nowCharPos += 2 * lastRow;
			else
				nowCharPos += 2 * (lastRow - nowCharPos % lastRow);
		}
	}
	return result;
}

int main() {
	printf("%s\n", convert("PAYPALISHIRING", 3)); // answer: PAHNAPLSIIGYIR
	return 0;
}
