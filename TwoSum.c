#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int a[2];
int *twoSum(int numbers[], int n, int target) 
{
	int bitmap[40960];
	int i;
	for(i=0;i<n;i++)
	{
		bitmap[numbers[i]+100] = i;
	}

	int first,second;
	for(first=0;first<n;first++)
	{
		if(bitmap[target-numbers[first]+100])
		{
			second = bitmap[target-numbers[first]+100];
			a[0] = first+1;
			a[1] = second+1;
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
	printf("index:%d,%d;cal:%d+%d=%d", *index, *(index+1), data[*index-1], data[*(index+1)-1], target);
	return 0;
}

