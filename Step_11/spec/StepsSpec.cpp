#include "stdafx.h"


#include "./../src/Steps.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class StepsSpec
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
		void ZeroSteps()
		{
			int n = 0;
			int result = get_steps(0);
			Assert::AreEqual(0, result, L"0 should be 0", 1, 2);
		}
		[TestMethod, Timeout(3000)]
		void OneSteps()
		{
			int n = 0;
			int result = get_steps(1);
			Assert::AreEqual(1, 1, L"0 should be 0", 1, 2);
		}
		[TestMethod,Timeout(5000)]
		void SmallCases()
		{
			int n = 0,i=0;
			int result = get_steps(0);
			int inputs[6] = { 3, 5, 7, 9, 10, 12 };
			int answers[6] = { 3, 8, 21, 55, 89, 233 };
			for (i = 0; i < 6; i++){
				Assert::AreEqual(answers[i],get_steps(inputs[i]), L"Failed for either 3,5,7,9,10,12", 1, 2);
			}
		}

	};
}
