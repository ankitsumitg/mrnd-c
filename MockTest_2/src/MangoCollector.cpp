/*
Summer has started here at Mission RnD world ,and each City here is flourishing with Mangoes .
In MrnD world, Each city is connected to at max 2 more cities .
There is a MangoCollector named Bob ,who visits  cities and collects some mangoes on his way at each
city . At each city ,he can also loose some mangoes as some cities are filled with thiefs .

Each city is represented using a struct node which has 3 fields , data specifying the number of mangoes
lost or gained in that city ,and left and right will be pointing to either NULL or next City (node).

Once he goes from City 1 to City 2 ,He cant go back again .He stops travelling when there are no more
cities connected to current city .

He wants to collect K number of mangoes at the end . Can you help him to find the number of ways,he can
start at Start City (start) and reach end city where he finally has K mangoes .

At any point of time ,his net mangoes count can be negetive too ,like he currently has 5 mangoes,
and he travels to a city where he looses 10 mangoes ,Now he will have -5 mangoes .
K can be negetive too ,In this case Bob wants to be at loss at the end .
Bob wont stop travelling even if his current mangoes count has reached K mangoes ,but the current city
is still connected to more cities .

For 50% of Test cases ,You need to copy the shortest final path where he reached his Final Count K .[Bob cant
travel anymore ].If two paths have same minimum length "Copy whose product off all nums in path is small",
Each value in the path will be the Gain/Loss he faced during each city in the path .

Input :
A Node start(starting city), Integer K ,and a pointer to an array where you need to copy
shortest path and Copy its length to shortestpathlen
[Memory is already allocated for both array and integer,Dont allocate it again,Just change the values]

Output :
Return the number of ways in which he can start from Startcity and end his travel with K nodes .Also copy the
shortest path in shortestpath array provided and its length in shortestpathlen.Return -1 for NULL inputs .

Example 1:
      5
     / \
    4   3
   / \
 -3  -1
StartCity : 5 ,K=8 Total number of ways are 2 [5,4,-1 and 5,3] .Shortest path is [5,3]

Example 2:
           10
          /  \
        5     -2
       / \    / \
      5   1  9   9
         / \    / \
        10  1  3   -1
                     \
                      1
Start City : 10 ,K=17 , Total number of ways are 3
Ways are 10->5->1->1 and 10-> -2 ->9 and 10-> -2 -> 9 -> -1 -> 1
Shortest Path is [10,-2,9] (Not 10->5->1 as its product 50 is larger than -180)

Start City : -2 . K=10 . Total number of ways is 1 .Shortest Path is : [-2,9,3]
StartCity : 10 , K=100 ,Total number of ways is 0 .Shortest path is []

Note :You can use your own custom function with extra parameters, Max height of Tree will be 1000.
*/
#include <stdlib.h>
#include <stdio.h>
void util(struct node* c, int k, int sum, int *a, int *i, int *total, int *temp, int j,int *len);
struct node{
	int data;
	struct node *left;
	struct node *right;
};



int mangocity_count_ways(struct node *startcity, int k, int *shortestpath, int *shortestpathlen) {
	//Just Copy values in shortestpath and shortestpathlen .Dont allocate memory for it .
	if (startcity == NULL)
	return -1;
	int a[100], i = 0, total = 0,sum =0;
	int temp[100], j = 0;
	int len[100];
	util(startcity, k, sum, a, &i, &total,temp,j,len);
	int check = 0,ocheck = INT_MAX;
	int sum2 = 0;
	int  p = 0;
	int temp2 = 0;
	int minimum = len[0], location;
	int gh = 0;
	for (int c = 1; c < total; c++)
	{
		if (len[c] < minimum)
		{
			minimum = len[c];
			location = c;
		}
		
	}
	for (int i = 0; i < location;i++)
		gh += len[i];
	for (int l = gh; l < gh+len[location]; l++)
	{
		shortestpath[p++] = a[l];
		//printf("%d", a[l]);
		*shortestpathlen = len[location];
		/*sum2 = sum2 + a[l];
		if (sum2 == k)
		{
			check = a[l + 1];
			l++;
			sum2 = 0;
			if (check < ocheck)
			{
				for (int u = temp2; u < l; u++)
					shortestpath[p++] = a[u];
				*shortestpathlen = check;
				ocheck = check;
				p = 0;
			}
			temp2 = l+1;
			
		}*/
	}
	return len[location];  // total
}
void util(struct node* c, int k,int sum,int *a,int *i,int *total,int *temp,int j,int *len)
{
	if (c == NULL)
		return;

	// add the current node's value
	sum += c->data;

	// add the value to path
	temp[j] = c->data;
	j = j + 1;

	// if left child exists
	if (c->left != NULL)
		util(c->left,k, sum, a, i, total, temp, j,len);

	// if right child exists
	if (c->right != NULL)
		util(c->right, k, sum, a, i, total, temp, j,len);
	if (sum == k)
	{
		for (int l = 0; l < j; l++)
		{
			a[(*i)] = temp[l];
			*i = *i + 1;
		}
		/*a[*i] = j;
		*i = *i + 1;*/
		len[*total] = j;
		*total = *total +1;
	}
	j = j - 1;
	return;
}