#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_r(int *row, int n) {
	int i;
	for(i=0;i<n;i++) {
		printf("%d ", *(row+i));
	}
	printf("\n");
}

int *getRow(int rowIndex) {
	rowIndex++;
	int row;
	int col;
	int * nowRow = calloc(sizeof(int), rowIndex);
	int * preRow = calloc(sizeof(int), rowIndex);
	int * tmpRow = NULL;
	for(row=1;row<rowIndex;row++) {
		printf("start: row %d\n", row);
		printf("%p %p %p", nowRow, preRow, tmpRow);
		printf("pre:");
		print_r(preRow, rowIndex);
		printf("4:%d\n", *(preRow+4) );
		for(col=0;col<row;col++) {
			print_r(preRow, rowIndex);
			printf("%p %p %p", nowRow, preRow, tmpRow);
			printf("scol:%d, 4:%d\n", col, *(preRow+4) );
			if(col == 0 || col == row - 1) {
				printf("ttt: %p %p %p %p\n", nowRow, preRow, tmpRow, nowRow+col);
			printf("33col:%d, 4:%d\n", col, *(preRow+4) );
				printf("ti12312: %p %p %p %p %p %p\n", preRow, preRow+1, preRow+2, preRow+3, preRow+4, nowRow+col);
				*(nowRow+col) = 1;
			printf("34col:%d, 4:%d\n", col, *(preRow+4) );
			} else {
			if (row != 8) 
			{
				*(nowRow+col) = *(preRow+col) + *(preRow+col-1);
			}
			}
			printf("%p %p %p", nowRow, preRow, tmpRow);
			printf("ecol:%d, 4:%d\n", col, *(preRow+4) );
			printf("col:%d %d=%d+%d\n", col, *(nowRow+col), *(preRow+col), *(preRow+col-1));
		}
		print_r(nowRow, rowIndex);
		//memcpy(preRow, nowRow, rowIndex);

		tmpRow = preRow;
		preRow = nowRow;
		nowRow = tmpRow;
		tmpRow = NULL;
		printf("end.\n\n");
	}
	free(nowRow);
	return preRow;
}

int main() {
	int i = 9;
	int * row = getRow(i);
	print_r(row, i);
	return 0;
}
