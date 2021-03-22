/*
This struct denotes the move played by user, X means the x cordinate and Y means y cordinate.
*/
typedef struct ReversiMove {
	int x, y;
}ReversiMove;

/*
Create a ReversiMove struct (malloc/calloc etc) and return it.
Assign parameters x and y to its fields.
*/
ReversiMove *createMove(int x, int y) {


	ReversiMove* move = (ReversiMove*)(malloc(sizeof(ReversiMove)));
	move->x = x - 1;
	move->y = y - 1;

	return move;
}
/*
To check the validity of coordinate on the board
*/

int isvalidCoordinate(ReversiGame *game, int x, int y) {

	if (x >= 0 && x < game->rows && y >= 0 && y < game->cols)
		return 1;

	return 0;


}
/*
Take Only Valid Input x, y two integers . If Invalid input is entered ,Take input again . Keep Taking input until its valid
Hint : Use While Loop and isValidInput function
Cordinates are 1 indexed. Ie first row/column is denoted by 1 while giving input.
*/

ReversiMove *inputMove(ReversiGame *game) {

	int x;
	int y;
	int check = 0;
	do{

		scanf("%d", &x);
		scanf(" %d", &y);
		check = isvalidCoordinate(game, x, y);

	} while (check != 1);

	ReversiMove* move = createMove(x , y );

	return move;
}




/*
Check if the move can be placed, if its going to make a valid capture to the opponent coins
*/

bool checkNorth(ReversiGame* game, ReversiMove* move, bool flag){

	
	if (move->x == 0)
		return false;


	char toBePlaced;
	char toBeChecked;

	if (game->turn == -1){

		toBeChecked = 'w';
		toBePlaced = 'b';
	}
	else{

		toBeChecked = 'b';
		toBePlaced = 'w';
	}

	int count = 0;

	int coord1 = (move->x) - 1;
	int coord2 = move->y;
	bool check = false;


	while (coord1 >= 0){

		if (game->board[coord1][coord2] == toBeChecked)
			count++;

		else if (game->board[coord1][coord2] == toBePlaced){

			check = true;
			break;

		}

		else
			break;

		coord1--;

	}


	if (check && flag && count>0){

		game->board[move->x][move->y] = toBePlaced;
		coord1 = (move->x) - 1;

		if (toBePlaced == 'b'){

			game->blackCount = game->blackCount + count;
			game->whiteCount = game->whiteCount - count;
		}
		else{

			game->whiteCount = game->whiteCount + count;
			game->blackCount = game->blackCount - count;
		}

		while (count != 0){

			game->board[coord1][coord2] = toBePlaced;
			coord1--;
			count--;

		}

		return true;
	}

	else if (check && count > 0)
		return true;


	else
		return false;

}

bool checkSouth(ReversiGame* game, ReversiMove* move, bool flag){

	
	if (move->x == (game->rows) - 1)
		return false;

	char toBePlaced;
	char toBeChecked;

	if (game->turn == -1){

		toBeChecked = 'w';
		toBePlaced = 'b';
	}
	else{

		toBeChecked = 'b';
		toBePlaced = 'w';
	}


	int count = 0;
	bool check = false;
	int coord1 = (move->x) + 1;
	int coord2 = move->y;


	while (coord1 < game->rows){

		if (game->board[coord1][coord2] == toBeChecked)
			count++;

		else if (game->board[coord1][coord2] == toBePlaced){

			check = true;
			break;

		}

		else
			break;

		coord1++;

	}

	if (check && flag && count>0){

		game->board[move->x][move->y] = toBePlaced;

		if (toBePlaced == 'b'){

			game->blackCount = game->blackCount + count;
			game->whiteCount = game->whiteCount - count;
		}
		else{

			game->whiteCount = game->whiteCount + count;
			game->blackCount = game->blackCount - count;
		}

		coord1 = (move->x) + 1;

		while (count != 0){

			game->board[coord1][coord2] = toBePlaced;
			coord1++;
			count--;

		}

		return true;
	}

	else if (check && count > 0)
		return true;


	else
		return false;


}



