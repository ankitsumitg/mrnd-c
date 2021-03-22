/*
ProblemCode: Fibo2048Row
score : 20

Today you are going to develop a simple game called Fibo2048. You might have already played
this game on your mobile. There is a slight variation to the fibo2048 game vs the game you
already played.

In Fibo 2048, 2 Tiles will be merged only if they are consecutive numbers in the fibonacci series
Ie assuming fibonacci series is 1,1,2,3,5,8,13,21 ...
These pairs will can be merged (1,1) , (1,2) , (2,1) , (5,8), (8,5) etc
Pairs like (0,2) .. (1,7) . (1,5) wont be merged.

When 2 tiles are merged they will give rise to a new tile, whose value is the sum of numbers
of the 2 tiles which are merged.

Like if tile1 = 2, tile 2 = 3, mergedTile value is 5.

You can play this game at https://www.coolmath-games.com/0-2048-fibonacci

Here in this problem you need to implement mergeRow method which will take input 1 row,
and a direction (assume user input) . You need to modify the row by applying all merges which
can happen.

Rules :
-> A Tile which is already merged cant be merged again. Ie in 1,2,2,3, If direction is right,
Final answer would be 0,0,3,5. (but not 0,0,0,8) .
-> Each Tile in 1 turn will only take part in 1 merge.
-> If the direction is right, Priority is given to rightmost merges, ie 0,1,2,1 will change as
0,0,1,3 instead of 0,0,3,1. (Vice versa for left)
-> **A tile with 0 cant participate in a merge.**. Consider 0 as empty tile and dont process it.
-> Two tiles merging will result in 1 tile being 0 and other tile having its sum.
-> Row length will be same before and after merges you need to fill empty tiles after merges with
0s.

Input :
Array consisting of numbers, Length of array(row), Direction.

direction will be either 'r' or 'l'. 'r' denotes right swipe, 'l' denotes leftswipe.

SampleInputs/Outputs :
All below are examples for right merges.

0,0,0,1 -> 0,0,0,1 [No merges, 0 cant participate in a merge]
0,2,3 -> 0,0,5 [Simple 2,3 merges into 5]
0,3,2 -> 0,0,5 [2,3 or 3,2 both result into 5]
1,2,2,3 -> 0,0,3,5 [Double merge]
3,3,3,3 -> 3,3,3,3 [No merges]
3,3,5,1 -> 0,3,8,1 [3,5 -> 8]

Constraints and Notes :
-> Max Value in the row initally will be <=1000.
-> Min Value in the row will be 1.
-> Row can contain numbers which are not part of fibo series at all also, like 4,10,20 etc
-> Max Number that can be acheived after merges is <2000.
-> Two 1s being merges will give 2.
-> len will be <=2000

*/
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include <stdlib.h>
void mergerow(int *row, int len, char direction) {
	if (row == NULL || len <= 0)
		return;
	int fib[20] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765};
	int m = 1;
	while (m)
	{
		m = 0;
		if (direction == 'R')
		{
			for (int i = 0; i < len; i++)
			{
				if (i + 1 < len)
				{
					int x = row[i];
					int y = row[i + 1];
					if (x == 1 && y == 1)
					{
						row[i] = 0;
						row[i + 1] = 2;
						m++;
						i++;
					}
					else if (x == 1 && y == 2 || x == 2 && y == 1)
					{
						row[i] = 0;
						row[i + 1] = 3;
						m++;
						i++;
					}
					else if (x == 2 && y == 3 || x == 3 && y == 2)
					{
						row[i] = 0;
						row[i + 1] = 5;
						m++;
						i++;
					}
					else if (x == 3 && y == 5 || x == 5 && y == 3)
					{
						row[i] = 0;
						row[i + 1] = 8;
						m++;
						i++;
					}
				}
				
			}

		}
	}

}