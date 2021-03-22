/*
ProblemCode : StudentsLoop
score : 20

It was games hour and all students are trying some parade formations for their upcoming republic day.
Each student will hold hand of the next student. In this imaginary school, every student has only 1 hand.
They will form a formation where all students stand in a line holding each other and the last student can either
hold a poll or some other student already present in the line.
Assume students are 1,2,3,4,5
Formation1 -> 3-2-1-5-4-Pole. (All students are standing straight, 3 is first student and 4 is last student)
Formation2 -> 3-2-1-5-4
                  |   |
                  -----
In formation2, 4 is holding one more student 1. Here 2 is holding 1,1 is holding 5, 5 is holding 4, 4 is holding 1 and so on.

But once while students are doing these formations, a strong gale occured and every student got dispersed, left hold of whomever they
are holding before. But after the gale is finished, they want to reform the same formation again, but all students having
very weak memory they cant form the formation again.

Now they appointed you as their observer, Once students form a formation they will signal you. and you need to see the formation
and write it in your book, You can represent the formation using a string. Its your wish how you represent.

Now once you stored the formation as a string in your book, even if a gale comes and students get dispersed, they will simply
ask you to instruct them how do they form back the formation again, You will look into your book and based on the string stored
you will instruct them and create the formation again.

TLDR: Given a list you need to convert that into a string. the list can contain loops or not.
This conversion you need to write in storeFormation function.

You need to also write how the list can be recreated, in createFormation function. It will be passed the previous stored string.
So if the last student 10 holds 3 previously, he should still hold 3, after recreation.

The order created by createFormation should be the same as original one.

Sample Input 1:
1->2->3->4 -> storeFormation -> "SAMPLEALGO" -> createFormation -> 1->2->3->4

Sample Input 2:
2->3->5->7->10  -> storeFormation -> "SAMPLEALGO2" -> createFormation -> 2->3->5->7->10
|        |                                                               |        |
--<-<-<-<-                                                               --<-<-<-<-

In store formation, dont modify the existing list. In createFormation you need to create a duplicated list with exact ordering 
of students and loop if exists should also be created amognst same set of students.

Constraints :
-> INT_MIN<RollNum<INT_MAX
-> Len of list less than 1000.
*/


#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>



struct loopnode {
	int roll;
	struct loopnode * next;
};

char * storeFormation(struct loopnode* head) {
	return NULL;
}

struct loopnode * createFormation(char *s) {
	return NULL;
}


