#include "stdafx.h"
#include "../src/TimeComplexity.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class TimeComplexitySpec
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
		//
		//You can use the following additional attributes as you write your tests:
		//
		//Use ClassInitialize to run code before running the first test in the class
		//[ClassInitialize()]
		//static void MyClassInitialize(TestContext^ testContext) {};
		//
		//Use ClassCleanup to run code after all tests in a class have run
		//[ClassCleanup()]
		//static void MyClassCleanup() {};
		//
		//Use TestInitialize to run code before running each test
		//[TestInitialize()]
		//void MyTestInitialize() {};
		//
		//Use TestCleanup to run code after each test has run
		//[TestCleanup()]
		//void MyTestCleanup() {};
		//
#pragma endregion 
		void compareStrings(char *expected, char *actual) {
			if (actual == NULL)
				Assert::AreEqual(0, 2, L"Actual is null  ", 1, 2);
			int i = 0;
			for (i; expected[i] != '\0'; i++) {
				if (actual[i] == '\0') {
					Assert::AreEqual(0, 1, L"Actual length mismatch for time complexity  ", 1, 2);
				}
				if (expected[i] != actual[i]) {
					Assert::AreEqual(0, 1, L"Actual letter mismatch for time complexity  ", 1, 2);
				}
			}
			if (expected[i] != '\0' || actual[i] != '\0')
				Assert::AreEqual(0, 1, L"Actual letter mismatch for time complexity  ", 1, 2);
		}


		void testfunction1() {
			char *expectedAns = "O(logn)";
			char *actualAns = function1(100);
			compareStrings(expectedAns, actualAns);
		}

		void testfunction2() {
			char *expectedAns = "O(n)";
			char *actualAns = function2(10);
			compareStrings(expectedAns, actualAns);
		}

		void testfunction3() {
			char *expectedAns = "O(n*logn)";
			char *actualAns = function3(10);
			compareStrings(expectedAns, actualAns);
		}

		void testfunction4() {
			char *expectedAns = "O(n)";
			char *actualAns = function4(10);
			compareStrings(expectedAns, actualAns);
		}

		void testfunction5() {
			int arr[5] = { 3, 2, 8, 2, 4 };
			char *expectedAns = "O(n*n)";
			char *actualAns = function5(arr, 5);
			compareStrings(expectedAns, actualAns);
		}

		void testfunction6() {
			char *expectedAns = "O(n)";
			char *actualAns = function6(8);
			compareStrings(expectedAns, actualAns);
		}

		void testfunction7() {
			char *expectedAns = "O(n)";
			char *actualAns = function7(125);
			compareStrings(expectedAns, actualAns);
		}

		void testfunction8() {
			char *expectedAns = "O(n*logn)";
			char *actualAns = function8(10);
			compareStrings(expectedAns, actualAns);
		}

		void testfunction9() {
			char *expectedAns = "O(n*n*logn)";
			char *actualAns = function9(10);
			compareStrings(expectedAns, actualAns);
		}

		void testfunction10() {
			char *expectedAns = "O(n^n)";
			char *actualAns = function10(7);
			compareStrings(expectedAns, actualAns);
		}

		void testfunction11() {
			int arr[7] = { 1, 1, 2, 8, 5, 2, 1 };
			char *expectedAns = "O(n*n)";
			char *actualAns = function11(arr, 7);
			compareStrings(expectedAns, actualAns);
		}

		void testfunction12() {
			int arr[5] = { 1, 2, 8, 4, 9 };
			char *expectedAns = "O(n*n)";
			char *actualAns = function12(arr, 5);
			compareStrings(expectedAns, actualAns);
		}

		void testfunction13() {
			float arr[5] = { 1.4, 2.2, 2.7, 2.3, 3.5 };
			char *expectedAns = "O(n)";
			char *actualAns = function13(arr, 5);
			compareStrings(expectedAns, actualAns);
		}

		void testfunction14() {
			int arr[5] = { 3, -1, 2, 4, 5 };
			char *expectedAns = "O(n)";
			char *actualAns = function14(arr, 5);
			compareStrings(expectedAns, actualAns);
		}

		[TestMethod, Timeout(1000)]
		void TC_F1()
		{
			testfunction1();
		};
		[TestMethod, Timeout(1000)]
		void TC_F2()
		{
			testfunction2();
		};		
		[TestMethod, Timeout(1000)]
		void TC_F3()
		{
			testfunction3();
		};
		[TestMethod, Timeout(1000)]
		void TC_F4()
		{
			testfunction4();
		};

		[TestMethod, Timeout(1000)]
		void TC_F5F6()
		{
			testfunction5();
			testfunction6();
		};
		[TestMethod, Timeout(1000)]
		void TC_F7F8()
		{
			testfunction7();
			testfunction8();
		};
		[TestMethod, Timeout(1000)]
		void TC_F9F10()
		{
			testfunction9();
			testfunction10();
		};
		[TestMethod, Timeout(1000)]
		void TC_F11F12()
		{
			testfunction11();
			testfunction12();
		};
		[TestMethod, Timeout(1000)]
		void TC_F13F14()
		{
			testfunction13();
			testfunction14();
		};


	};
}
