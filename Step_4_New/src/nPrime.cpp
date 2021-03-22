/*

Here you will be doing the same ArraysQuestion you did before, but now in multiple ways.

OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7]
INPUTS: An Integer N
OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)
ERROR CASES: Return NULL for invalid inputs
Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}

Observations: (Write down what you observed here):

Way 1 : Time complexity is O(n)

Way 2 : Time complexity is O(logn) and space efficient because of dynamic memory allocation

Way 3: Most efficient code

Conclusion : Optimized code is better.
*/


#include <stdio.h>
#include <math.h>
#include<stdlib.h>


/*

Manually loop over every element, Find if its prime or not. Store it in an array.
Write the worst complexity code you can write :D.
*/
int* nPrimeBruteForce(int N)
{
	if (N <= 1) return NULL;
	int isPrime(int);
	int* x = (int *)malloc(100 * sizeof(int));
	int j = 0;
	for (int i = 2; i < N; i++)
	{
		if (isPrime(i)){
			x[j] = i;
			j++;
		}
	}

	realloc(x, j*sizeof(int));
	return x;
	return NULL;
}


/*
Remove even numbers, Run it again.
Just remove even numbers. So it should essentially take half of time for function 1, Did it really happened?

*/
int* nPrimeEvenRemoved(int N)
{
	if (N <= 1) return NULL;
	int isPrime(int);
	int* x = (int *)malloc(100 * sizeof(int));
	int j = 0;
	x[j] = 2;
	j++;
	for (int i = 3; i < N; i += 2)
	{
		if (isPrime(i)){
			x[j] = i;
			j++;
		}
	}

	realloc(x, j*sizeof(int));
	return x;
}

/*
Do all optimizations you can think of.

Hint :
A number can be considered a prime, if its not divisible by any of the primes which are less than it.
ie 100 can be considered as a prime, if no prime number which is less than 100 divides 100 (With remainder as 0).
7 is prime as no prime less than it (2,3,5) can divide it. Think proof for this too.

This heavily reduces the number of divisions you do. If you did correctly you should see some heavy difference in timings.

*/
int* nPrimeOptimized(int N)
{
	if (N <= 1) return NULL;
	int isPrime(int);
	//int x[500];
	int* x = (int *)malloc(500 * sizeof(int));
	int j = 0, flag, k;
	x[j] = 2;
	j++;
	for (int i = 3; i < N; i += 2)
	{
		for (k = 0, flag = 0; k < j; k++)
		{
			if (i%x[k] == 0)
			{
				flag++;
				break;
			}
		}

		if (flag == 0)
		{
			x[j] = i;
			j++;
		}
	}

	realloc(x, j*sizeof(int));
	return x;
}
int isPrime(int number){
	if (number == 2)
		return 1;
	//for even numbers
	if (number % 2 == 0)
		return 0;
	//skipping division with even numbers
	for (int i = 3; i <= sqrt((double)number); i += 2)
		if (number%i == 0)
			return 0;
	return 1;
}