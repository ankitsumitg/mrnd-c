#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/countFactorials.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(countFactorialsSpec)
	{
	public:

		bool compare(long l, long h, int expected) {
			int actual=countFactorials(l,h);
			if (actual==expected)
				return true;
			return false;
		}

		TEST_METHOD(basicCheck)
		{
			//basic test case.
			Assert::IsTrue(compare(0,1,1), L"Simple test case failed.", LINE_INFO());

			//basic test case with no factorials.
			Assert::IsTrue(compare(30,100,0), L"Simple test case failed.", LINE_INFO());

			//basic test case with 0 range.
			Assert::IsTrue(compare(720,720,1), L"Simple test case failed.", LINE_INFO());

		}

		TEST_METHOD(errorCheck)
		{
			Assert::IsTrue(compare(-5,100,-1), L"Constraints check test case failed.", LINE_INFO());
			Assert::IsTrue(compare(100, 2,-1), L"Constraints check test case failed.", LINE_INFO());
		}

		TEST_METHOD(longCheck)
		{
			
			Assert::IsTrue(compare(2, 1000000000,11), L"countFactorials test case failed.", LINE_INFO());
			Assert::IsTrue(compare(2, 720,5), L"countFactorials test case failed.", LINE_INFO());
			Assert::IsTrue(compare(1289, 479001600, 6), L"countFactorials test case failed.", LINE_INFO());
		}


	};
}