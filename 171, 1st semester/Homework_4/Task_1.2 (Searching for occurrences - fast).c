/*
Алгоритм КМП для поиска вхождений подстроки в строку.
===================================================================
KMP algorithm to search for occurrences of a substring in a string
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char temp[1000], str[2000], subStr[1000];
	str[0]='%';
	str[1]='\0';
	scanf("%s", &temp);
	scanf("%s", &subStr);
	int m = strlen(subStr);
	strcat(str, subStr);
	strcat(str, "&");
	strcat(str, temp);
	int n = strlen(str), prefix[2000], i = 0, current = 0;
	prefix[1] = 0;
	for (i = 2; i < n; ++i)
	{
		current = prefix[i-1];
		while (current > 0 && str[i]!=str[current + 1]) 
			current = prefix[current];
		if (str[i] == str[current + 1]) current++;
		prefix[i] = current;
	}
	for (i = m + 1; i < n; ++i)
		if (prefix[i] == m) printf("%d ", i - (2 * m + 1));
	return 0;
}