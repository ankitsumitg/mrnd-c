/*
Problem Code :PHEIGHTS

You are given an Array of Integers and length .The numbers in the array denotes the heights of the people .
Imagine people are standing one behind another and A[0] will be the last guy .

Ex: In the array of A:[1,8,3,4,2] . 2 is the first guy , 4 is behind him , 3 is behind 4 etc and so on . ie A[0] is behind a[1],a[2],a[3],a[4].
A[0] can see all people from A[1:Len-1]
A[1] can see all people from A[2:Len-1] etc

(You can view the set of people , as standing from Left to Right also if that makes it convinient)

There are now a set of Rules :
->Each person can also see the person who is ahead of him . (In the array you can treat it like he can see only the people who are on the right side ) .
->If a person height is X , he can only see the persons whose height are greater or equal than him (>=X). [Unless any person whose height is greater but is blocked by some other person
whose height is even more ]

Ex: Let Array be [2,5,7,6,8,4,5]
2 can see only 5,7,8 . [He cant see 6 because 7 blocks it]
5 can see 7,8 [Again he cant see 6, as 7 blocks it]
7 can see only 8
6 can see only 8
8 can see no one
4 can see 5 and 5 can see no one .

**You need to return an Array which is made up of the **index** of the person who can be viewed by max number of people and also how many people can see him.**
Like in the above example , you need to return the index of 8 ie 4 . As 8 can be watched by 3 people .where as every other element can be watched by fewer than 3 people .

If there are multiple people who can be viewed by same number of people , Return the Array whose index of the person is less .

Ex2 : Input :4,3,8,6,5,1,7,2  Output : Returns [6,3] [6 is the Index of 7 and 3 people can see him]
Ex3 : Input :1,2,7,20,3,5,4,9,8 Output : Returns [3,3] [3 is the Index of 20 and 3 people can see him]
Explanation for Ex3 : Even though both 20 and 9 can be watched by 3 people , as 20's index is less return that array .

Constraints :
0<=A[i]<=100000
0<=Len<=100000

In the case of 4,6,5,6,6,5,0 . 4 can see all three 6's .6 can also each other . The final ans is {4,4}

Note : Return NULL for Invalid Inputs .0 is also a valid viewbale people count .
*/
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
int orderA(int *a, int len);
int orderD(int *a, int len);
int incNless(int *a, int len);
int* getLeaderIndex(int *arr, int len)
{
	int index = 0;
	if (arr == NULL)
		return NULL;
	int* x = NULL;
	x = (int*)malloc(100000 * sizeof(int));
	int* y = NULL;
	y = (int*)malloc(2 * sizeof(int));
	int check = incNless(arr, len);
	if (check != -1)
	{
		//If the array is increasin upto certain elment and then the same patter n continues upto that element but that element is less then the previous element
		// Example 1 3 5 8 9 13 46 1 3 5 8 9 13 42 1 3 5 8 9 13 40 an so on here 46 is the most viewed element and its index is the number of times viewed
		y[0] = check;
		y[1] = check;
		return y;
	}  // if array is in ascending order
	else if (orderA(arr, len) == 1)
	{
		y[0] = len - 1;
		y[1] = len - 1;
		return y;
	}// if array is in decresing order
	else if (orderD(arr, len) == 1)
	{
		y[0] = 0;
		y[1] = 0;
		return y;
	}// if array is unorded
	else
	{
		int i = 0, j = 0;
		for (i = 0; i < len; i++)
			for (j = i + 1; j < len; j++)
			{
				int check = -1;
				if (arr[j]  > arr[i])
				{
					check = 0;
					int k = j - 1;
					while (k)
					{
						if (k >= i){
							if (arr[k] > arr[j])
							{
								check++;
								break;
							}
							k--;
						}
						else break;
					}
				}
				//storring each element which can be seen by each element
				if (check == 0)
				{
					x[index] = arr[j];
					index++;
				}
			}
			realloc(x, (index)*sizeof(int));
			//finding the max repeated element and how many times it is repeated
			int maxCount, maxElement, count;
			maxCount = INT_MIN;
			for (i = 0; i < index + 1; i++)
			{
				count = 1;
				for (j = i + 1; j < index + 1; j++)
				{
					if (x[j] == x[i])
					{
						count++;
						if (count > maxCount)
						{
							maxCount = count;
							maxElement = x[j];
						}
					}
				}
			}
		//	find the index of the max seen element
			for (int i = len - 1; i >= 0; i--)
				if (arr[i] == maxElement)
					y[0] = i;
			y[1] = maxCount;
			return y;// returing the element
		}
}
int orderA(int *a, int len)
{
	int check = 1;
	for (int j = 0; j<len-1; j++)
	{
		if (a[j]>a[j + 1])
		{
			check = 0;
			break;
		}
	}
	return check;
}
int orderD(int *a, int len)
{
	int check = 1;
	for (int j = 0; j<len-1; j++)
	{
		if (a[j]<a[j + 1])
		{
			check = 0;
			break;
		}
	}
	return check;
}
int incNless(int *a, int len)
{
	int check = -1;
	int j = 0;
	for (j = 0; j<len - 1; j++)
	{
		if (a[j]>a[j + 1])
		{
			check = j;
			break;
		}
	}
	int temp = check;
	//if j reaches array length tha it is in ascending order
	if (j == len - 1)
		return -1;
	//checking the pattern continues, if not then return -1
	for (j = check; j<len; j++)
	{
		if (a[check]<a[j + 1])
		{
			check = -1;
		}
	}
	// if 1st element is not equal
	if (a[0] != a[check + 1])
		check = -1;
	return check;
}