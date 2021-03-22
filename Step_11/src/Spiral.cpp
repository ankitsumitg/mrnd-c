/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
int * find(int rows, int columns, int **input_array, int *i,int x,int y, int d, int *visited, int *ans);
void solve_spiral(int **mat, int m, int n, int k, int *p, int *ans);
int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL || columns <= 0 || rows <= 0)
	return NULL;
	//int *visited = (int *)malloc(rows* columns * sizeof(int));
	int i = 0;
//	int d = 1;
	/*for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			*(visited + i*columns + j) = 0;*/
	int *ans = (int*)malloc(rows*columns*(sizeof(int)));
	/*for (int i = 0; i < rows*columns; i++)
		ans[i] = -1;*/
	solve_spiral(input_array, rows, columns, 0, &i, ans);//find(rows, columns, input_array, &i, d,0,0, visited,ans);
	//for (int i = 0; i < sizeof(ans); i++)
	//	printf("%d - %d", ans[i]);
	return ans;
}
void solve_spiral(int **mat, int m, int n, int k,int *p,int *ans) {
	if (m <= 0 || n <= 0)
		return ;
	if (m == 1) {
		for (int j = 0; j < n; j++)
		{
			int x = *p;
			ans[x] = mat[k][k + j];
			(*p)++;
			//printf("%d - %d   ", x,ans[x]);
		}
		return ;
	}
	if (n == 1) {
		for (int i = 0; i < m; i++)
		{
			int x = *p;
			ans[x] = mat[k + i][k];
			(*p)++;
			//printf("%d - %d   ", x, ans[x]);
		}
		return ;
	}
	// put from top left
	for (int j = 0; j < n - 1; j++)
	{
		int x = *p;
		ans[x] = mat[k][k + j];
		(*p)++;
		//printf("%d - %d   ", x, ans[x]);
	}
	// put from top right
	for (int i = 0; i < m - 1; i++)
	{
		int x = *p;
		ans[x] = mat[k + i][k + n - 1];
		(*p)++;
		//printf("%d - %d   ", x, ans[x]);
	}
	// put from bottom right
	for (int j = 0; j < n - 1; j++)
	{
		int x = *p;
		ans[x] = mat[k + m - 1][k + n - 1 - j];
		(*p)++;
		//printf("%d - %d   ", x, ans[x]);
	}
	// put from bottom left
	for (int i = 0; i < m - 1; i++)
	{
		int x = *p;
		ans[x] = mat[k + m - 1 - i][k];
		(*p)++;
		//printf("%d - %d   ", x, ans[x]);
	}
	solve_spiral(mat, m - 2, n - 2, k + 1,p,ans);
}
/*int * find(int rows, int columns, int **input_array, int *i,int x,int y, int d,int *visited,int *ans)
{
	ans[*i++] = input_array[x][y];
	visited[x*columns + y] = 1;
	if (ans[rows*columns - 1] != -1)
		return ans;
	if (visited[(x + 1)*columns + y] == 0)
		if (find(rows, columns, input_array, i, x, y, d, visited,ans))
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
}*/