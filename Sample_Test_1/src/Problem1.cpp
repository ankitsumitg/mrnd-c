/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Given nums = [1, 20, 2, 4], target = 24,

Because nums[1] + nums[3] = 20 + 4 = 24,
return [1, 3].

If target is 5 ,Return [0,3]
If target is 22 ,return [1,3]

Note : 
Return_Array[0] should always be less than Return_Array[1]

Constraints : 
len <100000 
-100000< nums[i] <100000

Question Source Link : https://leetcode.com/problems/two-sum/
We Picked this standard problem from Online , as its a very famous one and you will get habituated on solving on
Leetcode .
*/
#include <stdio.h>
#include <stdlib.h>
int* sumoftwo(int *nums, int target, int len){
	if (nums == NULL)
		return NULL;
	int *a = (int*)malloc(2*sizeof(int));
	//Brute force approach
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (nums[j] == target - nums[i]) {
				a[0] = i;
				a[1] = j;
				return a;
			}
		}
	}
	return NULL;
}