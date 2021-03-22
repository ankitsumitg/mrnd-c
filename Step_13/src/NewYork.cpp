/*

Problem Code : New York

Count the number of ways of reaching top left cell (0,0) to right bottom cell (n-1,m-1) of a 2d matrix.

You have to change the direction "exactly 'k' times", you can change to any direction top,down,left,right.

You can start with any direction (initially at (0,0) only right and down are possible).

For Example :
N = 3, m = 4 , k = 1
These are the two sequences , change in direction is indicated by *

(1,1) -->  (2,1) -->  (3,1) -->  (3,2)* -->  (3,3) --> (3,4)
(1,1) -->  (1,2) -->  (1,3) -->  (1,4) --> (2,4)* -->  (3,4)

N = 3, m = 4, k = 2

(1,1) --> (2,1) --> (2,2)* --> (2,3) -->  (2,4) -->  (3,4)*
(1,1) --> (1,2) -->  (2,2)* --> (3,2) -->  (3,3)* --> (3,4)
(1,1) --> (1,2) -->  (1,3) -->  (2,3)* -->  (3,3) -->  (3,4)*

Return 0 for invalid cases
*/
//Took help
#include <stdio.h>
#include <stdlib.h>

int newyork_recur(int n, int m, int x, int y, int K, int dir) {

	int result = 0;

	int right = K - 1;
	int left = K - 1;
	int top = K - 1;
	int bottom = K - 1;

	if (n - 1 == x && m - 1 == y){
		if (K == 1)
			return 1;
		return 0;
	}

	if (((x >= 0 && x < n) && ((y >= 0 && y < m))) && K > 0){

		if (dir == 1)
			top += 1;
		else if (dir == 2)
			right += 1;
		else if (dir == 3)
			bottom += 1;
		else
			left += 1;

		result += newyork_recur(n, m, x - 1, y, top, 1);
		result += newyork_recur(n, m, x, y + 1, right, 2);
		result += newyork_recur(n, m, x + 1, y, bottom, 3);
		result += newyork_recur(n, m, x, y - 1, left, 4);


		return result;
	}
	return 0;
}

int NewYork(int n, int m, int k){

	if (n <= 0 && m <= 0)
		return 0;

	if (k < 0)
		return 0;

	return newyork_recur(n, m, 0, 1, k + 1, 2) + newyork_recur(n, m, 1, 0, k + 1, 3);
}