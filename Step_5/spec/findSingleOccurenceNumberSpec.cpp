#include "stdafx.h"
#include "../src/findSingleOccurenceNumber.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class findSingleOccurenceNumberSpec
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

		[TestMethod, Timeout(1000)]
		void FSON_nullCheck()
		{
			Assert::AreEqual(findSingleOccurenceNumber(NULL, 2), -1, L"Null check failed.", 1,2 );
		}

		[TestMethod, Timeout(1000)]
		void FSON_sortedArray()
		{
			int A[7] = { 2, 2, 2, 3, 6, 6, 6 };
			Assert::AreEqual(findSingleOccurenceNumber(A, 7), 3, L"sorted Array case failed.", 1,2 );

			int A1[7] = { 2, 2, 2, 3, 3, 3, 6 };
			Assert::AreEqual(findSingleOccurenceNumber(A1, 7), 6, L"sorted Array case failed.", 1,2 );

			int A2[7] = { 2, 3, 3, 3, 6, 6, 6 };
			Assert::AreEqual(findSingleOccurenceNumber(A2, 7), 2, L"sorted Array case failed.", 1,2 );
		}

		[TestMethod, Timeout(1000)]
		void FSON_unSortedArray()
		{
			int A[10] = { 12, 1, 12, 3, 12, 1, 1, 2, 3, 3 };
			Assert::AreEqual(findSingleOccurenceNumber(A, 10), 2, L"un sorted Array case failed.", 1,2 );

			int A1[10] = { 12, 1, 2, 3, 2, 1, 1, 2, 3, 3 };
			Assert::AreEqual(findSingleOccurenceNumber(A1, 10), 12, L"un sorted Array case failed.", 1,2 );

			int A2[10] = { 12, 1, 12, 3, 12, 2, 2, 2, 3, 3 };
			Assert::AreEqual(findSingleOccurenceNumber(A2, 10), 1, L"un sorted Array case failed.", 1,2 );
		}


	};
}
