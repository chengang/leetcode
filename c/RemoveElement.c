#include <stdio.h>
#include <stdlib.h>

#define elemn 3

int removeElement(int A[], int n, int elem) {
	int i = 0;
	for(i=0;i<n;i++) {
		if(A[i] == elem) {
			A[i] = A[n-1];
			i--;
			n--;
		} 
	}
	return n;
}

int main() {
	int A[elemn] = {2,2,3};
	int elem = 2;
	int result = removeElement(A, elemn, elem);

	printf("%d\n", result);
	return 0;
}
