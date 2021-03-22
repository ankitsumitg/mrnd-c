/*
Given two Binary Search Trees ,Merge Both of them into a Single Binary Search Tree .
The Resultant Binary Search Tree will be BST1 .ie Merge all elements of BST2 into BST1.
	Example 1:

	Input :
	20        25
	/  \      /  \
	5    30   10   35
	Output :

	Bst 1 :
	20
	/   \
	5     30
	\   /  \
	10 25   35

BST 2 can be merged in BST1 sometimes in many number of ways ,
Any 1 of those correct ways would be fine .

Finally All elements of Both Trees should be in BST 1 .Dont process NULL Inputs
If an element of BST2 is already in BST 1, then BST2 node is ignored.

(Both r1 and r2 shouldnt be NULL at the time of Input)
Note : Dont Create Nodes using malloc,or Swap the data values or else your solution would receive 100%
cut in the marks you got for this question .
You need to solve this question only by changing links.
You will also receive Bonus marks for any better optimizations you make .
Difficulty : Medium -Hard

*/
#include <stdlib.h>
#include <stdio.h>

#include <stdlib.h>
#include <stdio.h>

struct BstNode {
	int data;
	struct BstNode *left;
	struct BstNode *right;
};

void inorder(struct BstNode*, struct BstNode*);
void addNode(struct BstNode*, struct BstNode*);

void merge_two_bst(struct BstNode **root1, struct BstNode *root2) {

	if (root2 == NULL)
		return;
	struct BstNode *temp1 = *root1;
	if (!temp1){
		*root1 = root2;
		return;
	}

	struct BstNode *temp2 = *root1;
	struct BstNode *temp3 = root2;

	while (temp2->right != NULL)
		temp2 = temp2->right;

	int a = temp2->data;

	while (temp3->left != NULL)
		temp3 = temp3->left;

	int b = temp3->data;

	if (a < b)
		temp2->right = root2;

	else
	{
		inorder(temp1, root2);
		temp1 = *root1;
	}
}

void inorder(struct BstNode *root1, struct BstNode* root2)
{
	if (root2->left)
		inorder(root1, root2->left);

	root2->left = NULL;

	addNode(root1, root2);

	if (root2->right)
		inorder(root1, root2->right);

	root2->right = NULL;
}

void addNode(struct BstNode *root1, struct BstNode* node)
{
	if (root1->data == node->data)
		return;
	if (root1->data > node->data && root1->left)
		addNode(root1->left, node);
	else if (root1->data > node->data)
		root1->left = node;

	if (root1->data < node->data && root1->right)
		addNode(root1->right, node);
	else if (root1->data < node->data)
		root1->right = node;
}	