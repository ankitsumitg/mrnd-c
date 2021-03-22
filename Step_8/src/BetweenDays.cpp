/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Year 999 will be represented as 0999.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL && date2head == NULL)
		return -1;
	else{
		int firstDate = 0, firstMonth = 0, firstYear = 0, secondDate = 0, secondMonth = 0, secondYear = 0;
		struct node *temp1 = date1head, *temp2 = date2head;
		int i = 0;
		while (temp1 != NULL && temp2 != NULL)
		{
			if (i < 2)
			{
				firstDate = firstDate * 10 + temp1->data;
				secondDate = secondDate * 10 + temp2->data;
				i++;
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
			else if (i >= 2 && i < 4)
			{
				firstMonth = firstMonth * 10 + temp1->data;
				secondMonth = secondMonth * 10 + temp2->data;
				i++;
				temp1 = temp1->next;
				temp2 = temp2->next;

			}
			else
			{
				firstYear = firstYear * 10 + temp1->data;
				secondYear = secondYear * 10 + temp2->data;
				i++;
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
		}
		//finding no. of days from the initial date 00000000
		firstMonth = (firstMonth + 9) % 12;
		firstYear = firstYear - firstMonth / 10;
		
		int FirstNoOfDays = 365 * firstYear + firstYear / 4 - firstYear / 100 + firstYear / 400 + (firstMonth * 306 + 5) / 10 + (firstDate - 1);

		secondMonth = (secondMonth + 9) % 12;
		secondYear = secondYear - secondMonth / 10;
		int SecondNoOfDays = 365 * secondYear + secondYear / 4 - secondYear / 100 + secondYear / 400 + (secondMonth * 306 + 5) / 10 + (secondDate - 1);

		int x = abs(FirstNoOfDays - SecondNoOfDays);
		/* uses absolute if the first date is smaller so it wont give negative number */
		// if date is same
		if (x == 0)
			return x;
		else return x - 1;
	}
}