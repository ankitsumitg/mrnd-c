#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/sortedArrayPositionsChange.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(sortedArrayPositionsChangeSpec)
	{
	public:

		TEST_METHOD(SAPinValidInputCheck)
		{
			
			Assert::IsNull(sortedArrayPositionsChange(NULL, 1), L"Array NULL check failed.", LINE_INFO());
			int Arr1[1] = { 1 };
			Assert::IsNull(sortedArrayPositionsChange(Arr1, -2), L"Length less than zero check failed.", LINE_INFO());
		}

		TEST_METHOD(SAPnoValuesAreSwapped)
		{
			int Arr[5] = { 10, 20, 30, 40, 50 };
			sortedArrayPositionsChange(Arr, 5);
			Assert::AreEqual(20, Arr[1], L"Value at index 1 should be 20", LINE_INFO());
			Assert::AreEqual(40, Arr[3], L"Value at index 3 should be 40", LINE_INFO());
		}

		TEST_METHOD(SAPfirstAndLastValuesAreSwapped)
		{
			int Arr[5] = { 50, 20, 30, 40, 10 };
			sortedArrayPositionsChange(Arr, 5);
			Assert::AreEqual(10, Arr[0], L"Value at index 0 should be 10", LINE_INFO());
			Assert::AreEqual(50, Arr[4], L"Value at index 4 should be 50", LINE_INFO());
		}

		TEST_METHOD(SAPpositionsChange)
		{
			int Arr[5] = { 10, 40, 30, 20, 50 };
			sortedArrayPositionsChange(Arr, 5);
			Assert::AreEqual(20, Arr[1], L"Value at index 1 should be 20", LINE_INFO());
			Assert::AreEqual(40, Arr[3], L"Value at index 3 should be 40", LINE_INFO());
		}

	};
}