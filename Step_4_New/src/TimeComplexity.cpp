/**
Here you will be given 14 functions for which you have to return Big-Oh time complexity as a string.
You only need to fill return values for functions whose name starts with "function", it might use some helper functions.
You need to calculate the complexity of those helper functions too and return overall bigoh complexity from
wrapper function.

For example for function0. You need to return "O(n)";

If exacty time complexity is 6(n*n) . You just need to return n*n.
Rules for returning Strings :
'O' should be capital.
You can't write nlogn, write O(n*logn).
Use ^ character only if the power is not a constant. 
n^2 is to be written as n*n.
n^n can be written as it is.

For functions taking arrays as input ,consider n as size of array.

Try to solve the tasks without looking at answers, even if testcases fail.This makes sure you are learning really.
*/

#include<stdio.h>
#include<math.h>

char* function0(int n) {
	//Sample Not tested
	int i;
	for (i = 0; i < n; i++) {

	}

	return "O(n)";
}

char* function1(int n) {
	int i, j;
	for (i = 0, j = n; i < j; i *= 2, j /= 2);

	return "O(logn)";
}

char* function2(int n) {
	int i;
	for (i = 0; i<n; i++) {
		//some code
	}
	for (i = 0; i<6 * n; ++i) {
		//some other code
	}

	return "O(n)";
}

char* function3(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j += i) {
			//some code
		}
	}

	return "O(n*logn)";
}

//Consider n as number of digits in "number" 
int digit_count(int number) {
	int count = 0;
	while (number != 0) {
		number /= 10;
		count++;
	}
	return count;
}

char* function4(int number) {
	digit_count(number);
	return "O(n)";
}

void swap(int *n1, int *n2) {
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void randomSort(int *arr, int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}

char* function5(int *arr, int size) {
	randomSort(arr, size);
	return "O(n*n)";
}

int factorial(int n) {
	int i, result = 1;
	for (i = 2; i <= n; i++) {
		result *= i;
	}
	return result;
}

char* function6(int n) {
	factorial(n);
	return "O(n)";
}

//Consider n as number of digits in number
int reverse(int number) {
	int reversed_num = 0, remainder;
	while (number != 0) {
		remainder = number % 10;
		reversed_num = reversed_num * 10 + remainder;
		number /= 10;
	}
	return reversed_num;
}

char* function7(int number) {
	reverse(number);
	return "O(n)";
}

char* function8(int n) {
	int i, j;
	int k = 0;
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j *= 2) {
			for (k = 2; k < 1000; k++){

			}
		}
	}
	return "O(n*logn)";
}

char* function9(int n) {
	int i, j;
	for (i = n; i >= 1; i /= 2){ //logn
		for (j = 1; j<n*n; j++){ // n square times
			//some code
		}
	}
	return "O(n*n*logn)";
}

int power(int base, int exp) {
	int i, result = 1;
	for (i = 1; i <= exp; i++) {
		// mutiplying n with n, n times
		result *= base;
	}
	return result;
}

char* function10(int n) {
	int i, j;
	for (i = 1; i <= n; i += 2) {
		for (j = 1; j <= power(n, i); j += 2) {
			//some O(1) tasks
		}
	}
	return "O(n^n)";
}

void remove_dup(int *arr, int size){
	int i, j, k, *ptr = NULL;
	for (i = 0; i < size; i++) {
		for (j = i + 1; j < size;) {
			if (arr[j] == arr[i]) {
				for (k = j; k < size; k++) {
					arr[k] = arr[k + 1];
				}
				size--;
			}
			else
				j++;
		}
	}
}

char* function11(int *array, int size) {
	remove_dup(array, size);
	return "O(n*n)";
}

int find_min_sum(int *array, int size) {
	int i, j, min_sum = 0, sum;
	for (i = 0; i < size - 1; i++) {
		for (j = i + 1; j < size; j++) {
			sum = array[i] + array[j];
			if (abs(min_sum) > abs(sum)) {
				min_sum = sum;
			}
		}
	}
	return min_sum;
}

char* function12(int *array, int size) {
	find_min_sum(array, size);
	return "O(n*n)";
}

//calculates standard deviation
float calculate_sd(float *array, int size) {
	float sum = 0.0, mean, sd = 0.0;
	int i;
	for (i = 0; i<size; ++i) {
		sum += array[i];
	}
	mean = sum / size;
	for (i = 0; i<size; ++i)
		sd += power(array[i] - mean, 2);
	return sqrt(sd / 10);
}

char* function13(float* array, int size) {
	calculate_sd(array, size);
	return "O(n)";
}

int negative_sum(int *array, int size) {
	int i, sum = 0;
	for (i = 0; i<size; i++) {
		if (array[i] < 0)
			sum += array[i];
	}
	return sum;
}

char* function14(int *array, int size) {
	negative_sum(array, size);
	return "O(n)";
}




