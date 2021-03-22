/*
Leaderboard is one of the most used tool as part of C Course. In this question you will also be developing a similar leaderboard
although on a smaller scale.

You are given scores for 3 lessons, and you need to prepare the final leaderboard.

Each lesson scores are given as a string in the below format.
name1,score1\n
name2,score2\n
(\n is the seperator between 2 name,score pairs and the last name,score pair also ends with \n followed by \0)

Sample lesson1 score: 
abc,3\n,bca,100\ncbb,43\n

(It denotes abc has got 3 score in lesson1, where as bca got 100 and cbb got 43).

Constraints : 
-> Name will be of 3 letters only. and will contain only 'a','b','c' characters. (ie aab,abc,bbb etc , zyz is invalid)
-> Each name will occur only once in 1 particular lesson scores string.
-> 0<=Score<=100.
-> Only 3 lessons will be given.
-> Lesson scores string can be empty or NULL too.
-> Each name,score pair will surely be seperated by \n

You need to parse all the 3 given lessons scores strings and prepare a final leaderboard.
Final Leaderboard will be of below format :
name1,score1,score2,score3,total_score\n
name2,score1,score2,score3,total_score\n
name3,score1,score2,score3,total_score\n

Output Expectations : 
-> It should be sorted. If 2 names have same total_scores, give priority to the one who is alphabetically before.
ie, bbb and aaa with same scores, aaa will appear before.
-> If abc has score in lesson1,and lesson2, but not present in lesson3, take his lesson 3 score as 0.
-> If a name has never occured in any lesson, his name should not be present in final leaderboard.
-> If all 3 lesson scores are null, or empty, return an empty string.
-> Even if 1 is null and other 2 are empty, Still return empty string.
-> Final leaderboard will be of max 1000 chars.
-> Alphabatical sorting when equal accounts for 20% of total marks.
-> Output String last char should be \n followed by \0(Denoting string end).

Sample Input : 

char *s1 = "abc,3\nbca,4\n";
char *s2 = "bca,99\n";
char *s3 = "cca,100\n";

Sample Output : 
bca,4,99,0,103\n
cca,0,0,100,100\n
abc,3,0,0,3\n

Notes: 
Dont use String functions
In above representations, An extra enter after \n is given just for easier understanding, actual strings will only have letters
what is shown.
ie in the case of
abc,44\n
ccc,12\n
aaa,100\n
actual string will be abc,44\nccc,12\naaa,100\n

Total Marks : 30
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

char * mini_leaderboard(char *lesson1,char *lesson2,char *lesson3) {
	
	return NULL;
}