#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "../src/NearestSortedNumber.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class NearestSortedNumberSpec
	{
	private:
		TestContext^ testContextInstance;

	public:
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

#pragma region Additional test attributes

#pragma endregion 
		int checker(char *expected,char *actual){
			if (expected == NULL || actual == NULL) 
				return (actual == expected);
			int len1 = 0, len2 = 0;
			for (len1 = 0; expected[len1]; len1++);
			for (len2 = 0; actual[len2]; len2++);
			if (len1 != len2) return 0;
			for (int i = 0; i < len1; i++){
				if (expected[i] != actual[i]) return 0;
			}
			return 1;
		}

		[TestMethod, Timeout(1000)]
		void NearestSortedNumber_Samples()
		{
			char *res;
			res = NearestSortedNumber("25", 2);
			Assert::AreEqual(checker("25", res), 1, L"Wrong Answer", 1, 2);

			res = NearestSortedNumber("10", 2);
			Assert::AreEqual(checker("9", res), 1, L"Wrong Answer", 1, 2);

			res = NearestSortedNumber("19", 2);
			Assert::AreEqual(checker("19", res), 1, L"Wrong Answer", 1, 2);

			res = NearestSortedNumber("20", 2);
			Assert::AreEqual(checker("19", res), 1, L"Wrong Answer", 1, 2);

			res = NearestSortedNumber("2wer5", 2);
			if (res != NULL) Assert::AreEqual(1,2, L"Expected NULL", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void NearestSortedNumber_Test01()
		{
			char *res;
			res = NearestSortedNumber("25", 2);
			Assert::AreEqual(checker("25", res), 1, L"Wrong Answer", 1, 2);

			res = NearestSortedNumber("10", 2);
			Assert::AreEqual(checker("9", res), 1, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void NearestSortedNumber_Test02()
		{
			char *res;
			res = NearestSortedNumber("2wer5", 2);
			if (res != NULL) Assert::AreEqual(1, 2, L"Expected NULL", 1, 2);
		};


		[TestMethod, Timeout(1000)]
		void NearestSortedNumber_Test03()
		{
			char *res;
			res = NearestSortedNumber("25", 2);
			Assert::AreEqual(checker("25", res), 1, L"Wrong Answer", 1, 2);

			res = NearestSortedNumber("10", 2);
			Assert::AreEqual(checker("9", res), 1, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void NearestSortedNumber_Test04()
		{
			char *res;
			res = NearestSortedNumber("9999991", 7);
			Assert::AreEqual(checker("8999999", res), 1, L"Wrong Answer", 1, 2);

			res = NearestSortedNumber("1110", 4);
			Assert::AreEqual(checker("999", res), 1, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void NearestSortedNumber_Test05()
		{
			char *res;
			res = NearestSortedNumber("123123", 6);
			Assert::AreEqual(checker("122999", res), 1, L"Wrong Answer", 1, 2);

			res = NearestSortedNumber("123123123", 9);
			Assert::AreEqual(checker("122999999", res), 1, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void NearestSortedNumber_Test06()
		{
			char *res;
			res = NearestSortedNumber("112233445576", 12);
			Assert::AreEqual(checker("112233445569", res), 1, L"Wrong Answer", 1, 2);

			res = NearestSortedNumber("987654321", 9);
			Assert::AreEqual(checker("899999999", res), 1, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void NearestSortedNumber_Test07()
		{
			char *res;
			res = NearestSortedNumber("999999999999999999998", 21);
			Assert::AreEqual(checker("899999999999999999999", res), 1, L"Wrong Answer", 1, 2);

			res = NearestSortedNumber("99999999999999992",17);
			Assert::AreEqual(checker("89999999999999999", res), 1, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void NearestSortedNumber_Test08()
		{
			char *res;
			for (int i = 0; i < 10000; i++){
				res = NearestSortedNumber("10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001", 101);
				Assert::AreEqual(checker("9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999", res), 1, L"Wrong Answer", 1, 2);

				res = NearestSortedNumber("99999999999999992", 17);
				Assert::AreEqual(checker("89999999999999999", res), 1, L"Wrong Answer", 1, 2);
			}
		};
		[TestMethod, Timeout(1000)]
		void NearestSortedNumber_Test09()
		{
			char *res;
			for (int i = 0; i < 10000; i++){
				res = NearestSortedNumber("88888", 5);
				Assert::AreEqual(checker("88888", res), 1, L"Wrong Answer", 1, 2);

				res = NearestSortedNumber("1000001", 7);
				Assert::AreEqual(checker("999999", res), 1, L"Wrong Answer", 1, 2);
			}
		};

		[TestMethod, Timeout(1000)]
		void NearestSortedNumber_Test10()
		{
			char *res;
			for (int i = 0; i < 10000; i++){
				res = NearestSortedNumber("1", 1);
				Assert::AreEqual(checker("1", res), 1, L"Wrong Answer", 1, 2);

				res = NearestSortedNumber("0", 1);
				if (res != NULL) Assert::AreEqual(1, 2, L"Expected NULL", 1, 2);
			}
		};

		[TestMethod, Timeout(1000)]
		void NearestSortedNumber_Test11()
		{
			char *res;
			for (int i = 0; i < 10000; i++){
				res = NearestSortedNumber(NULL, 1);
				if (res != NULL) Assert::AreEqual(1, 2, L"Expected NULL", 1, 2);;

				res = NearestSortedNumber("0", -1);
				if (res != NULL) Assert::AreEqual(1, 2, L"Expected NULL", 1, 2);
			}
		};

		[TestMethod, Timeout(1000)]
		void NearestSortedNumber_Test12()
		{
			char *res;
			for (int i = 0; i < 10000; i++){
				res = NearestSortedNumber("50", 2);
				Assert::AreEqual(checker("49",res), 1, L"Wrong Answre", 1, 2);;

				res = NearestSortedNumber("0", 0);
				if (res != NULL) Assert::AreEqual(1, 2, L"Expected NULL", 1, 2);
			}
		};

		[TestMethod, Timeout(1000)]
		void NearestSortedNumber_Test13()
		{
			char *res;
			for (int i = 0; i < 100000; i++){
				res = NearestSortedNumber("10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001", 101);
				Assert::AreEqual(checker("9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999", res), 1, L"Wrong Answer", 1, 2);

				res = NearestSortedNumber("99999999999999992", 17);
				Assert::AreEqual(checker("89999999999999999", res), 1, L"Wrong Answer", 1, 2);
			}
		};

		[TestMethod, Timeout(1000)]
		void NearestSortedNumber_Test14()
		{
			char *res;
			for (int i = 0; i < 100000; i++){
				res = NearestSortedNumber("10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001", 101);
				Assert::AreEqual(checker("9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999", res), 1, L"Wrong Answer", 1, 2);

				res = NearestSortedNumber("99999999999999992", 17);
				Assert::AreEqual(checker("89999999999999999", res), 1, L"Wrong Answer", 1, 2);
			}
		};
	};

}