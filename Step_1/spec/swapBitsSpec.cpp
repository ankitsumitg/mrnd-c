#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/swapBits.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(swapBitsSpec)
	{
	public:

		void testSwapBitsSpec(unsigned int number, int p1,int p2,int n, unsigned int expected) {
			unsigned int actual = swapBits(number, p1, p2, n);
			Assert::AreEqual(expected, actual, L"swapBitsSpec test case failed", LINE_INFO());
		}
		TEST_METHOD(swapBitsEasy)
		{
			
			testSwapBitsSpec(47, 1, 5, 3, 227);
			testSwapBitsSpec(28,0,3,2,7);
		}

		TEST_METHOD(swapBitsNegative)
		{

			testSwapBitsSpec(1234567, -8, 10, 15, 0);
			testSwapBitsSpec(1234567, 8, 61, 15, 0);
			testSwapBitsSpec(9457865, 5, 27, -14, 0);
		}

		TEST_METHOD(swapBitsZero)
		{

			testSwapBitsSpec(0, 0, 18, 10, 0);
		}

		TEST_METHOD(swapBitsLong)
		{

			
			testSwapBitsSpec(682, 1, 6, 3, 868);
			testSwapBitsSpec(4294967295, 1, 20, 8, 4294967295);
			testSwapBitsSpec(178, 0, 4, 4, 43);
			testSwapBitsSpec(8, 1, 8, 4, 1024);
			testSwapBitsSpec(65535, 0, 16, 16, 4294901760);
			testSwapBitsSpec(178, 0, 30, 5, 2147483808);
			testSwapBitsSpec(2147483647, 0, 29, 25, 4261412867);
			
			
		}


	};
}