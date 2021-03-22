#include "stdafx.h"
#include "../src/sortLinkedList.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class sortLinkedListSpec
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

		bool compare(struct node *head, struct node *result) {
			while (head && result && head->num == result->num) {
				head = head->next;
				result = result->next;
			}
			return !head && !result;
		}

		[TestMethod, Timeout(1000)]
		void sortLinkedList_nullCheck()
		{
			struct node * answer = sortLinkedList(NULL);
			if (answer != NULL) {
				Assert::AreEqual(1, 2, L"Null check Failed", 1, 2);
			}
		}

		[TestMethod, Timeout(1000)]
		void sortLinkedList_sortedLinkedList()
		{
			struct node *head = createList(1234);
			Assert::IsTrue(compare(sortLinkedList(head), head), L"Sorted Linked list check failed.", 1,2);
		}

		[TestMethod, Timeout(1000)]
		void sortLinkedList_singleNode()
		{
			struct node *head = createList(1);
			Assert::IsTrue(compare(sortLinkedList(head), head), L"Single Node check failed.", 1,2);
		}

		[TestMethod, Timeout(1000)]
		void sortLinkedList_moreThanOneNode()
		{
			struct node *head = createList(42153);
			Assert::IsTrue(compare(sortLinkedList(head), createList(12345)), L"Random Linked list check failed.", 1,2);
		}

	};
}
