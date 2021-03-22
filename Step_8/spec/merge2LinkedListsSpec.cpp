#include "stdafx.h"
#include <stdlib.h>
#include "../src/merge2LinkedLists.cpp"
using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class merge2LinkedListsSpec
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
			struct node *res = merge2LinkedLists(NULL,NULL);
			int check = 0;
			if (res == NULL){
				check = 1;
			}
			Assert::AreEqual(1, check, L"Null check failed.", 1, 2);
		}

		[TestMethod, Timeout(2000)]
		void oneLinkedListNULL()
		{
			Assert::IsTrue(compare(merge2LinkedLists(NULL, createList(123)), 123), L"First linked list Null check failed.", 1,2);
			Assert::IsTrue(compare(merge2LinkedLists(createList(123), NULL), 123), L"Second linked list Null check failed.", 1,2);
		}

		
		[TestMethod, Timeout(2000)]
		void sameLinkedLists()
		{
			Assert::IsTrue(compare(merge2LinkedLists(createList(123), createList(123)), 112233), L"Merge same linked lists case failed.", 1,2);
		}

		[TestMethod, Timeout(2000)]
		void sortedLinkedListsUnEqualLength()
		{
			Assert::IsTrue(compare(merge2LinkedLists(createList(123), createList(45)), 12345), L"Merge linked lists unequal length case failed.", 1,2);
			Assert::IsTrue(compare(merge2LinkedLists(createList(79), createList(1)), 179), L"Merge linked lists unequal length case failed.", 1,2);
			Assert::IsTrue(compare(merge2LinkedLists(createList(14), createList(4678)), 144678), L"Merge linked lists unequal length case failed.", 1,2);
		}

		[TestMethod, Timeout(2000)]
		void sortedLinkedListsEqualLength()
		{
			Assert::IsTrue(compare(merge2LinkedLists(createList(123), createList(456)), 123456), L"Merge linked lists equal length case failed.", 1,2);
			Assert::IsTrue(compare(merge2LinkedLists(createList(789), createList(123)), 123789), L"Merge linked lists equal length case failed.", 1,2);
			Assert::IsTrue(compare(merge2LinkedLists(createList(246), createList(135)), 123456), L"Merge linked lists equal length case failed.", 1,2);
			Assert::IsTrue(compare(merge2LinkedLists(createList(125), createList(237)), 122357), L"Merge linked lists equal length case failed.", 1,2);
			Assert::IsTrue(compare(merge2LinkedLists(createList(146), createList(468)), 144668), L"Merge linked lists equal length case failed.", 1,2);
		}


	};
}