bool checkEast(ReversiGame* game, ReversiMove* move, bool flag){


	if (move->y == (game->cols) - 1)
		return false;

	char toBePlaced;
	char toBeChecked;

	if (game->turn == -1){

		toBeChecked = 'w';
		toBePlaced = 'b';
	}
	else{

		toBeChecked = 'b';
		toBePlaced = 'w';
	}

	int count = 0;
	bool check = false;
	int coord1 = move->x;
	int coord2 = (move->y) + 1;


	while (coord2 < game->cols){

		if (game->board[coord1][coord2] == toBeChecked)
			count++;

		else if (game->board[coord1][coord2] == toBePlaced){

			check = true;
			break;

		}

		else
			break;

		coord2++;

	}

	if (check && flag && count > 0){

		game->board[move->x][move->y] = toBePlaced;

		if (toBePlaced == 'b'){

			game->blackCount = game->blackCount + count;
			game->whiteCount = game->whiteCount - count;
		}
		else{

			game->whiteCount = game->whiteCount + count;
			game->blackCount = game->blackCount - count;
		}

		coord2 = (move->y) + 1;

		while (count != 0){

			game->board[coord1][coord2] = toBePlaced;
			coord2++;
			count--;

		}

		return true;
	}


	else if (check && count > 0)
		return true;


	else
		return false;


}

bool checkWest(ReversiGame* game, ReversiMove* move, bool flag){

	
	if (move->y == 0)
		return false;

	char toBePlaced;
	char toBeChecked;

	if (game->turn == -1){

		toBeChecked = 'w';
		toBePlaced = 'b';
	}
	else{

		toBeChecked = 'b';
		toBePlaced = 'w';
	}

	int count = 0;
	bool check = false;
	int coord1 = move->x;
	int coord2 = (move->y) - 1;


	while (coord2 >= 0){

		if (game->board[coord1][coord2] == toBeChecked)
			count++;

		else if (game->board[coord1][coord2] == toBePlaced){

			check = true;
			break;

		}

		else
			break;

		coord2--;

	}

	if (check && flag && count>0){

		game->board[move->x][move->y] = toBePlaced;

		if (toBePlaced == 'b'){

			game->blackCount = game->blackCount + count;
			game->whiteCount = game->whiteCount - count;
		}
		else{

			game->whiteCount = game->whiteCount + count;
			game->blackCount = game->blackCount - count;
		}

		coord2 = (move->y) - 1;

		while (count != 0){

			game->board[coord1][coord2] = toBePlaced;
			coord2--;
			count--;

		}

		return true;
	}

	else if (check && count > 0)
		return true;


	else
		return false;


}

bool checkNorthEast(ReversiGame* game, ReversiMove* move, bool flag){


	if (move->y == (game->cols) - 1 || move->x == 0)
		return false;

	char toBePlaced;
	char toBeChecked;

	if (game->turn == -1){

		toBeChecked = 'w';
		toBePlaced = 'b';
	}
	else{

		toBeChecked = 'b';
		toBePlaced = 'w';
	}

	int count = 0;
	bool check = false;
	int coord1 = (move->x) - 1;
	int coord2 = (move->y) + 1;


	while (coord1 >= 0 && coord2<game->cols){

		if (game->board[coord1][coord2] == toBeChecked)
			count++;

		else if (game->board[coord1][coord2] == toBePlaced){

			check = true;
			break;

		}


		else
			break;

		coord1--;
		coord2++;

	}

	if (check && flag && count>0){

		game->board[move->x][move->y] = toBePlaced;

		if (toBePlaced == 'b'){

			game->blackCount = game->blackCount + count;
			game->whiteCount = game->whiteCount - count;
		}
		else{

			game->whiteCount = game->whiteCount + count;
			game->blackCount = game->blackCount - count;
		}

		coord1 = (move->x) - 1;
		coord2 = (move->y) + 1;
		while (count != 0){

			game->board[coord1][coord2] = toBePlaced;

			coord1--;
			coord2++;
			count--;

		}

		return true;
	}

	else if (check && count > 0)
		return true;


	else
		return false;


}

