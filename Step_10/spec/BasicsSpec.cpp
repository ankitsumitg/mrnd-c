#include "stdafx.h"


#include "./../src/Basics.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class BasicsSpec
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
		void SubStringTest()
		{
			char * message = "JonSnow";
			int a = 2;
			int b = 5;
			char * actual = subString(message, a, b);
			char expected[5] = "onSn";
			int expectedLen = 5;
			for (int i = 0; i < expectedLen; i++) {
				Assert::AreEqual(expected[i], actual[i], L"Task3 Substring match failed", 1, 2);
			}
		}

		[TestMethod, Timeout(3000)]
		void Task3_invokeSubStrTest()
		{
			char * message = "Daenerys targaryen";
			int a = 3;
			int b = 13;
			char * actual = invokeSubStr(&subString, message, a, b);
			char expected[12] = "enerys targ";
			int expectedLen = 12;
			for (int i = 0; i < expectedLen; i++) {
				Assert::AreEqual(expected[i], actual[i], L"Task3 Substring match failed,Invoke Substring properly", 1, 2);
			}
		}

		[TestMethod, Timeout(3000)]
		void Task4_addSubMulDivTests()
		{
			int a = 10;
			int b = 2;
			float expectedSum = 12;
			float expectedDiff = 8;
			float expectedProduct = 20;
			float expectedQuotient = 5;
			Assert::AreEqual(expectedSum, getSum(a, b), L"getSum Failed", 1, 2);
			Assert::AreEqual(expectedDiff, getDiff(a, b), L"getDiff Failed", 1, 2);
			Assert::AreEqual(expectedProduct, getProduct(a, b), L"getProduct Failed", 1, 2);
			Assert::AreEqual(expectedQuotient, getQuotient(a, b), L"getQuotient Failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void Task4_performOperationTest()
		{
			int a = 10;
			int b = 2;
			float expectedSum = 12;
			float expectedDiff = 8;
			float expectedProduct = 20;
			float expectedQuotient = 5;
			Assert::AreEqual(expectedSum, performOperation(&getSum, a, b), L"perform operation using getSum Failed", 1, 2);
			Assert::AreEqual(expectedDiff, performOperation(&getDiff, a, b), L"perform operation using getDiff Failed", 1, 2);
			Assert::AreEqual(expectedProduct, performOperation(&getProduct, a, b), L"perform operation using getProduct Failed", 1, 2);
			Assert::AreEqual(expectedQuotient, performOperation(&getQuotient, a, b), L"perform operation using getQuotient Failed", 1, 2);
		}


	};
}
