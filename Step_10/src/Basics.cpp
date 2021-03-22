/*
Function Pointers Tutorial :
-> https://stackoverflow.com/questions/840501/how-do-function-pointers-in-c-work (If you try out samples it might be enough)
-> http://www.cprogramming.com/tutorial/function-pointers.html (Leave polymorphism)
-> https://www.youtube.com/watch?v=ynYtgGUNelE
-> https://www.youtube.com/watch?v=sxTFSDAZM8s
With function pointers, you can pass 1 function to another function and call first function from 2nd function.

Only start solving lessons, if you can did these things. (Do these in a diff project or some other compiler)
-> Implemented atleast 5-6 samples of function pointers code you read in tutorials
-> Printed out the addresses of Function pointers and played around.

TLDR :
Function Pointer Parameter: returnType (*functionParameterName)(parameter definitions);
Calling function : invokingFunctionName(&functionToBePassed);

First let us learn what function pointers and basic sample programs in it. Later we will learn the real use of them
during coding hashmaps etc.
*/
/*
Task 1 :
->Write a function "printDefaultMessage" which prints "Hello Function Pointers".
->Write one more function invokePrint1, which takes a function pointer.
->When invokePrint1 is called with address of printDefaultMessage, it should call printDefaultMessage.
(ie default message needs to be printed).
We solved this task for you, Carefully understand what we did.
*/
#include <stdio.h>
#include <stdlib.h>


void printDefaultMessage() {
	//Print default message.
	printf("Hello Function Pointers");
}

void invokePrint1(void(*print)()) {
	//print is a function pointer, which points to whatever function address that is passed.
	//In this example &printDefaultMessage is passed , so when print() is called, printDefaultMessage will be executed.
	
}

void task1() {
	//Pass printDefaultMessage Address to invokePrint1
	invokePrint1(&printDefaultMessage);
}

/*
Task 2: (Learn Function pointers which can take parameters)
->Write a function "printMessage" which takes a message and prints "Hello <Message>".
->Write one more function invokePrint2, which takes a function pointer and a message.
->When invokePrint2 is called with address of printMessage and a message, it should call printMessage and also pass the string it got.
.(ie message needs to be printed).
*/
void printMessage(char * message) {
	puts(message);
	
}

void invokePrint2(void(*print)(char *), char * message) {
	//Invoke print function here, which should call printMessage along with message
	print("message");
	
}

void task2() {
	//Take a fixed message string, and call invokePrint2 and also pass printMessage address.
	char *message = "Hello";
	invokePrint2(&printMessage, message);
}


/*
Task 3: (Learn Function pointers which can return values)
->Write a function subString which takes a string (str) and 2 integers (a,b), and returns the str[a:b]
ie if string is "abhijith" and a=2 and b=4 , return "bhi"
Consider string indexes are 1 indexed.
->Write one more function invokeSubStr, which takes a function pointer, a string and 2 indexes.
->When invokeSubStr is called with address of subString, str, and 2 indexes,
it should call subString with respective values and return the substring.
*/

/*
Substring function. 
Return a new string which is a substring of str from index a to b [inclusive]
*/
char * subString(char *str, int a, int b){
	char * temp=(char*)malloc((b-a+2)*sizeof(char));
	int t = 0;
	for (int i = a-1; i < b; i++)
		temp[t++] = str[i];
	temp[t] = '\0';
	return temp;
}

char * invokeSubStr(char * (*function_ptr)(char *, int, int), char * str, int a, int b) {
	//Invoke function_ptr function here, which should call subString along with a,b and return respective value
	return function_ptr(str, a, b);
	
}

void task3() {
	//Take a fixed message string,two indexes and call invokeSubStr and also pass subString address along with 2 indexes.
	
}

/*
Task 4 :
-> Write 4 functions, getSum,getDiff,getProduct and getDivisor, which will take 2 float numbers,performs the operation and
returns the result
-> Write a performOperation Function which takes a function pointer and 2 floats, and calls the function passed
and returns it value.
-> Write a task4 function which takes a 3 ints as input.
Operation Type Operand1 Operand2.
If Operation Type is 1, pass getSum function to  performOperation and 2 floats.
If Operation Type is 2, pass getDiff function to  performOperation and 2 floats.
If Operation Type is 3, pass getProduct function to  performOperation and 2 floats.
If Operation Type is 4, pass getQuotient function to  performOperation and 2 floats.
Expected output is like
Product of 9 and 5 is 45
or
Sum of 3 and 4 is 7 etc
*/
float getSum(float a, float b) {
	return a + b;
}

float getDiff(float a, float b) {
	return a - b;
}

float getProduct(float a, float b) {
	return a*b;
}

float getQuotient(float a, float b) {
	return a/b;
}

float performOperation(float(*operation)(float, float), float a, float b){
	//Call operation with a,b and return respective value.
	return operation(a,b);
}

void task4() {

	//Write 4 if elses, testing multiple operations , pass respective function pointers
	/*
	int operation = 1;
	float a = 6;
	float b = 3;

	if (operation == 1){
		printf("Sum is %f\n", performOperation(&getSum, a, b));
	}
	else if (operation == 2){
		performOperation(&getDiff, a, b);
	}
	*/

}

void test_functionpointers_starter() {

	//task1();
	//task2();
	//task3();
	//task4();

}