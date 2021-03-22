#include <stdio.h>
#include <stdlib.h>

/*
	Problem Code : Snake

	Srinivas is a snake lover. He recently started coding. He came across the snake game in his phone and he
	wanted to simulate it with his own coding knowledge. He divided the task into some modules and he asked
	your help for one of the modules. The module he asked is predicting the initial position of snake.

	The snake moves in the fashion shown below.

        1   ->   2  ->   3       ->      4        -> 5  
                 1       2               3           4 1
                         1               2 1         3 2       
	                                                                                                                                        
	Here 1 is the head of the snake.

	So initially the length of the snake is known.
	Now your job is to initialise the 2D matrix of 3x100 size with the position of the snake as shown above
	and leave the other positions as 0.
	
	Movement : Go down till end,Go right 1 step, Go Up till end,Go right 1 step, Repeat.
	
	Input : Length of the snake
	Output : Position of the snake based on its length.
	
	Ex:

	1)	Input =		1		
		Output = 	1


	2)	Input =		7
		Output = 	17   12  11  6  5
			    	16   13  10  7  4  1
                    15   14   9  8  3  2

					8
					8  3  2
					7  4  1
					6  5
 
	Return NULL for invalid cases.

*/



int** initialSnakePosition(int len){
	int** snakeBoard = NULL;
	if (len <= 0 || len >300)
		return NULL;

	//create snakeBoardHere
	snakeBoard = (int**)calloc(3, sizeof(int*));
	for (int i = 0; i < 3; i++){
		snakeBoard[i] = (int*)calloc(100, sizeof(int));
	}
	int temp = len;
	int k = 0;
	while (temp>0)
	{
		if (k % 2 == 0)
		{
			snakeBoard[0][k] = temp;
			temp--;
			snakeBoard[1][k] = temp;
			temp--;
			snakeBoard[2][k] = temp;
			temp--;
			k++;
		}
		else
		{
			snakeBoard[2][k] = temp;
			temp--;
			snakeBoard[1][k] = temp;
			temp--;
			snakeBoard[0][k] = temp;
			temp--;
			k++;
		}
	}
	//You can write any helper functions here, You need to fill the above created board
	return snakeBoard;
}