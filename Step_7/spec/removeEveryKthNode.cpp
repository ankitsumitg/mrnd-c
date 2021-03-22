#include "stdafx.h"
#include "../src/removeEveryKthNode.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class removeEveryKthNodeSpec
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

#pragma endregion 
		struct node * createNode(int num) {
			struct node *newNode = (struct node *)malloc(sizeof(struct node));
			newNode->num = num;
			newNode->next = NULL;
			return newNode;
		}

		struct node * createList(int num) {
			struct node *head = createNode(num % 10);
			num /= 10;
			while (num) {
				struct node *newNode = createNode(num % 10);
				newNode->next = head;
				head = newNode;
				num /= 10;
			}
			return head;
		}

		bool compare(struct node *result, int num) {
			struct node *head = createList(num);
			while (head && result && head->num == result->num) {
				head = head->next;
				result = result->next;
			}
			return !head && !result;
		}

		[TestMethod, Timeout(1000)]
		void removeEveryKthNode_T1(){
			struct node * answer = removeEveryKthNode(NULL, 2);
			if (answer != NULL) {
				Assert::AreEqual(1,2, L"Null check Failed", 1, 2);
			}
		}

		[TestMethod, Timeout(1000)]
		void removeEveryKthNode_T2(){
			struct node *head = createList(1234);
			struct node * answer = removeEveryKthNode(head, 1);
			if (answer != NULL) {
				Assert::AreEqual(1, 2, L"K value 1 case failed", 1, 2);
			}
		}

		[TestMethod, Timeout(1000)]
		void removeEveryKthNode_T3(){
			struct node *head = createList(1234);

			struct node * answer = removeEveryKthNode(head, 0);
			if (answer != NULL) {
				Assert::AreEqual(1, 2, L"K value 0 case failed.", 1, 2);
			}
		}

		[TestMethod, Timeout(1000)]
		void removeEveryKthNode_T4(){
			struct node *head = createList(1234);

			struct node * answer = removeEveryKthNode(head,-3);
			if (answer != NULL) {
				Assert::AreEqual(1, 2, L"K value less than zero case failed", 1, 2);
			}
		}

		[TestMethod, Timeout(1000)]
		void removeEveryKthNode_T5(){
			Assert::IsTrue(compare(removeEveryKthNode(createList(12345678), 3), 124578), L"K value odd case failed.", 1,2);
			Assert::IsTrue(compare(removeEveryKthNode(createList(12345678), 2), 1357), L"K value even case failed.", 1,2);
			Assert::IsTrue(compare(removeEveryKthNode(createList(12345678), 8), 1234567), L"K value equal to length case failed.", 1,2);
			Assert::IsTrue(compare(removeEveryKthNode(createList(12345678), 9), 12345678), L"K value greater than length case failed.", 1,2);
		}


	};
}
