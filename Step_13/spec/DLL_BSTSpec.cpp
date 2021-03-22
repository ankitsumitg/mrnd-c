#include "stdafx.h"
#include <stdlib.h>
#include "../src/DLL_BST.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;


namespace spec
{
	[TestClass]
	public ref class DLL_BSTSpec
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
		
		struct node_dll *newNode_DLL_spec(int key){
			struct node_dll *temp = (struct node_dll *)malloc(sizeof(struct node_dll));
			temp->data = key;
			temp->next = NULL;
			temp->prev = NULL;
			return temp;
		}

		struct node_dll * make_dll_spec(int *arr, int len){
			struct node_dll *root = newNode_DLL_spec(arr[0]);
			struct node_dll *temp = root;
			for (int i = 1; i < len; i++){
				struct node_dll *cur = newNode_DLL_spec(arr[i]);
				temp->next = cur;
				cur->prev = temp;
				temp = temp->next;
			}
			return root;
		}

		struct node_bst *newNode_spec(int key)
		{
			struct node_bst *temp = (struct node_bst *)malloc(sizeof(struct node_bst));
			temp->data = key;
			temp->left = NULL;
			temp->right = NULL;
			return temp;
		}

		struct node_bst * add_node_spec(struct node_bst *root, int data){
			if (root == NULL) return newNode_spec(data);

			if (data < root->data)
				root->left = add_node_spec(root->left, data);
			else if (data > root->data)
				root->right = add_node_spec(root->right, data);

			return root;
		}

		struct node_bst * make_bst_spec(int *arr, int len){
			struct node_bst *root = NULL;
			for (int i = 0; i < len; i++){
				root = add_node_spec(root, arr[i]);
			}
			return root;
		}

		void delete_tree(struct node_bst *root){
			if (root != NULL)
			{
				delete_tree(root->left);
				delete_tree(root->right);
				delete root;
				if (root->left != NULL)
					root->left = NULL;
				if (root->right != NULL)
					root->right = NULL;
				root = NULL;
			}
		}

		void dll_bst_spec(int *arr,int *arr_bst,int len1,int len2,int ans){
			try{
				struct node_dll * head = make_dll_spec(arr, len1);
				struct node_bst *root = make_bst_spec(arr_bst, len2);
				int check = is_identical(head, root);
				Assert::AreEqual(ans, check, L"Failed for Problem3", 1, 2);
				delete_tree(root);
			}
			catch (System::Exception ^e){
				Assert::AreEqual(1, 2, L"Exception maybe Nullpointer occured", 1, 2);
			}
		}

		[TestMethod, Timeout(1000)]
		void dll_bst_test01()
		{
			try{
				int check = is_identical(NULL, NULL);
				Assert::AreEqual(-1, check, L"Failed sample 0 for NULL case in P1", 1, 2);
			}
			catch (System::Exception ^e){
				Assert::AreEqual(-1, 0, L"NULL pointer thrown", 1, 2);
			}
		};

		[TestMethod, Timeout(1000)]
		void dll_bst_test02()
		{
			int arr[5] = { 1, 2, 3, 4, 5 };
			int bst_arr[5] = { 5, 3, 2, 1, 4 };
			int len1 = 5;
			int len2 = 5;
			int ans = 1;
			dll_bst_spec(arr, bst_arr,len1,len2,ans);
			bst_arr[0] = 999;
			dll_bst_spec(arr, bst_arr, len1, len2, 0);
		};

		[TestMethod, Timeout(1000)]
		void dll_bst_test03()
		{
			int arr[8] = { 1, 2, 3, 4, 5,6,7,8 };
			int bst_arr[8] = {  5,2,7,1,3,6,8,4};
			int len1 = 8;
			int len2 = 8;
			int ans = 1;
			dll_bst_spec(arr, bst_arr, len1, len2, ans);
			bst_arr[0] = 999;
			dll_bst_spec(arr, bst_arr, len1, len2, 0);
		};

		[TestMethod, Timeout(1000)]
		void dll_bst_test04()
		{
			int arr[8] = { 1, 2, 3, 4, 5,6,7,8 };
			int bst_arr[8] = { 5 ,2, 6 ,3 ,7, 1, 4,8 };
			int len1 = 8;
			int len2 = 8;
			int ans = 1;
			dll_bst_spec(arr, bst_arr, len1, len2, ans);
			bst_arr[0] = 999;
			dll_bst_spec(arr, bst_arr, len1, len2, 0);
		};

		[TestMethod, Timeout(1000)]
		void dll_bst_test05()
		{
			int arr[7] = { 1, 2, 3, 4,5,6,8 };
			int bst_arr[7] = { 5 ,2, 6 ,3 , 1, 4,8 };
			int len1 = 7;
			int len2 = 7;
			int ans = 1;
			dll_bst_spec(arr, bst_arr, len1, len2, ans);
			arr[3] = 20;
			dll_bst_spec(arr, bst_arr, len1, len2, 0);
		};

		[TestMethod, Timeout(1000)]
		void dll_bst_test06()
		{
			int arr[7] = { 1,1,1,1,1,1,1 };
			int bst_arr[7] = { 5 ,2, 6 ,3 , 1, 4,8 };
			int len1 = 7;
			int len2 = 7;
			dll_bst_spec(arr, bst_arr, len1, len2, 0);
			arr[3] = 20;
			dll_bst_spec(arr, bst_arr, len1, len2, 0);
		};
	};
}