bool checkNorthWest(ReversiGame* game, ReversiMove* move, bool flag){

	
	if (move->y == 0 || move->x == 0)
		return false;

	char toBePlaced;
	char toBeChecked;

	if (game->turn == -1){

		toBeChecked = 'w';
		toBePlaced = 'b';
	}
	else{

		toBeChecked = 'b';
		toBePlaced = 'w';
	}

	int count = 0;
	bool check = false;
	int coord1 = (move->x) - 1;
	int coord2 = (move->y) - 1;


	while (coord1 >= 0 && coord2 >= 0){

		if (game->board[coord1][coord2] == toBeChecked)
			count++;

		else if (game->board[coord1][coord2] == toBePlaced){

			check = true;
			break;

		}

		else
			break;

		coord1--;
		coord2--;

	}

	if (check && flag && count>0){

		game->board[move->x][move->y] = toBePlaced;

		if (toBePlaced == 'b'){

			game->blackCount = game->blackCount + count;
			game->whiteCount = game->whiteCount - count;
		}
		else{

			game->whiteCount = game->whiteCount + count;
			game->blackCount = game->blackCount - count;
		}
		coord1 = (move->x) - 1;
		coord2 = (move->y) - 1;
		while (count != 0){

			game->board[coord1][coord2] = toBePlaced;

			coord1--;
			coord2--;
			count--;

		}
		return true;
	}

	else if (check && count > 0)
		return true;


	else
		return false;

}


bool checkSouthEast(ReversiGame* game, ReversiMove* move, bool flag){


	if (move->y == (game->cols) - 1 || move->x == (game->rows) - 1)
		return false;

	char toBePlaced;
	char toBeChecked;

	if (game->turn == -1){

		toBeChecked = 'w';
		toBePlaced = 'b';
	}
	else{

		toBeChecked = 'b';
		toBePlaced = 'w';
	}
	int count = 0;
	bool check = false;
	int coord1 = (move->x) + 1;
	int coord2 = (move->y) + 1;


	while (coord1 < game->rows && coord2<game->cols){

		if (game->board[coord1][coord2] == toBeChecked)
			count++;

		else if (game->board[coord1][coord2] == toBePlaced){

			check = true;
			break;

		}

		else
			break;

		coord1++;
		coord2++;

	}

	if (check && flag && count>0){

		game->board[move->x][move->y] = toBePlaced;

		if (toBePlaced == 'b'){

			game->blackCount = game->blackCount + count;
			game->whiteCount = game->whiteCount - count;
		}
		else{

			game->whiteCount = game->whiteCount + count;
			game->blackCount = game->blackCount - count;
		}

		coord1 = (move->x) + 1;
		coord2 = (move->y) + 1;

		while (count != 0){

			game->board[coord1][coord2] = toBePlaced;

			coord1++;
			coord2++;
			count--;

		}
		return true;
	}

	else if (check && count > 0)
		return true;


	else
		return false;
}

bool checkSouthWest(ReversiGame* game, ReversiMove* move, bool flag){


	if (move->y == 0 || move->x == (game->rows) - 1)
		return false;

	char toBePlaced;
	char toBeChecked;

	if (game->turn == -1){

		toBeChecked = 'w';
		toBePlaced = 'b';
	}
	else{

		toBeChecked = 'b';
		toBePlaced = 'w';
	}

	int count = 0;
	bool check = false;
	int coord1 = (move->x) + 1;
	int coord2 = (move->y) - 1;


	while (coord1 < game->rows && coord2 >= 0){

		if (game->board[coord1][coord2] == toBeChecked)
			count++;

		else if (game->board[coord1][coord2] == toBePlaced){

			check = true;
			break;

		}
		else
			break;

		coord1++;
		coord2--;

	}

	if (check && flag && count>0){

		game->board[move->x][move->y] = toBePlaced;
		
		if (toBePlaced == 'b'){

			game->blackCount = game->blackCount + count ;
			game->whiteCount = game->whiteCount - count;
		}
		else{

			game->whiteCount = game->whiteCount + count ;
			game->blackCount = game->blackCount - count;
		}

		coord1 = (move->x) + 1;
		coord2 = (move->y) - 1;

		while (count != 0){

			game->board[coord1][coord2] = toBePlaced;

			coord1++;
			coord2--;
			count--;

		}
		return true;

	}

	else if (check && count > 0)
		return true;


	else
		return false;
}





int isValidMove(ReversiGame *game, ReversiMove *move) {


	if (!isvalidCoordinate(game, move->x, move->y))
		return 0;

	if (game->board[move->x][move->y] == 'w' || game->board[move->x][move->y] == 'b')
		return 0;

	if (checkNorth(game, move, false))
		return 1;

	else if (checkSouth(game, move, false))
		return 1;

	else if (checkWest(game, move, false))
		return 1;

	else if (checkEast(game, move, false))
		return 1;

	else if (checkNorthWest(game, move, false))
		return 1;

	else if (checkNorthEast(game, move, false))
		return 1;

	else if (checkSouthWest(game, move, false))
		return 1;

	else if (checkSouthEast(game, move, false))
		return 1;

	else

		return 0;
}

