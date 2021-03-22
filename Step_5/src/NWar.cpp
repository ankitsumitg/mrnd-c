/*
Problem Code :NWAR

There is a war going among numbers ,on who should be considered as a Leader and finally they have reached a conclusion .
For those numbers when breaked into digits and Individual squares are added ,and if the sum is not 1 ,the process is repeated for the sum and so on.
When doing this if any any time ,Sum reaches 1 , that number can be called as Leader Number , other wise not .

Ex: 1000 => (1^2 + 0^2 + 0^2 + 0^2) ==> 1 .1000 is a leader number
Ex: 44 => (16+16) => 32 => (9+4) ==> 13 => (1+9) ==> 10 ==> (1+0) ==> 1. 44 is a leader number .
Ex: 67 => (36+49) ==> 85 => By Doing Dividing and Squaring and Summing we get this series
89 => 145 => 42 => 20 => 4 => 16 => 37 => 58 => 89 , As 89 is already generated No matter how many times we do this process We can never reach 1 .So its not a leader Element .

Given an Array of Numbers ,You need to return the array of Leader Elements .You should also copy the Number of Leader Elements Found in *leadersArraLen variable .
Order should be maintained in the Result Array .

Ex Input : [

Constraints :
0<= A[i]< 1000000
0<len<10000

Note : Returns Array Length will not be greater than 10001 . And If the leader number occured 2 or more times in the original array include those many times in answer
Note : Return NULL for Invalid Inputs
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int sumf(int);

int* getSquareLeaderArray(int *arr, int len, int *leadersArrayLen)
{	/*
					Little bit of research
Let s(n)s(n) be the function that adds the square of the digits in nn.

Note that for r≥3r≥3, and dk∈{0,1,…9}dk∈{0,1,…9} for k=1,2,…,rk=1,2,…,r with dr≥1dr≥1, we have that
n=d0+∑k=1r−1dk10k+dr10r>d20+∑k=1r−1d2k+d2r=s(n)
n=d0+∑k=1r−1dk10k+dr10r>d02+∑k=1r−1dk2+dr2=s(n)
because 10>dk10>dk and d0+dr10r≥1000≥92+92≥d20+d2rd0+dr10r≥1000≥92+92≥d02+dr2.

Therefore if nn has at least three digits then n>s(n)n>s(n). This implies that eventually we will obtain a number of at most three digits. So it suffices to check what happens for the integers in [1,999][1,999]: it can be verified that given n∈[1,999]n∈[1,999], then s(k)(n)∈{1,89}s(k)(n)∈{1,89} with k≤11k≤11.

Hence, we may conclude that for any n≥1n≥1 the sequence, after a finite number of steps, will enter in one of the two cycles:


(1)   or   (89,145,42,20,4,16,37,58).

 */
	if (arr == NULL)
		return NULL;
	int* x = NULL;
	x = (int*)malloc(10000 * sizeof(int));
	int k = 0;
	for (int i = 0; i < len; i++)
	{
		//checking for each element
		int temp = arr[i];
		if (temp == 0)
			goto bb;
	aa:
		int sum=sumf(arr[i]);//findinf sum of squares of digits
		if (sum == 1)// if sum equal then assign to output array
		{
			x[k] = temp;
			k++;
		}//other wise they converge to one of these number only
		else if (sum == temp || sum == 4 || sum == 16 || sum == 37 || sum == 58 || sum == 89 || sum == 145 || sum == 42 || sum == 20)
		{

			goto bb;
		}
		else 
		{ 
			arr[i] = sum;
			goto aa;
		}
	bb:
		arr[i] = temp;
	}//reallocating the memory
	realloc(x, (k)*(sizeof(int)));
	*leadersArrayLen = k;
	return x;
}
int sumf(int x) // function for finding the sum  of squres of digits
{
	int temp = x;
	int digit, sum = 0;
	while (temp > 0)
	{
		digit = temp % 10;
		sum = sum + (int)pow((float)digit,2);
		temp /= 10;
	}
	return sum;
}

