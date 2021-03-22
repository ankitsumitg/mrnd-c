/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};
void inorder_check(node * root, node ** k, node ** temp1, node ** temp2);
void swap_nodes(struct node *a, struct node *b);
void fix_bst(node * root){
	if (root == NULL)
		return;
	//double pointer to store the address
	node *temp1 = NULL, *temp2 = NULL, **k = (node **)malloc(sizeof(node));
	k[0] = NULL;
	inorder_check(root, k, &temp1, &temp2);
	swap_nodes(temp1, temp2);
}
//by inorder sorting. NO new array is created

void inorder_check(node * root, node ** k, node ** temp1, node ** temp2){
	if (root == NULL)
		return;
	inorder_check(root->left, k, temp1, temp2);
	if (k[0] != NULL){
		if (root->data < k[0]->data){
			if (*temp1 == NULL)
			{
				*temp1 = k[0];
				*temp2 = root;
			}
			else
				*temp2 = root;
		}
	}
	k[0] = root;
	inorder_check(root->right, k, temp1, temp2);
}

void swap_nodes(struct node *a, struct node *b){
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}


