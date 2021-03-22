#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/variableArguments.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(variableArgumentsSpec)
	{
	public:

		TEST_METHOD(variableArgumentsTest)
		{
			Assert::AreEqual(0, variableArguments(1, 10), L"Variable arguments test failed.", LINE_INFO());
			Assert::AreEqual(1, variableArguments(1, 91), L"Variable arguments test failed.", LINE_INFO());
			Assert::AreEqual(0, variableArguments(2, 1, 20), L"Variable arguments test failed.", LINE_INFO());
			Assert::AreEqual(2, variableArguments(2, 92, 93), L"Variable arguments test failed.", LINE_INFO());
		}

	};
}