/*
OVERVIEW: 
1)Write a function which takes a decimal number as input and returns the octal number for decimalToOctal().
E.g.: decimalToOctal(10) returns 12.

2)Write a function which takes a fractional decimal number as input and returns the octal number for decimalToOctalFraction()
until precision two
E.g.: decimalToOctal(6.06) returns 6.03

INPUTS: Single decimal number num;

OUTPUT: Octal value of the Decimal Number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>

int decimalToOctal(int num)
{
	if(num>0){

	int pow(int,int);
	int on = 0 , rem, count = 0;
	while (num != 0)
	{
		rem = num % 8;
		on = on + rem * pow(10, count);
		num = num / 8;
		count++;
	}
	return on;
	}
	else return 0;
}

float decimalToOctalFraction(float num)
{
	return 0.0;
}
