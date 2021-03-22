/*
	problemCode : NearestSortedNumber
	score : 15

	A Sorted Number is a number in which all its digits are in non-decending order.
	for example "129" , "222", "345", "999" are all Sorted Numbers.
	Where as the numbers "110" , "1000", "143" are not Sorted Numbers.

	You are given an integer N in the form of a string.
	
	Your task is to find the the last Sorted Number in the range [1,N]

	Sorted Numbers = [1,2,3,4,5,6,7,8,9,  11,12,13,...19,  22,23,24,.... INF]

	Sample Cases : 
	N = 10, result = 9
	N = 12, result = 12
	N = 19, result = 19
	N = 21, result = 19

	Note : 
	1) if there is no answer or the input is invalid , return NULL
	2) Input consists of no leading zeros, and output should not consist of leading zeros
	returning "0002" instead of "2" is considered as a wrong answer.

	Constraints : 
	1 <= len <= 100000 (i.e 100000 digits not integer 100000)
*/


#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include <stdlib.h>
int isTidy(int num);
int isdigit(char x)
{
	int isDigit;
	if (x > '9' || x < '0')
		isDigit = 0;
	else
		isDigit = 1;
	return isDigit;
}
char * NearestSortedNumber(char *N, int len){
	if (N == NULL || len <= 0 || strlen(N) == 0 || N[0] == '\0')
	return NULL;
	int isDigit = 0;
	int j = 0;
	while (j<strlen(N)){
		isDigit = isdigit(N[j]);
		if (isDigit == 0) break;
		j++;
	}
	long long x,y;
	if (isDigit == 0)
		return NULL;
	else
		x = atoi(N);
	/*if (x % 10 == 0)
		y = x - 1;
	else y = x;*/
	aa:
	if (isTidy(x))
	{
		char snum[100000];
		_itoa_s(x, snum, 10);
		return snum;
	}
	else { x--;
	goto aa;
	}
	
}
int isTidy(int num)
{
	int prev = 10;
	while (num)
	{
		int rem = num % 10;
		num /= 10;
		if (rem > prev)
			return 0;
		prev = rem;
	}

	return 1;
}


