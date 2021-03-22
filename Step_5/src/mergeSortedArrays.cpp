/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>


struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int compareDate(char*, char*);



struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) 
{
	if (A == NULL || B == NULL)
		return NULL;
	int i = 0, j = 0, k = 0;
	//size of return array of structures is Alen + Blen
	struct transaction *x = NULL;
	x = (transaction *)malloc((ALen + BLen)*sizeof(transaction));
	while (k < ALen + BLen)
	{
		//if 1st one is greater add 2nd one into x
		if (compareDate(A[i].date, B[j].date) == 1)
		{
			x[k] = B[j];
			k++;
			j++;
		}
		//if 2nd one is greater or equal to 1st one add 1st one into x
		else
		{
			x[k] = A[i];
			k++;
			i++;
		}
		//If  A reached its end copy remaining elemnts of B into x
		if (i == ALen)
		{
			while (j < BLen)
			{
				x[k] = B[j];
				k++;
				j++;
			}
		}
		//If B reached its end copy remaining elemnts of A into x
		if (j == BLen)
		{
			while (i < ALen)
			{
				x[k] = A[i];
				k++;
				i++;
			}
		}

	}
	return x;
}

int compareDate(char *date1, char *date2)
{
	int d1, d2, m1, m2, y1, y2;
	//using sscanf_s or sscanf(depricated function) function to scan the numbers from the string
	sscanf_s(date1, "%d-%d-%d", &d1, &m1, &y1);
	sscanf_s(date2, "%d-%d-%d", &d2, &m2, &y2);
	// if both are equal return 0, if 1st one is greater then return 1 else return 2
	if (d1 == d2 && m1 == m2 && y1 == y2) return 0;
	else if (y1 > y2) return 1;
	else if (y1 < y2) return 2;
	else
	{
		if (m1 > m2) return 1;
		else if (m1 < m2) return 2;
		else
		{
			if (d1 > d2) return 1;
			else return 2;
		}
	}
}