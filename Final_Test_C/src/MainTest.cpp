/*
Final Test 1
Make Sure you submit well before time .
And dont repeteadtly submit ,as it will cause sync issues , Try to submit alteast with
5-10mins gap between each submit .
Make sure your files are uploaded to GoogleDrive before Time Expires.

95% of times ,The last minute Code changes wont fetch you any more marks .It might even
decrease or become 0 , If it leads to a Project Build Failure .
*/

#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include <stdlib.h>s
#include "FunctionHeaders.h"
struct node {
	int bin;
	struct node* firstnode;
	struct node* secondnode;
	struct node* thirdnode;
};
int charToInt(char bin){
	switch (bin){
	case '0':	return 0;
	case '1':	return 1;
	case '2':	return 2;
	}
	return -1;
}

struct node* createNewNode(char bin){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->bin = charToInt(bin);
	temp->firstnode = NULL;
	temp->secondnode = NULL;
	temp->thirdnode = NULL;
	return temp;
}

struct node* constructTree(char *binString){
	struct node* root = NULL;
	struct node* nodes[2005];
	int i = 0;
	while (binString[i] != '\0'){
		nodes[i] = createNewNode(binString[i]);
		i++;
	}
	int invalid = 2;
	int mid = (i / 3);
	for (int i = 0; i < mid; i++){
		struct node* curnode = nodes[i];
		struct node* firstnode = nodes[(i * 3) + 1];
		struct node* secondnode = nodes[(i * 3) + 2];
		struct node* thirdnode = nodes[(i * 3) + 3];
		if (curnode->bin != invalid){
			if (firstnode->bin != invalid){
				curnode->firstnode = firstnode;
			}
			if (secondnode->bin != invalid){
				curnode->secondnode = secondnode;
			}
			if (thirdnode->bin != invalid){
				curnode->thirdnode = thirdnode;
			}
		}
	}
	root = nodes[0];
	return root;
}

int main(){

	//Test here
	/*
	
	*/
	char* res = NearestSortedNumber("20", 2);
	const int N = 5, M = 5;
	int values[N][M] = {
		{ 2, 1, 0, 2, 1 },
		{ 1, 0, 1, 2, 1 },
		{ 1, 0, 0, 2, 1 }
	};
//	int res = lastOne(&values[0][0], 3, 5);
	/*struct node* x = constructTree("1010011100110111111111111111111111111111");
	int y = MaxGold(x);*/
	return 0;
}

