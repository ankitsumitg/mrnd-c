/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	int count = 0;
	// prev = head for k = 1
	struct node *prev = head, *current = head, *temp = NULL; 
	while (current != NULL)
	{
		count++;
		if (K == 0)
			break;
		//If k = 1 it will free() all the nodes till end or else it will free every kth element
		if (count % K == 0)   
		{
			prev->next = current->next;
			temp = current;
			current = current->next;
			free(temp);
			continue;
		}
		prev = current;
		current = current->next;
	}
	// If k = 1 the nodes are all free'd but head is still pointing somewhere so make it NULL
	if (K <= 1)  
	{
		head = NULL;
	}
	return head;
}