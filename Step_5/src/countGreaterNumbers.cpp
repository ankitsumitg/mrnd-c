/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include<stdio.h>
#include <string.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) 
{
	int c = 0;
	for (int i = 0; i < len; i++)
	{
		//if date is not present for loop will end automatically
		if (strcmp(date, (Arr + i)->date) == 0)
		{
			//if its last date
			if (i == len - 1)
				break;
			//if next date is also equal then continue
			if (strcmp(date, (Arr + i + 1)->date) == 0)
				continue;
			c = len - i - 1;
			break;
		}
	}
return c;
}
