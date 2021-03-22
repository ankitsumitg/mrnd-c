#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/removeArrayDuplicates.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(removeArrayDuplicatesSpec)
	{
	public:

		TEST_METHOD(RADinValidInputCheck)
		{
			
			int len = removeArrayDuplicates(NULL, 1);
			Assert::AreEqual(-1, len, L"Invalid input should return -1", LINE_INFO());
			
			int Arr1[1] = { 1 };
			len = removeArrayDuplicates(Arr1, -2);
			Assert::AreEqual(-1, len, L"Invalid Len input should return -1", LINE_INFO());

		}

		TEST_METHOD(RADnoDuplicates)
		{
			int Arr[3] = { 1, 2, 3 };
			int len=removeArrayDuplicates(Arr, 3);
			Assert::AreEqual(3, len, L"Length should be 3", LINE_INFO());
			Assert::AreEqual(1, Arr[0], L"Value at index 0 should be 1", LINE_INFO());
			Assert::AreEqual(2, Arr[1], L"Value at index 1 should be 2", LINE_INFO());
			Assert::AreEqual(3, Arr[2], L"Value at index 2 should be 3", LINE_INFO());
		}

		TEST_METHOD(RADunSortedArray)
		{
			int Arr[7] = { 1, 2, 3, 1, 2, 3, 4 };
			int len=removeArrayDuplicates(Arr, 7);
			Assert::AreEqual(4, len, L"Length should be 4", LINE_INFO());
			Assert::AreEqual(1, Arr[0], L"Value at index 0 should be 1", LINE_INFO());
			Assert::AreEqual(2, Arr[1], L"Value at index 1 should be 2", LINE_INFO());
			Assert::AreEqual(3, Arr[2], L"Value at index 2 should be 3", LINE_INFO());
			Assert::AreEqual(4, Arr[3], L"Value at index 3 should be 4", LINE_INFO());
		}

		TEST_METHOD(RADsortedArray)
		{
			int Arr[6] = { 1, 1, 2, 2, 3, 3 };
			int len=removeArrayDuplicates(Arr, 6);
			Assert::AreEqual(3, len, L"Length should be 3", LINE_INFO());
			Assert::AreEqual(1, Arr[0], L"Value at index 0 should be 1", LINE_INFO());
			Assert::AreEqual(2, Arr[1], L"Value at index 1 should be 2", LINE_INFO());
			Assert::AreEqual(3, Arr[2], L"Value at index 2 should be 3", LINE_INFO());
		}

	};
}