#include "stdafx.h"
#include "../src/Fibo2048Row.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class Fibo2048RowSpec
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

		void validate_fibo(int *expected, int *actual, int len) {
			for (int i = 0; i < len; i++){
				Assert::AreEqual(expected[i], actual[i], L"Wrong Answer for fiboRow,Keep debug point and check", 1, 2);
			}
		}
		[TestMethod, Timeout(1000)]
		void Fibo2048Row_Sample1()
		{
			int n = 4;
			int row[6] = { 2,3,2,3 };
			int expected[6] = { 0,0,5,5 };
			mergerow(row, n, 'r');
			validate_fibo(expected, row, n);
		};

		[TestMethod, Timeout(1000)]
		void Fibo2048Row_NullCheck() {
			mergerow(NULL, 5, 'r');
		}


		//20 Test cases. 5 Easy. 5Medium (3 bignumbers,2 wrong fibo), 10 Hard (2 Variants)
		[TestMethod, Timeout(1000)]
		void Fibo2048Row_Easy1()
		{
			int n = 4;
			int row[6] = { 0,0,0,0};
			int expected[6] = { 0, 0, 0, 0 };
			mergerow(row, n, 'r');
			validate_fibo(expected, row, n);
		};
		[TestMethod, Timeout(1000)]
		void Fibo2048Row_Easy2()
		{
			int n = 4;
			int row[6] = { 10,10,8,10 };
			int expected[6] = { 10,10,8,10};
			mergerow(row, n, 'r');
			validate_fibo(expected, row, n);
		};

		[TestMethod, Timeout(1000)]
		void Fibo2048Row_Easy3()
		{
			int n = 6;
			int row[6] = { 1,0,1,1,0,1 };
			int expected[6] = { 0,0,0,0,2,2};
			mergerow(row, n, 'r');
			validate_fibo(expected, row, n);
		};

		[TestMethod, Timeout(1000)]
		void Fibo2048Row_TwelveNumbers() {
			int n = 12;
			int row[12] = { 1,1,0,13,0,21,8,3,5,0,0,3 };
			int expected[12] = { 0,0,0,0,0,0,0,2,34,8,3,8};
			mergerow(row, n, 'r');
			validate_fibo(expected, row, n);
			int row2[12] = { 1, 1, 0, 13, 0, 21, 8, 3, 5, 0, 0, 3 };
			int expected2[12] = { 2,34,8,8,3};
			mergerow(row2, n, 'l');
			validate_fibo(expected2, row2, n);
		}

		[TestMethod, Timeout(1000)]
		void Fibo2048Row_TwelveNumbers2() {
			int n = 12;
			int row[12] = { 1, 1, 0, 13, 0, 21, 8, 3, 5, 0, 0, 3 };
			int expected[12] = { 0, 0, 0, 0, 0, 0, 0, 2, 34, 8, 3, 8 };
			mergerow(row, n, 'r');
			validate_fibo(expected, row, n);
			int row2[12] = { 1, 1, 0, 13, 0, 21, 8, 3, 5, 0, 0, 3 };
			int expected2[12] = { 2, 34, 8, 8, 3 };
			mergerow(row2, n, 'l');
			validate_fibo(expected2, row2, n);
		}
		[TestMethod, Timeout(1000)]
		void Fibo2048Row_BigNum1() {
			int n = 8;
			int row[8] = { 233, 0, 377, 3, 610, 987,987,610 };
			int expected[8] = {  0,0,0,0,610,3,1597,1597};
			mergerow(row, n, 'r');
			validate_fibo(expected, row, n);
			int row2[8] = { 233, 0, 377, 3, 610, 987, 987, 610 };
			int expected2[8] = { 610, 3, 1597, 1597,0,0,0,0 };
			mergerow(row2, n, 'l');
			validate_fibo(expected2, row2, n);
		}

		[TestMethod, Timeout(1000)]
		void Fibo2048Row_BigNum2() {
			int n = 10;
			int row[10] = { 233, 0, 377, 3, 610, 987, 987, 610,0,0 };
			int expected[10] = { 0,0,0, 0, 0, 0, 610, 3, 1597, 1597 };
			mergerow(row, n, 'r');
			validate_fibo(expected, row, n);
			int row2[10] = { 233, 0, 377, 3, 610, 987, 987, 610,0,0 };
			int expected2[10] = { 610, 3, 1597, 1597, 0, 0, 0, 0,0,0 };
			mergerow(row2, n, 'l');
			validate_fibo(expected2, row2, n);
		}

		[TestMethod, Timeout(1000)]
		void Fibo2048Row_BigNum3() {
			int n = 10;
			int row[10] = { 233, 0, 377, 3, 610, 987, 987, 610, 0, 0 };
			int expected[10] = { 0, 0, 0, 0, 0, 0, 610, 3, 1597, 1597 };
			mergerow(row, n, 'r');
			validate_fibo(expected, row, n);
			int row2[10] = { 233, 0, 377, 3, 610, 987, 987, 610, 0, 0 };
			int expected2[10] = { 610, 3, 1597, 1597, 0, 0, 0, 0, 0, 0 };
			mergerow(row2, n, 'l');
			validate_fibo(expected2, row2, n);
		}

		void runBigTestCase1() {

			const int n = 2000;
			int row[n];
			int expected[n];
			int row2[n];
			int expected2[n];
			int i = 0;
			while (i < n) {
				expected[i] = 0;
				expected2[i] = 0;
				i++;
			}
			i = 0;
			int numberOfPairs = 0;
			while (i < n) {
				row[i] = 377;
				row[i + 1] = 0;
				row[i + 2] = 0;
				row[i + 3] = 0;
				row[i + 4] = 610;
				row2[i] = 377;
				row2[i + 1] = 0;
				row2[i + 2] = 0;
				row2[i + 3] = 0;
				row2[i + 4] = 610;
				i = i + 5;
				numberOfPairs++;
			}
			i = 0;
			while (i < numberOfPairs) {
				expected[n - i - 1] = 987;
				expected2[i] = 987;
				i++;
			}
			mergerow(row, n, 'r');
			validate_fibo(expected, row, n);
			mergerow(row2, n, 'l');
			validate_fibo(expected2, row2, n);
		}

		void runBigTestCase2() {

			const int n = 2000;
			int row[n];
			int expected[n];
			int row2[n];
			int expected2[n];
			int i = 0;
			while (i < n) {
				expected[i] = 0;
				expected2[i] = 0;
				i++;
			}
			i = 0;
			int numberOfPairs = 0;
			while (i < n) {
				row[i] = 55;
				row[i + 1] = 89;
				row[i + 2] = 610;
				row[i + 3] = 0;
				row[i + 4] = 377;
				row2[i] = 55;
				row2[i + 1] = 89;
				row2[i + 2] = 610;
				row2[i + 3] = 0;
				row2[i + 4] = 377;
				i = i + 5;
				numberOfPairs+=2;
			}
			i = 0;
			while (i < numberOfPairs) {
				expected[n - i - 1] = 987;
				expected[n - i - 2] = 144;
				expected2[i] = 144;
				expected2[i + 1] = 987;
				i++;
				i++;
			}
			mergerow(row, n, 'r');
			validate_fibo(expected, row, n);
			mergerow(row2, n, 'l');
			validate_fibo(expected2, row2, n);
		}
		//Hard 
		[TestMethod, Timeout(1000)]
		void Fibo2048Row_Hard1() {
			int timeCount = 0;
			int numberOfTimes = 100;
			while (timeCount < numberOfTimes) {
				runBigTestCase1();
				timeCount++;
			}
		}
		[TestMethod, Timeout(1000)]
		void Fibo2048Row_Hard2() {
			int timeCount = 0;
			int numberOfTimes = 100;
			while (timeCount < numberOfTimes) {
				runBigTestCase1();
				timeCount++;
			}
		}
		[TestMethod, Timeout(1000)]
		void Fibo2048Row_Hard3() {
			int timeCount = 0;
			int numberOfTimes = 100;
			while (timeCount < numberOfTimes) {
				runBigTestCase1();
				timeCount++;
			}
		}
		[TestMethod, Timeout(1000)]
		void Fibo2048Row_Hard4() {
			int timeCount = 0;
			int numberOfTimes = 100;
			while (timeCount < numberOfTimes) {
				runBigTestCase1();
				timeCount++;
			}
		}
		[TestMethod, Timeout(1000)]
		void Fibo2048Row_Hard5() {
			int timeCount = 0;
			int numberOfTimes = 100;
			while (timeCount < numberOfTimes) {
				runBigTestCase1();
				timeCount++;
			}
		}

		[TestMethod, Timeout(1000)]
		void Fibo2048Row_Hard6() {
			int timeCount = 0;
			int numberOfTimes = 100;
			while (timeCount < numberOfTimes) {
				runBigTestCase2();
				timeCount++;
			}
		}
		[TestMethod, Timeout(1000)]
		void Fibo2048Row_Hard7() {
			int timeCount = 0;
			int numberOfTimes = 100;
			while (timeCount < numberOfTimes) {
				runBigTestCase2();
				timeCount++;
			}
		}

		[TestMethod, Timeout(1000)]
		void Fibo2048Row_Hard8() {
			int timeCount = 0;
			int numberOfTimes = 100;
			while (timeCount < numberOfTimes) {
				runBigTestCase2();
				timeCount++;
			}
		}

		[TestMethod, Timeout(1000)]
		void Fibo2048Row_Hard9() {
			int timeCount = 0;
			int numberOfTimes = 100;
			while (timeCount < numberOfTimes) {
				runBigTestCase2();
				timeCount++;
			}
		}

		[TestMethod, Timeout(1000)]
		void Fibo2048Row_Hard10() {
			int timeCount = 0;
			int numberOfTimes = 100;
			while (timeCount < numberOfTimes) {
				runBigTestCase2();
				timeCount++;
			}
		}
	};
}
