#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/NumbertoStr.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(NumbertoStrSpec)
	{
	public:

		TEST_METHOD(BasicInt)
		{
			float number = 345;
			char str[20];
			number_to_str(number, str, 0);
			Assert::AreEqual('3', str[0], L"Char at index 0 should be 3", LINE_INFO());
			Assert::AreEqual('4', str[1], L"Char at index 1 should be 4", LINE_INFO());
			Assert::AreEqual('5', str[2], L"Char at index 2 should be 5", LINE_INFO());

			
		}
		TEST_METHOD(BasicDecimalFloat)
		{
			float number = 345.344;
			char str[20];
			number_to_str(number, str, 2);
			Assert::AreEqual('3', str[0], L"Char at index 0 should be 3", LINE_INFO());
			Assert::AreEqual('4', str[1], L"Char at index 1 should be 4", LINE_INFO());
			Assert::AreEqual('5', str[2], L"Char at index 2 should be 5", LINE_INFO());
			Assert::AreEqual('.', str[3], L"Char at index 3 should be .", LINE_INFO());
			Assert::AreEqual('3', str[4], L"Char at index 4 should be 3", LINE_INFO());
			Assert::AreEqual('4', str[5], L"Char at index 5 should be 4", LINE_INFO());

		}
		TEST_METHOD(NegBasicInt)
		{
			float number = -34;
			char str[20];
			number_to_str(number, str, 0);
			//printf("asd");
			Assert::AreEqual('-', str[0], L"Char at index 0 should be -", LINE_INFO());
			Assert::AreEqual('3', str[1], L"Char at index 1 should be 3", LINE_INFO());
			Assert::AreEqual('4', str[2], L"Char at index 2 should be 4", LINE_INFO());
		}
		TEST_METHOD(NegDecimalInt)
		{
			float number = -34.435;
			char str[20];
			number_to_str(number, str, 2);
			//printf("asd");
			Assert::AreEqual('-', str[0], L"Char at index 0 should be -", LINE_INFO());
			Assert::AreEqual('3', str[1], L"Char at index 1 should be 3", LINE_INFO());
			Assert::AreEqual('4', str[2], L"Char at index 2 should be 4", LINE_INFO());
			Assert::AreEqual('.', str[3], L"Char at index 3 should be .", LINE_INFO());
			Assert::AreEqual('4', str[4], L"Char at index 4 should be 4", LINE_INFO());
			Assert::AreEqual('3', str[5], L"Char at index 5 should be 3", LINE_INFO());
		}

		

	};
}