#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/removeSpaces.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(removeSpacesSpec)
	{
	public:

		bool compareStrings(char *str1, char *str2) {
			while (*str1 && *str2) {
				if (*str1 != *str2) return false;
				str1++;
				str2++;
			}
			if (*str1 || *str2) return false;
			return true;
		}

		TEST_METHOD(emptyAndNullString)
		{
			char str[] = "";
			removeSpaces(str);
			Assert::IsTrue(compareStrings(str, ""), L"Empty string input failed.", LINE_INFO());
			Assert::AreEqual('\0', removeSpaces(NULL), L"Null string input failed.", LINE_INFO());
		}

		TEST_METHOD(noSpacesString)
		{
			char str[] = "123";
			removeSpaces(str);
			Assert::IsTrue(compareStrings(str, "123"), L"No Spaces string input failed.", LINE_INFO());
		}

		TEST_METHOD(spacesString)
		{
			char str[] = "12 w 2e     we  2 3     ";
			removeSpaces(str);
			Assert::IsTrue(compareStrings(str, "12w2ewe23"), L"Spaces string input failed.", LINE_INFO());
		}
	};
}