#include "stdafx.h"
#include "../src/sortedArraysCommonElements.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class sortedArraysCommonElementsSpec
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
		void SACE_NullCheck()
		{
			struct transaction A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
			if (sortedArraysCommonElements(NULL, 2, NULL, 3) != NULL){
				Assert::Fail("SACE null check failed.");
			}
			if (sortedArraysCommonElements(A, 2, NULL, 3) != NULL){
				Assert::Fail("SACE null check failed.");
			}
			if (sortedArraysCommonElements(NULL, 2, A, 3) != NULL){
				Assert::Fail("SACE null check failed.");
			}
		}

		[TestMethod, Timeout(1000)]
		void SACE_noCommonElements()
		{
			struct transaction A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
			struct transaction B[3] = { { 40, "21-10-2006", "Fourth" }, { 50, "13-11-2007", "Fifth" }, { 60, "13-08-2008", "Sixth" } };
			if (sortedArraysCommonElements(A, 3, B, 3) != NULL){
				Assert::Fail("SACE No common elements Check failed.");
			}
		}

		[TestMethod, Timeout(1000)]
		void SACE_sameArray()
		{
			struct transaction A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
			struct transaction B[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
			//int A[3] = { 1, 2, 3 }, expected[3] = { 1, 2, 3 };
			struct transaction expected[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
			struct transaction *result = sortedArraysCommonElements(A, 3, A, 3);
			Assert::IsTrue(compare(result, expected, 3), L"All common elements Check failed.", 1,2 );
		}

		[TestMethod, Timeout(1000)]
		void SACE_radomCommonElements()
		{
			struct transaction A[5] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 40, "21-10-2006", "Fourth" }, { 50, "13-11-2007", "Fifth" } };
			struct transaction B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "22nd" }, { 320, "27-08-2015", "32nd" } };
			//int A[5] = { 1, 2, 3, 4, 5 }, B[3] = { 1, 22, 32 }, expected[1] = { 1 };
			struct transaction expected[3] = { { 10, "09-10-2003", "First" } };
			struct transaction *result = sortedArraysCommonElements(A, 5, B, 3);
			Assert::IsTrue(compare(result, expected, 1), L"One common element Check failed.", 1,2 );
		}


	};
}
