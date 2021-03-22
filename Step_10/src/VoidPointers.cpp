/*
In this lesson you will be learning about void pointers , how to pass them, Why they are used etc.

Links : Just google "Void Pointers in C", (you can do the same in youtube too)

With void * as function parameter, you can pass address of any variable of any datatype. (By typecasting it to void*).
Lets say you wanted to write a sort function which sorts either list of ints, or floats or char etc.
You can write either 3 seperate quick sort functions 1 for each int sorting, float sorting and char sorting
or write a common quick sort function which takes void * array and can sort everything.

Void * are commonly used in conjuction with function pointers etc.
Yes I know most of you didnt understood a bit what I said, Lets learn this step by step.
Just go by task by task and patiently do it.
By the end of this lesson you are expected to have a good grip over void pointers and how to use them along side function
pointers.
*/
#include <stdio.h>
#include <stdlib.h>

/*
Void* is just a variable which can store address of any other variable (Irrespective of its dataType)
Task 5 :
-> Write a function which takes a void * ptr, and type cast it to int * and print its value.
Also return the int value stored in the ptr;
TLDR : Print and return the value printed.
*/

int typeCastVoidToInt(void * ptr) {
	int x = *(int*)ptr;
	return x;
}

void task5() {
	int a = 5;
	typeCastVoidToInt((void *)&a);
}

/*
Task 6 :
-> Write a function which takes a  4 void * ptr.
You need to typecast each one to a different datatype pointer and print it.
Example For printing float ptr value:
printf("Value stored at floar_ptr is  %ld",*(float *)float_ptr);
Expected output:
Value stored at long_ptr is 7
Value stored at float_ptr is 8.3
Value stored at char_ptr is a
Value stored at str_ptr is voidpointers
*/

void typeCastToAllDataTypes(void * long_ptr, void * float_ptr, void * char_ptr, void * str_ptr) {
	printf("Value stored at long_ptr is %ld\n", *(long *)long_ptr);
	//Other code
	printf("Value stored at float_ptr is %f\n", *(float *)float_ptr);
	printf("Value stored at char_ptr is %c\n", *(char *)char_ptr);
	printf("Value stored at str_ptr is ");
	puts((char *)str_ptr);
	printf("\n");
}

void task6() {
	long a = 7;
	float b = 8.3;
	char c = 'a';
	char * d = "voidpointers";
	//Call typeCastToAllDataTypes with a,b,c,d . You need to find out
	//each variable address and then typecast to void * before passing.(Well for some just typecasting might be enough)
	typeCastToAllDataTypes((void *)&a, (void *)&b, (void *)&c, (void *)&d);
	
}

/*
Task 7 :
-> You are given 3 functions which each return a void *.
You need to call each of these functions, Typecast them to their respective datatype pointers,and print the values.
Expected output is
Float is 5.7
Int is 9
String is samplestring
*/

void * getFloatAsVoidStar() {
	/*
	What happens if you didnt use malloc and just declare a constant and return its address.Think.
	*/
	float *a = (float *)malloc(sizeof(float));
	*a = 5.7;
	return (void *)a;
}

void * getIntAsVoidStar() {
	int *a = (int *)malloc(sizeof(int));
	*a = 9;
	return (void *)a;
}

void * getStringAsVoidStar() {
	char * str = "samplestring";
	return (void *)str;
}

void task7() {
	//Call getFloatAsVoidStar,getIntAsVoidStar and getStringAsVoidStar and print their values.
	
}


/*
Task 8 and 9  and 10: (These 3 tasks are related to each other)
-> First write 3 functions which compares either 2 ints or floats or chars and returns 1 if first parameter is greater
or 0 if equal or -1 if lesser.
Return type of these functions will be int, and parameters types will be void *. (You need to typecast and compare)

->Write a function which takes 2 void * values, and one compare function (which also takes 2 void *), and returns
address of which value is greater. (If equal return first address)
Ie .
This code sample should work
float val1 = 4;
float val2 = 5.5;
void * a = (void *)&val1;
void * b = (void *)&val2;
printf("Float : %f is greater between 4 and 5.5\n", *(float *)getGreater(a,b,&compareFloat));

ie .
getGreater uses compareFloat function to find which value is greater and then returns its address.
You need to typecast void * to float * and print it.

Note : See how void * function is declared and used in parameters, return types etc.
*/

