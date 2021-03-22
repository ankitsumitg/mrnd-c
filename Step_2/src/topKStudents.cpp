/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
Problem Code :TK
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

struct student ** topKStudents(struct student *students, int len, int K) 
{
	void swap(struct student *, struct student*);
	if (K <= 0)
	return NULL;

	//Making in descending order as in question scoresDescendingSort
	int i, j;
	for (i = 0; i < len; i++)
	{
		for (j = i; j < len; j++)
		{
			if ((students + j)->score >(students + i)->score)
			{
				swap((students + i), (students + j));
			}
		}
	}
	//declaring new structure array dynamic memory allocation
	struct student** x = (student**)malloc(K*sizeof(student));
	for (i = 0; i < K; i++)
	{
		*(x + i) = (students + i);
	}
	return x;
}

void swap(struct student *one, struct student *two)
{
	struct student t = *one;
	*one = *two;
	*two = t;
}