/*

Problem : Return the Count of how many times the word occurred in given string in two ways
Way1: Not using Recursion
Way2:Using Recursion [Optional]

Input : "Hello HelloAgain HelloAGAINAGAIN commonItsHelloagain","Hello"
Output : 4

Note: Dont modify original str or word,Just return count ,Spaces can also be part of words like "ab cd" in "ab cd ab cd" returns 2
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int count_word_in_str_way_1(char *str, char *word)
{
	if (str == NULL || str[0] == '\0')
	{
		return 0;
	}
	else
	{
		int check = 0;
		int count = 0;
		int len = strlen(word);
		for (int i = 0; str[i] != '\0'; i++)
		{
			check = 0;
			for (int j = 0; j < len; j++)
			{
				int k = i;
				//checing whether the pattern is matched or not
				while (str[k] == word[j] && k<strlen(str)&&j<len)
				{
					check++;
					k++;
					j++;
				}
				//if length mathces the number matched check characters
				if (check == len)
				{
					count++;
				}
				break;
			}
		}
		return count;

	}
}

int count_word_int_str_way_2_recursion(char *str, char *word){
	return 0;
}

