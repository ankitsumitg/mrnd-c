/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
void pre(struct node *root, int *arr, int *i);
void in(struct node *root, int *arr, int *i);
void post(struct node *root, int *arr, int *i);
void inorder(struct node *root, int *arr){
	if (arr == NULL)
		goto aa;
	int i = 0;
	in(root, arr, &i);
aa:;
}
void preorder(struct node *root, int *arr){
	if (arr == NULL)
		goto bb;
	int i = 0;
	pre(root, arr, &i);
bb:;
}
void postorder(struct node *root, int *arr){
	if (arr == NULL)
		goto cc;
	int i = 0;
	post(root, arr, &i);
cc:;
	
}
void pre(struct node *root, int *arr, int *i)
{
	if (root != NULL)
	{

	arr[*i] = root->data;
	*i = *i + 1;
	pre(root->left, arr,i);
	pre(root->right, arr,i);
	}
}
void in(struct node *root, int *arr, int *i)
{
	if (root != NULL)
	{
		in(root->left, arr, i);
		arr[*i] = root->data;
		*i = *i + 1;
		in(root->right, arr, i);
	}
}
void post(struct node *root, int *arr, int *i)
{
	if (root != NULL)
	{
		post(root->left, arr, i);
		post(root->right, arr, i);
		arr[*i] = root->data;
		*i = *i + 1;
	}
}

