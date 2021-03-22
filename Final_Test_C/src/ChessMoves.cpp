/*

problemCode : ChessMoves
score : 15

Praveen is teaching chess to his students, he started teaching the basics
i.e piece movements of King,Rook,Bishop on Day1


After teaching he wants to test them by giving simple puzzles,
To make it intresting , the chess board is infinitely expanding towards right and bottom.

He asks his students 3 type of questions,
If there is a piece [Rook or Bishop or King] at position (x1,y1)
what is the minimum number of moves required for that piece to move to position (x2,y2)

    1 2 3 4 5 . . . INF                 1 2 3 4 5 . . . INF
1   . . . . . . . . INF             1   . . . . . . . . INF
2   . . . . . . . . INF             2   . . . . . . . . INF
3   . . . . x . . . INF             3   . x . . . . . . INF
4   . . . . . . . . INF             4   . . . . . . . . INF
5   . . . . R . . . INF             5   . . . . R . . . INF
.   . . . . . . . . INF             .   . . . . . . . . INF
.   . . . . . . . . INF             .   . . . . . . . .	INF
INF . . . . . . . . INF             INF . . . . . . . . INF

piece = Rook							piece = Rook
source = (5,5)							source = (5,5)
dest = (2,5)							dest  = (3,2)
MinMovesRequired = 1  					MinMovesRequired = 2

    1 2 3 4 5 . . . INF                 1 2 3 4 5 . . . INF
1   x . . . . . . . INF             1   . . . . . . . . INF
2   . . . . . . . . INF             2   . . . . . . . . INF
3   . . . . . . . . INF             3   . . . . . . . . INF
4   . . . . . . . . INF             4   . . . . . . . . INF
5   . . . . B . . . INF             5   . . x . B . . . INF
.   . . . . . . . . INF             .   . . . . . . . . INF
.   . . . . . . . . INF             .   . . . . . . . . INF
INF . . . . . . . . INF             INF . . . . . . . . INF

piece = Bishop						piece = Bisiop
source = (5,5)						source = (5,5)
dest = (8,8)						dest  = (3,5)
MinMovesRequired = 1  				MinMovesRequired = 2

    1 2 3 4 5 . . . INF                 1 2 3 4 5 . . . INF
1   . . . . . . . . INF             1   . . . . . . . . INF
2   . . . . . . . . INF             2   . . . . . . . . INF
3   x . . . . . . . INF             3   . . . . x . . . INF
4   . . . . . . . . INF             4   . . . . . . . . INF
5   . . . . K . . . INF             5   . . . . K . . . INF
.   . . . . . . . . INF             .   . . . . . . . . INF
.   . . . . . . . . INF             .   . . . . . . . . INF
INF . . . . . . . . INF             INF . . . . . . . . INF

piece = King						piece = King
source = (5,5)						source = (5,5)
dest = (3,1)						dest  = (3,5)
MinMovesRequired = 4  				 MinMovesRequired = 2

Note :
[1] If the destination cannot be reached by the piece, return -1
[2] All the inputs, outputs fits in a 64 bit integer
*/

/**
@sourceX,sourceY contains initial position 1 <= sourceX,sourceY <= 1e18
@destX,destY contains destination positions 1 <= destX,destY <= 1e18
@piece contains type of the piece			piece ∈ {'K','R','B'} 
*/

long long minimumPieceMoves(long long sourceX, long long sourceY, 
							long long destX, long long destY, char piece){
	if (sourceX <= 0 || sourceY <= 0 || destX <= 0 || destY <= 0 )
	return 0;
	if (piece == 'K' || piece == 'R' || piece == 'B')
	{
		int x;
		return 1;
	}
	else return 0;
	return 0;
}

