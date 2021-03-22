/*

ProblemCODE : BINARYSTROP
Difficulty : Medium
Marks : 15

Given two binary numbers in form of strings and
a string representing "AND", "OR", "NOR" or "XOR". Return the output string which forms by doing the specified operation on those 2 strings .


Ex:	Input: "101", "111", op =  "OR"
Output: "111"


Ex:	Input: "10101", "1111", op =  "AND"
Output: "00101"

Ex:	Input: "0111", "1010", op =  "XOR"
Output: "0010"

Ex:	Input: "0011", "1010", op =  "NOR"
Output: "0100"

Note :
In the above representations ,Write those strings on a paper ,you will understand them better . [Align them to the Right]
If 1 string length is less than other ,you need to consider missing letters as 0's ie "1111" AND "1" is same as "1111" AND "0001".
Ie if a String is "" ,you should consider it as All 0's .This dosent not apply if String is NULL.

Reference : http://www.bristolwatch.com/pport/pics/logic_table.gif [For AND,OR,XOR]
For NOR : http://www.circuitstoday.com/wp-content/uploads/2010/04/2-Input-NOR-Gate-Truth-Table.jpg

Contraints :
String length < 50.
For 50% of TestCases ,only AND/OR operations will be given .

Difficulty : Medium

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char out(char, char, char*);


char *performOperation(char *str1, char *str2, char *operation)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	char* ans = NULL;
	char* str3 = NULL;
	int k;
	if (len1 == len2)
	{
		ans = (char*)malloc((len1+1)*sizeof(char));
		k = len1 - 1;
	}
	else if (len1 > len2)
	{
			ans = (char*)malloc((len1+1)*sizeof(char));
			k = len1 - 1;
	}
	else
	{
		ans = (char*)malloc((len2+1)*sizeof(char));
		k = len2 - 1;
	}
	ans[k + 1] = '\0';
	if (len1 == 0)
	{
		str3=(char*)malloc((len2 + 1)*sizeof(char));
		for (int i = 0; i < len2; i++)
			str3[i] = '0';
		str3[len2] = '\0';
		str1 = str3;
	}
	if (len2 == 0)
	{
		str3 = (char*)malloc((len1 + 1)*sizeof(char));
		for (int i = 0; i < len1; i++)
			str3[i] = '0';
		str3[len1] = '\0';
		str2 = str3;
	}
	len1--;
	len2--;
	//applyting the operation from last characters
	while (len1 >= 0 || len2 >= 0)
	{
		if (len1 < 0)
		{
			ans[k] = out('0', str2[len2], operation);
			k--;
			len2--;

		}
		else if (len2 < 0)
		{
			ans[k] = out(str1[len1],'0', operation);
			k--;
			len1--;
		}
		else
		{
			ans[k] = out(str1[len1], str2[len2], operation);
			k--;
			len1--;
			len2--;

		}
	}

return ans;
}
//function to find  out the output for one and one input
char out(char a, char b, char* op)
{
	if (op[0] == 'A')
	{
		if (a == '1' && b == '1')
			return '1';
		else
			return '0';

	}
	else if (op[0] == 'O')
	{
		if (a == '0' && b == '0')
			return '0';
		else
			return '1';

	}
	else if (op[0] == 'X')
	{
		if (a == b)
			return '0';
		else 
			return '1';
	}
	else
	{
		if (a == '0' && b == '0')
			return '1';
		else
			return '0';

	}



}








