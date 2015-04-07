#include <stdio.h>
#include <string.h>

char result[100] = "";
char *convertToTitle(int n) {
	int i = 0;
	int n2 = n;
	while(n2>0)
	{
		n2 = (n2 - 1) / 26;
		i++;
	}

	i--;
	while(n>0)
	{
		result[i] = (char) ((n - 1) % 26 + 65);
		n = (n - 1) / 26;
		i--;
	}

	return result;
}

int main() {
	printf("%s", (char *)convertToTitle(701));
	return 0;
}
