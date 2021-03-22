/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes
will be followed by ones and then twos.

You should only change the links and shouldnt swap the data. Basically no write operation should be done on data field.

INPUTS:  SLL head pointer
OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2
ERROR CASES:
NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

/*
Optional : For this function swapping data is allowed.Although this wont be tested on our end.
It is only for learning purpose.
*/
void sll_012_sort_swapData(struct node **head){

}

/*
This is the actual function. You are supposed to change only the links.
*/
void sll_012_sort(struct node **head){
	/*Put 0s towards the head and put 2s towards the tail. Dont change the 1s*/

	struct node* head1 = *head;
	if (head1 == NULL || head1->next == NULL)
		return;
	// pointer to last node in the list
	struct node* end = *head;
	int numOfNodes = 1;
	while (end->next != NULL)
	{
		end = end->next;
		numOfNodes++;
	}
	node *tail = end;
	node *ptr = *head;
	node *prev = *head;
	for (int i = 0; i<numOfNodes; i++)
	{
		node* temp = ptr;
		ptr = ptr->next;
		if (temp->data == 0)
		{
			// Inserting at head (If First Node - Skip)
			if (prev != temp)
			{
				temp->next = *head;
				*head = temp;
				prev->next = ptr;
			}
		}
		else if (temp->data == 2)
		{
			// Inserting at the End.
			tail->next = temp;
			temp->next = NULL;
			tail = temp;
			// If first Node.
			if (prev == temp)
				*head = prev = ptr;
			else
				prev->next = ptr;
		}
		else
		{
			if (prev != temp)
				prev = prev->next;
		}
	}
}

