/*
Author : Abhijith Ravuri
*/

#include "stdafx.h"
#include <stdlib.h>

#include "FunctionHeaders.h"
void generate_array(int **input_array, int rows, int columns, int seq);
void generate_array(int **input_array, int rows, int columns, int seq)
{
	int k = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			input_array[i][j] = (k++)*seq;
}
struct student
{
	char letter;
	struct student *first;
	struct student *second;
	struct student *third;
};
struct student * new_node_spec_p5(char letter){
	struct student *temp = (struct student *)malloc(sizeof(struct student));
	temp->letter = letter;
	temp->first = NULL;
	temp->second = NULL;
	temp->third = NULL;
	return temp;
}
struct student * constructFormation_spec(char *students){
	struct student *root = NULL;
	struct student *nodes[2005];
	int i = 0;
	while (students[i] != '\0'){
		nodes[i] = new_node_spec_p5(students[i]);
		i++;
	}

	char invalidLetter = 'X';
	int mid = (i / 3);
	for (int i = 0; i < mid; i++){
		struct student *curnode = nodes[i];
		struct student *firstnode = nodes[(i * 3) + 1];
		struct student *secondnode = nodes[(i * 3) + 2];
		struct student *thirdnode = nodes[(i * 3) + 3];
		if (curnode->letter != invalidLetter){
			if (firstnode->letter != invalidLetter){
				curnode->first = firstnode;
			}
			if (secondnode->letter != invalidLetter){
				curnode->second = secondnode;
			}
			if (thirdnode->letter != invalidLetter){
				curnode->third = thirdnode;
			}
		}
	}
	root = nodes[0];
	return root;
}

void createFormationAndTest(char *students, int expectedMax, int expectedMin) {
	struct student * leaderStudent = constructFormation_spec(students);
	int actualMaxBallDistance = 0;
	int actualMinBallDistance = 0;
	findBallDistance(leaderStudent, &actualMinBallDistance, &actualMaxBallDistance);
}
int main(){
	
	//Check NSnipers

	//Check CountPairs Sample Code 
//	int pairs = count_pairs_wrapper("ababa", 5);

	//Check Steps Sample Code
	//int x = get_steps(3);

	//Check Spiral Sample Code

	//Check Maze Sample Code

	/*
	int maze[6][1] = {
		{ 1 },
		{ 1 },
		{ 1 },
		{ 1 },
		{ 0 },
		{ 1 },
	};

	int m = 6, n = 1;
	int x1 = 0, y1 = 0, x2 = 5, y2 = 0;

	int check=path_exists(&maze[0][0], m, n, x1, y1, x2, y2);
	printf("%d\n", check);*/
	
	/*int rows = 5, columns = 5;
	int **input_array = (int **)malloc(rows * sizeof(int *));
	for (int i = 0; i < rows; i++)
		input_array[i] = (int *)malloc(columns * sizeof(int));

	generate_array((int**)input_array, rows, columns, 1);

	int *output_array = spiral(rows, columns, (int**)input_array);
	*/
	const int n = 5, m = 5;
	int blocks[n][m] = {
		{ 1, 2, 0, 1, 0 },
		{ 0, 0, 0, 9, 0 },
		{ 0, 0, 0, 8, 0 },
		{ 0, 1, 4, 6, 5 },
		{ 0, 0, 2, 3, 4 }, };
	const int jc_exp = 6;
	int maxpath_exp[jc_exp + 1] = { 2, 3, 4, 5, 6, 8, 9 };
	int nopath = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", blocks[i][j]);
		printf("\n");
	}
	int jc = 0;
	int *res = pillars_max_jumps(&blocks[0][0], n, m, &jc);
	for (int i = 0; i < jc + 1; i++)
		printf("%d ", res[i]);
	return 0;
	/*char students[100] = "ABCDXXXHIJKLM";	int expectedMinBallDistance = 1;
	int expectedMaxBallDistance = 3;
	createFormationAndTest(students, expectedMaxBallDistance, expectedMinBallDistance);*/
}