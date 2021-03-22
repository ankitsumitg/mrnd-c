/*
Some where in MissionRnD world ,there is a large plot of empty Rectangular land ,divided into Blocks of
equal size . A Land of N Blocks at length and M Blocks at Breadth will have total of N x M Blocks .

Each Block has a pillar of Height H .[0 <= H <=100000] .A Pillar is said to be a Leader if there are no more
neighbouring pillars (East ,West ,Noth and South) whose height is greater than current one .
And excatly opposite ,A pillar is said to be a Looser if there are no more neighbouring pillars
whose height is less than the current pillar height

If a block has 0 specified ,It has No pillar and No person can be on that block.In the below example
1,2,4... are heights of pillars at that block.Do not consider 0 while calculating Leaders or Loosers .
Example :

1 2 0 1 0
0 0 0 9 0
0 0 0 8 0
0 1 4 6 5
0 0 2 3 4

Here a[0][1] ie 2 ,and a[1][3] ie 9 are leaders ,as all their neighbouring elements are less or equal than it .
Here a[0][0] ie 1 ,and a[0][3] ie 1 and a[3][1] ie 1 and a[4][2] ie 2 are Loose Pillars ,as all their
neighbouring pillars height are greater or equal than it .

Now there is a child who likes to jump from one pillar to another ,He starts at a looser Pillar and jumps to
a nearby pillar (4 Directions) ,if the nearby pillar height is "strictly greater" than curernt pillar height .
So he can jump from 1 to 3 ,or 3 to 7 but not 4 to 1 and 5 to 5 .[all these are heights]
He continues jumping until he reaches a LeaderPillar .

As he likes jumping ,He would like to know the ans which starts at a Looser Pillar and ends at a Leader Pillar
that involves maximum jumps ,Can you help the child solve his Task ?

In the above example :
1-2 ans , requires only 1 jump
1-4-6-8-9 requires 4 jumps
2-3-4-5-6-8-9 requires 6 jumps
1-9 requires only 1 jump.
So in the above example you need to return [2,3,4,5,6,8,9] and copy 6 in jumps_count

Input :
A 2D Array (passed as Single pointer,First element Address) ,N (number of Cols), M(number of rows),
jumps_count (Pointer to an Integer)
Output :
Return the Max Jumps ans  ,and copy number of max jumps into jumps_count .

Constraints :
0<=N<=10000
0<=M<=10000
Note : If there is no such ans ,Copy 0 in jumps_count and return NULL,(Same for Invalid Inputs too)
Examples :
-----
2 1 7
3 0 4   ->Max ans : [1,2,3,5,6] ,jumps_count =4 [Here both 4's are looser elements]
5 6 4
--------
5 8 9 10
4 3 1 0
3 0 0 3   ->Max ans is [1,2,3,4,5,8,9,10] , jumps_count =8
2 1 1 1
---------
0 0 0
0 4 0  ->Max ans is [4] ,jumps_count=0;
0 0 0
Note : There will be only One Maximum Jumps ans .[If there are multiple ,Return any 1 ans]
*/
#include <stdlib.h>
#include <stdio.h>
//int isLooser(int *blocks, int m, int n, int i, int j);
//int isLeader(int *blocks, int m, int n, int i, int j);



//Here is my solution and is working very well but am getting stack over flow for test cases 13 14 15
//I tried to optimize but no luck;


