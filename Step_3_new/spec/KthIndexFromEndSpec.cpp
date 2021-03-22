#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/KthIndexFromEnd.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(KthIndexFromEndSpec)
	{
	public:

		TEST_METHOD(emptyAndNullString)
		{
			Assert::AreEqual('\0', KthIndexFromEnd("", 2), L"Empty string input failed.", LINE_INFO());
			Assert::AreEqual('\0', KthIndexFromEnd(NULL, 2), L"Null string input failed.", LINE_INFO());
		}

		TEST_METHOD(negativeValue)
		{
			Assert::AreEqual('\0', KthIndexFromEnd("swer", -2), L"K negative value input failed.", LINE_INFO());
		}

		TEST_METHOD(KgreaterThanLength)
		{
			Assert::AreEqual('\0', KthIndexFromEnd("swer", 8), L"K greater than length input failed.", LINE_INFO());
		}

		TEST_METHOD(firstIndex)
		{
			Assert::AreEqual('s', KthIndexFromEnd("swer", 3), L"First index input failed.", LINE_INFO());
		}

		TEST_METHOD(lastIndex)
		{
			Assert::AreEqual('r', KthIndexFromEnd("swer", 0), L"Last index input failed.", LINE_INFO());
		}

		TEST_METHOD(middleIndex)
		{
			Assert::AreEqual('e', KthIndexFromEnd("swer", 1), L"Middle index input failed.", LINE_INFO());
		}
	};
}