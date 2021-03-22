/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define SIZE 31

char ** commonWords(char *str1, char *str2) {
	int mystrlen(char*);
	int contains(char*, char*);
	char** write(char**, int, char*);
	if (str1 == NULL || str2 == NULL) return NULL;

	int l1 = mystrlen(str1);
	int l2 = mystrlen(str2);

	int i = 0, j, spc = 0, current = -1, ns = 0, prev = -1, pos = 0;
	//Dynamic allocation od size according to gicen conditions
	char *ret = (char*)malloc((l1 + l2)*sizeof(char));
	char **arr = (char **)malloc(31 * sizeof(char *));
	for (int k = 0; k < 32; k++)
		arr[k] = (char*)malloc(31 * sizeof(char));

	for (int m = 0; m < 32; m++)
		for (int n = 0; n < 32; n++)
			arr[m][n] = '\0';

	*ret = '\0';

	while (i<mystrlen(str1))
	{
		if (str1[i] == ' ' || str1[i] == '\0')
			ns++;
		i++;
	}
	if (ns == strlen(str1)) return NULL;

	for (int n = 0; n <= ns; n++)
	{
		for (i = prev + 1; i < l1; i++)
		{
			if (str1[i] == ' ' || str1[i] == '\0') break;
		}

		current = i;

		char* temp = (char*)malloc((l1)*sizeof(int));

		for (j = 0; j < current - prev - 1; j++)
		{
			*(temp + j) = *(str1 + prev + 1 + j);
		}

		prev = i;

		temp[j] = '\0';

		int flag = contains(temp, str2);

		if (flag != -1)
		{
			arr = write(arr, pos, temp);
			pos++;
		}

		free(temp);
	}

	if (pos == 0) return NULL;
	return arr;
}

int contains(char *pattern, char *search)
{
	int mystrlen(char*);
	int slen = mystrlen(search);
	int plen = mystrlen(pattern);
	int i, j, k;

	for (i = 0; i <= slen - plen; i++)
	{
		for (j = 0, k = i; (search[k] == pattern[j]) && (j < plen); j++, k++);
		if (j == plen)
			return j;
	}
	return -1;
}

int mystrlen(char* str)
{
	int i = 0;
	while (str[i] != '\0') i++;
	return i;
}

char** write(char** arr, int pos, char* temp)
{
	int i = 0;
	for (i = 0;; i++)
	{
		if (temp[i] == '\0')
		{
			arr[pos][i] = temp[i];
			break;
		}
		arr[pos][i] = temp[i];
	}
	return arr;
}