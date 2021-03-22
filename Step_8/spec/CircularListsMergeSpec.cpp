#include "stdafx.h";
#include <stdlib.h>;
#include "./../src/CircularListsMerge.cpp";

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class CircularListsMergeSpec
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
			newNode->data = num;
			newNode->next = NULL;
			return newNode;
		}

		void addNode(struct node **head, int data){
			struct node * cur = createNode(data);
			if (*head == NULL){
				*head = cur;
			}
			else{
				struct node *temp = *head;
				cur->next = temp;
				*head = cur;
			}
		}
		void make_it_circular(struct node *head){
			struct node *temp = head;
			while (head->next != NULL){
				head = head->next;
			}
			head->next = temp;
		}
		int is_correct(struct node *head, int *arr, int len){
			int i = 0;
			while (head != NULL){
				int data = head->data;
				if (arr[i]!=data){
					return 0;
				}
				else{
					i++;
					head = head->next;
				}

				if (head == NULL){
					return 0;
				}
				if (i == len){
					return 1;
				}
			}
		}
		void mrnd_sort(int *arr, int len){
			for (int i = 0; i < len - 1; i++){
				for (int j = 0; j < len - i - 1; j++){
					if (arr[j] > arr[j + 1]){
						int t = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = t;
					}
				}
			}
		}

		[TestMethod, Timeout(1000)]
		void Sample1_CircularListsMerge()
		{
			struct node *head1 = NULL;
			struct node *head2 = NULL;
			int len = merge_circularlists(&head1, &head2);

			Assert::AreEqual(-1, len, L"Failed sample 0 for NULL case in LL", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Sample2_CircularListsMerge()
		{
			int nums[5] = { 1, 3,5 };
			int nums2[5] = { 2, 4,6 };
			//Last 1 is for checking whether A is circular or not .6 should again point to 1
			int ans[10] = { 1, 2, 3, 4,5,6,1 };
			
			int l1 = 3, l2 = 3, i;
			struct node *head1 = NULL;
			struct node *head2 = NULL;
			for (i = l1 - 1; i >= 0; i--){
				addNode(&head1, nums[i]);
			}
			for (i = l2 - 1; i >= 0; i--){
				addNode(&head2, nums2[i]);
			}
			make_it_circular(head1);
			make_it_circular(head2);

			int len = merge_circularlists(&head1, &head2);
			int check = is_correct(head1, ans, len + 1);
			Assert::AreEqual(l1+l2, len, L"Failed for sample 2 in CLL 2", 1, 2);
			Assert::AreEqual(1, check, L"Failed for sample 2 in CLL 2", 1, 2);
		};


		//Server Side Test Results 
		[TestMethod, Timeout(1000)]
		void Real_CircularListsMerge1()
		{
			int nums[5] = { 1, 3, 5,7,9 };
			int nums2[5] = { 2, 4, 6,8,10 };
			//Last 1 is for checking whether A is circular or not .6 should again point to 1
			int ans[100] = { 1, 2, 3, 4, 5, 6,7,8,9,10, 1 };
			int l1 = 5, l2 = 5, i;
			struct node *head1 = NULL;
			struct node *head2 = NULL;
			for (i = l1 - 1; i >= 0; i--){
				addNode(&head1, nums[i]);
			}
			for (i = l2 - 1; i >= 0; i--){
				addNode(&head2, nums2[i]);
			}
			make_it_circular(head1);
			make_it_circular(head2);

			int len = merge_circularlists(&head1, &head2);
			int check = is_correct(head1, ans, len + 1);
			Assert::AreEqual(l1 + l2, len, L"Failed for Real in CLL 2", 1, 2);
			Assert::AreEqual(1, check, L"Failed for Real in CLL 2", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Real_CircularListsMerge2()
		{
			int nums[5] = { 1, 3, 5, 7, 9 };
			int nums2[5] = { 2, 4, 6, 8, 10 };
			//Last 1 is for checking whether A is circular or not .6 should again point to 1
			int ans[100] = { 1, 2, 4,6,8,10,1 };
			int l1 = 1, l2 = 5, i;
			struct node *head1 = NULL;
			struct node *head2 = NULL;
			for (i = l1 - 1; i >= 0; i--){
				addNode(&head1, nums[i]);
			}
			for (i = l2 - 1; i >= 0; i--){
				addNode(&head2, nums2[i]);
			}
			make_it_circular(head1);
			make_it_circular(head2);

			int len = merge_circularlists(&head1, &head2);
			int check = is_correct(head1, ans, len + 1);
			Assert::AreEqual(l1 + l2, len, L"Failed for Real in CLL 2", 1, 2);
			Assert::AreEqual(1, check, L"Failed for Real in CLL 2", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Real_CircularListsMerge3()
		{
			int nums[5] = { 1, 3, 5, 7, 9 };
			int nums2[5] = { 2 };
			//Last 1 is for checking whether A is circular or not .6 should again point to 1
			int ans[100] = { 1,2,3,5,7,9,1 };
			int l1 = 5, l2 = 1, i;
			struct node *head1 = NULL;
			struct node *head2 = NULL;
			for (i = l1 - 1; i >= 0; i--){
				addNode(&head1, nums[i]);
			}
			for (i = l2 - 1; i >= 0; i--){
				addNode(&head2, nums2[i]);
			}
			make_it_circular(head1);
			make_it_circular(head2);

			int len = merge_circularlists(&head1, &head2);
			int check = is_correct(head1, ans, len + 1);
			Assert::AreEqual(l1 + l2, len, L"Failed for Real in CLL 2", 1, 2);
			Assert::AreEqual(1, check, L"Failed for Real in CLL 2", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_CircularListsMerge4()
		{
			int nums[5] = { 1, 3, 5 };
			int nums2[5] = { 2, 4, 6 };
			//Last 1 is for checking whether A is circular or not .6 should again point to 1
			int ans[100] = { 1, 2, 3, 4, 5, 6,1 };
			int l1 = 3, l2 = 3, i;
			struct node *head1 = NULL;
			struct node *head2 = NULL;
			for (i = l1 - 1; i >= 0; i--){
				addNode(&head1, nums[i]);
			}
			for (i = l2 - 1; i >= 0; i--){
				addNode(&head2, nums2[i]);
			}
			make_it_circular(head1);
			make_it_circular(head2);

			int len = merge_circularlists(&head1, &head2);
			int check = is_correct(head1, ans, len + 1);
			Assert::AreEqual(l1 + l2, len, L"Failed for Real in CLL 2", 1, 2);
			Assert::AreEqual(1, check, L"Failed for Real in CLL 2", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_CircularListsMerge5()
		{
			int nums[5] = { 1, 3, 5 };
			int nums2[5] = { 2, 4, 6 };
			//Last 1 is for checking whether A is circular or not .6 should again point to 1
			int ans[100] = { 1, 2, 3, 4, 5, 6, 1 };
			int l1 = 3, l2 = 3, i;
			struct node *head1 = NULL;
			struct node *head2 = NULL;
			for (i = l1 - 1; i >= 0; i--){
				addNode(&head1, nums[i]);
			}
			for (i = l2 - 1; i >= 0; i--){
				addNode(&head2, nums2[i]);
			}
			make_it_circular(head1);
			make_it_circular(head2);

			int len = merge_circularlists(&head1, &head2);
			int check = is_correct(head1, ans, len + 1);
			Assert::AreEqual(l1 + l2, len, L"Failed for Real in CLL 2", 1, 2);
			Assert::AreEqual(1, check, L"Failed for Real in CLL 2", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_CircularListsMerge6()
		{
			int nums[5] = { 1, 3, 6 };
			int nums2[5] = { 2, 4, 5 };
			//Last 1 is for checking whether A is circular or not .6 should again point to 1
			int ans[100] = { 1, 2, 3, 4, 5, 6, 1 };
			int l1 = 3, l2 = 3, i;
			struct node *head1 = NULL;
			struct node *head2 = NULL;
			for (i = l1 - 1; i >= 0; i--){
				addNode(&head1, nums[i]);
			}
			for (i = l2 - 1; i >= 0; i--){
				addNode(&head2, nums2[i]);
			}
			make_it_circular(head1);
			make_it_circular(head2);

			int len = merge_circularlists(&head1, &head2);
			int check = is_correct(head1, ans, len + 1);
			Assert::AreEqual(l1 + l2, len, L"Failed for Real in CLL 2", 1, 2);
			Assert::AreEqual(1, check, L"Failed for Real in CLL 2", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_CircularListsMerge7()
		{
			int nums[5] = { 1, 3, 4 };
			int nums2[5] = { 2, 5, 6 };
			//Last 1 is for checking whether A is circular or not .6 should again point to 1
			int ans[100] = { 1, 2, 3, 4, 5, 6, 1 };
			int l1 = 3, l2 = 3, i;
			struct node *head1 = NULL;
			struct node *head2 = NULL;
			for (i = l1 - 1; i >= 0; i--){
				addNode(&head1, nums[i]);
			}
			for (i = l2 - 1; i >= 0; i--){
				addNode(&head2, nums2[i]);
			}
			make_it_circular(head1);
			make_it_circular(head2);

			int len = merge_circularlists(&head1, &head2);
			int check = is_correct(head1, ans, len + 1);
			Assert::AreEqual(l1 + l2, len, L"Failed for Real in CLL 2", 1, 2);
			Assert::AreEqual(1, check, L"Failed for Real in CLL 2", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_CircularListsMerge8()
		{
			int nums[50] = { 1, 3, 5,10,20,30,40,50,60,100 };
			int nums2[50] = { 2, 4, 6,7,8,9,11,13,55,65 };
			//Last 1 is for checking whether A is circular or not .6 should again point to 1
			int ans[100] = { 1, 2, 3,4,5,6,7,8,9,10,11,13,20,30,40,50,55,60,65,100,1};
			int l1 = 10, l2 = 10, i;
			struct node *head1 = NULL;
			struct node *head2 = NULL;
			for (i = l1 - 1; i >= 0; i--){
				addNode(&head1, nums[i]);
			}
			for (i = l2 - 1; i >= 0; i--){
				addNode(&head2, nums2[i]);
			}
			make_it_circular(head1);
			make_it_circular(head2);

			int len = merge_circularlists(&head1, &head2);
			int check = is_correct(head1, ans, len + 1);
			Assert::AreEqual(l1 + l2, len, L"Failed for Real in CLL 2", 1, 2);
			Assert::AreEqual(1, check, L"Failed for Real in CLL 2", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_CircularListsMerge9()
		{
			int nums[50] = { 1, 3, 5, 10, 20, 30, 40, 50, 60, 100 };
			int nums2[50] = { 2, 4, 6, 7, 8, 9, 11, 13, 55, 65 };
			//Last 1 is for checking whether A is circular or not .6 should again point to 1
			int ans[100] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 20, 30, 40, 50, 55, 60, 65, 100, 1 };
			int l1 = 10, l2 = 10, i;
			struct node *head1 = NULL;
			struct node *head2 = NULL;
			for (i = l1 - 1; i >= 0; i--){
				addNode(&head1, nums[i]);
			}
			for (i = l2 - 1; i >= 0; i--){
				addNode(&head2, nums2[i]);
			}
			make_it_circular(head1);
			make_it_circular(head2);

			int len = merge_circularlists(&head1, &head2);
			int check = is_correct(head1, ans, len + 1);
			Assert::AreEqual(l1 + l2, len, L"Failed for Real in CLL 2", 1, 2);
			Assert::AreEqual(1, check, L"Failed for Real in CLL 2", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_CircularListsMerge10()
		{
			int nums[50] = { 1, 3, 5, 10, 20, 30, 40, 50, 60, 100 };
			int nums2[50] = { 2, 4, 6, 7, 8, 9, 11, 13, 55, 65 };
			//Last 1 is for checking whether A is circular or not .6 should again point to 1
			int ans[100] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 20, 30, 40, 50, 55, 60, 65, 100, 1 };
			int l1 = 10, l2 = 10, i;
			struct node *head1 = NULL;
			struct node *head2 = NULL;
			for (i = l1 - 1; i >= 0; i--){
				addNode(&head1, nums[i]);
			}
			for (i = l2 - 1; i >= 0; i--){
				addNode(&head2, nums2[i]);
			}
			make_it_circular(head1);
			make_it_circular(head2);

			int len = merge_circularlists(&head1, &head2);
			int check = is_correct(head1, ans, len + 1);
			Assert::AreEqual(l1 + l2, len, L"Failed for Real in CLL 2", 1, 2);
			Assert::AreEqual(1, check, L"Failed for Real in CLL 2", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_CircularListsMerge11()
		{
			int nums[50] = { 1, 3, 5, 10, 20, 30, 40, 50, 60, 100 };
			int nums2[50] = { 2, 4, 6, 7, 8, 9, 11, 13, 55, 65 };
			//Last 1 is for checking whether A is circular or not .6 should again point to 1
			int ans[100] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 20, 30, 40, 50, 55, 60, 65, 100, 1 };
			int l1 = 10, l2 = 10, i;
			struct node *head1 = NULL;
			struct node *head2 = NULL;
			for (i = l1 - 1; i >= 0; i--){
				addNode(&head2, nums[i]);
			}
			for (i = l2 - 1; i >= 0; i--){
				addNode(&head1, nums2[i]);
			}
			make_it_circular(head1);
			make_it_circular(head2);

			int len = merge_circularlists(&head1, &head2);
			int check = is_correct(head1, ans, len + 1);
			Assert::AreEqual(l1 + l2, len, L"Failed for Real in CLL 2", 1, 2);
			Assert::AreEqual(1, check, L"Failed for Real in CLL 2", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_CircularListsMerge12()
		{
			int nums[50] = { 1, 6, 7, 10, 20, 30, 40, 50, 60, 100 };
			int nums2[50] = { 2, 3, 4, 5, 8, 9, 11, 13, 55, 65 };
			//Last 1 is for checking whether A is circular or not .6 should again point to 1
			int ans[100] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 20, 30, 40, 50, 55, 60, 65, 100, 1 };
			int l1 = 10, l2 = 10, i;
			struct node *head1 = NULL;
			struct node *head2 = NULL;
			for (i = l1 - 1; i >= 0; i--){
				addNode(&head2, nums[i]);
			}
			for (i = l2 - 1; i >= 0; i--){
				addNode(&head1, nums2[i]);
			}
			make_it_circular(head1);
			make_it_circular(head2);

			int len = merge_circularlists(&head1, &head2);
			int check = is_correct(head1, ans, len + 1);
			Assert::AreEqual(l1 + l2, len, L"Failed for Real in CLL 2", 1, 2);
			Assert::AreEqual(1, check, L"Failed for Real in CLL 2", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_CircularListsMerge13()
		{
			int nums[50] = { 1, 1, 1, 1, 1, 2, 2, 2, 3, 55 };
			int nums2[50] = { 2, 2, 2, 5, 8, 9, 9, 13, 55, 55 };
			//Last 1 is for checking whether A is circular or not .6 should again point to 1
			int ans[100] = { 1,1,1,1,1,2,2,2,2,2,2,3,5,8,9,9,13,55,55,55,1 };
			int l1 = 10, l2 = 10, i;
			struct node *head1 = NULL;
			struct node *head2 = NULL;
			for (i = l1 - 1; i >= 0; i--){
				addNode(&head2, nums[i]);
			}
			for (i = l2 - 1; i >= 0; i--){
				addNode(&head1, nums2[i]);
			}
			make_it_circular(head1);
			make_it_circular(head2);

			int len = merge_circularlists(&head1, &head2);
			int check = is_correct(head1, ans, len + 1);
			Assert::AreEqual(l1 + l2, len, L"Failed for Real in CLL 2", 1, 2);
			Assert::AreEqual(1, check, L"Failed for Real in CLL 2", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_CircularListsMerge14()
		{
			int nums[50] = { 1, 1, 1, 2, 2, 2, 2, 2, 3, 55 };
			int nums2[50] = { 2, 2, 2, 5, 5, 9, 9, 13, 55, 55 };
			//Last 1 is for checking whether A is circular or not .6 should again point to 1
			int ans[100] = { 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 3, 5, 5, 9, 9, 13, 55, 55, 55, 1 };
			int l1 = 10, l2 = 10, i;
			struct node *head1 = NULL;
			struct node *head2 = NULL;
			for (i = l1 - 1; i >= 0; i--){
				addNode(&head2, nums[i]);
			}
			for (i = l2 - 1; i >= 0; i--){
				addNode(&head1, nums2[i]);
			}
			make_it_circular(head1);
			make_it_circular(head2);

			int len = merge_circularlists(&head1, &head2);
			int check = is_correct(head1, ans, len + 1);
			Assert::AreEqual(l1 + l2, len, L"Failed for Real in CLL 2", 1, 2);
			Assert::AreEqual(1, check, L"Failed for Real in CLL 2", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_CircularListsMerge15()
		{
			int nums[50] = { 1, 1, 1, 1, 1, 2, 2, 2, 3, 55 };
			int nums2[50] = { 2, 2, 2, 5, 8, 9, 9, 13, 55, 55 };
			//Last 1 is for checking whether A is circular or not .6 should again point to 1
			int ans[100] = { 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 5, 8, 9, 9, 13, 55, 55, 55, 1 };
			int l1 = 10, l2 = 10, i;
			struct node *head1 = NULL;
			struct node *head2 = NULL;
			for (i = l1 - 1; i >= 0; i--){
				addNode(&head2, nums[i]);
			}
			for (i = l2 - 1; i >= 0; i--){
				addNode(&head1, nums2[i]);
			}
			make_it_circular(head1);
			make_it_circular(head2);

			int len = merge_circularlists(&head1, &head2);
			int check = is_correct(head1, ans, len + 1);
			Assert::AreEqual(l1 + l2, len, L"Failed for Real in CLL 2", 1, 2);
			Assert::AreEqual(1, check, L"Failed for Real in CLL 2", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_CircularListsMerge16()
		{
			int nums[50] = { 1, 2,3,4,5,6,7,8,9,10};
			int nums2[50] = {11,12,13,14,15,16,17,18,19,20 };
			//Last 1 is for checking whether A is circular or not .6 should again point to 1
			int ans[100] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20, 1 };
			int l1 = 10, l2 = 10, i;
			struct node *head1 = NULL;
			struct node *head2 = NULL;
			for (i = l1 - 1; i >= 0; i--){
				addNode(&head2, nums[i]);
			}
			for (i = l2 - 1; i >= 0; i--){
				addNode(&head1, nums2[i]);
			}
			make_it_circular(head1);
			make_it_circular(head2);

			int len = merge_circularlists(&head1, &head2);
			int check = is_correct(head1, ans, len + 1);
			Assert::AreEqual(l1 + l2, len, L"Failed for Real in CLL 2", 1, 2);
			Assert::AreEqual(1, check, L"Failed for Real in CLL 2", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_CircularListsMerge17()
		{
			int nums[50] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			int nums2[50] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
			//Last 1 is for checking whether A is circular or not .6 should again point to 1
			int ans[100] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 1 };
			int l1 = 10, l2 = 10, i;
			struct node *head1 = NULL;
			struct node *head2 = NULL;
			for (i = l1 - 1; i >= 0; i--){
				addNode(&head1, nums[i]);
			}
			for (i = l2 - 1; i >= 0; i--){
				addNode(&head2, nums2[i]);
			}
			make_it_circular(head1);
			make_it_circular(head2);

			int len = merge_circularlists(&head1, &head2);
			int check = is_correct(head1, ans, len + 1);
			Assert::AreEqual(l1 + l2, len, L"Failed for Real in CLL 2", 1, 2);
			Assert::AreEqual(1, check, L"Failed for Real in CLL 2", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_CircularListsMerge18()
		{
			int nums[50] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			int nums2[50] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			//Last 1 is for checking whether A is circular or not .6 should again point to 1
			int ans[100] = { 1,1,2, 2, 3,3,4, 4, 5,5,6, 6, 7,7,8, 8, 9,9, 10,10, 1 };
			int l1 = 10, l2 = 10, i;
			struct node *head1 = NULL;
			struct node *head2 = NULL;
			for (i = l1 - 1; i >= 0; i--){
				addNode(&head2, nums[i]);
			}
			for (i = l2 - 1; i >= 0; i--){
				addNode(&head1, nums2[i]);
			}
			make_it_circular(head1);
			make_it_circular(head2);

			int len = merge_circularlists(&head1, &head2);
			int check = is_correct(head1, ans, len + 1);
			Assert::AreEqual(l1 + l2, len, L"Failed for Real in CLL 2", 1, 2);
			Assert::AreEqual(1, check, L"Failed for Real in CLL 2", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_CircularListsMerge19()
		{
			int nums[50] = { 1, 1, 1, 1, 5, 6, 7, 8, 9, 10 };
			int nums2[50] = { 1, 1, 1, 1, 1, 6, 7, 8, 9, 10 };
			//Last 1 is for checking whether A is circular or not .6 should again point to 1
			int ans[100] = { 1, 1,1,1,1,1,1,1,1, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 1 };
			int l1 = 10, l2 = 10, i;
			struct node *head1 = NULL;
			struct node *head2 = NULL;
			for (i = l1 - 1; i >= 0; i--){
				addNode(&head2, nums[i]);
			}
			for (i = l2 - 1; i >= 0; i--){
				addNode(&head1, nums2[i]);
			}
			make_it_circular(head1);
			make_it_circular(head2);

			int len = merge_circularlists(&head1, &head2);
			int check = is_correct(head1, ans, len + 1);
			Assert::AreEqual(l1 + l2, len, L"Failed for Real in CLL 2", 1, 2);
			Assert::AreEqual(1, check, L"Failed for Real in CLL 2", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_CircularListsMerge20()
		{
			const int l1 = 1000, l2 = 2000;
			int i;
			int nums[l1];
			int nums2[l2];
			int ans[l1 + l2 + 1];
			int odd = 1, even = 2;
			for (i = 0; i < l1; i++){
				nums[i] = odd;
				odd += 2;
			}
			for (i = 0; i < l2; i++){
				nums2[i] = even;
				even += 2;
			}
			odd = 1; even = 2;
			for (i = 0; i < l1; i++){
				ans[i] = nums[i];
			}
			int k = 0;
			for (; k < l2; ){
				ans[i] = nums2[k];
				i++;
				k++;
			}
			mrnd_sort(ans, l1 + l2);
			ans[l1 + l2] = 1;
			
			struct node *head1 = NULL;
			struct node *head2 = NULL;
			for (i = l1 - 1; i >= 0; i--){
				addNode(&head2, nums[i]);
			}
			for (i = l2 - 1; i >= 0; i--){
				addNode(&head1, nums2[i]);
			}
			make_it_circular(head1);
			make_it_circular(head2);

			int len = merge_circularlists(&head1, &head2);
			int check = is_correct(head1, ans, len + 1);
			Assert::AreEqual(l1 + l2, len, L"Failed for Real in CLL 2", 1, 2);
			//Assert::AreEqual(2, ans[0], L"Failed for Real in CLL 2", 1, 2);
			Assert::AreEqual(1, check, L"Failed for Real in CLL 2", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_CircularListsMerge21()
		{
			const int l1 = 1000, l2 = 2000;
			int i;
			int nums[l1];
			int nums2[l2];
			int ans[l1 + l2 + 1];
			int odd = 1, even = 2;
			for (i = 0; i < l1; i++){
				nums[i] = odd;
				odd += 2;
			}
			for (i = 0; i < l2; i++){
				nums2[i] = even;
				even += 2;
			}
			odd = 1; even = 2;
			for (i = 0; i < l1; i++){
				ans[i] = nums[i];
			}
			int k = 0;
			for (; k < l2;){
				ans[i] = nums2[k];
				i++;
				k++;
			}
			mrnd_sort(ans, l1 + l2);
			ans[l1 + l2] = 1;

			struct node *head1 = NULL;
			struct node *head2 = NULL;
			for (i = l1 - 1; i >= 0; i--){
				addNode(&head1, nums[i]);
			}
			for (i = l2 - 1; i >= 0; i--){
				addNode(&head2, nums2[i]);
			}
			make_it_circular(head1);
			make_it_circular(head2);

			int len = merge_circularlists(&head1, &head2);
			int check = is_correct(head1, ans, len + 1);
			Assert::AreEqual(l1 + l2, len, L"Failed for Real in CLL 2", 1, 2);
			//Assert::AreEqual(2, ans[0], L"Failed for Real in CLL 2", 1, 2);
			Assert::AreEqual(1, check, L"Failed for Real in CLL 2", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_CircularListsMerge22()
		{
			const int l1 = 1000, l2 = 2000;
			int i;
			int nums[l1];
			int nums2[l2];
			int ans[l1 + l2 + 1];
			int odd = 1, even = 2;
			for (i = 0; i < l1; i++){
				nums[i] = 1;
			}
			for (i = 0; i < l2; i++){
				nums2[i] = 2;
			}
			odd = 1; even = 2;
			for (i = 0; i < l1; i++){
				ans[i] = nums[i];
			}
			int k = 0;
			for (; k < l2;){
				ans[i] = nums2[k];
				i++;
				k++;
			}
			mrnd_sort(ans, l1 + l2);
			ans[l1 + l2] = 1;

			struct node *head1 = NULL;
			struct node *head2 = NULL;
			for (i = l1 - 1; i >= 0; i--){
				addNode(&head2, nums[i]);
			}
			for (i = l2 - 1; i >= 0; i--){
				addNode(&head1, nums2[i]);
			}
			make_it_circular(head1);
			make_it_circular(head2);

			int len = merge_circularlists(&head1, &head2);
			int check = is_correct(head1, ans, len + 1);
			Assert::AreEqual(l1 + l2, len, L"Failed for Real in CLL 2", 1, 2);
			//Assert::AreEqual(2, ans[0], L"Failed for Real in CLL 2", 1, 2);
			Assert::AreEqual(1, check, L"Failed for Real in CLL 2", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_CircularListsMerge23()
		{
			const int l1 = 1000, l2 = 2000;
			int i;
			int nums[l1];
			int nums2[l2];
			int ans[l1 + l2 + 1];
			int odd = 1, even = 2;
			for (i = 0; i < l1; i++){
				nums[i] = odd;
				odd += 3;
			}
			for (i = 0; i < l2; i++){
				nums2[i] = even;
				even += 6;
			}
			odd = 1; even = 2;
			for (i = 0; i < l1; i++){
				ans[i] = nums[i];
			}
			int k = 0;
			for (; k < l2;){
				ans[i] = nums2[k];
				i++;
				k++;
			}
			mrnd_sort(ans, l1 + l2);
			ans[l1 + l2] = 1;

			struct node *head1 = NULL;
			struct node *head2 = NULL;
			for (i = l1 - 1; i >= 0; i--){
				addNode(&head2, nums[i]);
			}
			for (i = l2 - 1; i >= 0; i--){
				addNode(&head1, nums2[i]);
			}
			make_it_circular(head1);
			make_it_circular(head2);

			int len = merge_circularlists(&head1, &head2);
			int check = is_correct(head1, ans, len + 1);
			Assert::AreEqual(l1 + l2, len, L"Failed for Real in CLL 2", 1, 2);
			//Assert::AreEqual(2, ans[0], L"Failed for Real in CLL 2", 1, 2);
			Assert::AreEqual(1, check, L"Failed for Real in CLL 2", 1, 2);
		};
	};
}
