#include "stdafx.h"
#include "CppUnitTest.h"
#include <malloc.h>
#include "../src/maxPosNegSum.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(maxPosNegSumSpec)
	{
	public:
		TEST_METHOD(maxPosNegSuminInValidInputCheck)
		{
			int Arr1[5] = { 1, 9, 8, 2, 3 };
			Assert::AreEqual(0,maxPosNegSum(Arr1,5), L"Array invalid input failed.", LINE_INFO());
			int Arr2[5] = { -1, -9, -8, -2, -3 };
			Assert::AreEqual(0, maxPosNegSum(Arr2, 5), L"Array invalid input failed.", LINE_INFO());
			int Arr3[1] = {};
			Assert::AreEqual(0,maxPosNegSum(Arr3,0), L"Length equal to zero check failed.", LINE_INFO());
			int Arr4[1] = {};
			Assert::AreEqual(0, maxPosNegSum(Arr4, -1), L"Length less than zero check failed.", LINE_INFO());
		}

		TEST_METHOD(maxPosNegSuminsertValidInputCheck)
		{
			int Arr1[8] = {1, 9, 8, 2, 3, -1, -10, -5};
			Assert::AreEqual(8, maxPosNegSum(Arr1, 8), L"Valid input check failed", LINE_INFO());
			int Arr2[6] = {-10, -1, -2, -9, -12, 0};
			Assert::AreEqual(-1, maxPosNegSum(Arr2, 6), L"Valid input check failed", LINE_INFO());
			int Arr3[30] = { -2, -83, 67, 98, -72, -74, 29, 39, 60, 36, 4, -93, 83, -55, 69, -10, -29, 38, -64, -14, -93, 76, -58, 32, -84, 17, -64, 96, -40, -74 };
			Assert::AreEqual(96, maxPosNegSum(Arr3, 30), L"Valid input check failed", LINE_INFO());
		}
	};
}