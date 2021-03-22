#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/count.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(countSpec)
	{
	public:

		TEST_METHOD(countzero)
		{
			Assert::AreEqual(-1, count(0, 12), L"Count: zero as first parameter failed", LINE_INFO());
			Assert::AreEqual(0, count(123, 0), L"Count: zero as second parameter failed", LINE_INFO());
		}

		TEST_METHOD(countpositive)
		{
			Assert::AreEqual(123, count(1, 123), L"Count: one as first parameter failed", LINE_INFO());
			Assert::AreEqual(0, count(123, 1), L"Count: one as second parameter failed", LINE_INFO());
			Assert::AreEqual(5, count(3, 15), L"Count: remainder zero case failed", LINE_INFO());
			Assert::AreEqual(4, count(12, 55), L"Count: remainder non-zero case failed", LINE_INFO());
			Assert::AreEqual(0, count(234, 15), L"Count: num1 > num2 case failed", LINE_INFO());
		}

	};
}