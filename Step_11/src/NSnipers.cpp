/*
There is a general and he has N Snipers in his control . He has a battefield of NxN Blocks .
He now has to place all N snipers in the battle field such that he can have control of all Blocks,
ie each block should atleast have One sniper having control on it .

A Sniper has control of all blocks in line in all 4 directions . and also all blocks in all 4 diagonals
from his position .

Example :

. C C C
C C S C
. C C C
C . C .

In the above field if Sniper S is placed at (1,2) He has control of all blocks denoted by C .
But their is a problem for the General. All his snipers dont like each other So if any sees any
other sniper in his field of view (Control Blocks) ,he will instantly kill the other sniper .So
Your task is to help the general to place all his N Snipers on NxN field such that ,No sniper can
kill other sniper,but still have control of all the Blocks .

Input : A NxN battlefield , which is all 0's , and N (number of snipers )
Output : Return 1 if its General can place all N snipers or else return 0 .
		 Also modify the battlefield ,such that Blocks which have sniper placed are denoted by 1
		 and all other blocks as 0.

		 Note : If there are multiple correct arrangements ,Arrange in any 1 of the possible ways.
Example Input :
int battle_field[4][4]={0};
solve_nsnipers(&battle_field[0][0],4);

Example Output :
Returns 1 , and modifies battle_field as follows .
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0


Read :How to access elements in 2D array when its first element address is passed : http://www.geeksforgeeks.org/pass-2d-array-parameter-c/

P.S: The Above Problem is just a modified version of a popular BackTracking problem .
*/

#include "stdafx.h"
int solve_nsnipers_util(int *battlefield, int col, int N);
int isSafe(int *battlefield, int row, int col, int N);
int solve_nsnipers(int *battlefield, int n){
	if (battlefield == NULL)
	return 0;
	return solve_nsnipers_util(battlefield, 0, n);
}
int solve_nsnipers_util(int *battlefield, int col,int N)
{
	//if all sinperds are in place
	if (col >= N)
		return 1;

	//placing sniper one by one for a given a row
	for (int i = 0; i < N; i++)
	{
		//checking if safe or not
		if (isSafe(battlefield, i, col,N))
		{
			//putting the sniper if its safe
			battlefield[i*N+col] = 1;
			if (solve_nsnipers_util(battlefield, col + 1,N))
				return 1;
			//backtracking
			battlefield[i*N+col] = 0; 
		}
	}
//no solution return 0
	return 0;
}
int isSafe(int *battlefield, int row, int col,int N)
{
	int i, j;
	//checking rows rows on left
	for (i = 0; i < col; i++)
		if (battlefield[row*N+i])
			return 0;
	//diagonals 
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (battlefield[i*N+j])
			return 0;
	for (i = row, j = col; j >= 0 && i<N; i++, j--)
		if (battlefield[i*N+j])
			return 0;
	return 1;
}