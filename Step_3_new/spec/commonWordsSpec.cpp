#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/commonWords.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(commonWordsSpec)
	{
	public:

		bool strcmp(char *str1, char *str2) {
			while (*str1 && *str2) {
				if (*str1 != *str2) {
					return false;
				}
				str1++;
				str2++;
			}
			return !*str1 && !*str2;
		}

		bool compare(char expected[][31], int count, char **actual) {
			for (int i = 0; i < count; ++i) {
				bool found = false;
				for (int j = 0; j < count; ++j) {
					if (strcmp(expected[i], actual[j])) {
						found = true;
						break;
					}
				}
				if (!found) {
					return false;
				}
			}
			return true;
		}

		TEST_METHOD(nullInput)
		{
			Assert::IsNull(commonWords(NULL, NULL), L"Common Words null check failed.", LINE_INFO());
		}

		TEST_METHOD(stringsWithSpaces)
		{
			char *str1 = "       ";
			char *str2 = " who what";
			Assert::IsNull(commonWords(str1, str2), L"No common words check failed.", LINE_INFO());
		}

		TEST_METHOD(noCommonWordsInput)
		{
			char *str1 = "the are all is well";
			char *str2 = " who what";
			Assert::IsNull(commonWords(str1, str2), L"No common words check failed.", LINE_INFO());
		}

		TEST_METHOD(commonWordsInput)
		{
			char *str1 = "the are all is well";
			char *str2 = "is who the";
			char expected[2][31] = { { "the" }, { "is" } };
			char **res = commonWords(str1, str2);
			Assert::IsTrue(compare(expected, 2, res), L"Common Words positive check failed.", LINE_INFO());
		}

	};
}