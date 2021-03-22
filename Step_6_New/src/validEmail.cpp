/*

In a college, there is a data centre where all the communications go on.
Like mails about Holidays, Schedules, Notices etc information.
The clerk at data centre used to ask students of every new batch to create new emails and submit through forms.
The clerk must know the name of the student by seeing the email.

But the students are mischevious. Their emails are unidentifiable.
For example: A student Manoj gave his email as iamironman123@gmail.com, Sunil as rockrocky143@gmail.co.in

The clerk is unable to find the name of the student just by seeing the email address.
So, he added a rule that email must contain the student name as prefix or suffix to email address

Example: Manoj has to create his email as "manojsomething@something.com" or "somethingmanoj@something.com"

Note: "abcmanojabc@live.com is invalid email address Since "manoj" is neither a prefix nor a suffix.

Help the clerk to check the following:

(1). Given email is Valid or not
ex: "manoj@gmail" is not a valid email address

(2). Given email satisfies the suffix/prefix condition
ex: student name: abc, email: "ab@c.com" is not valid
because even though it is valid email email address, it is not satisfying the clerk's new rule.


Given input is in the form of "name email" space seperated Name and email.
Return 1 if email condition (1) is only satisfied. Return 2 if both (1) and (2) are satisfied. Return 0 for all other cases
ex: INPUT: "Manoj iammanoj@gmail.com"
OUTPUT: 2

INPUT: "abc abc.com"
OUTPUT: 0


NOTE: (1) Do not use any string.h functions.
(2) Rules of a valid email address
a. should use only alphanumeric characters. That is, use only “a” through “z” and “0 (zero)” through “9”.
b. Use of the following characters: < > ( ) [ ] ; : , @ \ <space> is not allowed
c. As long as they are not the first character in the e-mail address, hyphens ( – ), underscores ( _ ), periods ( . ),
and numeric characters (“0” through “9”) are acceptable characters to use within the address.
d. Do not use null characters (spaces) between characters. However, as mentioned above, underscores are acceptable.
e. Email length must be less than or equal to 254 characters.
(3) MANoJ ,MaNoj all are same and to be treated as manoj in the name field
(4) Delimiter b/w name and email can be single or multiple spaces
(5) Input is in read only mode. you cannot edit it.
*/

#include <stdio.h>
#include <stdlib.h>
char tolower(unsigned char);
int cmp(char*, int, char*, int);


int isValidEmail(char *email)
{
	// variable email is in form of "name something@domain.server"
	char* name = (char*)malloc(100*sizeof(char));
	int c = 0;
	int i;
	for (i = 0; email[i] != '\0'; i++)
	{
		if (email[i] == '@')
			c++;
	}
	//if their is not @ symbol or more than one @  symbol or length of email is greater than 254
	if (c == 0 || c > 1 || i>253)
		return 0;
	else if (c == 1)
	{

		int i;
		for (i = 0; email[i] != ' '; i++)
		{
			name[i] = email[i];
		}
		name[i] = '\0';
		//separating the name of the student separately
		realloc(name, (i + 1)*sizeof(char));
		for (; email[i] != ' '; i++);
		i++;
		if (email[i] == '-' || email[i] == '_' || email[i] == '.')
			return 0;
		else
		{
			while(email[i] == ' ')
			i++;
			int j = i;
			//for not valid email address
			for (; email[j] != '\0'; j++)
			{
				if (email[j] == ' ' || email[j] == ')' || email[j] == '(' || email[j] == '[' || email[j] == ']' || email[j] == '<' || email[j] == '>' || email[j] == ',' || email[j] == '\\' || email[j] == ';' || email[j] == ':')
					return 0;
				else if (email[j] == '.')
					break;
			}
			j = i;
			char* id = (char*)malloc(100 * sizeof(char));
			int k = 0;
			for (; email[j] != '@'; j++)
			{
				id[k] = email[j];
				k++;
			}
			id[k] = '\0';
			//separating the email id separately
			realloc(id, (k + 1)*sizeof(char));
			int check = cmp(name,i-1, id,k);
			if (check == 1)
				return 2;
			else return 1;

		}
	}
}
int cmp(char* a,int len1, char* b,int len2)
{
	int c;
	int k = 0;
	c = 0;
	//checking match for only for the siffix or prefix
	for (int i = 0; i ==0 || i == len2-len1; i++)
	{
		c = 0;
		for (int j = 0; j < len1; j++)
		{
			int k = i;
			if ((b[k] >= 'a'&& b[k] <= 'z') || (b[k] >= 'A'&& b[k] <= 'Z') && (a[j] >= 'a'&& a[j] <= 'z') || (a[j] >= 'A'&& a[j] <= 'Z'))
			{
			while (tolower(b[k]) == tolower(a[j]) && k<len2 && j<len1)
			{
				c++;
				k++;
				j++;
			}
			if (c == len1 && tolower(b[0]) == tolower(a[0]) || tolower(b[len2-1]) == tolower(a[len1-1]))
			{
				return 1;
			}
			break;

			}
			else break;
		}
	}
	return 0;
}
//converting into the lower character 
char tolower(unsigned char ch) 
{
	if (ch >= 'A' && ch <= 'Z')
		ch = 'a' + (ch - 'A');
	return ch;
}