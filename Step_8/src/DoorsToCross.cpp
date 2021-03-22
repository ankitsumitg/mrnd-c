/*

Bharath is genius reverse engineer, invented a world demanding machine and Kept in a secret building with many doors with each door having a passkey.
A Pass temp is made up of some digits. Like a passkey can be 1234, 452 etc.
All doors will have passkeys of same digits, (formed from each other). like if number of doors are 3, 1223,2132,2321 can be passkeys for those doors.
(Where as 3321 cannot as 3 is repeated 2 times where as in above sequence its repeated only 1 time)

Sam is very excited to see his wonderful creation. So, she went to the building. She knows the final passkey of last door but dont know
what is the exact passkey for each before door. As said before there are many doors with lock in a linear fashion such that
she can cross second door only after crossing first door. she can cross third door only after crossing 2nd door.

Lets say the final pass temp she has is 758.
First door pass temp is the largest number that can be formed by given final passkey -> 875
Second door pass temp is the next largest number that can be formed -> 857
Third door opens for next largest number ->785
Finally fourth door has 758 as passkey and she can enter the room.

Find which Nth door's room contains the machine or How many doors should Sam cross to see the machine?

The final passkey Sam has will be given in the form of Doubly Linked List
eg: 7 <-> 5 <-> 8  o/p: 4

For the above Passkey ,output will be 4, as Sam needs to cross 4 doors which each door having below passkeys.
explanation: (1) 875 (2) 857 (3) 785 (4) 758

Ex 2 :
If DLL has 9 <-> 1 <-> 4 <-> 6.
For the above Passkey ,output will be 4, as Sam needs to cross 6 doors which each door having below passkeys.
explanation: (1) 9641 (2) 9614 (3) 9461 (4) 9416 (5) 9164 (6) 9146

NOTE:	(1)	DLL can contain maximum of 12 nodes
(2)	All doors will have a Passkey which is formed by the numbers of the original pass temp only
(3) From the first door to last, passkey will be in decreasing order.
(4) Duplicates are allowed
(5) "075" is not treated as "75". 0 is also given same importance as others.

You can solve this question in multiple ways.
Can you solve it without converting to any intermediate forms or using extra space etc? These will be the common followup questions
that can be asked in an interview.

Return -1 for invalid cases.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct passKeyNode
{
	int num;
	struct passKeyNode *prev;
	struct passKeyNode *next;
};
//void permute(char *a, int i, int n);
//void swap(char *x, char *y);
//int count = 0,check = 0;
//char num[20];
unsigned int fact(unsigned int n)
{
	int ans = 1, i;
	for (i = 2; i <= n; i++)
		ans *= i;
	return ans;
}
int doorstoCross(struct passKeyNode *passKeyHead)
{

	if (passKeyHead == NULL)
		return -1;
	int count = 0;
	int len = 0;
	int dup = 0;
	int doorno = 0;

	passKeyNode *temp = passKeyHead, *nexttemp;
	while (temp->next != NULL)
	{
		//for normal length
		len = 0;
		//for duplicate
		dup = 0;
		count = 0;
		//nexxt node afte temp
		nexttemp = temp->next;
		while (nexttemp != NULL)
		{
			count++;
			//if 1st number in temp isless then the number present in the nexttemp at preseent
			if (temp->num < nexttemp->num)
				len++;
			//if number is same means digit is repeated
			else if (temp->num == nexttemp->num)
				dup++;
			nexttemp = nexttemp->next;
		}
		//now finding the door number
		if (dup>0)
			doorno = doorno + (fact(count - 1) + 1)*len;
		else
			doorno = doorno + (fact(count)*len);
		temp = temp->next;
	}
	//returning the total number of doors including the starting door
	return doorno + 1;
}
//	if (passKeyHead == NULL)
//		return -1;
//	struct passKeyNode *temp = passKeyHead;
//	int i = 0;
//	char number[20];
//	while (temp != NULL)
//	{
//		number[i] = num[i] = temp->num + 48;
//		temp = temp->next;
//		i++;
//	}
//	num[i] = '\0';
//	number[i] = '\0';
//	int n = strlen(number);
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = i + 1; j < n; ++j)
//		{
//			if (number[i] < number[j])
//			{
//				char a = number[i];
//				number[i] = number[j];
//				number[j] = a;
//			}
//		}
//	}
//	permute(number, 0, n - 1);
//	int ans = count;
//	return ans;
//}
//
//void permute(char *a, int i, int n)
//{
//	if (check != 1)
//	{
//		int j;
//		if (i == n)
//		{
//			count++;
//			if (strcmp(a,num)== 0)
//				check++;
//		}
//		else {
//			for (j = i; j <= n; j++)
//			{
//				if (check == 1){
//					break;
//				}
//				else {
//				swap((a + i), (a + j));
//				permute(a, i + 1, n);
//				swap((a + i), (a + j)); //backtrack
//				}
//			}
//		}
//	}
//}
//void swap(char *x, char *y)
//{
//	char temp;
//	temp = *x;
//	*x = *y;
//	*y = temp;
//}