/*
Well Done for completing the first part of the C Course ,If you didnt finish
Do complete them and come here again .

Use MainArrays2 File for testing any other function in other Cpp files of the Strings Project.

DO NOT write main function in any other File or else your Build Fails.s

Objectives of C-Arrays-2 Lesson:

->Handling Arrays of Structures
->Sorting Arrays
->Learning Complexities of your Algorithm

*/
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

#include <stdio.h>
#include "FunctionHeadersArrays2.h"


int main(){

	//Test countGreaterNumbers
	//struct transaction Arr[5] = { { 60, "09-10-2003", "First" }, { 70, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 90, "21-05-2006", "Fourth" }, { 10, "29-11-2007", "Fifth" } };
//	int count = countGreaterNumbers(Arr, 5, "03-03-2005");

	//Test findSingleOccurenceNumber
//	struct transaction A[5] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 40, "21-10-2006", "Fourth" }, { 50, "13-11-2007", "Fifth" } };
//	struct transaction B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "22nd" }, { 320, "27-08-2015", "32nd" } };
	//int A[5] = { 1, 2, 3, 4, 5 }, B[3] = { 1, 22, 32 }, expected[1] = { 1 };
//	struct transaction expected[3] = { { 10, "09-10-2003", "First" } };
	//struct transaction *result = sortedArraysCommonElements(A, 5, B, 3);

	//Test mergeSortedArray

	//Test sortedArraysCommonElements

	//Test others
//	int input[10] = { 1, 100, 199, 5, 10, 15, 30, 60 };
//	int ans[6] = { 0, 2, 3, 5, 5, 7 };
//	int len = 8;
//	int *res = find_sequences(input, len);

	int arr[100] = { 0, 3, 8, 6, 5, 1, 7, 2 };
	int len = 8;
	int expectedArray[2] = { 6, 3 };
	int *actualArray = getLeaderIndex(arr, len);
//	int arr[100] = { 2, 20224, 20993, 20993, 0, 20242, 20245, 20254, 20257, 20258, 20993, 20993, 20260, 20275,
//		2, 20224, 20993, 20993, 0, 20242, 20245, 20254, 20257, 20258, 20993, 20993, 20260, 20275,
//		2, 20224, 20993, 20993, 0, 20242, 20245, 20254, 20257, 20258, 20993, 20993, 20260, 20275,
//		2, 20224, 20993, 20993, 0, 20242, 20245, 20254, 20257, 20258, 20993, 20993, 20260, 20275, };
//	int len = 14 * 4;
//	int ansLen = 0;
//	int expectedArray[100] = { 20224, 20242, 20245, 20254, 20257, 20258, 20260, 20275,
//		20224, 20242, 20245, 20254, 20257, 20258, 20260, 20275,
//		20224, 20242, 20245, 20254, 20257, 20258, 20260, 20275,
//		20224, 20242, 20245, 20254, 20257, 20258, 20260, 20275, };
	//int expectedLen = 32;

//	int *ans = getSquareLeaderArray(arr, len, &ansLen);

	return 0;
}
