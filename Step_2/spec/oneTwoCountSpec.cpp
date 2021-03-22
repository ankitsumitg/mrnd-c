#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/oneTwoCount.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(oneTwoCountSpec)
	{
	public:
		TEST_METHOD(inValidInputCheckoneTwoCountSpec)
		{
			int input[2];
			int* Arr;
			Arr = oneTwoCount(input,0);
			int* output = NULL;
			Assert::AreEqual(Arr, output, L"Valid input should return prime list", LINE_INFO());

			int input1[2];
			int* Arr1;
			Arr1 = oneTwoCount(input1, -10);
			int* output1 = NULL;
			Assert::AreEqual(Arr1, output1, L"Valid input should return prime list", LINE_INFO());
		}

		TEST_METHOD(validInputCheckoneTwoCountSpec)
		{
			int input[10] = { 1, 2, 2, 1, 1, 2, 1, 2, 1, 1 };
			int* Arr;
			Arr = oneTwoCount(input,10);
			int output[2] = { 6, 4 };
			for (int i = 0; i < 2; i++)
			{
				Assert::AreEqual(Arr[i], output[i], L"Valid input should return one's two's count", LINE_INFO());
			}

			int input2[8] = { 1, 1, 1, 1, 2, 2, 2, 2 };
			int* Arr2;
			Arr2 = oneTwoCount(input2,8);
			int output2[2] = { 4, 4 };
			for (int i = 0; i < 2; i++)
			{
				Assert::AreEqual(Arr2[i], output2[i], L"Valid input should return one's two's count", LINE_INFO());
			}
		    
			int input3[5] = { 1, 1, 1, 1, 1 };
			int* Arr3;
			Arr3 = oneTwoCount(input3, 5);
			int output3[2] = { 5, 0 };
			for (int i = 0; i < 2; i++)
			{
				Assert::AreEqual(Arr3[i], output3[i], L"Valid input should return one's two's count", LINE_INFO());
			}
		}
	};
}