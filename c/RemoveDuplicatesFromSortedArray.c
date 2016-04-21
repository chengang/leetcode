#include <stdio.h>
#include <stdlib.h>

void print_r(int A[], int n) {
	int i;
	for(i=0;i<n;i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

int min (int a, int b) {
	if (a > b)
		return b;
	else 
		return a;
}

int removeDuplicates(int A[], int n) {
	int i;
	int dupCount = 0;
	for(i=0;i<n-1;i++) {
		if(A[i] == A[i+1]) {
			dupCount++;
		} else {
			A[i+1-dupCount] = A[i+1];
		}
	}
	return n-dupCount;
}

int main() {
	int A[2] = {1,1};
	print_r(A, 2);
	int newLen = removeDuplicates(A, 2);
	printf("newLen: %d, ", newLen);
	print_r(A, 2);
	return 0;
}
