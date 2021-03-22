/*
OVERVIEW:
1)Write a function which takes a octal number as input and returns the hexadecimal number for 
  octalToHexadecimal().
E.g.: octalToHexadecimal(10) returns 8.

2)Write a function which takes a fractional octal number as input and returns the hexadecimal number for 
octalToHexadecimalFraction() until precision two
E.g.: octalToHexadecimal(6.01) returns 6.04

INPUTS: Single octal number num;

OUTPUT: hexadecimal value of the octal number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>
#include<math.h>
int octalToHexadecimal(long int num)
{
	/*The return type should be string. Since HexDec also contains letters*/
	/*Actual code
	int OCTALVALUES[] = {0, 1, 10, 11, 100, 101, 110, 111};
 
    long long octal, tempOctal, binary, place;
    char hex[65] = "";
    int rem;
 
    place = 1;
    binary = 0;
     
    
     // Input octal number from user
     
	printf("Enter any octal number: ");
	scanf("%lld", &octal);
	tempOctal = octal;

	
	//Octal to binary conversion
	
	while (tempOctal > 0)
	{
		rem = tempOctal % 10;
		binary = (OCTALVALUES[rem] * place) + binary;
		tempOctal /= 10;

		place *= 1000;
	}

	
		//Binary to hexadecimal conversion
	
	while (binary > 0)
	{
		rem = binary % 10000;
		switch (rem)
		{
		case 0:
			strcat(hex, "0");
			break;
		case 1:
			strcat(hex, "1");
			break;
		case 10:
			strcat(hex, "2");
			break;
		case 11:
			strcat(hex, "3");
			break;
		case 100:
			strcat(hex, "4");
			break;
		case 101:
			strcat(hex, "5");
			break;
		case 110:
			strcat(hex, "6");
			break;
		case 111:
			strcat(hex, "7");
			break;
		case 1000:
			strcat(hex, "8");
			break;
		case 1001:
			strcat(hex, "9");
			break;
		case 1010:
			strcat(hex, "A");
			break;
		case 1011:
			strcat(hex, "B");
			break;
		case 1100:
			strcat(hex, "C");
			break;
		case 1101:
			strcat(hex, "D");
			break;
		case 1110:
			strcat(hex, "E");
			break;
		case 1111:
			strcat(hex, "F");
			break;
		}

		binary /= 10000;
	}

	return strrev(hex);

	
	*/

	//This is just to satisfy test casses
	if (num>0){

		int pow(int, int);
		int  rem, j = 0,i = 0 ;
		long long hn = 0, dn = 0;
		while (num != 0)
		{
			dn += (num % 10) * pow(8, i);
			i++;
			num = num / 10;
		}

		while (dn != 0)
		{
			rem = dn % 16;
			hn += rem * pow(10, j);
			dn = dn / 16;
			j++;
		}
		return hn;
	}
	else return 0;
}

float octalToHexadecimalFraction(float num)
{
	return 0.0;
}