/*void travel(int *blocks, int m, int n, int i, int j, int *count, int *count2, int *ans2, int *ans,int *test);
int isSafe(int *blocks, int m, int n, int i, int j);
void put(int *blocks, int m, int n, int *test);
int * pillars_max_jumps(int *blocks, int n, int m, int *jumps_count){
	if (blocks == NULL)
		return NULL;
	int count1 = 0,count = 0;
	int *ans2 = new int[50];
	int *ans = new int[50];
	int prev = blocks[0];
	int c = 0,z = 0;
	//if all emelents are equal in matrix
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (prev == blocks[i*n + j] && blocks[i*n + j] != 0)
				c++;
			else prev = blocks[i*n + j];
			if (blocks[i*n + j] == 0)
				z++;
		}
	//if all emelents are equal in matrix including all zeroes
	if (c == m*n || z == m*n)
	{
		*jumps_count = 0;
		if (z == m*n)
			ans = NULL;
		else
			ans[0] = blocks[0];
		return ans;
	}

	//if all emelents are equal in matrix except 1st one
	if (c == m*n - 1)
	{
		*jumps_count = 1;
		//asign 1st one to smaller one and second one to greater one 
		ans[0] = (blocks[0] < blocks[1]) ? blocks[0] : blocks[1];
		ans[1] = (blocks[0] > blocks[1]) ? blocks[0] : blocks[1];
		return ans;
	}
	//or else
	int *test = new int[m*n];
	put(blocks, m, n, test);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (blocks[i*n + j] == 0);
			else if (test[i*n + j] == 1)
			{
				travel(blocks, m, n, i, j, &count1,&count, ans2,ans,test);
				count1 = 0;
			}
		}
	*jumps_count = count-1;
	return ans2;
}
void travel(int *blocks, int m, int n, int i, int j, int *count,int *count2,int *ans2, int *ans,int *test)
{
	ans[*count] = blocks[i*n + j];
	*count = *count + 1;
	printf("%d ", blocks[i*n + j]);
	if (test[i*n + j] == 2)
	{
		if (*count2 == 0)
			ans2[0] = ans[0];
		return ;
	}
	int e[4];
	int k = 0;
	int a, b, c, d;
	a = b = c = d = -1;
	int check = 0;
	int dir;
	if (isSafe(blocks, m, n, i, j + 1))
	{
		if (blocks[i*n + j + 1] > blocks[i*n + j])
		{
			a = blocks[i*n + j + 1];
			check++;
		dir = 1;
		}
	}
	if (isSafe(blocks, m, n, i + 1, j))
	{
		if (blocks[(i + 1)*n + j] > blocks[i*n + j])
		{
			b = blocks[(i + 1)*n + j];
			check++;
		dir = 2;
		}
	}
	if (isSafe(blocks, m, n, i, j - 1))
	{
		if (blocks[i*n + j - 1] > blocks[i*n + j])
		{
			c = blocks[i*n + j - 1];
			check++;
		dir = 3;
		}
	}
	if (isSafe(blocks, m, n, i - 1, j))
	{
		if (blocks[(i - 1)*n + j] > blocks[i*n + j])
		{
			d = blocks[(i - 1)*n + j];
			check++;
		dir = 4;
		}
	}
	if (a != -1)
		e[0] = a; 
	else e[0] = 1000;
	if (b != -1)
		e[1] = b;
	else e[1] = 1000;
	if (c != -1)
		e[2] = c;
	else e[2] = 1000;
	if (d != -1)
		e[3] = d;
	else e[3] = 1000;
	if (check == 1){
		if (dir == 1) travel(blocks, m, n, i, j + 1, count,count2, ans2, ans,test);
		
		else if (dir == 2) travel(blocks, m, n, i + 1, j, count, count2, ans2, ans,test);
		
		else if (dir == 3) travel(blocks, m, n, i, j - 1, count, count2, ans2, ans,test);
		
		else travel(blocks, m, n, i - 1, j, count, count2, ans2, ans,test);
	
	}
	else {
		int out = 1, min = 1000;//e[0];
		int d1[4] = { 0, 1, 0, -1 };
		int d2[4] = { 1, 0, -1, 0 };
		for (int l = 0; l < 4; l++)
		{
			if (test[(i + d1[l])*n + j + d2[l]] == 2 && e[l] != 1000)
				e[l] = 1000;
			if (e[l] < min)
			{
				min = e[l];
				out = l+1;
			}
		}
		if (out == 1) travel(blocks, m, n, i, j + 1, count, count2, ans2, ans,test);
		
		else if (out == 2) travel(blocks, m, n, i + 1, j, count, count2, ans2, ans,test);
		
		else if (out == 3) travel(blocks, m, n, i, j - 1, count, count2, ans2, ans,test);
		
		else travel(blocks, m, n, i - 1, j, count, count2, ans2, ans,test);
	

	}
	if (*count2 == 0)
	{
		for (int i = 0; i < *count; i++)
			ans2[i] = ans[i];
		*count2 = *count;
		return ;
	}
	else if (*count > *count2)
	{
		for (int i = 0; i < *count; i++)
			ans2[i] = ans[i];
		*count2 = *count;
		return ;
	}
	return ;
}
int isSafe(int *blocks, int m, int n, int i, int j)
{
	if (i >= 0 && i < m && j >= 0 && j < n && blocks[i*n + j] != 0)
		return 1;
	return 0;
}
// sotring looser pillar values as 1 and leadeer pillar valuesas 2 others 0
void put(int *blocks, int m, int n, int *test)
{
	//for looser
	int a[4];
	int k, l;
	//for leader
	int p, b, c, d;
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			if (blocks[i*n + j] == 0)
				test[i*n + j] = 0;
			k = 0;
			p = b = c = d = 0;
			if (isSafe(blocks, m, n, i + 1, j))
			{
				a[k++] = blocks[(i + 1)*n + j];
				p = blocks[(i + 1)*n + j];
			}
			if (isSafe(blocks, m, n, i, j + 1))
			{
				a[k++] = blocks[i*n + j + 1];
				b = blocks[i*n + j + 1];
			}
			if (isSafe(blocks, m, n, i - 1, j))
			{
				a[k++] = blocks[(i - 1)*n + j];
				c = blocks[(i - 1)*n + j];
			}
			if (isSafe(blocks, m, n, i, j - 1))
			{
				a[k++] = blocks[i*n + j - 1];
				d = blocks[i*n + j - 1];
			}
			for (l = 0; l < k; l++)
			{
				if (blocks[i*n + j] <= a[l]);
				else break;
			}
			if (l == k)
				test[i*n + j] = 1;
			else if (blocks[i*n + j] >= p && blocks[i*n + j] >= b &&blocks[i*n + j] >= c &&blocks[i*n + j] >= d)
				test[i*n + j] = 2;
			else test[i*n + j] = 0;
		}
	
}*/

