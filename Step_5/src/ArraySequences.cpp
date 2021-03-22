/*
Given an array which has two arithmetic sequences and
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array
will be start and end indexes of Second A.P

The final_arr[4], final_arr[5] values in final array
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index .

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int * find_sequences(int *arr, int len)
{
	if (arr == NULL)
		return NULL;
	int* x = NULL;
	x = (int*)malloc(6 * sizeof(int));
	int* a1 = NULL;
	a1 = (int*)malloc((len-1) * sizeof(int));
	float* a2 = NULL;
	a2 = (float*)malloc((len - 1) * sizeof(float));

	//No loops just main use of goto statement code is likely to be much optimized

	//Storing the consecutive diffrence in another array to check when the diffrence is same
	for (int i = 0; i < len - 1; i++)
		a1[i] = arr[i + 1] - arr[i];
	//Storing the consecutive ratio in another array to check when the ratio is same
	for (int i = 0; i < len - 1; i++)
		a2[i] = (float)arr[i + 1] / arr[i];
	int count = 0,i=0;
	//For first AP
	aaa:
		if (a1[i + 1] == a1[i])
		{
			if (count == 0)
				x[0] = i;
			x[1] = i + 2;
			count++;
			i++;
			goto aaa;
		}
		i++;
		if (count == 0)
			goto aaa;
		count = 0;
		//For second AP 
	bbb:
		if (a1[i + 1] == a1[i])
		{
			if (count == 0)
				x[2] = i;
			x[3] = i + 2;
			count++;
			i++;
			if (i == len - 2)
				goto ddd;
			goto bbb;
		}
		i++;
		if (i == len - 2)
			goto ddd;
		if (count == 0)
			goto bbb;
	ddd:
		count = 0;
		i = 0;
	//For GP
	ccc:
		if (a2[i + 1] == a2[i])
		{
			if (count == 0)
				x[4] = i;
			x[5] = i + 2;
			count++;
			i++;
			if (i == len - 2)
				goto eee;
			goto ccc;
		}
		i++;
		if (i == len - 2)
			goto eee;
		if (count == 0)
			goto ccc;
		eee:
	return x;
}