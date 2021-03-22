#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/isPerfect.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(isPerfectSpec)
	{
	public:

		bool compare(long input[], int actual[],int expected[], int length) {
			isPerfect(input, actual, length);
			for (int i = 0; i < length; ++i) {
				if (actual[i]!= expected[i]) {
					return false;
				}
			}
			return true;
		}

		TEST_METHOD(basicCheck)
		{
			//test case with 1 element that is a perfect number.
			long input2[] = { 6 };
			int expected2[] = { 1 };
			int actual2[] = { -1 };
			Assert::IsTrue(compare(input2, actual2, expected2, 1), L"Simple test case failed.", LINE_INFO());

			//test case with 1 element that is not a perfect number.
			long input1[] = { 100 };
			int expected1[] = { 0 };
			int actual1[] = { -1 };
			Assert::IsTrue(compare(input1, actual1, expected1, 1), L"Simple test case failed.", LINE_INFO());
			
		}

		TEST_METHOD(noPerfectCheck)
		{
			long input4[] = { 593876, 866062, 277500, 153415, 843916, 173, 201, 339, 721, 164, 117, 67, 492, 569, 183641, 547229, 223488, 79, 52, 30, 949019292, 745811560, 983614509, 654924842, 284599571, 519322040, 42839318, 769385043, 271495563, 359895855 };
			int expected4[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
			int actual4[] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
			Assert::IsTrue(compare(input4, actual4, expected4, 30), L"no perfects test case failed.", LINE_INFO());
		}

		TEST_METHOD(allPerfectCheck)
		{
			long input3[] = { 6, 28, 496, 8128, 33550336 };
			int expected3[] = { 1, 1, 1, 1, 1 };
			int actual3[] = {-1,-1,-1,-1,-1};
			Assert::IsTrue(compare(input3,actual3,expected3,5), L"isPerfect test case failed.", LINE_INFO());
		}

		TEST_METHOD(randomCheck)
		{
			long input5[] = { 769385043, 271495563, 359895855, 33550336, 58, 29, 66, 96, 50, 75, 15, 16, 7, 6, 8128, 580460, 336467, 104291, 973, 904, 632, 841, 551, 429, 141, 863, 849, 28, 496, 8128, 580460, 336467, 949019292, 745811560, 983614509, 654924842, 284599571, 519322040, 42839318 };
			int expected5[] = { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
			int actual5[] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
			Assert::IsTrue(compare(input5, actual5, expected5, 30), L"isPerfect test case failed.", LINE_INFO());
		}

	};
}