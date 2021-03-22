/*
ProblemCode : EncodeDecode

An instructor is running a coding course online for hundreds of students, He frequently conducts online tests for 
students to keep them up to date with new questions etc. But he is repeatedly observing that some group of students
are always copying and are submitting same solutions. As he has no other option left he decided to conduct final test
at a offline center where he can personally invigilate so that no one copies. He allows access for net so that 
students can get some theory concepts cleared during test time, but as expected Ram and Sham of the students are
again planning on sharing their answers through net.
Based on previous experiences, the instructor is sure that they will copy no matter how many times "Dont Copy" 
instructions were given etc. So he installed spoofers which will track their net usage and see if any meaningfull
data is being shared etc So that they can be caught.

Ram and Sham being very smart, started to design a encryption algorithm with which they can communicate with each
other without being detected. They also have designed decryption algortihm to know actual message.

Their message is simple, They want to pass the code (String) without being detected over network.
Like if ram wants to send abcde he will send it as cbdae to Sham, Sham decodes it again back to abcde.

Encryption/Encoding Algortihm : 
-> Initially encoded string will be empty;
-> Given an String, Each time the middle char of string will be picked, and appened to encoded string.
Ie if string is sanji, First n will be picked.
EncodedStr will be "n", Remaning message is "saji", "a" will be picked (In case of even letters, left most middle will be picked)
EncodedStr will be "na", Remaining message is "sji"."j" will be picked.
Encoded Str is "naj", Remaining Msg is "si". "s" will be picked. followed by i.
Final encoded str will be "najsi".

Similarly for Franky, Encoded Str will be anrkfy.

Decoding Algorithm : 
-> Opposite of above. Given "anrkfy" as initial message, it will be decoded to franky.

Some more examples :
-> luffy ----[Enc]---> fufly ---- [Dec]--> luffy

Your aim of this question is to help your friends Ram and Sham by implementing encode and decode functions so that they can pass
the exam :D.

Marks : 7 for Encode, 8 for decode . You need to write a O(n) solution to fetch full marks.

Notes : Return Empty Strings for Null inputs.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *decode(char *);
char *encode(char *);

void testEncodeDecode() {
	char * message = "luffy";
	char * encoded = encode(message);
	printf("Message : %s, Encoded : %s\n", message, encoded);
	printf("ReEncoding from Decoded String is %s\n", decode(encoded));
	//Write your sample inputs and outputs here.
}


char * encode(char *str) {
	if (str == NULL || str[0] == '\0')
		return "";
	int x = strlen(str)/2;
	int io = strlen(str);
	char* s = (char*)malloc((strlen(str) + 1)*sizeof(char));
	int i;
	int c = 0;
	int y;
	if (strlen(str) % 2 == 0)
	{
		c++;
		y = x;
	}
	for (i = 0; i < strlen(str); i++)
	{
		if (strlen(str) % 2 == 0)
		{
			if (i % 2 == 0)
			{
				s[i] = str[y - c];
				//c++;
			}
			else{
				s[i] = str[x];//+ c];
				//c++;
				x++;
				y--;
			}


		}
		else
		{
			if (i == 0)
			{
				s[i] = str[x];
				c++;
			}
			else if (i % 2 == 0)
			{
				s[i] = str[x + c];
				c++;
			}
			else{
				s[i] = str[x - c];
			//	c++;
			}
		}
	}
	s[i] = '\0';
	return s;
}
char* decode(char *str) {
	if (str == NULL || str[0] == '\0') 
		return "";
	int x = strlen(str) / 2;
	char* s = (char*)malloc((strlen(str) + 1)*sizeof(char));
	int i;
	//int c = 0;
	int y = x;
	if (strlen(str) % 2 == 0)
	{
		//c++;
		x--;
		y = x;
	}
	for (i = 0; i < strlen(str); i++)
	{
		if (strlen(str) % 2 == 0)
		{
			if (i % 2 == 0)
			{
				s[x] = str[i];
				//c++;
				x--;
				
			}
			else{
				y++;
				s[y] = str[i];//+ c];
				//c++;
				//x--;
				//c++;
			}


		}
		else
		{
			if (i == 0)
			{
				s[x] = str[i];
				//c++;
				y = x + 1;
				x--;
			}
			else if (i % 2 == 0)
			{
				s[y] = str[i];
				y++;
				//c++;
			}
			else{
				
				s[x] = str[i];
				x--;
				//	c++;
			}
		}
	}
	s[i] = '\0';
	return s;
}