/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/

#include<stdio.h>
#include <stdlib.h>


int findSingleOccurenceNumber(int *A, int len) 
{
	if (A == NULL)
		return -1;
	/*
			Littel bit of online help to understnad

		a number is XOR with same number then result is 0.

Also XOR is Associative and Commutative, it means
Associative    = giving the same result regardless of grouping, i.e. so that a*(b*c)=(a*b)*c 
Commutative = independent of order; as in e.g. "a x b = b x a"

1.  1 ^ 1 = 0
2.  1 ^ 1 ^ 2 ^ 2 = 0
3.  1 ^ 2 ^ 1 ^ 2 = 0

Irrespective of order, when a same number will be XOR twice then result will be 0.

So, Now lets see our original problem statement.
Given an array of integers. All numbers occur thrice except one number which occurs once. Find the number.

If all the number appeared twice except one number and we need to find that number then it is easy,

Let's take a small example, say given array is,
1. {1, 1 , 2}
Answer is 2 here, XOR all the numbers. result will be the number that appeared only once. 
From the fact we saw that when a number is XOR with same number then result is 0.
 = (1 ^ 1) ^ 2 
 = (0) ^ 2
 =  2  
Number that appear only once is 2.
	
	
	*/
	int first = 0, second = 0,notThird;
	for (int i = 0; i< len; i++)
	{
		second = second | first & A[i];
		first = first ^ A[i];
		notThird = ~(first & second);
		first = first & notThird;
		second = second & notThird;
	}
return first;
}