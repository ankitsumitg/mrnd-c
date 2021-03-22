/*
Use MainLinkedLists1 File for testing any other function in other Cpp files of the Strings Project.
DO NOT write main function in any other File or else your Build Fails.s
Do not write same add,display function in every CppFile .VS throws an error if two files
have some functions with same signature.
You can either change the signature in each file by using add1,display2 like that or
keep a common header file which has functions for handling common tasks for debugging
like displaying and include that header file in each Problem file .
Only jump into this lesson after you did all specified functions in Tutorial Lesson.
Objectives of C-LinkedLists-1 Lesson:
->Add/Delete/Display nodes in SLL
->Manipulate Links in SLL
->Handling SLL which have nodes of more than one data field
*/


//Do not edit below Header Files
#include <stdio.h>
#include <stdlib.h>
#include "FunctionHeadersLinkedLists1.h"

struct node {
	int data;
	struct node *next;
};

struct charNode{
	char letter;
	struct charNode *next;
};
struct charNode * createNode_Spec(char l) {
	struct charNode *newNode = (struct charNode *)malloc(sizeof(struct charNode));
	newNode->letter = l;
	newNode->next = NULL;
	return newNode;
}

struct charNode * createSLLFromString(char *str){
	int len = 0;
	int i = 0;
	while (str[i] != '\0'){
		len++;
		i++;
	}
	struct charNode *head = NULL;
	struct charNode *temp = NULL;
	i = 0;
	while (i < len){
		struct charNode *tempNode = createNode_Spec(str[i]);
		if (head){
			temp->next = tempNode;
			temp = tempNode;
		}
		else{
			head = tempNode;
			temp = tempNode;
		}
		i++;
	}
	temp->next = NULL;
	return head;
}
struct node * createNode(int n1) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = n1;
	newNode->next = NULL;
	return newNode;
}

struct node * add(struct node **head, int p){
	struct node *temp = *head;
	if (*head == NULL){
		(*head) = createNode(p);
		(*head)->next = NULL;
		return *head;
	}
	else{
		while (temp->next != NULL){
			temp = temp->next;
		}
		temp->next = createNode(p);
		temp->next->next = NULL;
		return temp->next;
	}
}

int check(int *nums, int len, struct node *head){
	int index = 0;
	struct node *temp = head;
	for (index = 0; index < len; index++){
		if (temp->data != nums[index]){
			return  0;
		}
		temp = temp->next;
	}
	return 1;
}

//Write  helper functions below with which you can create a sll on your own.
int isDivisibleSLL(struct charNode * head, int key);
int main(){

	//Test 012SortSll
	//Test numberToLinkedList

	//Test removeEveryKthNode

	//Test sortLinkedList

	//Test twodigitLinkedList

	//Test isDivSLL
//	char str[100] = "-1234";
//	int key = 6;
	//int expectedAns = 0;
//	struct charNode *head = createSLLFromString(str);
//	int actualAns = isDivisibleSLL(head, key);
	int num = 0;
	struct node *head = NULL;

	struct node *actualnodes[100];
	int actualNodeIndex = 0;
	int num_array[100] = { 2, 1, 0 };
	int output[100] = { 0, 1, 2 };
	int len = 3;
	int i = 0;
	for (i = 0; i<len; i++)
	{
		struct node * newNode = add(&head, num_array[i]);
		actualnodes[actualNodeIndex] = newNode;
		actualNodeIndex++;
	}
	sll_012_sort(&head);
	return 0;
}