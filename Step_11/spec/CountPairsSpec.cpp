#include "stdafx.h"


#include "./../src/CountPairs.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class CountPairsSpec
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


		[TestMethod, Timeout(3000)]
		void ZeroString()
		{
			int pairs=count_pairs_wrapper("", 0);
			Assert::AreEqual(0, pairs, L"0 Str pairs should be 0", 1, 2);
		}
		[TestMethod, Timeout(3000)]
		void SmallString1()
		{
			int pairs = count_pairs_wrapper("abc", 3);
			Assert::AreEqual(0, pairs, L"abc Str pairs should be 0", 1, 2);
		}
		[TestMethod, Timeout(3000)]
		void SmallString2()
		{
			int pairs = count_pairs_wrapper("aba", 3);
			Assert::AreEqual(1, pairs, L"aba Str pairs should be 1", 1, 2);
		}
		[TestMethod, Timeout(3000)]
		void SmallString3()
		{
			int pairs = count_pairs_wrapper("ababa",5);
			Assert::AreEqual(3, pairs, L"0 Str pairs should be 3", 1, 2);
		}
		[TestMethod, Timeout(3000)]
		void LargeString()
		{
			int pairs = count_pairs_wrapper("abababababxxxyyy", 16);
			Assert::AreEqual(10, pairs, L"abababababxxxyyy Str pairs should be 10", 1, 2);
		}

	};
}
