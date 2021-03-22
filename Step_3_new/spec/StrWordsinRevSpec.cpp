#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/StrWordsinRev.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(StrWordsinRevSpec)
	{
	public:

		TEST_METHOD(BasicStrNoSpaces)
		{
			char input[10] = "abhi";
			char output[10] = "abhi";
			int len = 4;
			int i = 0;
			str_words_in_rev(input,4);
			for (i = 0; i < len; i++){
				Assert::AreEqual(input[i],output[i], L"Failed 1 Not equals 1", LINE_INFO());
			}
			//printf("asd");
			
		}
		TEST_METHOD(BasicStr)
		{
			char input[10] = "a b c d";
			char output[10] = "d c b a";
			int len = 7;
			int i = 0;
			str_words_in_rev(input, len);
			for (i = 0; i < len; i++){
				Assert::AreEqual(input[i], output[i], L"Failed 1 Not equals 1", LINE_INFO());
			}
			//printf("asd");

		}
		TEST_METHOD(LargeStr)
		{
			char input[100] = "missionrnd is great";
			char output[100] = "great is missionrnd";
			int len = 19;
			int i = 0;
			str_words_in_rev(input, len);
			for (i = 0; i < len; i++){
				Assert::AreEqual(input[i], output[i], L"Failed 1 Not equals 1", LINE_INFO());
			}
			//printf("asd");

		}
		TEST_METHOD(MultiSpaces)
		{
			char input[100] = "missionrnd    is    great";
			char output[100] = "great    is    missionrnd";
			int len = 25;
			int i = 0;
			str_words_in_rev(input, len);
			for (i = 0; i < len; i++){
				Assert::AreEqual(input[i], output[i], L"Failed 1 Not equals 1", LINE_INFO());
			}
			//printf("asd");

		}


	};
}