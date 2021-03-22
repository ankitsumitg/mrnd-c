
/*
OVERVIEW: Given an array of integers find the maximum psible sum formed by a pitive and the native
integer in the array.
Ex: input: [1, 9, 8, 2, 3, -1,-10,-5] output: 8 (formed by 9 and -1) 

INPUTS: An Integer array and the length of the array

OUTPUT: Maximum psible sum formed by a pitive and the native integer in the array

ERROR CASES: Return 0 for the invalid inputs

NOTES:
*/

#include <stdio.h>

int maxPosNegSum(int* input,int length)
{
	if (*input == '\0')
		return 0;
	int max = 0, nmax = 0;
	int p[50], n[50],i = 0,j = 0;
	//Spliting into two array containg negative and positive integers
	for (int k = 0; k < length; k++)
	{
		if (*(input + k) < 0)
		{
			n[i] = *(input + k);
			i++;
		}
		else
		{
			p[j] = *(input + k);
			j++;
		}
	}
	if (i == 0 || j == 0)
		return 0;
	//Finding max pos
		max = p[0];
		for (int k = 0; k < i; k++) 
			if (p[k]>max) 
				max = p[k];
		//Finding max negative
		nmax = n[0];
		for (int k = 0; k < i; k++) 
			if (n[k]>nmax) 
				nmax = n[k];
		return max + nmax;
}