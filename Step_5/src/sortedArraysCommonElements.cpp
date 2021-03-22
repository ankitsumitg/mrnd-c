/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: 
A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) 
{
	if (A == NULL || B ==NULL)
	return NULL;
	struct transaction* x = NULL;
	int k = 0;
	for (int i = 0; i < ALen; i++)
		for (int j = 0; j < BLen; j++)
			if (strcmp((A + i)->date, (B + j)->date) == 0)
			{
				//reallocating and putting the values
				x = (transaction *)realloc(x,(k + 1)*sizeof(transaction));
				x[k] = A[i];
				k++;
				break;
			}
	return x;
}
