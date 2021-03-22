/*
Mock Test 2
Make Sure you submit well before time .
And dont repeteadtly submit ,as it will cause sync issues , Try to submit alteast with
5-10mins gap between each submit .
Make sure your files are uploaded to GoogleDrive before Time Expires.
95% of times ,The last minute Code changes wont fetch you any more marks .It might even
decrease or become 0 , If it leads to a Project Build Failure .
*/
#include <stdio.h>
#include "FunctionHeadersMockTest2.h"
#include <stdlib.h>
char *decode(char *);
char *encode(char *);
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *newNode_Mango(int key)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node * constructBinaryTree_spec(int *arr, int len){
	struct node *root = NULL;
	struct node *nodes[100];
	for (int i = 0; i < len; i++){
		nodes[i] = newNode_Mango(arr[i]);
	}
	int mid = (len / 2);
	for (int i = 0; i < mid; i++){
		struct node *curnode = nodes[i];
		struct node *leftnode = nodes[(i * 2) + 1];
		struct node *rightnode = nodes[(i * 2) + 2];
		if (curnode->data != -999){
			if (leftnode->data != -999){
				curnode->left = leftnode;
			}
			if (rightnode->data != -999){
				curnode->right = rightnode;
			}
		}
	}
	root = nodes[0];
	return root;
}

int compare_arrays_mc_spec(int *arr1, int *arr2, int len){
	int i = 0;
	while (i < len){
		if (arr1[i] != arr2[i]){
			return 0;
		}
		i++;
	}
	return 1;
}
void testMangoCollector(int advance, int *arr, int k, int ways_exp, int len, int *shortestpath_exp, int shortestpath_len_exp){
	struct node *root = constructBinaryTree_spec(arr, len);
	int finalarray[1000];
	int fl = 0;
	int ways = 0;
	ways = mangocity_count_ways(root, k, finalarray, &fl);
	//Assert::AreEqual(ways_exp, ways, L"Failed for Ways in MangoCollector", 1, 2);

	//Advance check checks ,shortestpath array and Len too ,Make it 0 ,if you want to Run only
	//for ways
	if (advance){
	//	Assert::AreEqual(fl, shortestpath_len_exp, L"Failed for ShortestPath Len in MangoCollector", 1, 2);
		if (fl == shortestpath_len_exp){
			int check = compare_arrays_mc_spec(finalarray, shortestpath_exp, shortestpath_len_exp);
			//Assert::AreEqual(1, check, L"Failed for ShortestPath in MangoCollector", 1, 2);
		}
	}

}
int main(){
	

	/*
	char *s1 = "abc,3\nbca,4\n";
	char *s2 = "bca,99\n";
	char *s3 = "cca,100\n";
	char * output = mini_leaderboard(s1,s2,s3);
	printf("[%s]", output);
	*/
	char *message = "roronoazoro";
	char *expectedEncoded = "onaozroorro";
	char *actual = encode(message);
	//Test encoding
	//char *message = "brook";
	//char *expectedEncoded = "orobk";
	//char *m = "orobk";
	////char *actual = encode(message);
	//char *s = decode(m);
	//testEncodeDecode();
	/*char *input = "<html><head></head></html>";
	int op = isStringValidDom(input);
	int expected = 1;*/
	int arr[] = { 10, 5, -2, 5, 1, 9, 9, -999, -999, 10, 1, -999, -999, 3, -1, -999, -999, -999, -999, -999, -999,
		-999, -999, -999, -999, -999, -999, -999, -999, -999, 1 };
	int k = 17;
	int ways_exp = 3;
	int shortestpath[] = { 10, -2, 9 };
	int shortestpath_len = 3;
	int len = sizeof(arr) / sizeof(arr[0]);
	testMangoCollector(1, arr, k, ways_exp, len, shortestpath, shortestpath_len);
}