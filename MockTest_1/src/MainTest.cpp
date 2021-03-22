/*
Mock Test 1
Make Sure you submit well before time .
And dont repeteadtly submit ,as it will cause sync issues , Try to submit alteast with
5-10mins gap between each submit .
Make sure your files are uploaded to GoogleDrive before Time Expires.

95% of times ,The last minute Code changes wont fetch you any more marks .It might even
decrease or become 0 , If it leads to a Project Build Failure .
*/

#include <stdio.h>
#include <stdlib.h>
#include "FunctionHeaders.h"

int main(){

	//Test here
	/*
	long long start1 = 5, end1 = 100;
	long long start2 = 8, end2 = 8;
	int result = countCommonStars(start1,end1,start2,end2,55);

	printf("result = %d", result);
	*/
	/*long long result = 0;
	result = countCommonStars(1,5,5,6,5);
	return 0;*/
	//int len = 9;
	//int** expectedOutput = (int**)calloc(3, sizeof(int*));
	//for (int i = 0; i < 3; i++){
	//	expectedOutput[i] = (int*)calloc(100, sizeof(int));
	//}
	//expectedOutput[0][0] = 9;
	//expectedOutput[1][0] = 8;
	//expectedOutput[2][0] = 7;
	//expectedOutput[2][1] = 6;
	//expectedOutput[1][1] = 5;
	//expectedOutput[0][1] = 4;
	//expectedOutput[0][2] = 3;
	//expectedOutput[1][2] = 2;
	//expectedOutput[2][2] = 1;

	//int** Output = initialSnakePosition(len);
	long dragonPower3[] = { 7, 10, 6 };
	long energyPortion3[] = { 8, 9, 7 };

	int res3 = canSavePrincess(dragonPower3, energyPortion3, sizeof(dragonPower3) / sizeof(dragonPower3[0]));
}

