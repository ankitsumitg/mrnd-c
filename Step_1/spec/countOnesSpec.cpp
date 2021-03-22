#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/countOnes.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(countOnesSpec)
	{
	public:
	
		TEST_METHOD(CountOneszero)
		{
			Assert::AreEqual(-1, countOnes(0), L"countOnes: zero as parameter failed", LINE_INFO());
		}
		TEST_METHOD(CountOnesnegative)
		{
			Assert::AreEqual(3, countOnes(-3), L"countOnes: negative number as parameter failed", LINE_INFO());
			Assert::AreEqual(6, countOnes(-13), L"countOnes: negative number as parameter failed", LINE_INFO());
			Assert::AreEqual(22, countOnes(-23), L"countOnes: negative number as parameter failed", LINE_INFO());
		}
		TEST_METHOD(CountOnespositive)
		{
			Assert::AreEqual(3, countOnes(3), L"countOnes: positive number as parameter failed", LINE_INFO());
			Assert::AreEqual(6, countOnes(13), L"countOnes: positive number as parameter failed", LINE_INFO());
			Assert::AreEqual(22, countOnes(23), L"countOnes: positive number as parameter failed", LINE_INFO());
		}

	};
}