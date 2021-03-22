#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/decimalToOctal.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(decimalToOctalSpec)
	{
	public:

		TEST_METHOD(decimaltoOctalzero)
		{
			Assert::AreEqual(0, decimalToOctal(0), L"decimalToOctal: zero as parameter failed", LINE_INFO());
		}
		TEST_METHOD(decimaltoOctalpositive)
		{
			Assert::AreEqual(1, decimalToOctal(1), L"decimalToOctal: one as parameter failed", LINE_INFO());
			Assert::AreEqual(202, decimalToOctal(130), L"decimalToOctal: 130 as parameter failed", LINE_INFO());
			Assert::AreEqual(30071, decimalToOctal(12345), L"decimalToOctal: 12345 as parameter failed", LINE_INFO());
			Assert::AreEqual(23420, decimalToOctal(10000), L"decimalToOctal: 10000 as parameter failed", LINE_INFO());
		}
		TEST_METHOD(decimaltoOctalnegative)
		{
			Assert::AreEqual(0, decimalToOctal(-1), L"decimalToOctal: negative number as parameter failed", LINE_INFO());
		}
	};
}