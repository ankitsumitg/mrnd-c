#include "stdafx.h"
#include <stdlib.h>
#include "../src/insertAtEveryKthNode.cpp";
using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class insertAtEveryKthNodeSpec
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
			struct node *head = NULL;
			struct node *res = insertAtEveryKthNode(NULL, 0);
			int check = 0;
			if (res == NULL){
				check = 1;
			}
			Assert::AreEqual(1, check, L"Failed for head is NULL in IAKN", 1, 2);
		}

		[TestMethod, Timeout(2000)] 
		void InvalidKValue()
		{
			struct node *head = createNode(5);
			struct node *res = insertAtEveryKthNode(head, 0);
			int check = 0;
			if (res == NULL){
				check = 1;
			}
			Assert::AreEqual(1, check, L"Failed for K is 0 in IAKN", 1, 2);
			
			res = insertAtEveryKthNode(head, -2);
			check = 0;
			if (res == NULL){
				check = 1;
			}

			Assert::AreEqual(1, check, L"Failed for K is -2 in IAKN", 1, 2);
		}

		[TestMethod, Timeout(2000)] 
		void KValueGreaterThanLength()
		{
			Assert::IsTrue(compare(insertAtEveryKthNode(createList(28349), 9), 28349), L"K value greater than length case failed.", 1, 2);
		}

		[TestMethod, Timeout(2000)] 
		void validKValue()
		{
			Assert::IsTrue(compare(insertAtEveryKthNode(createList(289), 1), 218191), L"K value one case failed.", 1, 2);
			Assert::IsTrue(compare(insertAtEveryKthNode(createList(222), 2), 2222), L"K value two case failed.", 1, 2);
			Assert::IsTrue(compare(insertAtEveryKthNode(createList(56934), 3), 569334), L"K value one case failed.", 1, 2);
			Assert::IsTrue(compare(insertAtEveryKthNode(createList(12345), 2), 1223425), L"K value one case failed.", 1, 2);
		}
		
	};
}