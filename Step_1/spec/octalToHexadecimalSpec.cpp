#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/octalToHexadecimal.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(octalToHexadecimalSpec)
	{
	public:

		TEST_METHOD(octaltoHexazero)
		{
			Assert::AreEqual(0, octalToHexadecimal(0), L"octalToHexadecimal: zero as parameter failed", LINE_INFO());
		}
		TEST_METHOD(octaltoHexapositive)
		{
			Assert::AreEqual(1, octalToHexadecimal(1), L"octalToHexadecimal: one as parameter failed", LINE_INFO());
			Assert::AreEqual(82, octalToHexadecimal(202), L"octalToHexadecimal: 202 as parameter failed", LINE_INFO());
			Assert::AreEqual(53699, octalToHexadecimal(1233231), L"octalToHexadecimal: 1233231 as parameter failed", LINE_INFO());
		}
		TEST_METHOD(octaltoHexanegative)
		{
			Assert::AreEqual(0, octalToHexadecimal(-1), L"octalToHexadecimal: negative number as parameter failed", LINE_INFO());
		}


	};
}