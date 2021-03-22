/*
Here you will compare 2 searching algorithms.

LinearSearch and BinarySearch

Question :
Given an arr and its length and a key element, return the index (Where key is found) if key is found in arr
or -1 if key is not found.

Sample Input : 
[1,2,3,4,5] Key : 4, Returns 3
[0,49,22] Key : 212, Returns -1

Observations: (Write down what you observed here, Run for various variations):

Linear Search:for this best case id O(1) and worst case is O(n)

Binary Search :it requires sorted array and divides the data into half bassed on middle consition so time complexity is O(logn)

Conclusion :
*/

int linearSearch(int *arr, int len, int key) {
	for (int i = 0; i < len; i++)
		if (arr[i] == key)
			return i;
	return -1;
}



int binarySearch(int *arr, int len, int key) {
	//Use this function as wrapper function,if you are implementing bs recursively.
	int first = 0;
	int last = len - 1;
	int middle = (first + last) / 2;

	while (first <= last) {
		if (arr[middle] < key)
			first = middle + 1;
		else if (arr[middle] == key) {
			return middle;
			break;
		}
		else
			last = middle - 1;

		middle = (first + last) / 2;
	}
	if (first > last)

		return -1;
}