#include "stdafx.h"
#include "../src/twodigitLinkedList.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class twodigitLinkedListSpec
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

		struct twoDigitNode * createNode(int n1, int n2) {
			struct twoDigitNode *newNode = (struct twoDigitNode *)malloc(sizeof(struct twoDigitNode));
			newNode->digit1 = n1;
			newNode->digit2 = n2;
			newNode->next = NULL;
			return newNode;
		}

		void add(struct twoDigitNode **head, int p, int q){
			struct twoDigitNode *temp = *head;
			if (*head == NULL){
				(*head) = createNode(p, q);
				(*head)->next = NULL;
			}
			else{
				while (temp->next != NULL){
					temp = temp->next;
				}
				temp->next = createNode(p, q);
				temp->next->next = NULL;
			}
		}
		[TestMethod, Timeout(1000)]
		void twoDigitLL_simpleTwoDigit()
		{
			int num = 0;
			struct twoDigitNode *head = NULL;
			add(&head, 1, 2);
			add(&head, 5, 6);
			add(&head, 3, 4);
			num = convert_sll_2digit_to_int(head);
			Assert::AreEqual(125634,num, L"Failed for input 125634.", 1,2);
		}

		[TestMethod, Timeout(1000)]
		void twoDigitLL_Zero2digit()
		{
			int num = 0;
			struct twoDigitNode *head = NULL;
			add(&head, 0, 0);
			num = convert_sll_2digit_to_int(head);
			Assert::AreEqual(0,num, L"Failed for input 125634.", 1, 2);
		}
		[TestMethod, Timeout(1000)]
		void twoDigitLL_Repeated2digit()
		{
			int num = 0;
			struct twoDigitNode *head = NULL;
			add(&head, 1, 1);
			add(&head, 2, 2);
			add(&head, 3, 3);
			num = convert_sll_2digit_to_int(head);
			Assert::AreEqual(112233,num, L"Failed for input 125634.", 1, 2);
		}
		[TestMethod, Timeout(1000)]
		void twoDigitLL_Leadingzero2digit()
		{
			int num = 0;
			struct twoDigitNode *head = NULL;
			add(&head, 0, 0);
			add(&head, 2, 2);
			add(&head, 3, 3);
			num = convert_sll_2digit_to_int(head);
			Assert::AreEqual(2233,num, L"Failed for input 125634.", 1, 2);
		}
	};
}
