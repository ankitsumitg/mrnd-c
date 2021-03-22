/*
This Project will seem to be little tougher than before ones .But It can be done very easily
once you completed C-Recursion Project completely .

Note : You can use the functions specified as wrapper functions ,and write new functions 
which might take more parameters .

*/
#include <stdio.h>
#include <stdlib.h>
#include "FunctionHeadersBST.h"



struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct node *newNode(int key)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node * new_node_spec(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node * add_node_spec(struct node *root, int data){
	if (root == NULL) return new_node_spec(data);

	if (data < root->data)
		root->left = add_node_spec(root->left, data);
	else if (data > root->data)
		root->right = add_node_spec(root->right, data);

	return root;
}

int main(){

	//Use it for testing ,Creating BST etc
	/*struct node *root = NULL;
	int nums[10] = { 2, 1, 3 };
	int elements = 3;
	for (int i = 0; i < 3; i++){
		root = add_node_spec(root, nums[i]);
	}

	int ans[3][3] = {
		{ 1, 2, 3 },
		{ 2, 1, 3 },
		{ 1, 3, 2 }
	};
	int results[3][3];
	inorder(root, &results[0][0]);
	preorder(root, &results[1][0]);
	postorder(root, &results[2][0]);*/
	/*struct node *root = NULL;
	int nums[20] = {10, 5, 15};

	for (int i = 0; i < 3; i++)
	{
		root = add_node_spec(root, nums[i]);
	}

	int h = get_height(root);
	int ls = get_left_subtree_sum(root);
	int rs = get_right_subtree_sum(root);
	int ans[3] = {2, 5, 15};
	int actualans[3] = {h, ls, rs};*/
}
