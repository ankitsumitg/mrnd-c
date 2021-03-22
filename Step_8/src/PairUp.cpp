/*

ProblemCODE : PICNICPAIR
Difficulty : Hard
Marks : 20

It is picnic Time in MissionRnD School and everyone has decided to go to Zoo .
Alll students are very much excited and want to roam the whole zoo with their Close friends ,and everyone formed a line where close friends stand one behind other ,But the class teacher has some different plans in her mind ,she want everyone in the class to know each other in the picnic as usually even in the school the same set of students talk with each other and usually some introverts are left out with no one to talk .

She wanted to pairUp students in the way that everyone gets paired up randomly ,But Doing randomly became difficult as she dosent have a Good Random number generator :D . She now decided that in the Line the first student ,gets paired up with the last student , the second student gets paired up with the second student from last ,third student with last third student and so on . This way she wants to pair up every student and form a new Line of students .

[Lets assume students have been assigned numbers as 1,2,3,4 ... ]
Ex: If initially the line is 1,2,3,4,5,6,7,8 , It will be transformed as 1,8,2,7,3,6,4,5 .

But the teacher isnt very good at Maths , so she has sent a mail to missionrnd admin team to solve the task ,As you all are very smart , We thought it would be best for you to solve the problem for us .
Can you write a program which helps the Teacher produce the final list and Help the introverts of the class to make new friends ?


Example 2 :
4->5->7->9->3->1->2->6->NULL gives output as 4->6->5->2->7->1->9->3->NULL.

Example 3 :
1->2->3->4->5->NULL gives output as 1->5->2->4->3->NULL.

Data Description :
Students List is given in the form of a Single Linked List .Last Node->next will be equal to Null .

Output :
You need to modify the original List according to the question given ,Dont create any new List .

Notes :
->You should directly operate on the LinkedList given changing the links .[Important]
->You shouldnt over-ride any values in the Nodes already given ,
->You shouldnt even malloc new Nodes or create a new SLL .
->You shouldnt Swap the Data values in the Node .

->If your code dosent satisfy above constraints you will get -5 Score .

->Numbers can be duplicate in the List .So dont count on them to be unique .

->Btw dont share the teachers plan to MissionRnD school students , or else some clever students will figure out the logic easily and fight for the Middle spot .
*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode{
	int val;
	struct ListNode *next;
};

void pairUp(struct ListNode *head){
	if (head == NULL)
		return;
	//considering array of pointers and storring the addresses of data elements
	int *a[10000], *b[10000];
	int i = 0;
	struct ListNode *temp = head;
	while (temp->next != NULL)
	{
		a[i] = &temp->val;
		temp = temp->next;
		i++;
	}
	a[i] = &temp->val;
	i++;
	//making last element NULL
	a[i] = NULL;
	int c = 0;
	i--;
	int x = i;
	int j = 0;
	//doing the shuffling of addresses according to the given conditons
	while (j <= i / 2)
	{
		if (c % 2 == 0)
		{
			b[c] = a[j];
			c++;

		}
		else
		{
			b[c] = a[x];
			c++;
			x--;
			j++;
		}
	}
	//if no. elements of is odd
	if (i % 2 == 0)
	{
		c--;
		b[c] = NULL;
	}// else even
	else b[c] = NULL;
	j = 0;
	// storing the head sddrsses
	temp = head;
	//now changind the ListNOde links addresses according to the shuffled array of pointers
	while (b[j] != NULL)
	{
		head->next = (ListNode *)b[j];
		head = head->next;
		j++;
	}
	//ending the ListNode
	head->next = NULL;
	//assigning back the head addresses
	head = temp;
}
