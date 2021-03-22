/*
Complexity Lesson

You are expected to run main function in this lesson multiple times, 
for each function,play around with multiple inputs,Form random large samples of data,
note down timings and report them in forum .We hope you learn in correct way. 
This is the reason we allocated 10 days for this lesson

How to do this lesson.
This lesson is not about passing testcases and submitting, Its about learning how to measure your code
how to find compelxity of your code etc. So dont just finish lesson asap, just by passing testcases,
Spend atleast 1-2 hours on each question finiding complexity,measuring time etc.

1st Activity is TimeComplexity.cpp where you will be given 10-15 code samples, you need to find out what each code
complexity is.

2) In PrimeNumber Testing you will write code in multiple ways to find whether a number is prime or not
and note down the performance measurements.

The same thing you will do for other questions as well Search,TwoSum,NPrime etc. 

Solve questions in this order TimeComplexity,PrimeNumber,Search,TwoSum,NPrime.

For each question there will be a observations comment box at top, fill it with your timings etc.

The test cases are timed for optimized functions, if you get timeout exception ,you really need to think and optimize your code.

Note :
If you give largeinputs to a bruteforce function it takes lot of time to execute. Think and Test.

We are expecting timings like this for a sample question:

Way1 : BruteForce :
100 loopCount, 1000 Elements. Time took : 50 seconds

Way 2: Optimized :
1000 loopCount, 1000 Elements : Time took : 3seconds.

Helpful Links : (Go through these before starting lesson, Copy Paste links)
•https://www.youtube.com/watch?v=PFd5s0bHgAQ
•https://www.hackerearth.com/practice/basic-programming/complexity-analysis/time-and-space-complexity/tutorial/
•http://discrete.gr/complexity/
•Robert Sedgewick's Algorithms(4th edition)

Author: Abhijith Ravuri & SVSRK Praveen
*/


#include <stdio.h>
#include "FunctionHeaders.h"
#include <iostream>
#include <time.h>

void measurePrimeNumberCheckingBruteForce();
void measurePrimeNumberCheckingSquareRoot();
void measurePrimeNumberCheckingOptimized();

int main(){
	/*
	//int temp = isPrimeSquareRoot(104395303);
	int a[6] = {4, 0,0,0, 1, 2 };
	int* ans = sumoftwoSortAndSearch(a, 5, 6);
	printf("%d%d", ans[0], ans[2]);
	//int actualIndex2= binarySearch(a, 3, 1);
	//printf("Prime checking for 9 should return 0, Got %d\n", isPrimeOptimized(9));

	*/

	int output1[168] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73,
		79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179,
		181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
		283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401,
		409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521,
		523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643,
		647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769,
		773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907,
		911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997 };

	int* Arr2;
	Arr2 = nPrimeOptimized(1000);
	for (int i = 0; i < 168; i++)
	{
		if(output1[i]!=Arr2[i]) printf("Error at %d\n",i);
	}

	printf("Running your code, it might take some time to finish...\n");

	void measureTwoSumOptimized();
	measureTwoSumOptimized();

	//Prime Check sample code
	//measurePrimeNumberCheckingBruteForce();
	//measurePrimeNumberCheckingSquareRoot();
	//measurePrimeNumberCheckingOptimized();
	
	//Do similar observations for Search
	/*
		See and understand how timing code is written for prime functions and write the same.
		You need to start time before calling searchFunction and then end time after calling.
		You wont notice much difference between linear search and binary search if you do it for small arrays
		Do it fo either very large array (100,0000 elements) or do it 10000 times for 10000elements. 
		Check Search_Test3.
		(Same which we did for prime)
	*/

	//Do similar observations for 2Sum

	//Do similar observations for nPrime.
	
}

void measureTwoSumOptimized() {
	clock_t start, end;
	double cpu_time_used;
	//we are running multiple times just to understand the effect of time complexity.(Good vs Bad)
	int a[1000] = { 77 };
	a[989] = 20;
	a[993] = 5;
	a[343] = 98;
	int len = 1000;
	int i1 = 5;
	int i2 = 20;
	int target = 25;
	int numberOfTimes = 1;

	start = clock();
	for (int i = 0; i < numberOfTimes; i++){
		int* ans = sumoftwoExtraArray(a, target, len);
		if (ans == NULL){
			printf("Wrong answer of TwoSum\n");
		}
		else
		{
			if (i1 != ans[0]) printf("Error of first variable");
			if (i2 != ans[1]) printf("Error of first variable");
		}
	}
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("For %d times, Took %f seconds in TwoSumOptimized\n", numberOfTimes, cpu_time_used);
}

void measurePrimeNumberCheckingBruteForce() {
	clock_t start, end;
	double cpu_time_used;
	//we are running multiple times just to understand the effect of time complexity.(Good vs Bad)
	int numberOfTimes = 5;
	start = clock();
	for (int i = 0; i < numberOfTimes; i++){
		//The below number 232910011 is a prime number.
		int primeCheck = isPrimeBruteForce(232910011);
		if (primeCheck == 0) {
			printf("You are returning a wrong answer for brute force prime checking\n");
			break;
		}
	}
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("For %d times, Took %f seconds in bruteForce\n", numberOfTimes, cpu_time_used);
}

void measurePrimeNumberCheckingSquareRoot() {
	clock_t start, end;
	double cpu_time_used;
	//we are running multiple times just to understand the effect of time complexity.(Good vs Bad)
	//You can increase or decrease it to fully understand the effect.
	int numberOfTimes = 10000;
	start = clock();
	for (int i = 0; i < numberOfTimes; i++){
		//The below number 232910011 is a prime number.
		int primeCheck = isPrimeSquareRoot(232910011);
		if (primeCheck == 0) {
			printf("You are returning a wrong answer for is prime square root checking\n");
			break;
		}
	}
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("For %d times, Took %f seconds in square root way\n", numberOfTimes, cpu_time_used);
}

void measurePrimeNumberCheckingOptimized() {
	clock_t start, end;
	double cpu_time_used;
	//we are running multiple times just to understand the effect of time complexity.(Good vs Bad)
	int numberOfTimes = 1000;
	start = clock();
	for (int i = 0; i < numberOfTimes; i++){
		//The below number 232910011 is a prime number.
		int primeCheck = isPrimeOptimized(232910011);
		if (primeCheck == 0) {
			printf("You are returning a wrong answer for is prime optimized checking\n");
			break;
		}
	}
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("For %d times, Took %f seconds in square root way\n", numberOfTimes, cpu_time_used);
}