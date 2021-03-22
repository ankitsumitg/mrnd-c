#include <stdarg.h>

/*
OVERVIEW: 	A school has unknown number of students. Write a function that takes a variable number of arguments representing student marks in english
and returns the number of students who scored > 90 marks.
E.g.: variableArguments(3, 20, 90, 98) returns 1. One value (98) is greater than 90.

INPUTS: 	First argument is number (arg_count) of student marks followed by "arg_count" number of arguments.
E.g.: If first argument to function is 5, total number of arguments to function will be 6 (1 + 5).

OUTPUT: 	Returns the number of students who scored > 90 marks.

ERROR CASES:

NOTES: 		use stdarg.h header.
*/
#include <stdarg.h>
int variableArguments(int arg_count, ...)
{
	va_list valist;
	int i = 0, count = 0;
	va_start(valist, arg_count);
	for (i = 1; i <= arg_count; i++)
	{
		if (va_arg(valist, int)>90) 
			count++;
	}
	//deallocating the memory
	va_end(valist);
	return count;
}