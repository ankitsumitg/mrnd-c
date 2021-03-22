/*
Given a value n

1. return nth Fibonacci number for the function nthFibonacci(int)
	EX: 0 for n=1 and 1 for n=2


2. return nth prime number for the function nthPrime(int)
	EX: 2 for n=1 and 3 for n=2

INPUTS: single integer n

OUTPUTS: nth Fibonacci number for nthFibonacci() 
		 nth prime number for nthPrime()

ERROR CASES: return -1 for the error cases
*/

int nthFibonacci(int n)
{
	if (n <= 0) return -1;
	else
	{
		int sum, i = 2, a = 0, b = 1;
		if (n == 0 || n == 1) return n;
		else
		{
			while (i < n)
			{
				sum = a + b;
				a = b;
				b = sum;
				i++;
			}
			return b;
		}
	}
}

int nthPrime(int num)
{
	if (num <= 0) return -1;
	else
	{
		int i, n, check, count = 0, temp;
		for (n = 2; n < 1000; n++)
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
			if (check == 0){
				count++;
			}
			if (count == num)
			{
				return n;
				break;
			}
		}
	}
}