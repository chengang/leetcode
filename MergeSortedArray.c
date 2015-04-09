#include <stdio.h>
#include <stdlib.h>

void print_r(int a[], int n) {
	int i = 0;
	for(i=0;i<n;i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void merge(int A[], int m, int B[], int n) {
	int ptrA = 0;
	int ptrB = 0;

	int count = 0;
	int C[n+m];

	while(ptrA < m || ptrB < n) {
		if (ptrA < m && ptrB < n) {
			if (A[ptrA] < B[ptrB]) {
				C[count] = A[ptrA];
				ptrA++;
			} else {
				C[count] = B[ptrB];
				ptrB++;
			}
		} else if (ptrA < m && ptrB >= n) {
			C[count] = A[ptrA];
			ptrA++;
		} else if (ptrA >= m && ptrB < n) {
			C[count] = B[ptrB];
			ptrB++;
		}
		count++;
	}

	int i;
	for(i=0;i<count;i++) {
		A[i] = C[i];
	}
}

int main() {
	//int a[50] = {2, 3, 5, 7, 9};
	//int b[6] = {1, 4, 8, 10, 12, 99};
	int a[6] = {1, 2, 3};
	int b[3] = {2, 5, 6};
	merge(a, 3, b, 3);
	print_r(a, 6);
	return 0;
}
