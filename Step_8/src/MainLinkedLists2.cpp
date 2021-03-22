/*

Use MainLinkedLists2 File for testing any other function in other Cpp files of the Strings Project.

DO NOT write main function in any other File or else your Build Fails.

Objectives of LinkedLists2 Lesson:

->Merging two Linked Lists
->Reversing a LinkedList
->Inserting at a specific index

*/
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
	int val;
	struct ListNode *next;
};
//struct node * createNode(int num) {
//	struct node *newNode = (struct node *)malloc(sizeof(struct node));
//	newNode->num = num;
//	newNode->next = NULL;
//	return newNode;
//}
//
//struct node * createList(int num) {
//	struct node *head = createNode(num % 10);
//	num /= 10;
//	while (num) {
//		struct node *newNode = createNode(num % 10);
//		newNode->next = head;
//		head = newNode;
//		num /= 10;
//	}
//	return head;
//}
//bool compare(struct node *result, int num) {
//	struct node *head = createList(num);
//	while (head && result && head->num == result->num) {
//		head = head->next;
//		result = result->next;
//	}
//	return !head && !result;
//}
//struct node * createNode(int num) {
//	struct node *newNode = (struct node *)malloc(sizeof(struct node));
//	newNode->data = num;
//	newNode->next = NULL;
//	return newNode;
//}
//
//void addNode(struct node **head, int data){
//	struct node * cur = createNode(data);
//	if (*head == NULL){
//		*head = cur;
//	}
//	else{
//		struct node *temp = *head;
//		cur->next = temp;
//		*head = cur;
//	}
//}
//struct ListNode *createNode_P6(int val){
//	struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
//	newNode->next = NULL;
//	newNode->val = val;
//	return newNode;
//}
//
//struct ListNode* createList_P6(char *s){
//	int i;
//	struct ListNode *walker = NULL;
//	struct ListNode *head = createNode_P6(s[0]);
//	walker = head;
//	for (i = 1; s[i] != '\0'; i++){
//		walker->next = createNode_P6(s[i]);
//		walker = walker->next;
//	}
//
//	return head;
//}
//
//void createDataAndTest_P6(char *input, char *expectedOutput) {
//	struct ListNode * head = createList_P6(input);
//	void pairUp(struct ListNode *head);
//	pairUp(head);
//
//	char actualStr[510] = "";
//	int i = 0;
//
//	while (head){
//		actualStr[i] = (head->val);
//		head = head->next;
//		i++;
//	}
//
//	i = 0;
//	while (expectedOutput[i] != '\0' || actualStr[i] != '\0'){
//		
//		i++;
//	}
//
//}
struct passKeyNode
{
	int num;
	struct passKeyNode *prev;
	struct passKeyNode *next;
};
struct passKeyNode *createnode(int num)
{
	struct passKeyNode *new_node = (struct passKeyNode*)malloc(sizeof(struct passKeyNode));
	new_node->num = num;
	new_node->prev = NULL;
	new_node->next = NULL;
	return new_node;
}

struct passKeyNode* strtoDLL(char *str)
{
	int len = 0;
	while (str[len] != '\0'){
		len++;
	}
	if (len == 0)
		return NULL;

	struct passKeyNode *head = createnode(str[len - 1] - '0');
	for (int i = len - 2; i >= 0; i--)
	{
		struct passKeyNode *temp = createnode(str[i] - '0');
		head->prev = temp;
		temp->next = head;
		head = temp;
	}

	return head;
}
#include <stdio.h>
#include "FunctionHeadersLinkedLists2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//void make_it_circular(struct node *head){
//	struct node *temp = head;
//	while (head->next != NULL){
//		head = head->next;
//	}
//	head->next = temp;
//}


int main(){

	//Test InsertAtEveryKthNode

	//Test LinkedListMedian
	//linkedListMedian(createList(19));

	//Test merge2 LinkedLists

	//Test reverse LinkedList
	//int dates[2][8] = { { 2, 4, 0, 3, 1, 9, 0, 0 }, { 0, 1, 0, 9, 2, 0, 1, 1 } };

	//struct node *date1head = NULL, *date2head = NULL;
	//for (int i = 7; i >= 0; i--){
	//	addNode(&date1head, dates[0][i]);
	//	addNode(&date2head, dates[1][i]);
	//}
	////1096+282+82
	//int days = between_days(date1head, date2head);
	//int nums[5] = { 1, 3, 5 };
	//int nums2[5] = { 2, 4, 6 };
	////Last 1 is for checking whether A is circular or not .6 should again point to 1
	//int ans[10] = { 1, 2, 3, 4, 5, 6, 1 };

	//int l1 = 3, l2 = 3, i;
	//struct node *head1 = NULL;
	//struct node *head2 = NULL;
	//for (i = l1 - 1; i >= 0; i--){
	//	addNode(&head1, nums[i]);
	//}
	//for (i = l2 - 1; i >= 0; i--){
	//	addNode(&head2, nums2[i]);
	//}
	//make_it_circular(head1);
	//make_it_circular(head2);

	//int len = merge_circularlists(&head1, &head2);
	//createDataAndTest_P6("123456", "162534");
	struct passKeyNode *passkey = strtoDLL("53124");
	int actualAns = doorstoCross(passkey);

	return 0;
}