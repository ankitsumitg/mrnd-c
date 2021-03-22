/*

	Given a matrix nxn and a starting point (p,q), 
	Output all the points in the matrix which are identical to the starting point in the fashion similar to magic tool in Adobe photoshop.
	Eg:
	(p,q) : (0,3)
	1 2 3 3
	3 2 3 3
	5 3 3 3
	4 5 1 4
	o/p : [ (0,2) (0,3) (1,2) (1,3) (2,2) (2,3) (2,1) ]

	Use 2 structures provided to solve the problem.
	
	struct point -> contains x, y corresponding to point on matrix.
	struct result -> contains 3 fields
						1. selected -> contains all the final points after the selecting process.
						2. size -> number of the selected points.
						3. visited -> utility variable to note the visited points on matrix during recursion.
	
	In error cases return a emply structures
		size = 0;
		selected = {};
		visited = {};

NOTE : Donot use any Global Variables
*/

//Took help
#include <malloc.h>
#include<stdlib.h>

struct Point {
	int x;
	int y;
};


struct result {
	Point* selected;
	bool *visited;
	int size;
};


void select(char *pixels, int m, int n, char magicClr, result* r, struct Point current, int *i, bool** visited) {
	// feel free to change this function parameters
	if (visited[current.x][current.y])
		return;
	char clr = *((pixels + current.x*(n + 1)) + current.y);
	if (clr == magicClr)
	{
		if (current.y)
			if (*((pixels + current.x*(n + 1)) + (current.y) - 1) == clr && visited[current.x][current.y - 1] == false){
				struct Point temp = current;
				temp.y = temp.y - 1;
				r->selected[(*i)++] = temp;
				select(pixels, m, n, magicClr, r, temp, i, visited);

			}

		if (current.x)
			if (*((pixels + (current.x - 1)*(n + 1)) + current.y) == clr && visited[current.x - 1][current.y] == false){
				struct Point temp = current;
				temp.x = temp.x - 1;
				r->selected[(*i)++] = temp;
				select(pixels, m, n, magicClr, r, temp, i, visited);
			}
		if (visited[current.x][current.y])
			return;
		r->selected[(*i)++] = current;
		r->size++;
		visited[current.x][current.y] = true;
		r->visited = &visited[0][0];

		if (current.y + 1 <= n)
			if (*((pixels + current.x*(n + 1)) + (current.y) + 1) == clr && visited[current.x][current.y + 1] == false){
				struct Point temp = current;
				temp.y = temp.y + 1;
				r->selected[(*i)++] = temp;
				select(pixels, m, n, magicClr, r, temp, i, visited);
			}
		if (current.x + 1 <= m)
			if (*((pixels + (current.x + 1)*(n + 1)) + (current.y)) == clr && visited[current.x + 1][current.y] == false){
				struct Point temp = current;
				temp.x = temp.x + 1;
				r->selected[(*i)++] = temp;
				select(pixels, m, n, magicClr, r, temp, i, visited);
			}
	}
	return;
}

struct result select_wrapper(char* pixels, int m, int n, struct Point pivot) {
	result r;
	r.size = 0;
	r.selected = {};
	r.visited = {};

	if (pixels == NULL || m<0 || n<0)
		return r;
	if (pivot.x < 0 || pivot.y < 0 || pivot.x>m + 1 || pivot.y>n + 1)
		return r;

	int noOfEle = (m + 1)*(n + 1), index = 0;;
	char magicClr = *((pixels + (pivot.x)*(n + 1)) + (pivot.y));

	r.selected = (struct Point*)calloc(noOfEle, sizeof(struct Point));
	bool **visited = (bool**)calloc(m + 1, sizeof(bool*));
	for (int i = 0; i <= m; ++i)
		visited[i] = (bool*)calloc(n + 1, sizeof(bool));
	r.visited = &visited[0][0];

	select(pixels, m, n, magicClr, &r, pivot, &index, visited);

	return r;
}