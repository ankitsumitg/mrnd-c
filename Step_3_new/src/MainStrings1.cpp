/*

Use MainStrings1 File for testing any other function in other Cpp files of the Strings Project.

DO NOT write main function in any other File or else your Build Fails.

Objectives of Strings-1 Lesson:

->Basics of Strings / Char Arrays .
->Learn about 2D Strings
->Convert Numbers/Floats into Strings
->Manipulating Strings

*/
#include <stdio.h>
#include "FunctionHeadersStrings1.h"

int main(){

	//Test KthIndexFromEnd 
	//char c = KthIndexFromEnd("qwertyui", 3);
//	printf("%c", c);
	//TestNumbertoStr
	//char a[20];
	//number_to_str(-34.435, a, 2);
	//for (int i = 0; i < 6; i++)
	//	printf("%c", a[i]);

	//removeSpaces
	
	char **a= commonWords("hi hello bye","hello hi");
	puts(a[0]);
	puts(a[1]);
	
	//StrWordsinRev
	//str_words_in_rev("hello  hi", 9);

	//commonWords


	return 0;
}