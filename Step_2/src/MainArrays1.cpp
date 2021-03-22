#include "FunctionHeadersArrays1.h"
#include <stdio.h>

struct student {
	char name[10];
	int score;
};

int main(){

	//Test RemoveArraysDuplicates
	
	//int arr[30] = { -2, -83, 67, 98, -72, -74, 29, 39, 60, 36, 4, -93, 83, -55, 69, -10, -29, 38, -64, -14, -93, 76, -58, 32, -84, 17, -64, 96, -40, -74 };
	//int len = maxPosNegSum(arr, 30);
	//printf("%d", len);
	int temp1[2] = { 2, 3 };

	int *num = sortedArrayInsertNumber(temp1, 2, 2);

	for (int i = 0; i < 6; i++)
	{
		printf("%3d", *(num + i));
	}

	//int c = removeArrayDuplicates(arr, 30);

	//Test Students Count
	/*
	int arr2[3]={1,4,10};
	int *newarray=sortedArrayInsertNumber(arr, 3, 3);
	printf("%d %d %d %d", newarray[0], newarray[1], newarray[2],newarray[3]);
	*/


	return 0;
}