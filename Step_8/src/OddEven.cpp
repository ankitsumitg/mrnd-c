/*
Given an SLL which has a modified version of node called oddevennode .
Each oddevennode will have a next pointer and a random pointer ,The next will point to the next oddevennode
in the SLL and random will point to NULL initially.

You need to modify the SLL random pointers in such a way that ,All odd numbers in the list
are connected by random pointers in the same order in which they are in SLL and the same for even numbers.

Ex : SLL is : 1-2-3-4-5-6 
Here 1->next will point to 2 ,2->next to 3 and so on till 6->next is NULL .All 1-6 nodes have random set to
NULL initially .Now you need to modify random pointers in such a way that First Odd number in List random will
point to second odd number in the list and so on .

so 1->random should point to 3 .3->random should point to 5 .5->random to NULL (As 5 is the last Oddnumber)
and 2->random should point to 4 ,4->random should point to 6 .6->random to NULL .(As 6 is last even number)

Return an Array consisting of two numbers [Oddcount,Evencount] or NULL for invalid Inputs

Ex 2 : 50->4->3->7->10->99->17
O.P : SLL randoms should be modified as .
50->4->10 . [Even numbers if transversed through Randoms from 50]
3->7->99->17. [Odd numbers if transversed through Randoms from 3]
The function SHOULD RETURN [4,3]  . Oddnumbers and Even numbers count array .

Note : The Order of Randoms Pointers should be in the same order they are in the original SLL .so if 33 has 
arrived before 5 in the SLL .33->random should be 5 but not in reverse .And it should also be continous ,Like 
if  there is only 1 odd node 71 any where between 33 and 5 ,33->random should point to 71 and 71->random should
point to 5.
The type if node is oddevennode ,and not Node .
*/
#include <stdlib.h>
#include <stdio.h>

struct oddevennode{
	int data;
	struct oddevennode * next;
	struct oddevennode * random;

};
//struct oddevennode * reverseLinkedList(struct oddevennode *head);
int * oddeven_sll(struct oddevennode *head){
	if (head == NULL)
	return NULL;
	else{
		struct oddevennode *temp = head,*next,*head1 = NULL,*head2 = NULL;
		int c1 = 0, c2 = 0;
		//traversing the list 
		while (temp != NULL)
		{
			//if odd
			if ((temp->data) % 2 != 0)
			{
				//if first number is odd the sore its addres
				if (head1 == NULL)
				{
					next = temp->next;
					head1 = temp;
					temp = temp->next;
					c1++;
				}
				//else set rondom to point to next number
				else
				{
					next = temp->next;
					head1->random = temp;
					head1->random->next = NULL;
					head1 = head1->random;
					temp->next = next;
					temp = temp->next;
					c1++;

				}
				/*struct oddevennode *temp1 = (oddevennode*)malloc(sizeof(oddevennode));
				temp1->data = temp->data;
				temp1->random = head1;
				head1 = temp1;
				temp = temp->next;*/
				
			}
			else
			{ //simmillary as above but for even number
				if (head2 == NULL)
				{
					next = temp->next;
					head2 = temp;
					temp = temp->next;
					c2++;
				}
				else
				{
					next = temp->next;
					head2->random = temp;
					head2->random->next = NULL;
					head2 = head2->random;
					temp->next = next;
					temp = temp->next;
					c2++;
				}

				/*struct oddevennode *temp1 = (oddevennode*)malloc(sizeof(oddevennode));
				temp1->data = temp->data;
				temp1->random = head2;
				head2 = temp1;
				temp = temp->next;
				c2++;*/
			}
		}

			//head1 = reverseLinkedList(head1);
			//head2 = reverseLinkedList(head2);
			//head->next = head1;
			//head = head2;
			//concat head 1 and head2 which sotres the odd and even numbers
			/*struct oddevennode *ptr;
			if (head1 == NULL)
			{
				head1 = head2;
			}
			ptr = head1;
			while (ptr->next != NULL)
				ptr = ptr->next;
			ptr->next = head2;
			//assigning it to random
			head->random = head1;*/
			int *a = (int*)calloc(2, sizeof(int));
			a[0] = c1;
			a[1] = c2;
			return a;
	}
}
//reverse function
//struct oddevennode * reverseLinkedList(struct oddevennode *head) {
//	struct oddevennode *temp, *prev, *current;
//	current = head;
//	prev = NULL;
//	while (current != NULL)
//	{
//		temp = current->random;
//		current->random = prev;
//		prev = current;
//		current = temp;
//	}
//	head = prev;
//	return head;
//}