#include "stdafx.h";
#include <stdlib.h>;
#include "./../src/OddEven.cpp";

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class OddEvenSpec
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

		struct oddevennode * createNode(int num) {
			struct oddevennode *newNode = (struct oddevennode *)malloc(sizeof(struct oddevennode));
			newNode->data = num;
			newNode->next = NULL;
			newNode->random = NULL;
			return newNode;
		}

		void addNode(struct oddevennode **head, int data){
			struct oddevennode * cur = createNode(data);
			if (*head == NULL){
				*head = cur;
			}
			else{
				struct oddevennode *temp = *head;
				cur->next = temp;
				*head = cur;
			}
		}

		int is_correct(struct oddevennode *head, int *arr, int len){
			int i = 0;
			while (head != NULL){
				int data = head->data;
				if (arr[i] != data){
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

		int compare_arrays(int *arr, int *arr2, int len){
			if (arr == NULL && arr2==NULL){
				return 0;
			}
			int i = 0;
			for (i = 0; i < len; i++){
				if (arr[i] != arr2[i]){
					return 0;
				}
			}
			return 1;
		}
		
		int * toArray(struct oddevennode *head, int len){
			int * res = (int *)malloc(len *(sizeof(struct oddevennode)));
			int i = 0;
			while (i < len){
				if (head == NULL){
					return NULL;
				}
				res[i] = head->data;
				
				head = head->random;
				if (i != len-1){
					if (head == NULL){
						return NULL;
					}
				}
				i++;
			}
			if (head != NULL){
				return NULL;
			}
			return res;
		}
		[TestMethod, Timeout(1000)]
		void Sample1_OddEvenSLL()
		{
			struct oddevennode *head = NULL;
			int *res = oddeven_sll(head);
			int check = 0;
			if (res == NULL){
				check = 1;
			}
			Assert::AreEqual(1, check, L"Failed sample 0 for NULL case in LL", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Sample2_OddEvenSLL()
		{
			struct oddevennode *head = NULL;
			int nums[20] = { 10,3,6,5,8,1,3 };
			int odds_expected[20] = { 3, 5, 1,3 };
			int evens_expected[20] = { 10, 6, 8 };
			int ans[2] = { 4, 3 };
			int check = 0, check2 = 0, check3 = 0;
			
			int totallen = ans[0] + ans[1];
			for (int i = totallen - 1; i >= 0; i--){
				addNode(&head, nums[i]);
			}
			int *res = oddeven_sll(head);
			if (res == NULL){
				check = 1;
			}


			struct oddevennode *oddnode = (head->next);
			struct oddevennode *evennode = head;
			
			check = compare_arrays(res, ans,2);
			int * odd_arr_actual=toArray(oddnode,res[0]);
			int	* evens_arr_actual = toArray(evennode,res[1]);
			check2=compare_arrays(odd_arr_actual, odds_expected,res[0]);
			check3=compare_arrays(evens_arr_actual, evens_expected, res[1]);
			
			Assert::AreEqual(1, check, L"Failed sample 2 for in ODDEVEN", 1, 2);
			Assert::AreEqual(1, check2, L"Failed sample 2 for in ODDEVEN", 1, 2);
			Assert::AreEqual(1, check3, L"Failed sample 2 for in ODDEVEN", 1, 2);
		};
		

		//Real Test Cases
		
		struct oddevennode * getOddnode_spec123(struct oddevennode * head){
			while (head != NULL){
				int rem = ((head->data) % 2);
				if (rem==1 || rem==-1){
					return head;
				}
				head = head->next;
			}
			return NULL;
		}
		struct oddevennode * getEvennode_spec123(struct oddevennode * head){
			while (head != NULL){
				if (((head->data) % 2) == 0){
					return head;
				}
				head = head->next;
			}
			return NULL;
		}

		void testOddEven_spec123(int *nums,int* odds_expected,int * evens_expected,int oc,int ec){
			
			
			struct oddevennode *head = NULL;
			int ans[2] = {oc,ec };
			int check = 0, check2 = 0, check3 = 0;

			int totallen = ans[0] + ans[1];
			for (int i = totallen - 1; i >= 0; i--){
				addNode(&head, nums[i]);
			}
			int *res = oddeven_sll(head);
			if (res == NULL){
				check = 1;
			}


			struct oddevennode *oddnode = getOddnode_spec123(head);
			struct oddevennode *evennode = getEvennode_spec123(head);

			check = compare_arrays(res, ans, 2);
			int * odd_arr_actual = toArray(oddnode, res[0]);
			int	* evens_arr_actual = toArray(evennode, res[1]);
			check2 = compare_arrays(odd_arr_actual, odds_expected, res[0]);
			check3 = compare_arrays(evens_arr_actual, evens_expected, res[1]);

			Assert::AreEqual(1, check, L"Real Failed for in ODDEVEN", 1, 2);
			Assert::AreEqual(1, check2, L"Real Failed for in ODDEVEN", 1, 2);
			Assert::AreEqual(1, check3, L"Real Failed for in ODDEVEN", 1, 2);
			
		}
		
		[TestMethod, Timeout(1000)]
		void Real1_OddEvenSLL(){
			int nums[20] = { 10, 3, 6, 5, 8, 1, 3 };
			int odds_expected[20] = { 3, 5, 1, 3 };
			int evens_expected[20] = { 10, 6, 8 };
			testOddEven_spec123(nums, odds_expected, evens_expected, 4, 3);

		}
		[TestMethod, Timeout(1000)]
		void Real2_OddEvenSLL(){
			int nums[20] = { 1,3,5,7,8,10 };
			int odds_expected[20] = { 1,3,5,7 };
			int evens_expected[20] = { 8,10 };
			testOddEven_spec123(nums, odds_expected, evens_expected, 4, 2);

		}
		[TestMethod, Timeout(1000)]
		void Real3_OddEvenSLL(){
			int nums[20] = { 1, 3, 5, 7, 8, 10 };
			int odds_expected[20] = { 1, 3, 5, 7 };
			int evens_expected[20] = { 8, 10 };
			testOddEven_spec123(nums, odds_expected, evens_expected, 4, 2);

		}
		[TestMethod, Timeout(1000)]
		void Real4_OddEvenSLL(){
			int nums[20] = { 1, 3, 5, 7 };
			int odds_expected[20] = { 1, 3, 5, 7 };
			int *evens_expected = NULL;
			testOddEven_spec123(nums, odds_expected, evens_expected, 4, 0);

		}
		[TestMethod, Timeout(1000)]
		void Real5_OddEvenSLL(){
			int nums[20] = { 7, 7,1, 7 };
			int odds_expected[20] = { 7, 7, 1, 7 };
			int *evens_expected = NULL;
			testOddEven_spec123(nums, odds_expected, evens_expected, 4, 0);

		}
		[TestMethod, Timeout(1000)]
		void Real6_OddEvenSLL(){
			const int len = 200000;
			int *nums = (int *)malloc(sizeof(int)*len);
			int *odds_expected = (int *)malloc(sizeof(int)*len);
			for (int i = 0; i < len; i++){
				nums[i] = 1;
				odds_expected[i] = 1;
			}
			int *evens_expected = NULL;
			testOddEven_spec123(nums, odds_expected, evens_expected, len, 0);

		}
		[TestMethod, Timeout(1000)]
		void Real7_OddEvenSLL(){
			const int len = 200000;
			int *nums = (int *)malloc(sizeof(int)*len);
			int *odds_expected = (int *)malloc(sizeof(int)*len);
			for (int i = 0; i < len; i++){
				nums[i] = 1;
				odds_expected[i] = 1;
			}
			int *evens_expected = NULL;
			testOddEven_spec123(nums, odds_expected, evens_expected, len, 0);

		}
		
		[TestMethod, Timeout(1000)]
		void Real8_OddEvenSLL(){
			const int len = 200000;
			int *nums = (int *)malloc(sizeof(int)*len);
			int *evens_expected = (int *)malloc(sizeof(int)*len);
			for (int i = 0; i < len; i++){
				nums[i] = 2;
				evens_expected[i] = 2;
			}
			int *odds_expected = NULL;
			testOddEven_spec123(nums, odds_expected, evens_expected, 0,len);

		}
		[TestMethod, Timeout(1000)]
		void Real9_OddEvenSLL(){
			const int len = 200000;
			int *nums = (int *)malloc(sizeof(int)*len);
			int *evens_expected = (int *)malloc(sizeof(int)*len);
			for (int i = 0; i < len; i++){
				nums[i] = 2;
				evens_expected[i] = 2;
			}
			int *odds_expected = NULL;
			testOddEven_spec123(nums, odds_expected, evens_expected, 0, len);

		}
		[TestMethod, Timeout(1000)]
		void Real10_OddEvenSLL(){
			int nums[20] = { -1, -3, -5, -7, -8, -10 };
			int odds_expected[20] = { -1, -3, -5, -7 };
			int evens_expected[20] = { -8, -10 };
			testOddEven_spec123(nums, odds_expected, evens_expected, 4, 2);
		}
		[TestMethod, Timeout(1000)]
		void Real11_OddEvenSLL(){
			int nums[20] = { -80, -10, 1, 30, -13, -7 };
			int odds_expected[20] = { 1, -13, -7 };
			int evens_expected[20] = { -80, -10,30 };
			testOddEven_spec123(nums, odds_expected, evens_expected, 3,3);
		}
		[TestMethod, Timeout(1000)]
		void Real12_OddEvenSLL(){
			int nums[20] = { -1, -3, -5, -7, -8, -10 };
			int odds_expected[20] = { -1, -3, -5, -7 };
			int evens_expected[20] = { -8, -10 };
			testOddEven_spec123(nums, odds_expected, evens_expected, 4, 2);
		}
		[TestMethod, Timeout(1000)]
		void Real13_OddEvenSLL(){
			int nums[20] = { -80, -10, 1, 30, -13, -7 };
			int odds_expected[20] = { 1, -13, -7 };
			int evens_expected[20] = { -80, -10, 30 };
			testOddEven_spec123(nums, odds_expected, evens_expected, 3, 3);
		}
		[TestMethod, Timeout(1000)]
		void Real14_OddEvenSLL(){
			int nums[20] = {0,0,0,0,0,0,0,0,0,0 };
			int *odds_expected = NULL;
			int evens_expected[20] = { 0,0,0,0,0,0,0,0,0,0 };
			testOddEven_spec123(nums, odds_expected, evens_expected, 0, 10);
		}
		[TestMethod, Timeout(1000)]
		void Real15_OddEvenSLL(){
			int nums[20] = { 999, 999, 999, 999, 999, 999, 999, 999, 999,999 };
			int odds_expected[20] = { 999, 999, 999, 999, 999, 999, 999, 999, 999, 999 };
			int *evens_expected = NULL;
			testOddEven_spec123(nums, odds_expected, evens_expected, 10, 0);
		}


		[TestMethod, Timeout(200)]
		void Real16_OddEvenSLL(){
			const int len = 10;
			int *nums = (int *)malloc(sizeof(int)*(2*len));
			int *evens_expected = (int *)malloc(sizeof(int)*len);
			int *odds_expected = (int *)malloc(sizeof(int)*len);
			int oddstart = -99999;
			int evenstart = -99998;
			int oi = 0;
			int ei = 0;
			for (int i = 0; i < (2*len); i++){
				if (i % 2 == 0){
					nums[i] = oddstart;
					odds_expected[oi] = oddstart;
					oddstart += 2;
					oi++;
				}
				else{
					nums[i] = evenstart;
					evens_expected[ei] = evenstart;
					evenstart += 2;
					ei++;
				}
			}
			
			testOddEven_spec123(nums, odds_expected, evens_expected, len, len);

		}
		[TestMethod, Timeout(200)]
		void Real17_OddEvenSLL(){
			const int len = 1000;
			int *nums = (int *)malloc(sizeof(int)*(2 * len));
			int *evens_expected = (int *)malloc(sizeof(int)*len);
			int *odds_expected = (int *)malloc(sizeof(int)*len);
			int oddstart = -99999;
			int evenstart = -99998;
			int oi = 0;
			int ei = 0;
			for (int i = 0; i < (2 * len); i++){
				if (i % 2 == 0){
					nums[i] = oddstart;
					odds_expected[oi] = oddstart;
					oddstart += 2;
					oi++;
				}
				else{
					nums[i] = evenstart;
					evens_expected[ei] = evenstart;
					evenstart += 2;
					ei++;
				}
			}

			testOddEven_spec123(nums, odds_expected, evens_expected, len, len);

		}
		[TestMethod, Timeout(200)]
		void Real18_OddEvenSLL(){
			const int len = 2000;
			int *nums = (int *)malloc(sizeof(int)*(2 * len));
			int *evens_expected = (int *)malloc(sizeof(int)*len);
			int *odds_expected = (int *)malloc(sizeof(int)*len);
			int oddstart = -99999;
			int evenstart = -99998;
			int oi = 0;
			int ei = 0;
			for (int i = 0; i < (2 * len); i++){
				if (i % 2 == 0){
					nums[i] = oddstart;
					odds_expected[oi] = oddstart;
					oddstart += 2;
					oi++;
				}
				else{
					nums[i] = evenstart;
					evens_expected[ei] = evenstart;
					evenstart += 2;
					ei++;
				}
			}

			testOddEven_spec123(nums, odds_expected, evens_expected, len, len);

		}
		[TestMethod, Timeout(200)]
		void Real19_OddEvenSLL(){
			const int len = 2000;
			int *nums = (int *)malloc(sizeof(int)*(2 * len));
			int *evens_expected = (int *)malloc(sizeof(int)*len);
			int *odds_expected = (int *)malloc(sizeof(int)*len);
			int oddstart = -99999;
			int evenstart = -99998;
			int oi = 0;
			int ei = 0;
			for (int i = 0; i < (2 * len); i++){
				if (i % 2 == 0){
					nums[i] = oddstart;
					odds_expected[oi] = oddstart;
					oddstart += 2;
					oi++;
				}
				else{
					nums[i] = evenstart;
					evens_expected[ei] = evenstart;
					evenstart += 2;
					ei++;
				}
			}

			testOddEven_spec123(nums, odds_expected, evens_expected, len, len);

		}
		[TestMethod, Timeout(1000)]
		void Real20_OddEvenSLL(){
			int nums[20] = { -1 };
			int odds_expected[20] = { -1};
			int *evens_expected = NULL;
			testOddEven_spec123(nums, odds_expected, evens_expected, 1, 0);
		}
		[TestMethod, Timeout(1000)]
		void Real21_OddEvenSLL(){
			int nums[20] = { 2 };
			int *odds_expected =NULL;
			int evens_expected[10] = { 2 };
			testOddEven_spec123(nums, odds_expected, evens_expected, 0, 1);
		}
		[TestMethod, Timeout(300)]
		void Real22_OddEvenSLL(){
			const int len = 2000;
			int *nums = (int *)malloc(sizeof(int)*(2 * len));
			int *evens_expected = (int *)malloc(sizeof(int)*len);
			int *odds_expected = (int *)malloc(sizeof(int)*len);
			int oddstart = -99999;
			int evenstart = -99998;
			int oi = 0;
			int ei = 0;
			for (int i = 0; i < (2 * len); i++){
				if (i % 2 == 0){
					nums[i] = oddstart;
					odds_expected[oi] = oddstart;
					oddstart += 2;
					oi++;
				}
				else{
					nums[i] = evenstart;
					evens_expected[ei] = evenstart;
					evenstart += 2;
					ei++;
				}
			}

			testOddEven_spec123(nums, odds_expected, evens_expected, len, len);

		}
		[TestMethod, Timeout(300)]
		void Real23_OddEvenSLL(){
			const int len = 2000;
			int *nums = (int *)malloc(sizeof(int)*(2 * len));
			int *evens_expected = (int *)malloc(sizeof(int)*len);
			int *odds_expected = (int *)malloc(sizeof(int)*len);
			int oddstart = -99999;
			int evenstart = -99998;
			int oi = 0;
			int ei = 0;
			for (int i = 0; i < (2 * len); i++){
				if (i % 2 == 0){
					nums[i] = oddstart;
					odds_expected[oi] = oddstart;
					oddstart += 2;
					oi++;
				}
				else{
					nums[i] = evenstart;
					evens_expected[ei] = evenstart;
					evenstart += 2;
					ei++;
				}
			}

			testOddEven_spec123(nums, odds_expected, evens_expected, len, len);

		}
		
	};
}