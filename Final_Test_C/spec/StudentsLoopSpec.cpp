#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "../src/StudentsLoop.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class StudentsLoopSpec
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
		struct loopnode * createStudentNode(int roll)	{
			struct loopnode *new_node = (struct loopnode*)malloc(sizeof(struct loopnode));
			new_node->roll = roll;
			new_node->next = NULL;
			return new_node;
		}

		struct loopnode * createListFromArray(int * nums, int len, int loopIndex) {
			struct loopnode* headnode = createStudentNode(nums[0]);
			struct loopnode* curNode = headnode;
			struct loopnode* loopnodeTemp;
			if (loopIndex == 0){
				loopnodeTemp = headnode;
			}
			int i = 1;
			while (i<len){
				curNode->next = createStudentNode(nums[i]);
				curNode = curNode->next;
				if (i == loopIndex) {
					loopnodeTemp = curNode;
				}
				i++;
			}
			curNode->next = NULL;
			if (loopIndex != -1) {
				curNode->next = loopnodeTemp;
			}
			return headnode;
		}

		void validateLoop(struct loopnode* expected, struct loopnode* actual, int n) {
			int i = 0;
			if (expected != NULL) {
				if (actual == NULL) {
					Assert::AreEqual(1, 2, L"Fail", 1, 2);
				}
				else {
					int i = 0;
					//Loop n times
					while (i<n) {
						int val1 = expected->roll;
						int val2 = actual->roll;
						if (val1 != val2) {
							Assert::AreEqual(1, 2, L"Fail", 1, 2);
						}
						i++;
						expected = expected->next;
						actual = actual->next;
						if (actual == NULL) {
							Assert::AreEqual(1, 2, L"Fail", 1, 2);
						}
					}

				}

			}
			else {
				if (actual != NULL) {
					Assert::AreEqual(1, 2, L"Fail", 1, 2);
				}
			}
		}

		void validateNonLoop(struct loopnode* expected, struct loopnode* actual) {
			int i = 0;
			if (expected != NULL) {
				if (actual == NULL) {
					Assert::AreEqual(1, 2, L"Fail", 1, 2);
				}
				else {
					while (expected != NULL) {
						int val1 = expected->roll;
						int val2 = actual->roll;
						if (val1 != val2) {
							Assert::AreEqual(1, 2, L"Fail", 1, 2);
						}
						expected = expected->next;
						actual = actual->next;
						if (actual == NULL && expected != NULL) {
							Assert::AreEqual(1, 2, L"Fail", 1, 2);
						}

					}

				}

			}
			else {
				if (actual != NULL) {
					Assert::AreEqual(1,2, L"Fail", 1, 2);
				}
			}
		}

		[TestMethod, Timeout(1000)]
		void StudentsLoop_Samples()
		{
			int nums[5] = { 10, 20, 5, 3, 1 };
			struct loopnode* head = createListFromArray(nums, 5, 1);
			struct loopnode* headcopy = createListFromArray(nums, 5, 1);
			char* str = storeFormation(headcopy);
			struct loopnode* actualhead = createFormation(str);
			validateLoop(head, actualhead, 10);
		};
		
		[TestMethod, Timeout(1000)]
		void StudentsLoop_Test01()
		{
			int nums[50];
			for (int i = 0; i < 50; i++) nums[i] = i;
			struct loopnode* head = createListFromArray(nums, 50, 1);
			struct loopnode* headcopy = createListFromArray(nums, 50, 1);
			char* str = storeFormation(headcopy);
			struct loopnode* actualhead = createFormation(str);

			validateLoop(head, headcopy, 500);  //test modification of original list
			validateLoop(head, actualhead, 500);
		};

		[TestMethod, Timeout(1000)]
		void StudentsLoop_Test02()
		{
			int nums[50];
			for (int i = 0; i < 50; i++) nums[i] = i;
			struct loopnode* head = createListFromArray(nums, 50, -1);
			struct loopnode* headcopy = createListFromArray(nums, 50, -1);
			char* str = storeFormation(headcopy);
			struct loopnode* actualhead = createFormation(str);

			validateNonLoop(head, headcopy);  //test modification of original list
			validateNonLoop(head, actualhead);
		};

		[TestMethod, Timeout(1000)]
		void StudentsLoop_Test03()
		{
			int nums[50];
			for (int i = 0; i < 50; i++) nums[i] = i;
			struct loopnode* head = createListFromArray(nums, 50, -1);
			struct loopnode* headcopy = createListFromArray(nums, 50, -1);
			char* str = storeFormation(headcopy);
			struct loopnode* actualhead = createFormation(str);

			validateNonLoop(head, headcopy);  //test modification of original list
			validateNonLoop(head, actualhead);
		};

		[TestMethod, Timeout(1000)]
		void StudentsLoop_Test04()
		{
			const int size = 1000;
			int nums[size];
			for (int i = 0; i < size; i++) nums[i] = i;
			struct loopnode* head = createListFromArray(nums, size, -1);
			struct loopnode* headcopy = createListFromArray(nums, size, - 1);
			char* str = storeFormation(headcopy);
			struct loopnode* actualhead = createFormation(str);

			validateNonLoop(head, headcopy);  //test modification of original list

			validateNonLoop(head, actualhead);
		};

		[TestMethod, Timeout(1000)]
		void StudentsLoop_Test05()
		{
			const int size = 1000;
			int nums[size];
			for (int i = 0; i < size; i++) nums[i] =1;
			struct loopnode* head = createListFromArray(nums, size, 1);
			struct loopnode* headcopy = createListFromArray(nums, size,1 );
			char* str = storeFormation(headcopy);
			struct loopnode* actualhead = createFormation(str);

			validateLoop(head, headcopy, size*size);  //test modification of original list
			validateLoop(head, actualhead,size*size);
		};

		[TestMethod, Timeout(1000)]
		void StudentsLoop_Test06()
		{
			const int size = 1000;
			int nums[size];
			for (int i = 0; i < size; i++) nums[i] = i+50;
			struct loopnode* head = createListFromArray(nums, size, 1);
			struct loopnode* headcopy = createListFromArray(nums, size, 1);
			char* str = storeFormation(headcopy);
			struct loopnode* actualhead = createFormation(str);

			validateLoop(head, headcopy, size*size);  //test modification of original list
			validateLoop(head, actualhead, size*size);
		};


		[TestMethod, Timeout(1000)]
		void StudentsLoop_Test07()
		{
			const int size = 1;
			int nums[size] = { 1 };

			struct loopnode* head = createListFromArray(nums, size,0);
			struct loopnode* headcopy = createListFromArray(nums, size, 0);
			char* str = storeFormation(headcopy);
			struct loopnode* actualhead = createFormation(str);

			validateLoop(head, headcopy, size*size);  //test modification of original list
			validateLoop(head, actualhead,200);
		};

		[TestMethod, Timeout(1000)]
		void StudentsLoop_Test08()
		{
			const int size = 1;
			int nums[size] = { 1 };

			struct loopnode* head = createListFromArray(nums, size, -1);
			struct loopnode* headcopy = createListFromArray(nums, size, -1);
			char* str = storeFormation(headcopy);
			struct loopnode* actualhead = createFormation(str);
			validateNonLoop(head, headcopy);  //test modification of original list
			validateNonLoop(head, actualhead);
		};

		[TestMethod, Timeout(1000)]
		void StudentsLoop_Test09()
		{
			const int size = 1;
			int nums[size] = { 10 };

			struct loopnode* head = NULL;
			struct loopnode* headcopy = NULL;
			char* str = storeFormation(headcopy);
			struct loopnode* actualhead = createFormation(str);
			validateNonLoop(head, headcopy);  //test modification of original list
			validateNonLoop(head, actualhead);
		};

		//50% of marks without sequences or duplicates
		//From now on, tests contains sequences and duplicates too.
		
		[TestMethod, Timeout(1000)]
		void StudentsLoop_Test10()
		{
			const int size = 100;
			int nums1[size],nums2[size],nums3[size],nums4[size];
			for (int i = 0; i < size; i++) {
				nums1[i] = i + 50;
				nums2[i] = i + 25;
				nums3[i] = i + 75;
				nums4[i] = i + 500;
			}
			struct loopnode* h1 = createListFromArray(nums1, size, -1);
			struct loopnode* h1c = createListFromArray(nums1, size, -1);
			
			struct loopnode* h2 = createListFromArray(nums2, size, -1);
			struct loopnode* h2c = createListFromArray(nums2, size, -1);
	
			struct loopnode* h3 = createListFromArray(nums3, size, -1);
			struct loopnode* h3c = createListFromArray(nums3, size, -1);
			
			struct loopnode* h4 = createListFromArray(nums4, size, -1);
			struct loopnode* h4c = createListFromArray(nums4, size, -1);

			char* str1 = storeFormation(h1c);
			char* str2 = storeFormation(h2c);
			char* str3 = storeFormation(h3c);
			char* str4 = storeFormation(h4c);

			for (int i = 0; i < 100; i++){
				struct loopnode* a1 = createFormation(str1);
				validateNonLoop(h1, a1);  //test modification of original list
				validateNonLoop(h1, h1c);

				struct loopnode* a3 = createFormation(str3);
				validateNonLoop(h3, a3);  //test modification of original list
				validateNonLoop(h3, h3c);

				struct loopnode* a2 = createFormation(str2);
				validateNonLoop(h2, a2);  //test modification of original list
				validateNonLoop(h2, h2c);


				struct loopnode* a4 = createFormation(str4);
				validateNonLoop(h4, a4);  //test modification of original list
				validateNonLoop(h4, h4c);
			}
		};
		
		[TestMethod, Timeout(1000)]
		void StudentsLoop_Test11()
		{
			const int size = 100;
			int nums1[size], nums2[size], nums3[size], nums4[size];
			for (int i = 0; i < size; i++) {
				nums1[i] = i - 50;
				nums2[i] = i - 25;
				nums3[i] = i - 75;
				nums4[i] = i - 500;
			}
			struct loopnode* h1 = createListFromArray(nums1, size, -1);
			struct loopnode* h1c = createListFromArray(nums1, size, -1);

			struct loopnode* h2 = createListFromArray(nums2, size, -1);
			struct loopnode* h2c = createListFromArray(nums2, size, -1);

			struct loopnode* h3 = createListFromArray(nums3, size, -1);
			struct loopnode* h3c = createListFromArray(nums3, size, -1);

			struct loopnode* h4 = createListFromArray(nums4, size, -1);
			struct loopnode* h4c = createListFromArray(nums4, size, -1);

			char* str1 = storeFormation(h1c);
			char* str2 = storeFormation(h2c);
			char* str3 = storeFormation(h3c);
			char* str4 = storeFormation(h4c);

			for (int i = 0; i < 100; i++){
				struct loopnode* a1 = createFormation(str1);
				validateNonLoop(h1, a1);  //test modification of original list
				validateNonLoop(h1, h1c);

				struct loopnode* a3 = createFormation(str3);
				validateNonLoop(h3, a3);  //test modification of original list
				validateNonLoop(h3, h3c);

				struct loopnode* a2 = createFormation(str2);
				validateNonLoop(h2, a2);  //test modification of original list
				validateNonLoop(h2, h2c);
				
				a2 = createFormation(str2);
				validateNonLoop(h2, a2);  //test modification of original list
				validateNonLoop(h2, h2c);

				struct loopnode* a4 = createFormation(str4);
				validateNonLoop(h4, a4);  //test modification of original list
				validateNonLoop(h4, h4c);

				a3 = createFormation(str3);
				validateNonLoop(h3, a3);  //test modification of original list
				validateNonLoop(h3, h3c);
			}
		};

		[TestMethod, Timeout(1000)]  //BIG NUMBERS
		void StudentsLoop_Test12()
		{
			const int size = 100;
			int nums1[size], nums2[size], nums3[size], nums4[size];
			for (int i = 0; i < size; i++) {
				nums1[i] = i + 50000;
				nums2[i] = i + 20000;
				nums3[i] = i + 765465460;
				nums4[i] = i + 5000000;
			}
			struct loopnode* h1 = createListFromArray(nums1, size, -1);
			struct loopnode* h1c = createListFromArray(nums1, size, -1);

			struct loopnode* h2 = createListFromArray(nums2, size, -1);
			struct loopnode* h2c = createListFromArray(nums2, size, -1);

			struct loopnode* h3 = createListFromArray(nums3, size, -1);
			struct loopnode* h3c = createListFromArray(nums3, size, -1);

			struct loopnode* h4 = createListFromArray(nums4, size, -1);
			struct loopnode* h4c = createListFromArray(nums4, size, -1);

			char* str1 = storeFormation(h1c);
			char* str2 = storeFormation(h2c);
			char* str3 = storeFormation(h3c);
			char* str4 = storeFormation(h4c);

			for (int i = 0; i < 100; i++){
				struct loopnode* a1 = createFormation(str1);
				validateNonLoop(h1, a1);  //test modification of original list
				validateNonLoop(h1, h1c);

				struct loopnode* a3 = createFormation(str3);
				validateNonLoop(h3, a3);  //test modification of original list
				validateNonLoop(h3, h3c);

				a3 = createFormation(str3);
				validateNonLoop(h3, a3);  //test modification of original list
				validateNonLoop(h3, h3c);


				struct loopnode* a2 = createFormation(str2);
				validateNonLoop(h2, a2);  //test modification of original list
				validateNonLoop(h2, h2c);


				struct loopnode* a4 = createFormation(str4);
				validateNonLoop(h4, a4);  //test modification of original list
				validateNonLoop(h4, h4c);
				
				a4 = createFormation(str4);
				validateNonLoop(h4, a4);  //test modification of original list
				validateNonLoop(h4, h4c);
			}
		};

		[TestMethod, Timeout(1000)]  //BIG NEGATIVES NUMBERS
		void StudentsLoop_Test13()
		{
			const int size = 100;
			int nums1[size], nums2[size], nums3[size], nums4[size];
			for (int i = 0; i < size; i++) {
				nums1[i] = i - 50000;
				nums2[i] = i - 20000;
				nums3[i] = i - 765465460;
				nums4[i] = i - 5000000;
			}
			struct loopnode* h1 = createListFromArray(nums1, size, -1);
			struct loopnode* h1c = createListFromArray(nums1, size, -1);

			struct loopnode* h2 = createListFromArray(nums2, size, -1);
			struct loopnode* h2c = createListFromArray(nums2, size, -1);

			struct loopnode* h3 = createListFromArray(nums3, size, -1);
			struct loopnode* h3c = createListFromArray(nums3, size, -1);

			struct loopnode* h4 = createListFromArray(nums4, size, -1);
			struct loopnode* h4c = createListFromArray(nums4, size, -1);

			char* str1 = storeFormation(h1c);
			char* str2 = storeFormation(h2c);
			char* str3 = storeFormation(h3c);
			char* str4 = storeFormation(h4c);

			for (int i = 0; i < 100; i++){
				struct loopnode* a1 = createFormation(str1);
				validateNonLoop(h1, a1);  //test modification of original list
				validateNonLoop(h1, h1c);

				struct loopnode* a3 = createFormation(str3);
				validateNonLoop(h3, a3);  //test modification of original list
				validateNonLoop(h3, h3c);

				a3 = createFormation(str3);
				validateNonLoop(h3, a3);  //test modification of original list
				validateNonLoop(h3, h3c);


				struct loopnode* a2 = createFormation(str2);
				validateNonLoop(h2, a2);  //test modification of original list
				validateNonLoop(h2, h2c);


				struct loopnode* a4 = createFormation(str4);
				validateNonLoop(h4, a4);  //test modification of original list
				validateNonLoop(h4, h4c);

				a4 = createFormation(str4);
				validateNonLoop(h4, a4);  //test modification of original list
				validateNonLoop(h4, h4c);
			}
		};


		[TestMethod, Timeout(1000)]  //Can you guess the sequence?
		void StudentsLoop_Test14()
		{
			const int size = 100;
			int nums1[size], nums2[size], nums3[size], nums4[size];
			for (int i = 0; i < size; i++) {
				nums1[i] = i - 50000;
				nums2[i] = i - 20000;
				nums3[i] = i - 765465460;
				nums4[i] = i - 5000000;
			}
			struct loopnode* h1 = createListFromArray(nums1, size, -1);
			struct loopnode* h1c = createListFromArray(nums1, size, -1);

			struct loopnode* h2 = createListFromArray(nums2, size, -1);
			struct loopnode* h2c = createListFromArray(nums2, size, -1);

			struct loopnode* h3 = createListFromArray(nums3, size, -1);
			struct loopnode* h3c = createListFromArray(nums3, size, -1);

			struct loopnode* h4 = createListFromArray(nums4, size, -1);
			struct loopnode* h4c = createListFromArray(nums4, size, -1);

			char* str1 = storeFormation(h1c);
			char* str2 = storeFormation(h2c);
			char* str3 = storeFormation(h3c);
			char* str4 = storeFormation(h4c);

			srand(12340);
			for (int i = 0; i < 100; i++){
				int r1 = rand() % 20;
				for (int i = 0; i < r1; i++){
					struct loopnode* a1 = createFormation(str1);
					validateNonLoop(h1, a1);  //test modification of original list
					validateNonLoop(h1, h1c);
				}

				int r2 = rand() % 3;
				for (int i = 0; i < r2; i++){
					struct loopnode* a3 = createFormation(str3);
					validateNonLoop(h3, a3);  //test modification of original list
					validateNonLoop(h3, h3c);
				}

				int r3 = rand() % 15;
				for (int i = 0; i < r3; i++){
					struct loopnode *a3 = createFormation(str3);
					validateNonLoop(h3, a3);  //test modification of original list
					validateNonLoop(h3, h3c);
				}

				int r4 = rand() % 25;
				for (int i = 0; i < r4; i++){
					struct loopnode* a2 = createFormation(str2);
					validateNonLoop(h2, a2);  //test modification of original list
					validateNonLoop(h2, h2c);
				}

				for (int i = 0; i < r1 + r2 + r3 + r4; i++){
					struct loopnode* a4 = createFormation(str4);
					validateNonLoop(h4, a4);  //test modification of original list
					validateNonLoop(h4, h4c);

					a4 = createFormation(str4);
					validateNonLoop(h4, a4);  //test modification of original list
					validateNonLoop(h4, h4c);
				}
			}
		};

		[TestMethod, Timeout(1000)]  //Can you guess the sequence?
		void StudentsLoop_Test15()
		{
			const int size = 100;
			int nums1[size], nums2[size], nums3[size], nums4[size];
			for (int i = 0; i < size; i++) {
				nums1[i] = i + 2;
				nums2[i] = i + 33;
				nums3[i] = i + 444;
				nums4[i] = i + 555;
			}
			struct loopnode* h1 = createListFromArray(nums1, size, 20);
			struct loopnode* h1c = createListFromArray(nums1, size, 20);

			struct loopnode* h2 = createListFromArray(nums2, size, 25);
			struct loopnode* h2c = createListFromArray(nums2, size, 25);

			struct loopnode* h3 = createListFromArray(nums3, size, 3);
			struct loopnode* h3c = createListFromArray(nums3, size, 3);

			struct loopnode* h4 = createListFromArray(nums4, size, 3);
			struct loopnode* h4c = createListFromArray(nums4, size, 3);

			char* str1 = storeFormation(h1c);
			char* str2 = storeFormation(h2c);
			char* str3 = storeFormation(h3c);
			char* str4 = storeFormation(h4c);

			srand(122);
			for (int i = 0; i < 100; i++){
				int r1 = rand() % 20;
				for (int i = 0; i < r1; i++){
					struct loopnode* a1 = createFormation(str1);
					validateLoop(h1, a1,size + 100);  //test modification of original list
					validateLoop(h1, h1c,size + 100);
				}

				int r2 = rand() % 3;
				for (int i = 0; i < r2; i++){
					struct loopnode* a3 = createFormation(str3);
					validateLoop(h3, a3, size + 100);  //test modification of original list
					validateLoop(h3, h3c, size + 100);
				}

				int r3 = rand() % 15;
				for (int i = 0; i < r3; i++){
					struct loopnode *a3 = createFormation(str3);
					validateLoop(h3, a3, size + 100);  //test modification of original list
					validateLoop(h3, h3c, size + 100);
				}

				int r4 = rand() % 25;
				for (int i = 0; i < r4; i++){
					struct loopnode* a2 = createFormation(str2);
					validateLoop(h2, a2, size + 100);  //test modification of original list
					validateLoop(h2, h2c, size + 100);
				}

				for (int i = 0; i < r1 + r2 + r3 + r4; i++){
					struct loopnode* a4 = createFormation(str4);
					validateLoop(h4, a4, size+100);  //test modification of original list
					validateLoop(h4, h4c, size+100);

					a4 = createFormation(str4);
					validateLoop(h4, a4, size+100);  //test modification of original list
					validateLoop(h4, h4c, size+100);
				}
			}
		};

		[TestMethod, Timeout(1000)] //LARGE N 
		void StudentsLoop_Test16()
		{
			const int size = 5000;
			int nums[size];
			srand(50);
			for (int i = 0; i < size; i++) {
				nums[i] = rand() % 10000;
			}
			struct loopnode* h1 = createListFromArray(nums, size, 20);
			struct loopnode* h1c = createListFromArray(nums, size, 20);

			for (int i = 0; i < size; i++) {
				nums[i] = rand() % 10000;
			}
			struct loopnode* h2 = createListFromArray(nums, size, 25);
			struct loopnode* h2c = createListFromArray(nums, size, 25);
			for (int i = 0; i < size; i++) {
				nums[i] = rand() % 10000;
			}
			struct loopnode* h3 = createListFromArray(nums, size, 3);
			struct loopnode* h3c = createListFromArray(nums, size, 3);
			for (int i = 0; i < size; i++) {
				nums[i] = rand() % 10000;
			}
			struct loopnode* h4 = createListFromArray(nums, size, 3);
			struct loopnode* h4c = createListFromArray(nums, size, 3);

			char* str1 = storeFormation(h1c);
			char* str2 = storeFormation(h2c);
			char* str3 = storeFormation(h3c);
			char* str4 = storeFormation(h4c);

			srand(122);
			for (int i = 0; i < 10; i++){
				int r1 = rand() % 10;
				for (int i = 0; i < r1; i++){
					struct loopnode* a1 = createFormation(str1);
					validateLoop(h1, a1, size + 100);  //test modification of original list
					validateLoop(h1, h1c, size + 100);
				}

				int r2 = rand() % 3;
				for (int i = 0; i < r2; i++){
					struct loopnode* a3 = createFormation(str3);
					validateLoop(h3, a3, size + 100);  //test modification of original list
					validateLoop(h3, h3c, size + 100);
				}

				int r3 = rand() % 5;
				for (int i = 0; i < r3; i++){
					struct loopnode *a3 = createFormation(str3);
					validateLoop(h3, a3, size + 100);  //test modification of original list
					validateLoop(h3, h3c, size + 100);
				}

				int r4 = rand() % 8;
				for (int i = 0; i < r4; i++){
					struct loopnode* a2 = createFormation(str2);
					validateLoop(h2, a2, size + 100);  //test modification of original list
					validateLoop(h2, h2c, size + 100);
				}

				for (int i = 0; i < r1 + r2 + r3 + r4; i++){
					struct loopnode* a4 = createFormation(str4);
					validateLoop(h4, a4, size + 100);  //test modification of original list
					validateLoop(h4, h4c, size + 100);

					a4 = createFormation(str4);
					validateLoop(h4, a4, size + 100);  //test modification of original list
					validateLoop(h4, h4c, size + 100);
				}
			}
		};

		[TestMethod, Timeout(1000)] //LARGE N  = 10^5
		void StudentsLoop_Test17()
		{
			const int size = 100000;
			int nums[size];
			srand(20);
			for (int i = 0; i < size; i++){
				nums[i] = rand()%255;
			}
			struct loopnode* head = createListFromArray(nums, size, -1);
			struct loopnode* headcopy = createListFromArray(nums, size, -1);
			char* str = storeFormation(headcopy);
			struct loopnode* actualhead = createFormation(str);

			validateNonLoop(head, headcopy);  //test modification of original list
			validateNonLoop(head, actualhead);
		};

		[TestMethod, Timeout(1000)]
		void StudentsLoop_Test18()
		{
			const int size = 10000;
			int nums[size];
			srand(333);
			for (int i = 0; i < size; i++) {
				nums[i] = rand() % 255;
			}
			struct loopnode* h1 = createListFromArray(nums, size, -1);
			struct loopnode* h1c = createListFromArray(nums, size, -1);
			for (int i = 0; i < size; i++) {
				nums[i] = rand() % 255;
			}
			struct loopnode* h2 = createListFromArray(nums, size, -1);
			struct loopnode* h2c = createListFromArray(nums, size, -1);
			for (int i = 0; i < size; i++) {
				nums[i] = rand()%255;
			}
			struct loopnode* h3 = createListFromArray(nums, size, -1);
			struct loopnode* h3c = createListFromArray(nums, size, -1);
			for (int i = 0; i < size; i++) {
				nums[i] = rand() % 255;
			}
			struct loopnode* h4 = createListFromArray(nums, size, -1);
			struct loopnode* h4c = createListFromArray(nums, size, -1);

			char* str1 = storeFormation(h1c);
			char* str2 = storeFormation(h2c);
			char* str3 = storeFormation(h3c);
			char* str4 = storeFormation(h4c);

			for (int i = 0; i < 10; i++){
				struct loopnode* a1 = createFormation(str1);
				validateNonLoop(h1, a1);  //test modification of original list
				validateNonLoop(h1, h1c);

				struct loopnode* a3 = createFormation(str3);
				validateNonLoop(h3, a3);  //test modification of original list
				validateNonLoop(h3, h3c);

				struct loopnode* a2 = createFormation(str2);
				validateNonLoop(h2, a2);  //test modification of original list
				validateNonLoop(h2, h2c);


				struct loopnode* a4 = createFormation(str4);
				validateNonLoop(h4, a4);  //test modification of original list
				validateNonLoop(h4, h4c);
			}
		};

		[TestMethod, Timeout(1000)]
		void StudentsLoop_Test19()
		{
			const int size = 100000;
			int nums[size];
			srand(333);
			for (int i = 0; i < size; i++) {
				nums[i] = rand()%25555;
			}
			struct loopnode* head = createListFromArray(nums, size, 88888);
			struct loopnode* headcopy = createListFromArray(nums, size, 88888);
			char* str = storeFormation(headcopy);
			struct loopnode* actualhead = createFormation(str);

			validateLoop(head, headcopy, 10*size);  //test modification of original list
			validateLoop(head, actualhead, 10*size);
		};
	};

}