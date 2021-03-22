/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

void enqueue(struct node* data);
struct node* dequeue();
int isEmpty();
struct node{
	struct node * left;
	int data;
	struct node *right;
};

int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)
		return NULL;
	int *arr = (int *)malloc(sizeof(int) * 20), i = 0;
	struct node *current;
	enqueue(root);
	while (!isEmpty())
	{
		current = dequeue();
		arr[i++] = current->data;
		if (current->right)
		{
			enqueue(current->right);
		}
		if (current->left)
			enqueue(current->left);
	}
	return arr;
}
//using queue node to store the data in linear way which are at same height

struct Qnode {
	struct node *data;
	struct Qnode *next;
}
*front = NULL, *rear = NULL;

void enqueue(struct node* data)
{
	struct Qnode *newNode = NULL;
	if (front == NULL)
	{

		newNode = (struct Qnode*)malloc(sizeof(struct Qnode));
		newNode->data = data;
		newNode->next = NULL;
		front = newNode;
		rear = newNode;
	}
	else
	{
		newNode = (struct Qnode*)malloc(sizeof(struct Qnode));
		newNode->data = data;
		newNode->next = NULL;
		rear->next = newNode;
		rear = rear->next;
	}
}
//after storing all the data just deques it
struct node* dequeue()
{
	struct Qnode *temp;
	if (front == NULL)
		return NULL;
	if (front == rear)
	{
		temp = front;
		front = rear = NULL;
		return temp->data;
	}
	temp = front;
	front = front->next;
	return temp->data;

}
int isEmpty()
{
	if (front == NULL)
		return 1;
	else
		return 0;
}