#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/sum.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(sumSpec)
	{
	public:

		TEST_METHOD(SumBasicTest)
		{
			Assert::AreEqual(5, sum(2, 3), L"Basic input failed", LINE_INFO());
		}
		
	};
}