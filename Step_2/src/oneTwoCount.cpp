/*
OVERVIEW: Given an Integer Array return the count of one's and two's in a new array of length two.
Ex: input: [1,2,2,1,2,1,2] 
	output: [3,4]
	where 3 is the count of 1's and 4 is the count of 2's

INPUTS: An Integer Array and length of the array 

OUTPUT: An Array with 1's count and 2's count

ERROR CASES: Return NULL for invalid inputs

Difficulty : Very Easy
*/

#include <stdio.h>
#include <stdlib.h>
int* oneTwoCount(int* input, int length)
{
	int o = 0, t = 0;
	if (length <= 0)
	return NULL;
	else
	{
		for (int i = 0; i < length; i++)
			if (*(input + i) == 1)
				o++;
			else if (*(input + i) == 2)
				t++;
	}
	int *a = (int *)calloc(2, sizeof(int));
	*a = o;
	*(a+1) = t;
	return a;
}