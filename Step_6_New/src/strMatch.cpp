/*
ProblemCode : STRMATCH
Marks : 10
Difficulty :Easy.

A String(which only has small case a-z letters) is said to be corrupted if some of the charecters are removed and replaced by the number of characters removed .
Like : apple can be converted into a3e (ppl removed), or a4 (pple removed),ap2e (pl removed) .

helloworld can be modified as hello5 , h9 , 9d , etc , There is no limit on the number of characters that can be removed , or number of different times they can be
removed .

Some more examples are ,abcdefghijkl can be modified as a2d2g4l , a10l .
If 2 or more numbers occured consecutively , you should consider them as a whole , like a23re , is not a "2Chars removed" "3Chars Removed" re ,
it is a "23 Chars removed" re .

Your Task is , Given two corrupted Strings , you need to find whether a common word can be formed from those both corrupted strings
, If Yes ,return 1 , If no word can formed return 0 , -1 For invalid inputs .

Ex Input : s1= "a3e" and s2="4e" , Example Output : 1 .

This is because , apple word can be formed from both .

Ex Input 2 : s1= "k2e2f" and s2="k1fr3" , Returns 0 . No common word can be formed from those both Strings .
Ex Input 3: "5e3" and "abcdeej2" returns 1 , where as if s1 is 5e3i and s2 is abcdeekoll returns 0

Constraints :
A String will only have letters from "a-z and 0-9" ;
0<=Len Of Str1,Str2 <=10000
Numbers occuring in the String can be anything from 1 till 999 .

You can implement the helper functions ,if you want ,Although its optional .Dont worry about space for this question .

Note : Only 25% of Cases ,will have numbers >9 in the Strings .
*/
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isSTRMatched(char *str1, char *str2)
{
	if (str1 == NULL || str2 == NULL)
		return 1;
	int a1[5], a2[5];
	int i = 0;
	char *p1 = str1;
	char *p2 = str2;
	//storing the numbers from the strings
	while (*p1) 
	{
		if (isdigit(*p1)) 
		{ 
			a1[i] = strtol(p1, &p1, 10);
			i++;
		}
		else
			p1++;
	}
	a1[i] = -1;
	i = 0;
	while (*p2)
	{
		if (isdigit(*p2))
		{
			a2[i] = strtol(p2, &p2, 10);
			i++;
		}
		else
			p2++;
	}
	a2[i] = -1;
	int count1 = 0, count2 = 0;
	//counting the number of characters in the strings 
	for (int i = 0; str1[i] != '\0'; i++)
		if (isalpha(str1[i]))
			count1++;
	for (int i = 0; str2[i] != '\0'; i++)
		if (isalpha(str2[i]))
			count2++;
	//adding the number of charracter count and number count 
	for (int i = 0; a1[i] != -1; i++)
			count1+=a1[i];
	for (int i = 0; a2[i] != -1; i++)
		count2 += a2[i];
	//if  counts are equal return 1 else return 0;
	if (count1 != count2)
		return 0;
	else 
		return 1;
}
