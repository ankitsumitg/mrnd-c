#include "stdafx.h"
#include "../src/DoorsToCross.cpp"
#include <string.h>

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class DoorsToCrossSpec
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


		struct passKeyNode *createnode(int num)
		{
			struct passKeyNode *new_node = (struct passKeyNode*)malloc(sizeof(struct passKeyNode));
			new_node->num = num;
			new_node->prev = NULL;
			new_node->next = NULL;
			return new_node;
		}

		struct passKeyNode* strtoDLL(char *str)
		{
			int len = 0;
			while (str[len] != '\0'){
				len++;
			}
			if (len == 0)
				return NULL;

			struct passKeyNode *head = createnode(str[len - 1] - '0');
			for (int i = len - 2; i >= 0; i--)
			{
				struct passKeyNode *temp = createnode(str[i] - '0');
				head->prev = temp;
				temp->next = head;
				head = temp;
			}

			return head;
		}


		[TestMethod, Timeout(1000)]
		void TC1_DTC()
		{
			struct passKeyNode *passkey = strtoDLL("321");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(1, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void TC2_DTC()
		{
			struct passKeyNode *passkey = strtoDLL("758");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(4, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void TC3_DTC()
		{
			struct passKeyNode *passkey = strtoDLL("");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(-1, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void TC4_DTC()
		{
			struct passKeyNode *passkey = strtoDLL("777");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(1, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void TC5_DTC()
		{
			struct passKeyNode *passkey = strtoDLL("049");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(6, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void TC6_DTC()
		{
			struct passKeyNode *passkey = strtoDLL("0049");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(12, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void TC7_DTC()
		{
			struct passKeyNode *passkey = strtoDLL("9876543212");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(2, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void TC8_DTC()
		{
			struct passKeyNode *passkey = strtoDLL("54321");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(1, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void TC9_DTC()
		{
			struct passKeyNode *passkey = strtoDLL("53124");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(12, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void TC10_DTC()
		{
			struct passKeyNode *passkey = strtoDLL("53412");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(8, actualAns, L"Failed  ", 1, 2);
		};
	};
}
