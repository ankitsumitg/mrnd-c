#include "stdafx.h"
#include "../src/mergeSortedArrays.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class mergeSortedArraysSpec
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


		bool compare(struct transaction *actual, struct transaction *expected, int length) {
			for (int i = 0; i < length; ++i) {
				if (actual[i].amount != expected[i].amount) {
					return false;
				}
			}
			return true;
		}

		[TestMethod, Timeout(1000)]
		void MSA_nullCheck()
		{
			struct transaction A[5] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 40, "21-05-2006", "Fourth" }, { 50, "29-11-2007", "Fifth" } };
			if (mergeSortedArrays(NULL, 2, NULL, 3) != NULL){
				Assert::Fail("MSA null check failed.");
			}
			if (mergeSortedArrays(A, 5, NULL, 3) != NULL){
				Assert::Fail("MSA null check failed.");
			}
			if (mergeSortedArrays(NULL, 2, A, 5) != NULL){
				Assert::Fail("MSA null check failed.");
			}
		}

		[TestMethod, Timeout(1000)]
		void MSA_sameArrays()
		{
			struct transaction A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
			struct transaction B[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
			//int A[3] = { 1, 2, 3 }, B[3] = { 1, 2, 3 };
			struct transaction *result = mergeSortedArrays(A, 3, B, 3);
			struct transaction expected[6] = { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 30, "03-03-2005", "Third" } };
			Assert::IsTrue(compare(result, expected, 6), L"Same arrays case failed.", 1,2 );

			//int A1[3] = { 1, 1, 1 }, B1[3] = { 1, 1, 1 };
			struct transaction A1[3] = { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" } };
			struct transaction B1[3] = { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" } };
			struct transaction *result1 = mergeSortedArrays(A1, 3, B1, 3);
			struct transaction expected1[6] = { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" } };
			Assert::IsTrue(compare(result1, expected1, 6), L"Same arrays case failed.", 1,2 );
		}

		[TestMethod, Timeout(1000)]
		void MSA_differentArrays()
		{
			struct transaction A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
			struct transaction B[3] = { { 40, "21-10-2006", "Fourth" }, { 50, "13-11-2007", "Fifth" }, { 60, "13-08-2008", "Sixth" } };
			//int A[3] = { 1, 2, 3 }, B[3] = { 4, 5, 6 };
			struct transaction *result = mergeSortedArrays(A, 3, B, 3);
			struct transaction expected[6] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 40, "21-10-2006", "Fourth" }, { 50, "13-11-2007", "Fifth" }, { 60, "13-08-2008", "Sixth" } };
			Assert::IsTrue(compare(result, expected, 6), L"Different arrays case failed.", 1,2 );

			struct transaction A1[3] = { { 40, "21-10-2006", "Fourth" }, { 50, "13-11-2007", "Fifth" }, { 60, "13-08-2008", "Sixth" } };
			struct transaction B1[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
			//struct transaction A1[3] = { 4, 5, 6 }, B1[3] = { 1, 2, 3 };
			struct transaction *result1 = mergeSortedArrays(A1, 3, B1, 3);
			Assert::IsTrue(compare(result1, expected, 6), L"Different arrays case failed.", 1,2 );
		}

		[TestMethod, Timeout(1000)]
		void MSA_commonElements()
		{
			struct transaction A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
			struct transaction B[3] = { { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 60, "22-04-2006", "Sixth" } };
			//int A[3] = { 1, 2, 3 }, B[3] = { 2, 3, 6 };
			struct transaction *result = mergeSortedArrays(A, 3, B, 3);
			struct transaction expected[6] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 30, "03-03-2005", "Third" }, { 60, "22-04-2006", "Sixth" } };
			Assert::IsTrue(compare(result, expected, 6), L"Different arrays case failed.", 1,2 );

			struct transaction A1[3] = { { 40, "09-10-2003", "Fourth" }, { 60, "19-10-2004", "Sixth" }, { 80, "03-03-2005", "Eigth" } };
			struct transaction B1[3] = { { 40, "09-10-2003", "Fourth" }, { 50, "19-10-2003", "Fifth" }, { 60, "19-10-2004", "Sixth" } };
			//int A1[3] = { 4, 6, 8 }, B1[3] = { 4, 5, 6 };
			struct transaction *result1 = mergeSortedArrays(A1, 3, B1, 3);
			struct transaction expected1[6] = { { 40, "09-10-2003", "Fourth" }, { 40, "09-10-2003", "Fourth" }, { 50, "19-10-2003", "Fifth" }, { 60, "19-10-2004", "Sixth" }, { 60, "19-10-2004", "Sixth" }, { 80, "03-03-2005", "Eigth" } };
			Assert::IsTrue(compare(result1, expected1, 6), L"Different arrays case failed.", 1,2 );
		}


	};
}
