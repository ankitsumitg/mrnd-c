/*
Problem Statement :

Check if a DOM (string format) is valid or not.
Take string as a input and validate if every opening tag end with closing tag.
valid tags are html, head, body, p.

consider the following priority for tags  [ html > head == body > p ]

Return false if you encounter a invalid tags.
For all invalid cases return -1; other wise 1

Eg: <html><head><body></body></head></html>  o/p : 1
<body><p></p></body> o/p : 1
<html><head></body></head></html> o/p: -1
<head><html></html></head> o/p: -1

In case of
- empty string return -1
- no tag return 1

NOTE : Donot use any Global Variables

Marks : 15
*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int isStringValidDom(char* input) {
	if (input == NULL || input[0] == '\0')
		return -1;
	int a[100];
	int x = 0;
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == '<')
		{
			i++;
			if (input[i] == '/')
			{
				i++;
				if (input[i] == 'h')
				{
					i++;
					if (input[i] == 't')
						a[x++] = -3;
					else if (input[i] == 'e')
						a[x++] = -2;
				}
				else if (input[i] == 'b')
					a[x++] = -2;
				else a[x++] = -1;
			}
			else
			{
				
				if (input[i] == 'h')
				{
					i++;
					if (input[i] == 't')
						a[x++] = 3;
					else if (input[i] == 'e')
						a[x++] = 2;
				}
				else if (input[i] == 'b')
					a[x++] = 2;
				else a[x++] = 1;
			}
		}
		while (input[i] != '>')
			i++;
	}
	if (x % 2 != 0)
		return -1;
	else
	{
		int y = x -1;
		int i = 0;
		int check = 1;
		while (i < x / 2){
			if (a[i] < a[i + 1])
				return -1;
			i++;
		}
		i = 0;
		while (i <= x / 2)
			if (a[i] + a[y] != 0)
			{
				return -1;
			}
			else {
				i++;
				y--;
			}
	}
	return 1;
}