#include "stdafx.h"
#include <stdlib.h>
#include "../src/MergeBSTs.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;


namespace spec
{
	[TestClass]
	public ref class MergeBSTsSpec
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
		
		struct BstNode *newNode_mergeBST(int key){
			struct BstNode *temp = (struct BstNode *)malloc(sizeof(struct BstNode));
			temp->data = key;
			temp->left = NULL;
			temp->right = NULL;
			return temp;
		}

		struct BstNode * insertNode_mergeBST(struct BstNode *root, int data) {
			if (root == NULL) return newNode_mergeBST(data);
			if (data < root->data)
				root->left = insertNode_mergeBST(root->left, data);
			else if (data > root->data)
				root->right = insertNode_mergeBST(root->right, data);
			return root;
		}

		struct BstNode * create_BST(int *arr, int len) {
			struct BstNode *root = NULL;
			for (int i = 0; i < len; i++) {
				root = insertNode_mergeBST(root, arr[i]);
			}
			return root;
		}

		int searchNode(struct BstNode *root, BstNode *node) {
			if (root == NULL) return 0;
			if (root == node && root->data == node->data) return 1;
			return searchNode(root->left,node) || searchNode(root->right,node);
		}

		void test_mergeBSTs(struct BstNode *root,struct BstNode *Nodes[],int len) {
			for (int i = 0; i < len; i++) {
				if (searchNode(root, Nodes[i]) == 0) {
					Assert::AreEqual(-1,Nodes[i]->data, L"Node not found in bst1", 1, 2);
				}
			}
		}

		void addToArray(BstNode **Nodes,BstNode *Node, int &len) {
			for (int i = 0; i < len; i++) {
				if (Nodes[i]->data == Node->data) return;
			}
			Nodes[len++] = Node;
		}

		void addNodes(struct BstNode *root, BstNode **Nodes, int &len) {
			if (root == NULL) return;
			addNodes(root->left, Nodes, len);
			addToArray(Nodes, root, len);
			addNodes(root->right, Nodes, len);
		}

		int totalNodeCount(struct BstNode *root) {
			if (root == NULL) {
				return 0;
			}
			else {
				return 1 + totalNodeCount(root->left) + totalNodeCount(root->right);
			}
		}

		[TestMethod, Timeout(1000)]
		void MergeBST_Test01()
		{
			int b1[] = { 20,5,30 }; int len1 = 3;
			int b2[] = { 25,10,35 }; int len2 = 3;

			BstNode *Nodes[30]; int len = 0;
			BstNode *bst1 = create_BST(b1,len1);
			BstNode *bst2 = create_BST(b2,len2);

			addNodes(bst1, Nodes, len);
			addNodes(bst2, Nodes, len);

			merge_two_bst(&bst1, bst2);
			
			//Assert::AreEqual(len, len1 + len2, L"Nodes Length", 1, 2);
			Assert::AreEqual(len, totalNodeCount(bst1), L"Nodes Length", 1, 2);
			
			test_mergeBSTs(bst1, Nodes,len);
		};

		[TestMethod, Timeout(1000)]
		void MergeBST_Test02()
		{
			int b1[] = { 20,5,30 }; int len1 = 3;
			int b2[] = { 25,10,35 ,5,20}; int len2 = 5;

			BstNode *Nodes[30]; int len = 0;
			BstNode *bst1 = create_BST(b1, len1);
			BstNode *bst2 = create_BST(b2, len2);

			addNodes(bst1, Nodes, len);
			addNodes(bst2, Nodes, len);

			merge_two_bst(&bst1, bst2);
			
			//Assert::AreEqual(len, len1 + len2 - 2, L"Nodes Length", 1, 2);
			Assert::AreEqual(len, totalNodeCount(bst1), L"Nodes Length", 1, 2);
			test_mergeBSTs(bst1, Nodes, len);
		};

		[TestMethod, Timeout(1000)]
		void MergeBST_Test03()
		{
			int b1[] = { 1,2,3,4,5,6,7,8,9 }; int len1 = 9;
			int b2[] = { 1,2,3,4,5,6,7,8,9,10 }; int len2 = 10;

			BstNode *Nodes[30]; int len = 0;
			BstNode *bst1 = create_BST(b1, len1);
			BstNode *bst2 = create_BST(b2, len2);

			addNodes(bst1, Nodes, len);
			addNodes(bst2, Nodes, len);
			merge_two_bst(&bst1, bst2);

			Assert::AreEqual(len, len1+1, L"Nodes Length", 1, 2);
			Assert::AreEqual(len, totalNodeCount(bst1), L"Nodes Length", 1, 2);
			test_mergeBSTs(bst1, Nodes, len);
		};

		[TestMethod, Timeout(1000)]
		void MergeBST_Test04()
		{
			int b1[] = { 1,2,3,4,5,6,7,8,9,10 }; int len1 = 10;
			int b2[] = { 11,15,99,52 }; int len2 = 4;

			BstNode *Nodes[30]; int len = 0;
			BstNode *bst1 = create_BST(b1, len1);
			BstNode *bst2 = create_BST(b2, len2);

			addNodes(bst1, Nodes, len);
			addNodes(bst2, Nodes, len);
			merge_two_bst(&bst1, bst2);

			Assert::AreEqual(len, len1+len2, L"Nodes Length", 1, 2);
			Assert::AreEqual(len, totalNodeCount(bst1), L"Nodes Length", 1, 2);
			test_mergeBSTs(bst1, Nodes, len);
		};

		[TestMethod, Timeout(1000)]
		void MergeBST_Test05()
		{
			int len1 = 0;
			int b2[] = { 11,15,99,52 };  int len2 = 4;

			BstNode *Nodes[30]; int len = 0;
			BstNode *bst1 = NULL;
			BstNode *bst2 = create_BST(b2, len2);

			addNodes(bst1, Nodes, len);
			addNodes(bst2, Nodes, len);
			merge_two_bst(&bst1, bst2);

			Assert::AreEqual(len, len1 + len2, L"Nodes Length1", 1, 2);
			Assert::AreEqual(len, totalNodeCount(bst1), L"Nodes Length2", 1, 2);
			test_mergeBSTs(bst1, Nodes, len);
		};

		[TestMethod, Timeout(1000)]
		void MergeBST_Test06()
		{
			int len1 = 0;
			int len2 = 0;

			BstNode *Nodes[30]; int len = 0;
			BstNode *bst1 = NULL;
			BstNode *bst2 = NULL;

			addNodes(bst1, Nodes, len);
			addNodes(bst2, Nodes, len);
			merge_two_bst(&bst1, bst2);

			Assert::AreEqual(len, len1 + len2, L"Nodes Length", 1, 2);
			Assert::AreEqual(len, totalNodeCount(bst1), L"Nodes Length", 1, 2);
			test_mergeBSTs(bst1, Nodes, len);
		};

		[TestMethod, Timeout(1000)]
		void MergeBST_Test07()
		{
			int b1[] = { 1,2,3,4,5,6,7,8,9,10 }; int len1 = 10;
			int len2 = 0;

			BstNode *Nodes[30]; int len = 0;
			BstNode *bst1 = create_BST(b1, len1);
			BstNode *bst2 = NULL;

			addNodes(bst1, Nodes, len);
			addNodes(bst2, Nodes, len);
			merge_two_bst(&bst1, bst2);

			Assert::AreEqual(len, len1 + len2, L"Nodes Length", 1, 2);
			Assert::AreEqual(len, totalNodeCount(bst1), L"Nodes Length", 1, 2);
			test_mergeBSTs(bst1, Nodes, len);
		};

	};
}
