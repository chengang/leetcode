#include <stdio.h>
#include <stdlib.h>

#define elemn 6

int removeElement(int A[], int n, int elem) {
	int i;
	int resultLen = 0;
	int * B = calloc(n, sizeof(int));
	for(i=0;i<n;i++) {
		if(A[i] != elem) {
			B[resultLen] = A[i];
			resultLen++;
		}
	}

	for(i=0;i<resultLen;i++) {
		A[i] = B[i];
	}
	return resultLen;
}

int main() {
	int A[elemn] = {0,2,4,3,0,0};
	int elem = 4;
	int result = removeElement(A, elemn, elem);

	printf("%d\n", result);
	return 0;
}
