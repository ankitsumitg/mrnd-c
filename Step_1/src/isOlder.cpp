/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isOlder(char *dob1, char *dob2) 
{
	int pow(int i, int n);
	int notLeap(int y);
	if (*(dob1 + 2) != '-' || *(dob2 + 2) != '-' || *(dob1 + 5) != '-' || *(dob2 + 5) != '-') return -1;
	else
	{
		int m1 = 0, m2 = 0, d1 = 0, d2 = 0, y1 = 0, y2 = 0;

		for (int i = 0; i < 2; i++)
		{
			d1 += (*(dob1 + i) - '0')*pow(10, 1 - i);
			d2 += (*(dob2 + i) - '0')*pow(10, 1 - i);
			m1 += (*(dob1 + 3 + i) - '0')*pow(10, 1 - i);
			m2 += (*(dob2 + 3 + i) - '0')*pow(10, 1 - i);
		}
		if (d1>31 || d2>31 || m1 > 12 || m2 > 12) return -1;
		for (int i = 0; i < 4; i++)
		{
			y1 += (*(dob1 + i + 6) - '0')*pow(10, 3 - i);
			y2 += (*(dob2 + i + 6) - '0')*pow(10, 3 - i);
		}
		if (notLeap(y1) && m1 == 2)
		{
			if (d1 > 28)
				return -1;
		}
		if (notLeap(y2) && m2 == 2)
		{
			if (d2 > 28)
				return -1;
		}
		if (d1 == d2 && m1 == m2 && y1 == y2) return 0;
		else if (y1 > y2) return 2;
		else if (y1 < y2) return 1;
		else{
			if (m1 > m2) return 2;
			else if (m1 < m2) return 1;
			else{
				if (d1 > d2) return 2;
				else return 1;
			}
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
int notLeap(int year)
{
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
		return 0;
	else return 1;
}