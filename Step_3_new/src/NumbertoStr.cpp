/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include<math.h>


void number_to_str(float number, char *str,int afterdecimal)
{

		/*   we can also use directly 
		
		
		sprintf(str, "%f", number);     
		
		
		*/


		int pow(int,int);
		int j = 0;
		//if negative addig - to str and making the number postive
		if (number < 0)
		{
			str[j] = '-';
			j++;
			number = -1 * number;
		}
		int i = (int)number;     // integer part
		float f = number - i;    // decimal part
		int a[10], k = 0;
		while (i != 0)
		{
			a[k] = i % 10;
			k++;
			i = i / 10;
			
		}
		for (int l = k - 1; l >= 0;l--)
		{
			str[j] = a[l] + '0';        // joining the integer part 
			j++;
		}
		if (afterdecimal != 0 || f ==0)
		{
			*(str + j) = '.';      // for decimal point 
			j++;
			f = f * pow(10, afterdecimal+1);
			int g = int(f);
			g = g / 10;
			k = 0;
			while (g !=0)
			{
				a[k] = g % 10;
				k++;
				g = g / 10;
			}
			for (int l = k - 1; l >= 0; l--)
			{
				str[j] = a[l] + '0';    //  for decimal part 
				j++;
			}
		}
}
int pow(int n, int i)
{
	int m = 1;
	while (i != 0)
	{
		m *= n;
		i--;
	}
	return m;

}
