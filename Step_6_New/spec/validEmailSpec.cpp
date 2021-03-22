#include "stdafx.h"
#include "../src/validEmail.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class validEmailSpec
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

		void testDefault1_P1()
		{
			int actualAns = isValidEmail("manoj abc@gmail.com");
			Assert::AreEqual(1, actualAns, L"Failed for Invalid case P1", 1, 2);
		};

		void testDefault2_P1()
		{
			int actualAns = isValidEmail("manoj iammanoj@gmail.com");
			Assert::AreEqual(2, actualAns, L"Failed for Invalid case P1", 1, 2);
		};

		void testDefault0_P1()
		{
			int actualAns = isValidEmail("abc abc.com");
			Assert::AreEqual(0, actualAns, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Sample1_ValidEmail()
		{
			int actualAns = isValidEmail("Manoj iammanoj@gmail.com");
			Assert::AreEqual(2, actualAns, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Sample2_ValidEmail()
		{
			int actualAns = isValidEmail("abc abc.com");
			Assert::AreEqual(0, actualAns, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Sample3_ValidEmail()
		{
			int actualAns = isValidEmail("abcd abc@d.com");
			Assert::AreEqual(1, actualAns, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void TC1_ValidEmail()
		{
			// First character must be alphabet
			int actualAns = isValidEmail("Manoj _manoj@gmail.com");
			Assert::AreEqual(0, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void TC2_ValidEmail()
		{
			// @ is not allowed
			int actualAns = isValidEmail("Manoj manoj@@gmail.com");
			Assert::AreEqual(0, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void TC3_ValidEmail()
		{
			// Check of case
			int actualAns = isValidEmail("MANOJ m_mAnOj@gmail.com");
			Assert::AreEqual(2, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void TC4_ValidEmail()
		{
			// prefix check
			int actualAns = isValidEmail("Manoj manojch@gmail.com");
			Assert::AreEqual(2, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void TC5_ValidEmail()
		{
			// sufix check
			int actualAns = isValidEmail("Manoj iammanoj@gmail.com");
			Assert::AreEqual(2, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void TC6_ValidEmail()
		{
			// Length of email check
			int actualAns = isValidEmail("a aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa@gmail.com");
			Assert::AreEqual(0, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void TC7_ValidEmail()
		{
			// '\' is not allowed 
			int actualAns = isValidEmail("Manoj iamma>noj@gmail.com");
			Assert::AreEqual(0, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void TC8_ValidEmail()
		{
			// space is not allowed
			int actualAns = isValidEmail("Manoj i am manoj@gmail.com");
			Assert::AreEqual(0, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void TC9_ValidEmail()
		{
			// .edu, .ac.in , .co.in are also valid
			int actualAns = isValidEmail("Manoj iammanoj@gmail.co.in");
			Assert::AreEqual(2, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void TC10_ValidEmail()
		{
			// two strings check
			int actualAns = isValidEmail("Manoj manoj");
			Assert::AreEqual(0, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void TC11_ValidEmail()
		{
			// single string check
			int actualAns = isValidEmail("Manoj");
			Assert::AreEqual(0, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void TC12_ValidEmail()
		{
			// only valid email  - 1
			int actualAns = isValidEmail("manoj abc_e-fg@gmail.co.in");
			Assert::AreEqual(1, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault2_P1();
		};

		[TestMethod, Timeout(1000)]
		void TC13_ValidEmail()
		{
			// only valid email  - 2
			int actualAns = isValidEmail("surya    suriii@sun.com      ");
			Assert::AreEqual(1, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault2_P1();
		};


		[TestMethod, Timeout(1000)]
		void TC14_ValidEmail()
		{
			// Null check
			int actualAns = isValidEmail("");
			Assert::AreEqual(0, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void TC15_ValidEmail()
		{
			// only valid email  - 2
			int actualAns = isValidEmail("surya    suriii@sun.com      ");
			Assert::AreEqual(1, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault2_P1();
		};

		[TestMethod, Timeout(1000)]
		void TC16_ValidEmail()
		{
			// only valid email  - 1
			int actualAns = isValidEmail("manoj abc_e-fg@gmail.co.in");
			Assert::AreEqual(1, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault2_P1();
		};

		[TestMethod, Timeout(1000)]
		void TC17_ValidEmail()
		{
			// Check of case
			int actualAns = isValidEmail("MANOJ m_mAnOj@gmail.com");
			Assert::AreEqual(2, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void TC18_ValidEmail()
		{
			// Check of case
			int actualAns = isValidEmail("MANOJ m_mAnOj@gmail.com");
			Assert::AreEqual(2, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void TC19_ValidEmail()
		{
			// middle instance
			int actualAns = isValidEmail("MAnOJ m_mAnOjabc@gmail.com");
			Assert::AreEqual(1, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault0_P1();
		};

		[TestMethod, Timeout(1000)]
		void TC20_ValidEmail()
		{
			// .edu, .ac.in , .co.in are also valid
			int actualAns = isValidEmail("Manoj iammanoj@gmail.co.in");
			Assert::AreEqual(2, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void TC21_ValidEmail()
		{
			// .edu, .ac.in , .co.in are also valid
			int actualAns = isValidEmail("Manoj iammanoj@gmail.co.in");
			Assert::AreEqual(2, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void TC22_ValidEmail()
		{
			// Length of email check
			int actualAns = isValidEmail("a aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa@gmail.com");
			Assert::AreEqual(0, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault2_P1();
		};

	};
}