/*
Check if the player can move , if the player is not able to move, he looses the turn
and the opponent gets the chance to play.
If both players are not able to make a move, then the game ends.
*/

int hasMove(ReversiGame *game){

	int i = 0;
	int j = 0;
	int check = 0;

	ReversiMove* tempMove = (ReversiMove*)malloc(sizeof(ReversiMove));

	for (i = 0; i < game->rows; i++){

		for (j = 0; j < game->cols; j++){

			tempMove->x = i;
			tempMove->y = j;

			if (game->board[i][j] == 'w' || game->board[i][j] == 'b')
				continue;

			check = isValidMove(game, tempMove);

			if (check == 1)
				return 1;

		}

	}

	return 0;
}

/*
Increment the number of moves in ReversiGame struct.
*/
void incrementMoves(ReversiGame *game) {

	game->NumberofMoves = (game->NumberofMoves) + 1;
}

/*
Toggle the turn in Reversi Game.
This function is to be called when you want to change the turn.
*/
void modifyTurn(ReversiGame *game) {

	game->turn = game->turn*(-1);


}

/*
End Reversi Game.
Populate game->winner field accordingly with who won. 1 for white, -1 for black.
This function is to be called when the game is ended.
*/
void endGame(ReversiGame *game) {
	
	game->state = 1;
	if (game->whiteCount > game->blackCount)
		game->winner = 1;
	else if (game->whiteCount < game->blackCount)
		game->winner = -1;

	else
		game->winner = 0;

	return;
}

/*
Wrapper function you will call only modify to increment moves and modify the turn.
*/

void modify(ReversiGame *game) {
	incrementMoves(game);
	modifyTurn(game);
}


/*
This function performs move action on the board
Note : call validity check performs using above functions before making a move
returns :
true on move sucess
false if move is invalid
*/

bool playMove(ReversiGame *game, ReversiMove *move) {

	bool flag = false;
	bool check1 = false;
	bool check2 = false;

	if (!isvalidCoordinate(game, move->x, move->y))
		return false;

	if (game->board[move->x][move->y] == 'b' || game->board[move->x][move->y] == 'w')
		return false;

	if (hasMove(game)){

		check1 = true;
		if (!isValidMove(game, move))
			return false;

		if (checkNorth(game, move, true))
			flag = true;

		if (checkSouth(game, move, true))
			flag = true;

		if (checkWest(game, move, true))
			flag = true;

		if (checkEast(game, move, true))
			flag = true;

		if (checkNorthWest(game, move, true))
			flag = true;

		if (checkNorthEast(game, move, true))
			flag = true;

		if (checkSouthWest(game, move, true))
			flag = true;

		if (checkSouthEast(game, move, true))
			flag = true;
	}

	else{

		modifyTurn(game);
		if (!isValidMove(game, move))
			return false;


		if (hasMove(game)){

			check2 = true;

			if (checkNorth(game, move, true))
				flag = true;

			if (checkSouth(game, move, true))
				flag = true;

			if (checkWest(game, move, true))
				flag = true;

			if (checkEast(game, move, true))
				flag = true;

			if (checkNorthWest(game, move, true))
				flag = true;

			if (checkNorthEast(game, move, true))
				flag = true;

			if (checkSouthWest(game, move, true))
				flag = true;

			if (checkSouthEast(game, move, true))
				flag = true;

		}

	}

	modifyTurn(game);
	if (flag){

		incrementMoves(game);
		modifyTurn(game);

		if (game->turn == 1){

			game->whiteCount = game->whiteCount + 1;
		}
		else{

			game->blackCount = game->blackCount + 1;
		}
		modifyTurn(game);
		if (checkReversiGameOver(game)){

			game->state = 1;
			endGame(game);
			printMoves(game);



		}

		return true;
	}

	
	if (!check1 && !check2){

		game->state = 1;
		endGame(game);
		printMoves(game);

		return true;

	}

	return false;
}


void printWinner(ReversiGame *game) {

	/*
	Sample output :
	Result Praveen has won. / Game is Drawn.
	*/

	if (game->winner == 1)
		printf("Result %s has won\n", game->player1name);
	else if (game->winner == -1)
		printf("Result %d has won\n", game->player2name);
	else
		printf("Game is Drawn\n");


}