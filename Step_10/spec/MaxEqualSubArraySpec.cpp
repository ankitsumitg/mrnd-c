#include "stdafx.h"


#include "./../src/MaxEqualSubArray.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class MaxEqualSubArraySpec
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



		[TestMethod,Timeout(3000)]
		void TestEqualSubArrayUsingInts_Test1()
		{

			int arr[12] = { 2, 2, 2, 3, 3, 3, 3, 3, 4, 5, 7, 7 };
			int expectedStart = 3;
			int expectedEnd = 7;
			void** intvalues = (void **)malloc(sizeof(void *) * 12);
			int i = 0;
			for (i = 0; i<12; i++){
				intvalues[i] = (void *)&arr[i];
			}
			int * result = max_equal_subarray(intvalues, 12, &compareInt2);
			Assert::AreEqual(expectedStart, result[0], L"Starting index for max equal sub array wrong", 1, 2);
			Assert::AreEqual(expectedEnd, result[1], L"Ending index for max equal sub array wrong", 1, 2);
		}
		

		[TestMethod, Timeout(3000)]
		void TestEqualSubArrayUsingInts_Test2()
		{

			int arr[12] = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
			int expectedStart = 0;
			int expectedEnd = 11;
			void** intvalues = (void **)malloc(sizeof(void *) * 12);
			int i = 0;
			for (i = 0; i<12; i++){
				intvalues[i] = (void *)&arr[i];
			}
			int * result = max_equal_subarray(intvalues, 12, &compareInt2);
			Assert::AreEqual(expectedStart, result[0], L"Starting index for max equal sub array wrong", 1, 2);
			Assert::AreEqual(expectedEnd, result[1], L"Ending index for max equal sub array wrong", 1, 2);
		}
		
		[TestMethod, Timeout(3000)]
		void TestEqualSubArrayUsingFloats_Test1()
		{

			float arr[12] = { 0.2, 0.2, 2, 4.2, 6.2, 2, 8.2, 9.2, 0.2, 0.2, 0.2, 0.2 };
			int expectedStart = 8;
			int expectedEnd = 11;
			void** intvalues = (void **)malloc(sizeof(void *) * 12);
			int i = 0;
			for (i = 0; i<12; i++){
				intvalues[i] = (void *)&arr[i];
			}
			int * result = max_equal_subarray(intvalues, 12, &compareFloat2);
			Assert::AreEqual(expectedStart, result[0], L"Starting index for max equal sub array wrong", 1, 2);
			Assert::AreEqual(expectedEnd, result[1], L"Ending index for max equal sub array wrong", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void TestEqualSubArrayUsingChars_Test1()
		{

			char arr[12] = "ababababbba";
			int expectedStart = 7;
			int expectedEnd = 9;
			void** intvalues = (void **)malloc(sizeof(void *) * 12);
			int i = 0;
			for (i = 0; i<12; i++){
				intvalues[i] = (void *)&arr[i];
			}
			int * result = max_equal_subarray(intvalues, 12, &compareChar2);
			Assert::AreEqual(expectedStart, result[0], L"Starting index for max equal sub array wrong", 1, 2);
			Assert::AreEqual(expectedEnd, result[1], L"Ending index for max equal sub array wrong", 1, 2);
		}


	};
}