int compareInt(void * a, void *b) {
	//Type cast to int *.extract value and compare
	if (*(int*)a > *(int*)b)
		return 1;
	else if (*(int*)a == *(int*)b)
		return 0;
	else return -1;
	
}

int compareFloat(void * a, void *b) {
	if (*(float*)a > *(float*)b)
		return 1;
	else if (*(float*)a == *(float*)b)
		return 0;
	else return -1;
	
}

int compareChar(void * a, void *b) {
	//a and b hold only 1 character
	if (*(char*)a > *(char*)b)
		return 1;
	else if (*(char*)a == *(char*)b)
		return 0;
	else return -1;
}
//Optional Do for compareStrings also.

void * getGreater(void *a, void *b, int(*compare)(void *, void *)) {
	//Use passed compare function.
	int x = compare(a, b);
	if (x == 1)
		return (void*)a;
	else return (void*)b;
}

void task8() {
	float val1 = 4;
	float val2 = 5.5;
	void * a = (void *)&val1;
	void * b = (void *)&val2;
	//Passing compareFloat to getGreater as function pointer.
	printf("Float : %f is greater between 4 and 5.5\n", *(float *)getGreater(a, b, &compareFloat));

	char val3 = 'a';
	char val4 = 'z';
	void * a1 = (void *)&val3;
	void * b1 = (void *)&val4;
	printf("Float : %c is greater between a and z\n", *(char *)getGreater(a1, b1, &compareChar));

	//Optional do for strings too. Pass 2 strings to getGreater and print which is alphabatically before/after.
}

/*
Same like above but with 3 void *, Use compareInt,compareFloat and compareChar functions to return addresses of 2 greater elements among the 3.
Write a function which finds out maximum 2 values in the passed 3 values and returns it as an array.
Parameters :
3 void *, and one function pointer to compare whether one void * is greater/lesser than other void *.

Return Type :
Array of 2 void *. result[0] will be a void * pointing to value which is greatest among 3, and
result[1] will be a void * pointing to next value which is greatest among 3.
Note :Compare the values not the addresses.

Assume all 3 values are unique.
Sample Input (Memory Layout):
[Address : 100] int a = 5; void * addr1 = (void *)&a;
[Address : 104] int b = 6; void * addr1 = (void *)&b;
[Address : 108] int c = 7; void * addr1 = (void *)&c;
So
addr1 : 100
addr2 : 104
addr3 : 108

Return an array which has addresses [108,104] (108 points to maximum value in the 3 passed values ie 7)
Assume each value is unique
*/
void ** getTwoGreater(void *addr1, void *addr2, void *addr3, int(*compare)(void *, void *)) {
	//Use malloc and create a array of 2 void *.
	int x = compare(addr1, addr2);
	int y = compare(addr2, addr3);
	
	void ** result = (void **)malloc(sizeof(void *) * 2);
	if (compare(addr1, addr2) == 1 && compare(addr1, addr3) == 1)

		if (compare(addr2, addr3) == 1)
		{
			result[0] = addr1;
			result[1] = addr2;
		}
		else
		{
			result[0] = addr1;
			result[1] = addr3;
		}

	if (compare(addr2, addr1) == 1 && compare(addr2, addr3) == 1)

		if (compare(addr1, addr3) == 1)
		{
			result[0] = addr2;
			result[1] = addr1;
		}
		else
		{
			result[0] = addr2;
			result[1] = addr3;
		}

	if (compare(addr3, addr2) == 1 && compare(addr3, addr1) == 1)

		if (compare(addr2, addr1) == 1)
		{
			result[0] = addr3;
			result[1] = addr2;
		}
		else
		{
			result[0] = addr3;
			result[1] = addr1;
		}

	//Write your code here. You can use compare to know which value is greater between any 2 addresses.
	//Assume if all void * are of float type, then compare function will also be a compareFloat one.
	return result;
}

void task9() {
	//Take 3 float values, pass those 3 variables addresses as void * to getTwoGreate function and print result[0],result[1];


	//Test the same for ints and char also.
}

/*
See previously instead of writing the same code 3 times for different data types where most of the code is same
, we solved it with a single function, and some datatype specific methods.

Lets now take this to next level. Solve MaxEqualSubSequence.cpp question.
*/
void test_voidpointers() {
	//task5();
	//task6();
	//task7();
	//task8();
	//task9();
}