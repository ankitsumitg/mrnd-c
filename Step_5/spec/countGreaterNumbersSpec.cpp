#include "stdafx.h"
#include "../src/countGreaterNumbers.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class countGreaterNumbersSpec
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
		void CGN_dateNotPresent()
		{
			struct transaction Arr[5] = { { 60, "09-10-2003", "First" }, { 70, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 90, "21-05-2006", "Fourth" }, { 10, "29-11-2007", "Fifth" } };
			int count = countGreaterNumbers(Arr, 5, "11-11-2015");
			Assert::AreEqual(0, count, L"count should be 0", 1,2);
		}

		[TestMethod, Timeout(1000)]
		void CGN_lastDate()
		{
			struct transaction Arr[5] = { { 60, "09-10-2003", "First" }, { 70, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 90, "21-05-2006", "Fourth" }, { 10, "29-11-2007", "Fifth" } };
			int count = countGreaterNumbers(Arr, 5, "29-11-2007");
			Assert::AreEqual(0, count, L"count should be 0", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void CGN_sameDatesArray()
		{
			struct transaction Arr[5] = { { 60, "09-10-2003", "First" }, { 70, "09-10-2003", "Second" }, { 30, "09-10-2003", "Third" }, { 90, "09-10-2003", "Fourth" }, { 10, "09-10-2003", "Fifth" } };
			int count = countGreaterNumbers(Arr, 5, "09-10-2003");
			Assert::AreEqual(0, count, L"count should be 0", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void CGN_firstDate()
		{
			struct transaction Arr[5] = { { 60, "09-10-2003", "First" }, { 70, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 90, "21-05-2006", "Fourth" }, { 10, "29-11-2007", "Fifth" } };
			int count = countGreaterNumbers(Arr, 5, "09-10-2003");
			Assert::AreEqual(4, count, L"count should be 4", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void CGN_middleDate()
		{
			struct transaction Arr[5] = { { 60, "09-10-2003", "First" }, { 70, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 90, "21-05-2006", "Fourth" }, { 10, "29-11-2007", "Fifth" } };
			int count = countGreaterNumbers(Arr, 5, "03-03-2005");
			Assert::AreEqual(2, count, L"count should be 2", 1, 2);
		}


	};
}
