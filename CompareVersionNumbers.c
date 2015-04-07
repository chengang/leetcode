#include <stdio.h>
#include <string.h>
int myStrLen(char * str) {
	int i = 0;
	while(1)
	{
		if(*(str+i) == '\0')
			return i;
		i++;
	}
}

int string2int(char *str, int start, int end) {
	int result = 0;
	int i;
	for(i=start;i<=end;i++)
	{
		result = result * 10 + *(str+i) - 48;
	}
	return result;
}

int compareString(char *str1, int start1, int end1, char *str2, int start2, int end2) {
	int res1 = string2int(str1, start1, end1);
	int res2 = string2int(str2, start2, end2);

	if( res1 > res2 )
	{
		return 1;
	}
	else if (res1 < res2)
	{
		return -1;
	}
	else
	{
		return 0;
	}

}

int eqZero(char * str, int start, int end) {
	while(start <= end)
	{
		if(*(str+start) != '0' && *(str+start) != '.')
		{
			return 0;
		}
		start++;
	}
	return 1;
}

int findDot(char * str, int start) {
	if(*(str+start) == '.' || *(str+start) == '\0')
		return start;
	while(++start)
	{
		if(*(str+start) == '.' || *(str+start) == '\0')
		{
			start--;
			return start;
		}
	}

	return start;
}

int compareVersion(char *version1, char *version2) {
	int len1 = myStrLen(version1) - 1;
	int len2 = myStrLen(version2) - 1;
	int iStart1 = -1;
	int iStart2 = -1;
	int iEnd1 = -1;
	int iEnd2 = -1;

	while(1) {
		//printf("main loop\n");
		iStart1++;
		iStart2++;
		iEnd1 = findDot(version1, iStart1);
		iEnd2 = findDot(version2, iStart2);
		printf("[%s][%d][%d] = [%s][%d][%d]\n", version1, iStart1, iEnd1, version2, iStart2, iEnd2);

		int result = compareString(version1, iStart1, iEnd1, version2, iStart2, iEnd2);
		printf("rrr %d\n", result);
		if(result != 0)
		{
			return result;
		}

		if (iEnd1 < len1 && iEnd2 < len2)
		{
			printf("case 1\n");
			iStart1 = iEnd1;
			iStart2 = iEnd2;
			continue;
		}
		else if (iEnd1 >= len1 && iEnd2 < len2)
		{
			printf("case 2\n");
			iStart2 = iEnd2 + 1;
			while(iEnd2 < len2)
			{
				iStart2++;
				iEnd2 = findDot(version2, iStart2);
				if(!eqZero(version2, iStart2, iEnd2))
				{
					return -1;
				}
				iStart2 = iEnd2;
			}
			return 0;
		}
		else if (iEnd1 < len1 && iEnd2 >= len2 )
		{
			printf("case 3\n");
			iStart1 = iEnd1 + 1;
			while(iEnd1 < len1)
			{
				iStart1++;
				iEnd1 = findDot(version1, iStart1);
				if(!eqZero(version1, iStart1, iEnd1))
				{
					return 1;
				}
				iStart1 = iEnd1;
			}
			return 0;
		}
		else
		{
			printf("case 4\n");
			return compareString(version1, iStart1, iEnd1, version2, iStart2, iEnd2);
		}
	}
}

int main() {
	char * a = "1.1";
	char * b = "1.01.0";
	int lenA = myStrLen(a);
	int lenB = myStrLen(b);

	printf("%d - %d\n", lenA, lenB);
	printf("%d", compareVersion(a, b));
	return 0;
}
