/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL && head2 == NULL)
	return NULL;
	else if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	else{
		struct node *current = NULL, *head = NULL;  
		struct node *temp1 = head1, *temp2 = head2; 
		// head is equla to he list whose first element is small and current is equal to that lists
		if (temp1->num < temp2->num)
		{
			current = temp1;
			temp1 = temp1->next;
		}
		else
		{
			current = temp2;
			temp2 = temp2->next;
		}
		head = current;
		while (temp1 != NULL && temp2 != NULL) 
		{
			//If the data of one list is small than other, then the smaller data node should be pointed by current and current points to that node now
			if (temp1->num < temp2->num)  
			{
				current->next = temp1;
				current = temp1;
				temp1 = temp1->next;
			}
			else
			{
				current->next = temp2;
				current = temp2;
				temp2 = temp2->next;
			}
		}
		// append if one list is empty
		if (temp1 == NULL)
			current->next = temp2;
		else
			current->next = temp1;
		return head;
	}
}
