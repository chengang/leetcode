#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int *twoSum(int numbers[], int n, int target) 
{
	int *index = malloc(8192);
	memset(index, 0, 8192);
	int i;
	for(i=0;i<n;i++)
	{
		*(index+numbers[i]+4096) = i;
	}

	int first,second;
	for(first=0;first<n;first++)
	{
		if(*(index+(target-numbers[first]+4096)))
		{
			second = *(index+(target-numbers[first]+4096));
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
	int data[5] = {-1,-2,-3,-4,-5};
	int target = -8;
	int *index = twoSum(data, 5, target);
	printf("index:%d,%d;cal:%d+%d=%d", *index, *(index+1), data[*index], data[*(index+1)], target);
	return 0;
}

