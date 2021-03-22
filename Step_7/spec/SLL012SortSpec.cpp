#include "stdafx.h"
#include "../src/SLL012Sort.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class SLL012SortSpec
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

		struct node * createNode(int n1) {
			struct node *newNode = (struct node *)malloc(sizeof(struct node));
			newNode->data = n1;
			newNode->next = NULL;
			return newNode;
		}

		struct node * add(struct node **head, int p){
			struct node *temp = *head;
			if (*head == NULL){
				(*head) = createNode(p);
				(*head)->next = NULL;
				return *head;
			}
			else{
				while (temp->next != NULL){
					temp = temp->next;
				}
				temp->next = createNode(p);
				temp->next->next = NULL;
				return temp->next;
			}
		}

		int check(int *nums, int len, struct node *head){
			int index = 0;
			struct node *temp = head;
			for (index = 0; index < len; index++){
				if (temp->data != nums[index]){
					return  0;
				}
				temp = temp->next;
			}
			return 1;
		}

		void checkAddresses(struct node *actualNodes[], int len, int *input) {
			int index = 0;
			for (index = 0; index < len; index++){
				int actualValue = actualNodes[index]->data;
				int expectedValue = input[index];
				Assert::AreEqual(expectedValue, actualValue, "You need to change only the links and not the data", 1, 2);
			}
		}

		[TestMethod, Timeout(1000)]
		void sllsort_T1(){
			int num = 0;
			struct node *head = NULL;
			int num_array[100] = { 0, 0, 0, 1, 1, 1, 2, 2, 2, 2 };
			struct node *actualnodes[100];
			int actualNodeIndex = 0; 
			int output[100] = { 0, 0, 0, 1, 1, 1, 2, 2, 2, 2 };
			int len = 10;
			int i = 0;
			for (i = 0; i<len; i++)
			{
				struct node * newNode = add(&head, num_array[i]);
				actualnodes[actualNodeIndex] = newNode;
				actualNodeIndex++;
			}
			sll_012_sort(&head);
			int d = check(output, len, head);
			Assert::IsTrue(d == 1, L"Failed for sll 0001112222.", 1,2);
			checkAddresses(actualnodes, len, num_array);
		}

		[TestMethod, Timeout(1000)]
		void sllSort_T2(){
			int num = 0;
			struct node *head = NULL;
			struct node *actualnodes[100];
			int actualNodeIndex = 0;
			int num_array[100] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
			int output[100] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
			int len = 10;
			int i = 0;
			for (i = 0; i<10; i++)
			{
				struct node * newNode = add(&head, num_array[i]);
				actualnodes[actualNodeIndex] = newNode;
				actualNodeIndex++;
			}
			sll_012_sort(&head);
			int d = check(output, len, head);
			Assert::IsTrue(d == 1, L"Failed for sll for all 1.", 1,2);
			checkAddresses(actualnodes, len, num_array);
		}

		[TestMethod, Timeout(1000)]
		void sllSort_T3(){
			int num = 0;
			struct node *head = NULL;
			struct node *actualnodes[100];
			int actualNodeIndex = 0;
			int num_array[100] = { 2, 2, 2, 1, 1, 1, 0, 0, 0 };
			int output[100] = { 0, 0, 0, 1, 1, 1, 2, 2, 2 };
			int len = 9;
			int i = 0;
			for (i = 0; i<len; i++)
			{
				struct node * newNode = add(&head, num_array[i]);

				actualnodes[actualNodeIndex] = newNode;
				actualNodeIndex++;
			}
			sll_012_sort(&head);
			int d = check(output, len, head);
			Assert::IsTrue(d == 1, L"Failed for sll 222111000.", 1, 2);
			checkAddresses(actualnodes, len, num_array);
		}

		[TestMethod, Timeout(1000)]
		void sllSort_T4(){
			int num = 0;
			struct node *head = NULL;

			struct node *actualnodes[100];
			int actualNodeIndex = 0;
			int num_array[100] = { 1, 2, 1, 1, 1, 2, 2, 0, 0, 0, 2, 1 };
			int output[100] = { 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2 };
			int len = 12;
			int i = 0;
			for (i = 0; i<len; i++)
			{
				struct node * newNode = add(&head, num_array[i]);
				actualnodes[actualNodeIndex] = newNode;
				actualNodeIndex++;
			}
			sll_012_sort(&head);
			int d = check(output, len, head);
			Assert::IsTrue(d == 1, L"Failed for sll 12111220021.", 1,2);
			checkAddresses(actualnodes, len, num_array);
		}


		[TestMethod, Timeout(1000)]
		void sllSort_T5(){
			int num = 0;
			struct node *head = NULL;

			struct node *actualnodes[100];
			int actualNodeIndex = 0;
			int num_array[100] = { 2,2,2,1,1,1 };
			int output[100] = { 1,1,1,2,2,2};
			int len = 6;
			int i = 0;
			for (i = 0; i<len; i++)
			{
				struct node * newNode = add(&head, num_array[i]);
				actualnodes[actualNodeIndex] = newNode;
				actualNodeIndex++;
			}
			sll_012_sort(&head);
			int d = check(output, len, head);
			Assert::IsTrue(d == 1, L"Failed for sll 222111.", 1, 2);
			checkAddresses(actualnodes, len, num_array);
		}


		[TestMethod, Timeout(1000)]
		void sllSort_T6(){
			int num = 0;
			struct node *head = NULL;

			struct node *actualnodes[100];
			int actualNodeIndex = 0;
			int num_array[100] = { 1, 1, 1, 0,0,0 };
			int output[100] = {0,0,0,1,1,1 };
			int len = 6;
			int i = 0;
			for (i = 0; i<len; i++)
			{
				struct node * newNode = add(&head, num_array[i]);
				actualnodes[actualNodeIndex] = newNode;
				actualNodeIndex++;
			}
			sll_012_sort(&head);
			int d = check(output, len, head);
			Assert::IsTrue(d == 1, L"Failed for sll 000111.", 1, 2);
			checkAddresses(actualnodes, len, num_array);
		}

		[TestMethod, Timeout(1000)]
		void sllSort_T7(){
			int num = 0;
			struct node *head = NULL;

			struct node *actualnodes[100];
			int actualNodeIndex = 0;
			int num_array[100] = { 2,1,0 };
			int output[100] = { 0, 1,2 };
			int len = 3;
			int i = 0;
			for (i = 0; i<len; i++)
			{
				struct node * newNode = add(&head, num_array[i]);
				actualnodes[actualNodeIndex] = newNode;
				actualNodeIndex++;
			}
			sll_012_sort(&head);
			int d = check(output, len, head);
			Assert::IsTrue(d == 1, L"Failed for sll 012.", 1, 2);
			checkAddresses(actualnodes, len, num_array);
		}
	};
}
