/*
Praveen loves to play chess a lot, especially endgames.
Among them he loves positions which consist of only 'Pawns' and no other pieces.

He has an 8x8 chessboard and several white pawns represented by 'w'
and black pawns represented by 'b'.

                                [BLACK's KINGDOM]

                                  0 1 2 3 4 5 6 7        black pawns moves down
       /\                    0    . . . . . . . .                \/
       /\                    1    b b b b b b b b                \/
       /\                    2    . . . . . . . .                \/
       /\                    3    . . . . . . . .                \/
       /\                    4    . . . . . . . .                \/
       /\                    5    . . . . . . . .                \/
       /\                    6    w w w w w w w w                \/
white pawns moves up         7    . . . . . . . .                \/

                                 [WHITE's KINGDOM]

He has his own rules for this game,
A pawn can only move 1 step forward towards his enemy kingdom in 1 move.

To make it clear if we mark the rows from [0 - 7],
a white pawn at a position(row, column) can move only to(row - 1, column) in a single move
and black pawn can move from(row, column) to (row + 1, column)
provided that the square is empty

Note :
if a player cannot move a piece, he looses his turn and it will be his opponents turn again.
if both cannot move any piece, then the game is drawn and consider as no one wins
Don't consider any other constraints like en-passent, capture and only 8 pawns as of real chess game.
There can be 64 pawns of the same color in the board.

[BLACK' KINGDOM]

     0 1 2 3 4 5 6 7                     0 1 2 3 4 5 6 7                 0 1 2 3 4 5 6 7
0    . . . . . . . .                0    . . . . . . . .            0    . . . . . . . .
1    . . . . . . b b                1    . . . . . . . .            1    . w . . . b . .
2    . . . . . . . .                2    . . . . . . . .            2    . . w . . . . .
3    . . . . . . . .                3    . . . b . . . .            3    . . . b . . b .
4    . . . . . . . .                4    . . . w . . . .            4    . . . w . . . .
5    . . . . . . b .                5    . . . . . . . .            5    w . . . . . b .
6    w . . . . . . .                6    . . . . . . . .            6    . . . . b . . .
7    . . . . . . . .                7    . . . . . . . .            7    . . . . . . . .

[WHITE KINGDOM]                        [GAME DRAWN]                [WHITE WINS]

[black reaches in 2 optimal moves]        -- No one can win --    Makes 1 move pawn(1, 1) to(0, 1)
[white reaches in 6 optimal moves]                                    and white wins the game
--Hence BLACK wins in 2 Move(s) --


-> A player can choose only 1 pawn in a single move(cannot choose pawns which cannot move),
and they take turns alternatively.
-> Initially the game starts with WHITE making his move.

"AIM OF THE GAME" :
-> The game ends when any of the WHITE pawn reaches the 1st Row, or BLACK pawn reaches 8th row.
-> The winner of the game will be the player who reached the Enemy kingdom first
(remember WHITE always moves first).

Your task is SIMPLE!, find Which KINGDOM will win and minimum number of moves required
if both the players played "OPTIMALLY!"

IF no one wins, return 0 and store '\0' in kingdom.
IF the position given is end position(Starting game itself no one can move), return -1 with '\0' in kingdom
*/


/**
board is an 8x8 char array where
'w' represent white pawn
'b' represent black pawn
'.' represent empty space

@return-type : int
the minimum number of moves that required to complete the game.

modify *colorWon with appropriate character as described above. ie store 'b' if black wins, or
store 'w' or '\0' respectively.

Marks : 20
*/


#include <stdio.h>

void smin(int &a, int b) {
	if (a > b) a = b;
}

int chessGame(char board[8][8], char *colorWon) {
	return 0;
}