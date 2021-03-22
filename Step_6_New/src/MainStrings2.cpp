/*

Use Strings2 File for testing any other function in other Cpp files of the Strings Project.

DO NOT write main function in any other File or else your Build Fails.s

Objectives of C-Strings-2 Lesson:

->Using malloc to create new strings
->New ways of Handling Strings

Solve CommonRoute , Concat4Strings keeping complexity in Mind , BruteForce solutions take
long time to pass ,and will eventually fail when we run on our side with Timeouts .

Make Sure The Each Individual Test cases for Large inputs dosent take more than
2Seconds. (ie Real20_CommonRoute TestCase in CommonRouteSpec)
*/

#include "FunctionHeadersStrings2.h"
#include <stdio.h>

int main(){


	//Test Consonants_Vowels
	//char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//	int consonants;
	//	int vowels;
	//	count_vowels_and_consonants(str, &consonants, &vowels);

	//Test getFrequencyofWord
	//char sentences[][100] = { "abababa", "he he", "ab cd ab cd", "    ", "1234 aaaaaaa", "asd324", "yzqwer 23425", "a" };
//	char words[][100] = { "ab", "he", "ab cd", " ", "aa", "asd324", "x", "a" };
//	int counts[100] = { 3, 2, 2, 4, 6, 0, 1 };
//	int sc = 7;
//	int si = 0;
//	for (si = 0; si < sc; si++){
//		int temp_c = count_word_in_str_way_1(sentences[si], words[si]);

//	}
	//Test getSubstring

	//Test getLastWord
	//char sentences[][100] = { "word", "he he", "   ", "d ab   ", "  x", "asd324", "", "a" };
	//char ans[][100] = { "word", "he", "", "ab", "x", "asd324", "", "a" };
//	int sc = 8;
	////int si = 0;
//	for (si = 0; si < sc; si++){
//		char *new_str = get_last_word(sentences[si]);
	//}

		//Test others
//	int actualAns = isValidEmail("MAnOJ m_mAnOjabc@gmail.com");
//	char s1[100] = "a3e2";
//	char s2[100] = "4ekl";
//	int expectedAns = 1;
//	int actualAns = isSTRMatched(s1, s2);

//	char str1[100] = "";
//	char str2[100] = "100111";
//	char eans[100] = "011000";
//	char * ans = performOperation(str1, str2, "NOR");
	int cost = -1;
	char hacklist[100] = "ADCB";
	char codelist[100] = "CBAD";
	char ans[100] = "AD";
	int cost_ans = 5;
	char *res = NULL;
	res = find_common_route(hacklist, codelist, &cost);
		return 0;
}

