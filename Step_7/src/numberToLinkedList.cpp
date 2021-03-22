/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES:

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
struct node * numberToLinkedList(int N) {
	if (N == 0)
	{
		struct node* temp = (node*)malloc(sizeof(node));
		temp->num = 0;
		temp->next = NULL;
		return temp;
	}
	else
	{
		struct node *head = NULL;
		if (N < 0)
			N = -N;
		int n;
		while (N > 0)
		{
			n = N % 10;
			//inserting at the beginning
			struct node *temp = (node*)malloc(sizeof(node));
			temp->num = n;
			temp->next = head;
			head = temp;
			N /= 10;
		}
		return head;
	}
}
