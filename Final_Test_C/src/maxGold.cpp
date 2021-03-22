/*
	problemCode : maxGold
	score : 20


 * Question:    Ragnar Lothbrok, a famous treasure collector went on an expedition to Paris. The Paris king offered him
 *              gold but the amount of gold offering depends on this problem.
 *				
 *              Ragnar need to start from the root of the 3-ary TREE and should reach any leaf. In this tree,
 *              each node contains either 0 or 1. Along the path travelled by Ragnar (root to leaf), forms a binary
 *              number. Ragnar will get the gold in tons of decimal value of the binary number.
 *
 *				A 3-ary tree is similar to any other tree except each node can have a maximum of 3 children.
 *
 *              Ragnar asked his intelligent friend Loki (you). How much maximum gold can they get,
 *
 * Example:                 1
 *                     /    |    \
 *                  0       1       0
 *                / | \   / | \   / | \   
 *               0  1  1 1  0  0 1  1  0
 *
 * Explanation:     In the above example, root to leaf paths are 100, 101, 101, 111, 110, 110, 101, 101, 100
 *                  Amoung them, 111 forms are highest decimal value which is 7.
 *                  So, Ragnar Lothbrok gets 7 tons of gold.
 *                  Return 7.
 *
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include<math.h>

struct node {
    int bin;
    struct node* firstnode;
    struct node* secondnode;
	struct node* thirdnode;
};

int height(struct node* n);
void pre(struct node* node, long long *data, long long c);
int binaryToDecimal(long long n);

int MaxGold(struct node* root) {
	if (root == NULL)
	return -1;
	//int h = height(root);
	//long long *x = (long long *)malloc(pow((double)2, h - 1)*sizeof(long long));
	long long data = 0;
	long long c = 0;
	pre(root, &data, c);
	int ans = binaryToDecimal(data);
	return ans;

}
int binaryToDecimal(long long n)
{
	long long num = n;
	long long dec_value = 0;
	long long base = 1;

	long long temp = num;
	while (temp)
	{
		long long last_digit = temp % 10;
		temp = temp / 10;

		dec_value += last_digit*base;

		base = base * 2;
	}

	return dec_value;
}
void pre(struct node* node, long long *data, long long c)
{
	if (node == NULL)
		return;
	c = c * 10 + node->bin;
	if (c > *data)
	{
		*data = c;
	}
	pre(node->firstnode, data, c);
	pre(node->secondnode, data, c);
	pre(node->thirdnode, data, c);
}

//int height(struct node* node)
//{
//	if (node == NULL)
//		return 0;
//	else
//	{
//		int l = height(node->firstnode);
//		int c = height(node->secondnode);
//		int r = height(node->thirdnode);
//
//		if (l > c && l> r)
//			return(l + 1);
//		else if (c > l&&c > r)
//			return(c + 1);
//		else return (r + 1);
//	}
//}
