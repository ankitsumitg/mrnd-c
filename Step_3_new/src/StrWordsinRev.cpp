/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void str_words_in_rev(char *input, int len)
{
	//I took help from online. But i understood and did diffrently
	// First reverse each word in string and then reverse the string
	void reverse(char*,char*);
	char *start = NULL;
	//storing the input into temp
	char *temp = input; 
	while (*temp)
	{
		//checking the string starts with character and not with the space
		if ((start == NULL) && (*temp != ' '))
		{
			start = temp;
		}
		if (start && ((*(temp + 1) == ' ') || (*(temp + 1) == '\0')))
		{
			reverse(start, temp);
			start = NULL;
		}
		temp++;
	}
	// now reversing the whole string
	reverse(input, temp - 1);
}
void reverse(char *start, char *end)
{
	char temp;
	while (start < end)
	{
		temp = *start;
		*start++ = *end;
		*end-- = temp;
	}
}