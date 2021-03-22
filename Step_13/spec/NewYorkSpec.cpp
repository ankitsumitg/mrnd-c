#include "stdafx.h"
#include <stdlib.h>
#include "../src/NewYork.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class NewYorkSpec
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
		void NewYork_Invalid()
		{
			int res = NewYork(0, 0, 2);
			Assert::AreEqual(0, res, L"Wrong Answer", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void NewYork_Test1()
		{
			int res = NewYork(3, 3, 2);
			Assert::AreEqual(2,res , L"Wrong Answer", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void NewYork_Test2()
		{
			int res = NewYork(3, 4, 1);
			Assert::AreEqual(2, res, L"Wrong Answer", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void NewYork_Test3()
		{
			int res = NewYork(3, 4, 2);
			Assert::AreEqual(3, res, L"Wrong Answer", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void NewYork_Test4()
		{
			int res = NewYork(3, 3, 5);
			Assert::AreEqual(176, res, L"Wrong Answer", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void NewYork_Test5()
		{
			int res = NewYork(5, 5, 7);
			Assert::AreEqual(153670, res, L"Wrong Answer", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void NewYork_Test6()
		{
			int res = NewYork(10, 10, 3);
			Assert::AreEqual(452, res, L"Wrong Answer", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void NewYork_Test7()
		{
			int res = NewYork(15, 15, 2);
			Assert::AreEqual(26, res, L"Wrong Answer", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void NewYork_Test8()
		{
			int res = NewYork(3, 3, 10);
			Assert::AreEqual(55886, res, L"Wrong Answer", 1, 2);
		}


		[TestMethod, Timeout(1000)]
		void NewYork_Test9()
		{
			int res = NewYork(2, 5, 10);
			Assert::AreEqual(223454, res, L"Wrong Answer", 1, 2);
		}


		[TestMethod, Timeout(1000)]
		void NewYork_Test10()
		{
			int res = NewYork(2,2,20);
			Assert::AreEqual(0, res, L"Wrong Answer", 1, 2);
		}

	};
}
