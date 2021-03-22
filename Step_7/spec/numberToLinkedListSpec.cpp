#include "stdafx.h"
#include "../src/numberToLinkedList.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class numberToLinkedListSpec
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

		bool compare(int A[], int len, struct node *head) {
			int i = 0;
			for (; i < len && head; ++i) {
				if (A[i] != head->num) {
					return false;
				}
				head = head->next;
			}
			return i == len && !head;
		}

		[TestMethod, Timeout(1000)]
		void numberToLinkedList_T1(){
			int num = 0;
			struct node *head = numberToLinkedList(num);
			Assert::IsTrue(head->num == num && !head->next, L"Number zero case failed.", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void numberToLinkedList_T2(){
			int num = -4568;
			int A[] = { 4, 5, 6, 8 };
			struct node *head = numberToLinkedList(num);
			Assert::IsTrue(compare(A, 4, head), L"Negative number case failed.", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void numberToLinkedList_T3(){
			int num = 8348;
			int A[] = { 8, 3, 4, 8 };
			struct node *head = numberToLinkedList(num);
			Assert::IsTrue(compare(A, 4, head), L"Positive number case failed.", 1, 2);
		}


	};
}
