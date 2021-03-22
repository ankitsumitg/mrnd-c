#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ReversiGame {
	
	char **board;	// char 'w' for whites, 'b' for blacks ' ' for empty 
	// do allocate memory for '\0' as it is character array.
	char *player1name;
	char *player2name;
	int whiteCount = 0;
	int blackCount = 0;
	int NumberofMoves = 0;
	int rows, cols;
	int turn = 1;   //1 for white, -1 for black
	int state = 0;  //0 for unfinished, 1 for game over
	int winner = 0; //1 for white, -1 for black
}ReversiGame;


void endGame(ReversiGame *game);
int hasMove(ReversiGame *game);
void modifyTurn(ReversiGame *game);
int checkReversiGameOver(ReversiGame *game);
/*

Create a new ReversiGame By allocating memory from Heap , Let it be game;
Create a 2D Array from Heap(Dynamically) with specified number of rows and cols
and copy its reference to game->board;

Note : Return NULL for Invalid Inputs
Note : Copy Rows into newlyCreatedBoard->rows , and vice versa for cols ,
Also copy player1name,player2name.
*/

ReversiGame * createNewGame(int rows, int cols, char *player1, char *player2) {

	int i = 0;

	if (rows != cols)
		return NULL;

	ReversiGame* newBoard = (ReversiGame*)malloc(sizeof(ReversiGame));
	newBoard->rows = rows;
	newBoard->cols = cols;
	newBoard->player1name = player1;
	newBoard->player2name = player2;
	newBoard->NumberofMoves = 0;
	newBoard->state = 0;
	newBoard->blackCount = 0;
	newBoard->whiteCount = 0;
	newBoard->winner = 0;



	char** game = (char**)malloc(rows*sizeof(char*));
	for (i = 0; i < rows; i++)
		game[i] = (char*)malloc((cols + 1)*sizeof(char));

	newBoard->board = game;

	return newBoard;
}


/*
Copy the tobeCopied Array into game->board .
Learn how to Copy a 2D array when address of first row is given.
Note this function is called in the following way

Also Initialize the turn variable, whiteCount with no of white coins and same for black.

Do Nothing for Invalid Inputs
*/

void initializeReversiGame(ReversiGame *game, char *tobeCopiedBoard, int rows, int cols, int turn) {

	if (rows != cols)
		return;

	if (rows<1 || cols<1)
		return;

	if (tobeCopiedBoard == NULL)
		return;

	int i = 0;
	int j = 0;
	char temp;
	int whiteCount = 0;
	int blackCount = 0;

	for (i = 0; i < rows; i++){
		for (j = 0; j < cols; j++){
			
			game->board[i][j] = *(tobeCopiedBoard + i*(cols + 1) + j);

			temp = game->board[i][j];

			if (temp == 'w')
				whiteCount++;

			else if (temp == 'b')
				blackCount++;

			else
				continue;
		}
	}

	game->blackCount = blackCount;
	game->whiteCount = whiteCount;

	
	game->turn = turn;
	
	
	if (hasMove(game)){

		game->turn = turn;
	}

	else{

		game->turn *= -1;
	}
	
	checkReversiGameOver(game);

	

	return;
}

/*
Check if the Current board is in End Position . Return 0 if the game is Ended, 1 if not .
Win Condition : Either all the squares are filled or a stalemate position (No one can Move)

*/

int checkReversiGameOver(ReversiGame *game){

	int temp1 = (game->rows)*(game->cols);
	int temp2 = ((game->blackCount) + (game->whiteCount));

	if (temp1 == temp2){

		game->state = 1;
		endGame(game);
		return 0;
	}

	else if (game->blackCount == 0){
		
		game->state = 1;
		game->winner = 1;
		endGame(game);
		return 0;
	}
	
	else if (game->whiteCount == 0){

		game->state = 1;
		game->winner = -1;
		endGame(game);
		return 0;
	}
	
	else{

		if (hasMove(game))
			return 1;

		modifyTurn(game);

		if (hasMove(game))
			return 1;

		modifyTurn(game);
		endGame(game);
		return 0;



	}
		

	return 1;

}

void printMoves(ReversiGame *game){

	printf("\nWhite Count is : %d", game->whiteCount);
	printf("\nBlack Count is : %d", game->blackCount);
	printf("\nTotal Move Count is : %d", game->NumberofMoves);

	/*
	Sample output :
	Whites Count : 5
	Black Count : 4
	Move Count : 9
	*/
	return;
}

/*
Print the Board in a Good Way.Make sure Each Number is properly formatted and Seperated, and Row lines too .
Print Empty Space when you encounter 0.Also make sure your board looks good for 5x5 or 7x7 boards too .
Use your Thinking / UI Skills .
See the link we shared for sample screenshots for inspiration.
*/

void drawBoardOnScreen(ReversiGame *game) {

	int i = 0;
	int j = 0;

	printf("\n\n\n\n\t\t\****       Reversi Game       \t\t\t\t****\n");

	for (i = 0; i<game->rows; i++){

		printf("\n\t\t");
		for (j = 0; j<game->cols; j++){


			printf(" %c ", game->board[i][j]);

		}

	}

	return;
}

/*
Clear The Screen , So that we can redraw the Board (which has modified values )
*/

void clearScreen(ReversiGame *game){
	system("cls");
}

/*
Clear the Screen and ReDraw the Board ,Call above two functions
*/

void clearAndRedrawScreen(ReversiGame *game){

	clearScreen(game);
	drawBoardOnScreen(game);
}

