/*

problemCode : RepeatedDivision
score : 10

Repeated 2 Division.

Given a Number N, your task is to find a number in the range [1,N]
such that the number is most divisible reptedly by 2

Example :
N = 6

x   -    DivisibleCount
1   -    0
2   -    1
3   -    0
4   -    2
5   -    0
6   -    1

Hence the answer is 4 since it can be repetedly divisible 2 times.

CONSTRAINTS : 
	1 <= N < 2^32

*/
unsigned int getMod(unsigned int n)
{
	return (n & 1);
}
int RepeatedDivision(int N){
	if (N<=0)
	return -1;
	unsigned int c = 0;
	unsigned int i, temp;
	for (i = 1; i <= N; i++)
	{
		temp = i;
		aa:
		if (!getMod(temp))
		{
			c++;
			temp = temp / 2;
			goto aa;
		}
	}
	return c;
}

