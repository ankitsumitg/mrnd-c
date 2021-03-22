#include "stdafx.h"
#include <stdlib.h>
#include "../src/linkedListMedian.cpp"
using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class linkedListMedianSpec
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
			int res = linkedListMedian(NULL);
			int check = 0;
			if (res == -1){
				check = 1;
			}
			Assert::AreEqual(1, check,L"Null check failed.", 1,2);
		}

		[TestMethod, Timeout(2000)] 
		void medianevenLength()
		{
			Assert::AreEqual(linkedListMedian(createList(19)), 5, L"Even length check failed.", 1,2);
			Assert::AreEqual(linkedListMedian(createList(3456)), 4, L"Even length check failed.", 1,2);
			Assert::AreEqual(linkedListMedian(createList(123678)), 4, L"Even length check failed.", 1,2);
			Assert::AreEqual(linkedListMedian(createList(555555)), 5, L"Even length check failed.", 1,2);
		}

		[TestMethod, Timeout(2000)] 
		void medianOddLength()
		{
			Assert::AreEqual(linkedListMedian(createList(3)), 3, L"Odd length check failed.", 1,2);
			Assert::AreEqual(linkedListMedian(createList(345)), 4, L"Odd length check failed.", 1,2);
			Assert::AreEqual(linkedListMedian(createList(23789)), 7, L"Odd length check failed.", 1,2);
			Assert::AreEqual(linkedListMedian(createList(44444)), 4, L"Odd length check failed.", 1,2);
		}

		


	};
}