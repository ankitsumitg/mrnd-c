
/*
OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7] 

INPUTS: An Integer N

OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)

ERROR CASES: Return NULL for invalid inputs

Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}
NOTES:

Try to think of a optimized way , and avoid unnecessary comparisons.
*/
#include <stdlib.h>
#include <stdio.h>
int* nPrime(int N)
{
	if (N == 0) return NULL;
	else
	{
		int i, j = 0, n, check, count = 0;
		int* a = (int *)malloc(1000 * sizeof(int));
		for (n = 2; n < N; n++)
		{
			check = 0;
			for (i = 2; i <= n / 2; i++)
			{
				if (n%i == 0)
				{
					check = 1;
					break;
				}
			}
			if (check == 0)
			{
				*(a + j) = n;
				j++;
			}
		}
		//Memory managemnet reallocating to exact size
		realloc(a, j*sizeof(int));
		return a;
	}
}