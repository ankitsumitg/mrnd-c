/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>
int path_exists_util(int *maze, int rows, int columns, int x1, int y1, int x2, int y2, int *visited);
int isSafe(int *maze, int M, int N, int i, int j,int *visited);
int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	int *visited = (int *)malloc(rows* columns * sizeof(int));
	int i, j;
	for (i = 0; i < rows; i++)
		for (j = 0; j < columns; j++)
			*(visited + i*columns + j) = 0;
	return path_exists_util(maze,rows,columns,x1,y1,x2,y2,visited);

}
int path_exists_util(int *maze, int rows, int columns, int x1, int y1, int x2, int y2, int *visited)
{

	if (rows > 0 && columns > 0 && maze[x2*columns+y2] !=0)
	{
		if (x1 == x2 && y1 == y2)
			return 1;
		if (isSafe(maze, rows, columns, x1, y1,visited))
		{
			if (visited[(x1+1)*columns + y1] == 0)
				if (path_exists_util(maze, rows, columns, x1 + 1, y1, x2, y2, visited))
					return 1;
			if (visited[x1*columns + (y1 + 1)] == 0)
				if (path_exists_util(maze, rows, columns, x1, y1 + 1, x2, y2, visited))
					return 1;
			if (visited[(x1 - 1)*columns + y1] == 0)
				if (path_exists_util(maze, rows, columns, x1 - 1, y1, x2, y2, visited))
					return 1;
			if (visited[x1*columns + (y1 - 1)] == 0)
				if (path_exists_util(maze, rows, columns, x1, y1 - 1, x2, y2, visited))
					return 1;
			return 0;
		}
		return 0;
	}
	else return 0;

}
int isSafe(int *maze,int M, int N, int i, int j,int *visited)
{
	if (i >= 0 && i < M && j >= 0 && j < N, maze[i*N + j] == 1)
	{
		visited[i*N + j] = 1;
		return 1;
	}
	return 0;
}
