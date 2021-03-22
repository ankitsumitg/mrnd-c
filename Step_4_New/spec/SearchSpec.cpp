#include "stdafx.h"
#include "../src/Search.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class SearchSpec
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
		void initArray(int *arr,int len) {
			int i = 0;
			for (i = 0; i < len; i++){
				arr[i] = i;
			}
		}
		[TestMethod ,Timeout(1000)]
		void Search_Test1()
		{
			int expectedIndex = 987;
			int key = expectedIndex;
			int arr[1000] = { 0 };
			int len = 1000;
			initArray(arr, len);
			int actualIndex = linearSearch(arr, len, key);
			Assert::AreEqual(expectedIndex, actualIndex, L"Linear Search Fail", 1, 2);

			int actualIndex2 = binarySearch(arr, len, key);
			Assert::AreEqual(expectedIndex, actualIndex2, L"Binary Search Fail", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Search_Test2()
		{
			int expectedIndex = 9879;
			int key = expectedIndex;
			int arr[10000] = { 0 };
			int len = 10000;
			initArray(arr, len);
			arr[expectedIndex] = key;
			int actualIndex = linearSearch(arr, len, key);
			Assert::AreEqual(expectedIndex, actualIndex, L"Linear Search Fail", 1, 2);

			int actualIndex2 = binarySearch(arr, len, key);
			Assert::AreEqual(expectedIndex, actualIndex2, L"Binary Search Fail", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Search_Test3()
		{
			int expectedIndex = 98799;
			int key = expectedIndex;
			int arr[100000] = { 0 };
			int len = 100000;
			initArray(arr, len);
			arr[expectedIndex] = key;
			int numberOfTimes = 100000;
			for (int i = 0; i < numberOfTimes; i++){

				int actualIndex2 = binarySearch(arr, len, key);
				Assert::AreEqual(expectedIndex, actualIndex2, L"Binary Search Fail", 1, 2);
			}
		};

		
	};
}
