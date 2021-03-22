#include "stdafx.h"
#include "CppUnitTest.h"
#include <malloc.h>
#include "../src/sortedArrayInsertNumber.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(sortedArrayInsertNumberSpec)
	{
	public:

		int * createArray() {
			int *Arr = (int *)malloc(5 * sizeof(int));
			Arr[0] = 2;
			Arr[1] = 4;
			Arr[2] = 6;
			Arr[3] = 8;
			Arr[4] = 10;
			return Arr;
		}

		TEST_METHOD(SAINinValidInputCheck)
		{
			
			Assert::IsNull(sortedArrayInsertNumber(NULL, 1, 1), L"Array NULL check failed.", LINE_INFO());
			int Arr1[1] = { 1 };
			Assert::IsNull(sortedArrayInsertNumber(Arr1, -2, 1), L"Length less than zero check failed.", LINE_INFO());
		}

		TEST_METHOD(SAINinsertAtFirstIndex)
		{
			int *Arr = createArray();
			Arr = sortedArrayInsertNumber(Arr, 5, 1);
			Assert::AreEqual(1, Arr[0], L"0th index value should be 1", LINE_INFO());
		}

		TEST_METHOD(SAINinsertAtLastIndex)
		{
			int *Arr = createArray();
			Arr = sortedArrayInsertNumber(Arr, 5, 12);
			Assert::AreEqual(12, Arr[5], L"5th index value should be 12", LINE_INFO());
		}

		TEST_METHOD(SAINinsertAtMiddleIndices)
		{
			int *Arr = createArray();
			Arr = sortedArrayInsertNumber(Arr, 5, 5);
			Assert::AreEqual(5, Arr[2], L"2nd index value should be 5", LINE_INFO());
		}
	};
}