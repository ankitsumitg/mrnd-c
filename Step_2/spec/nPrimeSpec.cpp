#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/nPrime.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(nPrimeSpec)
	{
	public:
		TEST_METHOD(inValidInputChecknPrimeSpec)
		{
			int* Arr;
			Arr = nPrime(0);
			int* output =NULL;
			Assert::AreEqual(Arr, output, L"Invalid input should return NULL", LINE_INFO());
		}

		TEST_METHOD(validInputChecknPrimeSpec)
		{
			int* Arr;
			Arr = nPrime(10);
			int output[4] = { 2, 3, 5, 7 };
			for (int i = 0; i < 4; i++)
			{
				Assert::AreEqual(Arr[i], output[i], L"Valid input should return prime list", LINE_INFO());
			}

			int* Arr2;
			Arr2 = nPrime(100);
			int output1[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89,97 };
			for (int i = 0; i < 25; i++)
			{
				Assert::AreEqual(Arr2[i], output1[i], L"Valid input should return prime list", LINE_INFO());
			}
		}

		
	};
}