//So i took help from my friend


//finding the max jump from the current position
int find_max_jumps(int* jumpsblock, int r, int c, int i, int j, int *blocks)
{
	int max = 1;

	if (blocks[i*c + j] == 0 || i >= r || j >= c || i < 0 || j < 0)
		return 0;

	if (jumpsblock[i*c + j] != -1)
		return jumpsblock[i*c + j];

	if (j + 1 <c && blocks[i*c + j + 1] > blocks[i*c + j])
		jumpsblock[i*c + j] = 1 + find_max_jumps(jumpsblock, r, c, i, j + 1, blocks);
	if (jumpsblock[i*c + j] > max)
		max = jumpsblock[i*c + j];

	if (i + 1 <r && blocks[(i + 1)*c + j] > blocks[i*c + j])
		jumpsblock[i*c + j] = 1 + find_max_jumps(jumpsblock, r, c, i + 1, j, blocks);
	if (jumpsblock[i*c + j] > max)
		max = jumpsblock[i*c + j];

	if ((j - 1) >= 0 && blocks[i*c + j - 1] > blocks[i*c + j])
		jumpsblock[i*c + j] = 1 + find_max_jumps(jumpsblock, r, c, i, j - 1, blocks);
	if (jumpsblock[i*c + j] > max)
		max = jumpsblock[i*c + j];

	if ((i - 1) >= 0 && blocks[(i - 1)*c + j] > blocks[i*c + j])
		jumpsblock[i*c + j] = 1 + find_max_jumps(jumpsblock, r, c, i - 1, j, blocks);
	if (jumpsblock[i*c + j] > max)
		max = jumpsblock[i*c + j];

	jumpsblock[i*c + j] = max;

	return max;
}
// Finding path from the max jump position
void find_path(int* jumpsblock, int r, int c, int i, int j, int* ans, int k, int *blocks)
{
	if (jumpsblock[i*c + j] == 0)
		return;

	ans[k++] = blocks[i*c + j];

	if (i - 1 >= 0 && jumpsblock[(i - 1)*c + j] + 1 == jumpsblock[i*c + j] && blocks[i*c + j]<blocks[(i - 1)*c + j])
		find_path(jumpsblock, r, c, i - 1, j, ans, k, blocks);

	if (j + 1 < c && jumpsblock[i*c + j + 1] + 1 == jumpsblock[i*c + j] && blocks[i*c + j]<blocks[i*c + j + 1])
		find_path(jumpsblock, r, c, i, j + 1, ans, k, blocks);

	if (i + 1 < r && jumpsblock[(i + 1)*c + j] + 1 == jumpsblock[i*c + j] && blocks[i*c + j]<blocks[(i + 1)*c + j])
		find_path(jumpsblock, r, c, i + 1, j, ans, k, blocks);

	if (j - 1 >= 0 && jumpsblock[i*c + j - 1] + 1 == jumpsblock[i*c + j] && blocks[i*c + j]<blocks[i*c + j - 1])
		find_path(jumpsblock, r, c, i, j - 1, ans, k, blocks);

}
int * pillars_max_jumps(int *blocks, int n, int m, int *jumps_count)
{
	if (blocks == NULL || n <0 || m<0)
		return NULL;
	int *jumpsblock = (int*)malloc(m*n*sizeof(int));
	for (int i = 0; i < n*m; i++)
	{
		jumpsblock[i] = -1;
	}
	int x = 0;
	int y = 0;
	int maxjumps = 0;
	int jumps = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			jumps = find_max_jumps(jumpsblock, n, m, i, j, blocks);

			if (jumps > maxjumps)
			{
				maxjumps = jumps;
				x = i;
				y = j;
			}
		}
	}

	*jumps_count = maxjumps - 1;

	if (maxjumps == 0)
		return NULL;

	int* ans = (int*)malloc(sizeof(int) * (maxjumps));

	find_path(jumpsblock, n, m, x, y, ans, 0, blocks);

	return ans;
}