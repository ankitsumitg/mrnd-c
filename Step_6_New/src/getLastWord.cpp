/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>
#include <string.h>

char * get_last_word(char * str)
{
	int s = 0, i=0;
	int len = strlen(str);
	while (str[i] == ' ')
	{
		i++;
		s++;
	}
	//string is null or empty or containg all spaces
	if (str == NULL || str[0] == '\0'|| s==len)
	{
		return "\0";
	}
	else
	{
		int s, f;
		for (int i = len - 1; i >= 0; i--)
		{
			if ((str[i] >= 'a'&& str[i] <= 'z') || (str[i] >= 'A'&& str[i] <= 'Z'))
			{
				f = i;
				while (str[i] != ' ' && i>=0)
					i--;
				s = i + 1;
				break;
			}
		}
		char *str2 = NULL;
		//dynamic allocation size is j-i+1
		str2 = (char *)malloc((f - s + 1)*sizeof(char));
		int l = 0;
		for (int k = s; k <= f; k++)
		{
			str2[l] = str[k];
			l++;
		}
		str2[l] = '\0';
		return str2;
	}
}