/*
In this question you will know how to assign,handle function pointers inside structures.

Given 2 arrays of ObjectNode's (which will have a value and function pointer).
You need to return the common values present in both the arrays. You also need to copy
final result array length into commonElementsLength

ObjectNode is a struct which holds a value of any type and also a equals function.

Sample float object Node.
float number = 7.45;
struct ObjectNode * floatObjectNode = (struct ObjectNode *)malloc(sizeof(struct ObjectNode));
floatObjectNode->value = (void *)&number;
floatObjectNode->equals = <Any Address of function which checks the equality of 2 void * who will point
to 2 float values)

Example :
Arr1 : [1,2,3,4,5]
Arr2 : [3,4,5,9,10]

So if each value in these 2 arrays are converted into objectNodes to create 2 more arrays
and sent to combine_common_elements sample output should be
[3,4,5]

You need to return an array of ObjectNode *, where each ObjectNode * points to one of the
common value. The return type of array would be struct ObjectNode **.

If 2 object nodes -> values are equal, you need to copy the first array's ObjectNode into final answer.
ie
Lets say inital int arrays are a=[1,3,4] and b=[2,5,3].
When converted to object node * array, now these are
[1000,1002,1004] and [1006,1008,1010] .

Here 1000 is address of a ObjectNode whose value will point to &a[0] ie 3's address.
1002-->value points to &a[1] like that 1010->value points to &b[2] ie 3's address.

The final returned array should be [1002]. (Even though both 1002 and 1010 point to 3, we will copy
only first object node arrays value)

Note 2 : (Final array shouldnt have any duplicates, If found Precedence needs to be given to first array
than second array,and in same array lesser index will get higher precedence)
If initial arrays are are a=[2,4,5,4] and b=[4,4,5,4,23,2]

Lets assume objectNodes1=[2000,2002,2004,2006] and objectNodes2=[2008,2010,2012,2014,2016,2018,2020]
(Here as in prev exampple 2004 points to 5, 2016 points to 4 etc.)
Return array should be [2000,2002]

*/

/*
Difficulties faced in this lesson :
->
->
*/
#include <stdio.h>
#include <stdlib.h>

/**
ObjectNode holds a value of any type and
also a equals function which will take 2 void * of the same datatype of value, and
this equals function should return 1 if both values are equal,0 otherwise.
*/
struct ObjectNode {
	void * value;
	int(*equals)(void *, void *);
};

/*
Sample equals Function for integers.
You will use this function while creating a Object node whose value holds address of an int.
*/
int equalsInt1(void * a, void *b) {
	//As a and b are void *, you need to first convert them to int * and extract the value.
	if (*(int*)a == *(int*)b)
		return 1;
	else return 0;
}

/*
Sample function to print INT.
*/
void printInt(void * value) {
	printf("%d\n", *(int *)value);
}

/*
Sample function to create a int Object Node from a int pointer and equals function passed.
*/
struct ObjectNode * createIntObjectNode(int *number, int(*equals)(void *, void *)) {
	//Malloc for struct ObjectNode and copy value and equals method appropirately.
	struct ObjectNode * ONode = (struct ObjectNode *)malloc(sizeof(struct ObjectNode));
	ONode->value = (void *)number;
	ONode->equals = equals;
	return ONode;
}

/*
@objectNodes1 -> Array1 of ObjectNodes pointing to values of same datatype.
@objectNodes2 -> Array1 of ObjectNodes pointing to values of same datatype.
@len1 -> length of objectNodes1
@len2 -> length of objectNodes2
@commonElementsLength -> final result array length which needs to be copied, it is already initialied, just copy the value.
*/
struct ObjectNode ** combine_common_elements(struct ObjectNode ** objectNodes1, struct ObjectNode ** objectNodes2, int len1, int len2, int *commonElementsLength) {
	struct ObjectNode ** result = (struct ObjectNode **)malloc(sizeof(struct ObjectNode *) * 100);
	int k = 0;
	for (int i = 0; i < len1; i++)
		for (int j = 0; j < len2; j++)
			if (objectNodes1[i]->equals(objectNodes1[i]->value, objectNodes2[j]->value) == 1)
			{
				if (k == 0)
				{
				result[k++] = objectNodes1[i];
				i++;
				}
				else
				{
					int p = 0;
					for (p = 0; p < k; p++)
						if (objectNodes1[i]->equals(objectNodes1[i]->value, result[p]->value) == 1)
							break;
					if (p == k)
					{
						result[k++] = objectNodes1[i];
						i++;
					}
						

				}
				if (i == len1)
					break;
				

			}
	*commonElementsLength = k;
	/*float a[100], b[100];
	for (int i = 0; i < len1; i++)
		a[i] = *(int*)objectNodes1[i]->value;
	for (int i = 0; i < len2; i++)
		b[i] = *(int*)objectNodes2[i]->value;*/
	
	return result;
}

void test_combine_common_elements() {
	
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int arr2[10] = { 6, 7, 8, 9, 10, 30, 40, 50, 10, 20 };
	int len1 = 10;
	int len2 = 10;
	//ans 1 2 3 6 7 8 9 10
	struct ObjectNode ** intvalues1 = (struct ObjectNode **) malloc(sizeof(struct ObjectNode *)*len1);
	struct ObjectNode ** intvalues2 = (struct ObjectNode **) malloc(sizeof(struct ObjectNode *)*len2);
	//Copy &arr[0] into intValues1 &arr[2] into intValues[2], same for intvalues2 too
	int i = 0;
	for (i = 0; i<len1; i++){
		intvalues1[i] = createIntObjectNode(&arr[i], &equalsInt1);
	}
	for (i = 0; i<len2; i++){
		intvalues2[i] = createIntObjectNode(&arr2[i], &equalsInt1);
	}
	//Get Combined array of ObjectNodes
	int commonLength = 0;
	struct ObjectNode ** result = combine_common_elements(intvalues1, intvalues2, len1, len2, &commonLength);
	//Print the values, using printInt method.
	

}
