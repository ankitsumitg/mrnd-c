#include "stdafx.h"
#include "../src/TwoSum.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class TwoSumSpec
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
		[TestMethod, Timeout(1000)]
		void TwoSum_NullCheck()
		{
			int * ans = sumoftwoBF(NULL, 0, 2);
			if (ans == NULL){

			}
			else{
				Assert::Fail("Failed if nums is Null");
			}
		};

		[TestMethod, Timeout(1000)]
		void TwoSumSort_LenAndKeyCheck()
		{
			int a[5] = { 1, 2, 3, 4, 5 };
			int* ans = sumoftwoBF(a, 0, -1);
			if (ans == NULL){

			}
			else{
				Assert::Fail("Failed if nums len is <1");
			}
		};

		[TestMethod, Timeout(1000)]
		void TwoSumBF_Test3()
		{
			int a[5] = { 15, 20, 13, 44, 5 };
			int len = 5;
			int i1 = 5;
			int i2 = 20;
			int target = 25;
			int* ans = sumoftwoBF(a, target, len);
			if (ans == NULL){
				Assert::Fail("Got Null ,Where as Answer Array Expected");
			}
			else{
				Assert::AreEqual(i1, ans[0], L"Failed TwoSumBF_Test3", 1, 2);
				Assert::AreEqual(i2, ans[1], L"Failed TwoSumBF_Test3", 1, 2);
			}
		};

		[TestMethod, Timeout(1000)]
		void TwoSumSort_Test4()
		{
			int a[1000] = { 0 };
			a[989] = 20;
			a[993] = 5;
			a[343] = 435;
			int len = 1000;
			int i1 = 5;
			int i2 = 20;
			int target = 25;
			int numberOfTimes = 1000;
			for (int i = 0; i < numberOfTimes; i++){
				int* ans = sumoftwoSortAndSearch(a, target, len);
				if (ans == NULL){
					Assert::Fail("Got Null ,Where as Answer Array Expected");
				}
				else{
					Assert::AreEqual(i1, ans[0], L"Failed TwoSumSort_Test4", 1, 2);
					Assert::AreEqual(i2, ans[1], L"Failed TwoSumSort_Test4", 1, 2);
				}
			}
		};
		[TestMethod, Timeout(1000)]
		void TwoSumOptimized_Test5()
		{
			int a[1000] = { 77 };
			a[989] = 20;
			a[993] = 5;
			a[343] = 98;
			int len = 1000;
			int i1 = 5;
			int i2 = 20;
			int target = 25;
			int numberOfTimes = 1000;
			for (int i = 0; i < numberOfTimes; i++){
				int* ans = sumoftwoExtraArray(a, target, len);
				if (ans == NULL){
					Assert::Fail("Got Null ,Where as Answer Array Expected");
				}
				else{
					Assert::AreEqual(i1, ans[0], L"Failed TwoSumSort_Test4", 1, 2);
					Assert::AreEqual(i2, ans[1], L"Failed TwoSumSort_Test4", 1, 2);
				}
			}
		};


		
	};
}
