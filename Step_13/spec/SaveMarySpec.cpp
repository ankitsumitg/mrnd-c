#include "stdafx.h"
#include "./../src/SaveMary.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class SaveMarySpec
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
		void TC0()
		{
			int n = -9, k = 0;
			int result = saveMary(n, k);
			Assert::AreEqual(-1, result, L"People cant be negative", 1, 2);
		}

		[TestMethod, Timeout(1500)]
		void TC1()
		{
			int n = 983, k = 753;
			int result = saveMary(n, k);
			Assert::AreEqual(87, result, L"Expected != Actual", 1, 2);
		}

		[TestMethod, Timeout(1500)]
		void TC2()
		{
			int n = 216, k = 198;
			int result = saveMary(n, k);
			Assert::AreEqual(75, result, L"Expected != Actual", 1, 2);
		}

		[TestMethod, Timeout(1500)]
		void TC3()
		{
			int n = 267, k = 5;
			int result = saveMary(n, k);
			Assert::AreEqual(226, result, L"Expected != Actual", 1, 2);
		}

		[TestMethod, Timeout(1500)]
		void TC4()
		{
			int n = 554, k = 302;
			int result = saveMary(n, k);
			Assert::AreEqual(489, result, L"Expected != Actual", 1, 2);
		}

		[TestMethod, Timeout(1500)]
		void TC5()
		{
			int n = 564, k = 57;
			int result = saveMary(n, k);
			Assert::AreEqual(277, result, L"Expected != Actual", 1, 2);
		}

		[TestMethod, Timeout(1500)]
		void TC6()
		{
			int n = 260, k = 7;
			int result = saveMary(n, k);
			Assert::AreEqual(176, result, L"Expected != Actual", 1, 2);
		}

		[TestMethod, Timeout(1500)]
		void TC7()
		{
			int n = 448, k = 437;
			int result = saveMary(n, k);
			Assert::AreEqual(88, result, L"Expected != Actual", 1, 2);
		}

		[TestMethod, Timeout(1500)]
		void TC8()
		{
			int n = 662, k = 341;
			int result = saveMary(n, k);
			Assert::AreEqual(400, result, L"Expected != Actual", 1, 2);
		}

		[TestMethod, Timeout(1500)]
		void TC9()
		{
			int n = 408, k = 351;
			int result = saveMary(n, k);
			Assert::AreEqual(211, result, L"Expected != Actual", 1, 2);
		}

		[TestMethod, Timeout(1500)]
		void TC10()
		{
			int n = 308, k = 156;
			int result = saveMary(n, k);
			Assert::AreEqual(75, result, L"Expected != Actual", 1, 2);
		}

		[TestMethod, Timeout(1500)]
		void TC11()
		{
			int n = 104, k = 3;
			int result = saveMary(n, k);
			Assert::AreEqual(103, result, L"Expected != Actual", 1, 2);
		}

		[TestMethod, Timeout(1500)]
		void TC12()
		{
			int n = 83, k = 27;
			int result = saveMary(n, k);
			Assert::AreEqual(31, result, L"Expected != Actual", 1, 2);
		}

		[TestMethod, Timeout(1500)]
		void TC13()
		{
			int n = 514, k = 193;
			int result = saveMary(n, k);
			Assert::AreEqual(293, result, L"Expected != Actual", 1, 2);
		}

		[TestMethod, Timeout(1500)]
		void TC14()
		{
			int n = 334, k = 250;
			int result = saveMary(n, k);
			Assert::AreEqual(73, result, L"Expected != Actual", 1, 2);
		}

		[TestMethod, Timeout(1500)]
		void TC15()
		{
			int n = 860, k = 321;
			int result = saveMary(n, k);
			Assert::AreEqual(599, result, L"Expected != Actual", 1, 2);
		}

		[TestMethod, Timeout(1500)]
		void TC16()
		{
			int n = 653, k = 499;
			int result = saveMary(n, k);
			Assert::AreEqual(139, result, L"Expected != Actual", 1, 2);
		}

		[TestMethod, Timeout(1500)]
		void TC17()
		{
			int n = 954, k = 755;
			int result = saveMary(n, k);
			Assert::AreEqual(335, result, L"Expected != Actual", 1, 2);
		}

		[TestMethod, Timeout(1500)]
		void TC18()
		{
			int n = 899, k = 196;
			int result = saveMary(n, k);
			Assert::AreEqual(643, result, L"Expected != Actual", 1, 2);
		}

		[TestMethod, Timeout(1500)]
		void TC19()
		{
			int n = 921, k = 376;
			int result = saveMary(n, k);
			Assert::AreEqual(133, result, L"Expected != Actual", 1, 2);
		}

		[TestMethod, Timeout(1500)]
		void TC20()
		{
			int n = 278, k = 10;
			int result = saveMary(n, k);
			Assert::AreEqual(258, result, L"Expected != Actual", 1, 2);
		}

		[TestMethod, Timeout(1500)]
		void TC21()
		{
			int n = 752, k = 585;
			int result = saveMary(n, k);
			Assert::AreEqual(357, result, L"Expected != Actual", 1, 2);
		}

		[TestMethod, Timeout(1500)]
		void TC22()
		{
			int n = 775, k = 710;
			int result = saveMary(n, k);
			Assert::AreEqual(241, result, L"Expected != Actual", 1, 2);
		}

		[TestMethod, Timeout(1500)]
		void TC23()
		{
			int n = 590, k = 126;
			int result = saveMary(n, k);
			Assert::AreEqual(273, result, L"Expected != Actual", 1, 2);
		}

		[TestMethod, Timeout(1500)]
		void TC24()
		{
			int n = 697, k = 610;
			int result = saveMary(n, k);
			Assert::AreEqual(350, result, L"Expected != Actual", 1, 2);
		}

		[TestMethod, Timeout(1500)]
		void TC25()
		{
			int n = 411, k = 287;
			int result = saveMary(n, k);
			Assert::AreEqual(54, result, L"Expected != Actual", 1, 2);
		}

	};
}
