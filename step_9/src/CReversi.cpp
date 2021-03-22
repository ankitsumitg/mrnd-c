#include <stdio.h>

/*
Objective of the Game .

Given a NxN Square Board of containing Whites and Blacks , the game is played between two players.
where each player owns one color (onePlayer chooses white and anotherPlayer chooses black).

Players take alternate turns and place their color on the one square such that it captures the other colors
as described in the figures given below.

The game ends when either the board is completely filled or both the players can't make a move.
Link : https://en.wikipedia.org/wiki/Reversi

We are using a ReversiGame structure to store all the Game related information , which also stores rows,cols,board,whiteCoinCount,blackCoinCount,MoveCount,Turn.
All The Board Related functions are in ReversiBoardUtils.h
We are representing the emptySquare using ' ' (space) in the 2d Array white coins with 'w' and blacks with 'b'.
We are using a ReversiMove struct to store Move(x,y) We are going to revisit this game again ,So make sure you are
implementing every feature .
Move(x,y) is 1 indexed. ie top left square is called as (1,1) instead of(0,0)

All MoveRelated Functions are present in ReverseMovesUtil.h

How Game is played :
Ex Lets take a 4x4 board ('w' representing whites, 'b' representing blacks, '.' representing empty )

  1 2 3 4												    1 2 3 4
1 . . . .												  1 . . . .
2 . w b .   ==> White places coin at (4,2) Turn ==>       2 . w b .   (see that it captures all the blacks between two
3 . b w .												  3 . w w .   white coins when a move is placed)
4 . . . .												  4 . w . .


  1 2 3 4				                                 1 2 3 4
1 . . . .											   1 . . . .
2 . w b .   ==> Black places coin at (4,3) Turn ==>    2 . w b .   (see that it captures all the white between two
3 . w w .											   3 . w b .   black coins when a move is placed)
4 . w . .										       4 . w b .

Note : only moves that captures the opponent coins are valid , example white cannot place the coin at (1,1) or (1,2) etc..

The rules of the game can be found at :
Link : http://www.ultraboardgames.com/othello/game-rules.php

Play the game at : https://www.mathsisfun.com/games/reversi.html and understand all the rules, once
you understand all rules, implement them.

*/

void Reversi_main(){
	//Take input 2 strings representing player1 and player2.
	ReversiGame *game = NULL;
	game = createNewGame(4, 3, "praveen", "abhijith");
	//Declare two variables called rows&cols
	int rows = 4, cols = 4;

	//Declare a 2D Array ,and assign some values to it .Let this array be table . 
	char table1[4][5] =
	{
		"    ",
		" wb ",
		" bw ",
		"    "
	};

	//Create a game using  createNewGame(int,int,char *,char *) with rows,cols and  two players
//	ReversiGame *game = createNewGame(rows, cols, "praveen", "abhijith");

	
	//Initalize the game with table ,Pass it as (char *)table along with the turn
	initializeReversiGame(game, (char *)table1, rows, cols, 1);


	//First Clear and Redraw the Screen ,First Time we need to show the board right ?

	//Also call printMoves , You also need to show the whiteMoveCount and blackMoveCount and totalMoveCount.

	//Use a Loop which repeatedly takes input(Reversi Move) from User and calls playMove function 
	//till the Game is Ended

	//Display Game is completed in <mmmm> Moves ,Good work <Name>
}