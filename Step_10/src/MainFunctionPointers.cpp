/*
Hello All,

In this lesson you will learn 2 completely new concepts called as function pointers and void pointers ,and how they go hand in hand.
It will be very very difficult to understand at first, but dont give up go with the flow, and you will have a very good feeling of accomplishment
at the end.

With this lesson you will finally understand a lot about memory addresses, pointers, how C works, how to pass around data types as void * etc.

In this lesson there are 4 lessons.
First you need to solve Basics.cpp (go through the tutorials we posted there before solving any lesson)
Next you need to solve VoidPointers followed by MaxEqualSubArray and CombineCommonElements

Tips :
-> Use Pen and paper a lot, write down values and assign temp addresses to them and see how they are passing when each line of code is executed
-> Use debugger a lot, keep as many break points as possible and try it out. Increase timeouts during debugging or else it might fail.

Created By Abhijith - 9/4/2017
*/
#include "stdafx.h"
#include <stdlib.h>
int * max_equal_subarray(void ** values, int length, int(*compare)(void *, void *));
#include "FunctionHeaders.h"
char * subString(char *str, int a, int b);
int compareInt2(void * a, void *b);
void * getGreater(void *a, void *b, int(*compare)(void *, void *));
int main(){
	//int arr[12] = { 2, 2, 2, 3, 3, 3, 3, 3, 4, 5, 7, 7 };
	//int expectedStart = 3;
	//int expectedEnd = 7;
	//void** intvalues = (void **)malloc(sizeof(void *) * 12);
	//int i = 0;
	//for (i = 0; i<12; i++){
	//	intvalues[i] = (void *)&arr[i];
	//}
	//int * result = max_equal_subarray(intvalues, 12, &compareInt2);
	/*float a1 = 9.99;
	float a2 = 1.998;
	void * greater = getGreater((void *)&a1, (void *)&a2, &compareFloat);*/
	/*int a1 = 999;
	int a2 = 998;
	int check = compareInt((void *)&a1, (void *)&a2);*/
	/*char * message = "JonSnow";
	int a = 2;
	int b = 5;
	char * actual = subString(message, a, b);
	char expected[5] = "onSn";*/
	//Check Basics
	//test_functionpointers_starter()

	//Refer FunctionHeaders.h for other functions.
	test_combine_common_elements();
	return 0;
}