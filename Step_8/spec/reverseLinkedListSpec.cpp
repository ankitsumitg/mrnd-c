#include "stdafx.h"
#include <stdlib.h>
#include "../src/reverseLinkedList.cpp"
using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class reverseLinkedListSpec
	{
	private:
		TestContext^ testContextInstance;
	public:
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

		[TestMethod, Timeout(2000)]
		void nullCheck()
		{
			struct node *res = reverseLinkedList(NULL);
			int check = 0;
			if (res == NULL){
				check = 1;
			}
			Assert::AreEqual(1, check, L"Null check failed.", 1, 2);
		}

		[TestMethod, Timeout(2000)]
		void singleNode()
		{
			Assert::AreEqual(true,compare(reverseLinkedList(createList(2)), 2), L"Single node case failed.", 1,2);
		}

		[TestMethod, Timeout(2000)]
		void twoNodes()
		{
			Assert::AreEqual(true,compare(reverseLinkedList(createList(25)), 52), L"Two nodes case failed.", 1,2);
		}


		[TestMethod, Timeout(2000)]
		void multipleNodes()
		{
			Assert::AreEqual(true,compare(reverseLinkedList(createList(289)), 982), L"Multiple nodes case failed.",1,2);
			Assert::AreEqual(true,compare(reverseLinkedList(createList(908234)), 432809), L"Multiple nodes case failed.", 1, 2);
			Assert::AreEqual(true,compare(reverseLinkedList(createList(00000)), 00000), L"Multiple nodes case failed.", 1, 2);
			Assert::AreEqual(true,compare(reverseLinkedList(createList(347634437)), 734436743), L"Multiple nodes case failed.", 1, 2);
			Assert::AreEqual(true,compare(reverseLinkedList(createList(223344)), 443322), L"Multiple nodes case failed.", 1, 2);		
		}
		

	};
}