/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};
int min(int a, int b);
int min_height(struct node *root);
int min_dist(struct node *root, struct node *temp, struct node *prev_roots[], int current_level);
int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL || temp == NULL)
		return -1;
	//to store the nodes, once calculated
	struct node *prev_roots[10];
	return min_dist(root, temp, prev_roots, 0);
}
int min(int a, int b)
{
	return (a < b) ? a : b;
}
//finding minimum height from the current node
int min_height(struct node *root)
{
	if (root == NULL)
		return INT_MAX;
	if (root->left == NULL && root->right == NULL)
		return 0;
	return min(min_height(root->left), min_height(root->right)) + 1;
}

int min_dist(struct node *root, struct node *temp, struct node *prev_roots[], int current_level)
{
	if (root == NULL)
		return INT_MAX;
	//if current node reachees the temp node.
	//find the minimun height from the current level
	if (root == temp)
	{
		int d = min_height(root);
		for (int i = current_level - 1; i >= 0; i--)
			d = min(d, (current_level - i) + min_height(prev_roots[i]));
		return d;
	}
	prev_roots[current_level] = root;
	current_level = current_level + 1;
	//finding the minimum of left subchild or right subchild
	return min(min_dist(root->left, temp, prev_roots, current_level), min_dist(root->right, temp, prev_roots, current_level));
}

