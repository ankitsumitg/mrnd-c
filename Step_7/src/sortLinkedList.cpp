/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};
struct node * sortLinkedList(struct node *head) {

	//Bubble sort method
	struct node *p1 = head, *p2;
	if (head == NULL)
		return NULL;
	while (p1 != NULL)
	{
		p2 = p1->next;
		while (p2 != NULL)
		{
			if (p1->num > p2->num)
			{
				//swapping the data bits if first number is greater than the second number
				int temp = p1->num;
				p1->num = p2->num;
				p2->num = temp;
			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	return head;
}