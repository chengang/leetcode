#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define TOTAL_INPUT 4

int *twoSum(int numbers[], int n, int target) 
{
	int *index = malloc(n);
	memset(index, 0, n);
	int i;
	for(i=0;i<n;i++)
	{
		*(index+numbers[i]) = i;
	}

	int first,second;
	for(first=0;first<n;first++)
	{
		if(*(index+(target-numbers[first])))
		{
			second = *(index+(target-numbers[first]));
			int *a = malloc(2);
			memset(a, 0, 2);
			*a = first;
			*(a+1) = second;
			return a;
		}
	}
	return NULL;
}

int main()
{
	int data[TOTAL_INPUT] = {4, 5, 8, 5};
	int target = 9;
	int *index = twoSum(data, TOTAL_INPUT, target);
	printf("index:%d,%d;cal:%d+%d=%d", *index, *(index+1), data[*index], data[*(index+1)], target);
	return 0;
}

