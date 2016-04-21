#include <stdio.h>
#include <stdlib.h>

void print_r(int array[], int count)
{
	printf("ARRAY:");
	int i;
	for(i=0;i<count;i++)
	{
		printf(" %d", array[i]);
	}
	printf("\n");
}

void merge(int input[], int inputCount, int leftStart, int leftCount, int rightStart, int rightCount)
{
	int totalCount = leftCount + rightCount;
	int result[totalCount];

	int leftPtr = leftStart;
	int rightPtr = rightStart;
	int totalPtr = 0;
	while(totalPtr < totalCount)
	{
		if(input[leftPtr] > input[rightPtr] && rightPtr < rightStart + rightCount && rightPtr < inputCount)
		{
			result[totalPtr] = input[rightPtr];
			rightPtr++;
		}
		else if(leftPtr < leftStart + leftCount && leftCount < inputCount)
		{
			result[totalPtr] = input[leftPtr];
			leftPtr++;
		}
		else if(rightPtr < inputCount)
		{
			result[totalPtr] = input[rightPtr];
			rightPtr++;
		}
		else
		{
			break;
		}
		totalPtr++;
	}

	int i;
	totalPtr = 0;
	for(i=leftStart;i<leftStart+leftCount;i++)
	{
		if (i >= inputCount)
			break;
		//printf("let %d %d %d\n", i, totalPtr, result[totalPtr]);
		input[i] = result[totalPtr];
		totalPtr++;
	}
	for(i=rightStart;i<rightStart+rightCount;i++)
	{
		if (i >= inputCount)
			break;
		//printf("let %d %d %d\n", i, totalPtr, result[totalPtr]);
		input[i] = result[totalPtr];
		totalPtr++;
	}
}

void sort(int a[], int n)
{
	int i;
	for(i=1;i<n;i=i*2)
	{
		int j;
		for(j=0;j<n;j+=i*2)
		{
			merge(a, n, j, i, j+i, i);
		}
	}
}

int main(void)  
{  
	int a[16] = { 2, 17777, 122, 18, 1, 5, 7, 9, 5, 23, 1, 90, 9, 435, 10, 91};
	print_r(a, 16);
	sort(a, 16);
	print_r(a, 16);

	int b[17] = { 2, 10, 17777, 122, 18, 1, 5, 7, 9, 5, 23, 1, 90, 9, 435, 10, 91};
	print_r(b, 17);
	sort(b, 17);
	print_r(b, 17);

	int c[18] = { 2, 10, 17777, 122, 18, 1, 5, 7, 9, 5, 23, 1, 90, 9, 435, 10, 91, 92};
	print_r(c, 18);
	sort(c, 18);
	print_r(c, 18);

	return 0;  
} 

