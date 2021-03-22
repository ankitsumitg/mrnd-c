#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/nthNumber.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(nthNumberSpec)
	{
	public:

		TEST_METHOD(FibPrimezero)
		{
			Assert::AreEqual(-1, nthFibonacci(0), L"nthFibonacci: zero as parameter failed", LINE_INFO());
			Assert::AreEqual(-1, nthPrime(0), L"nthPrime: zero as parameter failed", LINE_INFO());
		}

		TEST_METHOD(FibPrimepositive)
		{
			Assert::AreEqual(1, nthFibonacci(2), L"nthFibonacci: positive number as parameter failed", LINE_INFO());
			Assert::AreEqual(144, nthFibonacci(13), L"nthFibonacci: positive number as parameter failed", LINE_INFO());
			Assert::AreEqual(2584, nthFibonacci(19), L"nthFibonacci: positive number as parameter failed", LINE_INFO());
		
			Assert::AreEqual(3, nthPrime(2), L"nthPrime: positive number as parameter failed", LINE_INFO());
			Assert::AreEqual(229, nthPrime(50), L"nthPrime: positive number as parameter failed", LINE_INFO());
			Assert::AreEqual(509, nthPrime(97), L"nthPrime: positive number as parameter failed", LINE_INFO());
		}

		TEST_METHOD(FibPrimenegative)
		{
			Assert::AreEqual(-1, nthFibonacci(-2), L"nthFibonacci: negative number as parameter failed", LINE_INFO());
			Assert::AreEqual(-1, nthFibonacci(-100), L"nthFibonacci: negative number as parameter failed", LINE_INFO());
			Assert::AreEqual(-1, nthFibonacci(0), L"nthFibonacci: negative number as parameter failed", LINE_INFO());

			Assert::AreEqual(-1, nthPrime(-3), L"nthPrime: negative number as parameter failed", LINE_INFO());
			Assert::AreEqual(-1, nthPrime(-13), L"nthPrime: negative number as parameter failed", LINE_INFO());
			Assert::AreEqual(-1, nthPrime(-23), L"nthPrime: negative number as parameter failed", LINE_INFO());
		}
	};
}