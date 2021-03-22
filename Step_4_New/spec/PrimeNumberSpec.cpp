#include "stdafx.h"
#include "../src/PrimeNumber.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class PrimeNumberSpec
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
		void PrimeNumberBF_Test1()
		{
			int expectedAnswer = 1;
			int number = 997;
			int numberOfTimes = 10;
			for (int i = 0; i < numberOfTimes; i++){

				int actualAnswer = isPrimeBruteForce(number);
				Assert::AreEqual(expectedAnswer, actualAnswer, L"Prime Number Fail", 1, 2);
			}
		};

		[TestMethod, Timeout(1000)]
		void PrimeNumberBF_Test2()
		{
			int expectedAnswer = 1;
			int number = 104395303;
			int numberOfTimes = 1000;
			for (int i = 0; i < numberOfTimes; i++){

				int actualAnswer = isPrimeSquareRoot(number);
				Assert::AreEqual(expectedAnswer, actualAnswer, L"Prime Number SQRT Fail", 1, 2);
				int actualAnswer2 = isPrimeOptimized(104395307);
				Assert::AreEqual(0, actualAnswer2, L"Prime Number OPTIMIZED Fail", 1, 2);
			}
		};

		[TestMethod, Timeout(1000)]
		void PrimeNumberBF_Test3()
		{
			int expectedAnswer = 1;
			int number = 104395303;
			int numberOfTimes = 3000;
			for (int i = 0; i < numberOfTimes; i++){

				int actualAnswer = isPrimeOptimized(number);
				Assert::AreEqual(expectedAnswer, actualAnswer, L"Prime Number OPTIMIZED Fail", 1, 2);
				int actualAnswer2 = isPrimeOptimized(104395307);
				Assert::AreEqual(0, actualAnswer2, L"Prime Number OPTIMIZED Fail", 1, 2);
			}
		};
	};
}
