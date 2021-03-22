#include "stdafx.h"
#include "../src/IsDivSLL.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class IsDivSLLSpec
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

		struct charNode * createNode_Spec(char l) {
			struct charNode *newNode = (struct charNode *)malloc(sizeof(struct charNode));
			newNode->letter = l;
			newNode->next = NULL;
			return newNode;
		}

		struct charNode * createSLLFromString(char *str){
			int len = 0;
			int i = 0;
			while (str[i] != '\0'){
				len++;
				i++;
			}
			struct charNode *head = NULL;
			struct charNode *temp = NULL;
			i = 0;
			while (i < len){
				struct charNode *tempNode = createNode_Spec(str[i]);
				if (head){
					temp->next = tempNode;
					temp = tempNode;
				}
				else{
					head = tempNode;
					temp = tempNode;
				}
				i++;
			}
			temp->next = NULL;
			return head;
		}
		[TestMethod]
		void Sample1_Problem1()
		{
			int actualAns = isDivisibleSLL(NULL, 1);
			Assert::AreEqual(-1, actualAns, L"Failed for Invalid case P1", 1, 2);

		};

		[TestMethod]
		void Sample2_Problem1()
		{

			char str[100] = "+1234";
			int key = 5;
			int expectedAns = 1;
			struct charNode *head = createSLLFromString(str);
			int actualAns = isDivisibleSLL(head, key);
			Assert::AreEqual(expectedAns, actualAns, L"Failed  P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Sample3_Problem1()
		{

			char str[100] = "-1234";
			int key = 6;
			int expectedAns = 0;
			struct charNode *head = createSLLFromString(str);
			int actualAns = isDivisibleSLL(head, key);
			Assert::AreEqual(expectedAns, actualAns, L"Failed  P1", 1, 2);
		};

		//Real Cases

		void runSimpleTestCase(char *str, int key, int expectedAns, int key2, int expectedAns2){


			struct charNode *head = createSLLFromString(str);
			int actualAns = isDivisibleSLL(head, key);

			Assert::AreEqual(expectedAns, actualAns, L"Failed  P1", 1, 2);

			int actualAns2 = isDivisibleSLL(head, key2);
			Assert::AreEqual(expectedAns2, actualAns2, L"Failed  P1", 1, 2);

		}

		[TestMethod, Timeout(1000)]
		void Real3_Problem1()
		{
			runSimpleTestCase("-999999", 3, 1, 56743, 0);

		};

		[TestMethod, Timeout(1000)]
		void Real4_Problem1()
		{
			runSimpleTestCase("+999999", 3, 1, 56743, 0);

		};
		[TestMethod, Timeout(1000)]
		void Real5_Problem1()
		{
			runSimpleTestCase("999999", 3, 1, 56743, 0);

		};
		[TestMethod, Timeout(1000)]
		void Real6_Problem1()
		{
			runSimpleTestCase("-9999", 3, 1, 56743, 0);

		};


		[TestMethod, Timeout(1000)]
		void Real7_Problem1()
		{
			runSimpleTestCase("12345677", 34078, 1, 34065, 0);

		};

		[TestMethod, Timeout(1000)]
		void Real8_Problem1()
		{
			runSimpleTestCase("12345677", 34065, 0, 34078, 1);

		};
		[TestMethod, Timeout(1000)]
		void Real9_Problem1()
		{
			runSimpleTestCase("+12345677", 34078, 1, 34065, 0);

		};

		[TestMethod, Timeout(1000)]
		void Real10_Problem1()
		{
			runSimpleTestCase("-12345677", 34065, 0, 34078, 1);

		};

		[TestMethod, Timeout(1000)]
		void Real11_Problem1()
		{
			runSimpleTestCase("-4532100", 2697, 0, 2694, 0);

		};

		[TestMethod, Timeout(1000)]
		void Real12_Problem1()
		{
			runSimpleTestCase("-4532100", 757409, 1, 2694, 0);

		};

		[TestMethod, Timeout(1000)]
		void Real13_Problem1()
		{
			runSimpleTestCase("+4532100", 2697, 0, 2694, 0);

		};

		[TestMethod, Timeout(1000)]
		void Real14_Problem1()
		{
			runSimpleTestCase("4532100", 757409, 1, 2694, 0);

		};

		[TestMethod, Timeout(1000)]
		void Real15_Problem1()
		{
			runSimpleTestCase("4532100", 0, -1, 757409, 1);

		};

		[TestMethod, Timeout(1000)]
		void Real16_Problem1()
		{
			runSimpleTestCase("0000000", 0, -1, 2, 1);

		};
		[TestMethod, Timeout(1000)]
		void Real17_Problem1()
		{
			runSimpleTestCase("-0000000", 0, -1, 2, 1);

		};
		[TestMethod, Timeout(1000)]
		void Real18_Problem1()
		{
			runSimpleTestCase("+0000000", 0, -1, 2, 1);

		};

		[TestMethod, Timeout(1000)]
		void Real19_Problem1()
		{
			runSimpleTestCase("743271894", 137938249, 1, 5, 0);

		};

		[TestMethod, Timeout(1000)]
		void Real20_Problem1()
		{
			runSimpleTestCase("743271894", 137938249, 1, 5, 0);

		};

		[TestMethod, Timeout(1000)]
		void Real21_Problem1()
		{
			runSimpleTestCase("743271894", 137938249, 1, 5, 0);

		};

		[TestMethod, Timeout(1000)]
		void Real22_Problem1()
		{
			runSimpleTestCase("743271894", 137938249, 1, 5, 0);

		};

		[TestMethod, Timeout(1000)]
		void Real23_Problem1()
		{
			runSimpleTestCase("743271894", 137938249, 1, 5, 0);

		};

		[TestMethod, Timeout(1000)]
		void Real24_Problem1()
		{
			runSimpleTestCase("743271894", 137938249, 1, 5, 0);

		};

	};
}
