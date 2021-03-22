#include "stdafx.h"
#include "../src/maxGold.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class maxGoldSpec
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

		int charToInt(char bin){
			switch (bin){
			case '0':	return 0;
			case '1':	return 1;
			case '2':	return 2;
			}
			return -1;
		}

		struct node* createNewNode(char bin){
			struct node* temp = (struct node*)malloc(sizeof(struct node));
			temp->bin = charToInt(bin);
			temp->firstnode = NULL;
			temp->secondnode = NULL;
			temp->thirdnode = NULL;
			return temp;
		}

		struct node* constructTree(char *binString){
			struct node* root = NULL;
			struct node* nodes[2005];
			int i = 0;
			while (binString[i] != '\0'){
				nodes[i] = createNewNode(binString[i]);
				i++;
			}
			int invalid = 2;
			int mid = (i / 3);
			for (int i = 0; i < mid; i++){
				struct node* curnode = nodes[i];
				struct node* firstnode = nodes[(i * 3) + 1];
				struct node* secondnode = nodes[(i * 3) + 2];
				struct node* thirdnode = nodes[(i * 3) + 3];
				if (curnode->bin != invalid){
					if (firstnode->bin != invalid){
						curnode->firstnode = firstnode;
					}
					if (secondnode->bin != invalid){
						curnode->secondnode = secondnode;
					}
					if (thirdnode->bin != invalid){
						curnode->thirdnode = thirdnode;
					}
				}
			}
			root = nodes[0];
			return root;
		}

#pragma endregion 

		[TestMethod, Timeout(1000)]
		void maxGold_Sample()
		{
			struct node* head = NULL;
			int expectedAnswer = -1;
			int actualAnswer = MaxGold(head);
			Assert::AreEqual(expectedAnswer, actualAnswer, L"Real test 01 failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void maxGold_Real01()
		{
			struct node* head = createNewNode('1');
			int expectedAnswer = 1;
			int actualAnswer = MaxGold(head);
			Assert::AreEqual(expectedAnswer, actualAnswer, L"Real test 01 failed", 1, 2, 1, 2);

			head = createNewNode('0');
			expectedAnswer = 0;
			actualAnswer = MaxGold(head);
			Assert::AreEqual(expectedAnswer, actualAnswer, L"Real test 01 failed", 1, 2, 1, 2);

		};

		[TestMethod, Timeout(1000)]
		void maxGold_Real02()
		{
			struct node* head = createNewNode('1');
			head->firstnode = NULL;
			head->secondnode = createNewNode('1');
			head->thirdnode = createNewNode('0');

			head->thirdnode->secondnode = createNewNode('1');

			int expectedAnswer = 5;
			int actualAnswer = MaxGold(head);
			Assert::AreEqual(expectedAnswer, actualAnswer, L"Real test 01 failed", 1, 2, 1, 2);
		};


		[TestMethod, Timeout(1000)]
		void maxGold_Real03()
		{
			struct node* head = createNewNode('1');
			head->firstnode = NULL;
			head->secondnode = createNewNode('1');
			head->thirdnode = createNewNode('0');

			head->secondnode->firstnode = createNewNode('1');

			head->thirdnode->secondnode = createNewNode('1');
			head->thirdnode->secondnode->firstnode = createNewNode('1');

			int expectedAnswer = 11;
			int actualAnswer = MaxGold(head);
			Assert::AreEqual(expectedAnswer, actualAnswer, L"Real test 01 failed", 1, 2, 1, 2);
		};


		[TestMethod, Timeout(1000)]
		void maxGold_Real04()
		{
			struct node* head = createNewNode('1');
			head->firstnode = NULL;
			head->secondnode = createNewNode('1');
			head->thirdnode = createNewNode('0');

			head->secondnode->firstnode = createNewNode('1');

			head->thirdnode->secondnode = createNewNode('1');
			head->thirdnode->secondnode->firstnode = createNewNode('1');

			head->secondnode->firstnode->firstnode = createNewNode('1');
			int expectedAnswer = 15;
			int actualAnswer = MaxGold(head);
			Assert::AreEqual(expectedAnswer, actualAnswer, L"Real test 01 failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void maxGold_Real05()
		{
			struct node* head = createNewNode('1');
			head->firstnode = NULL;
			head->secondnode = createNewNode('1');
			head->thirdnode = createNewNode('0');

			head->secondnode->firstnode = createNewNode('1');

			head->thirdnode->secondnode = createNewNode('1');
			head->thirdnode->secondnode->firstnode = createNewNode('1');

			head->secondnode->secondnode = createNewNode('0');
			head->secondnode->secondnode->firstnode = createNewNode('1');

			int expectedAnswer = 13;
			int actualAnswer = MaxGold(head);
			Assert::AreEqual(expectedAnswer, actualAnswer, L"Real test 01 failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void maxGold_Real06()
		{
			char binString[100] = "1";
			struct node* head = constructTree(binString);
			int expectedAnswer = 1;
			int actualAnswer = MaxGold(head);
			Assert::AreEqual(expectedAnswer, actualAnswer, L"Real test 02 failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void maxGold_Real07()
		{
			char binString[100] = "0";
			struct node* head = constructTree(binString);
			int expectedAnswer = 0;
			int actualAnswer = MaxGold(head);
			Assert::AreEqual(expectedAnswer, actualAnswer, L"Real test 03 failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void maxGold_Real08()
		{
			char binString[100] = "1111111121211";
			struct node* head = constructTree(binString);
			int expectedAnswer = 7;
			int actualAnswer = MaxGold(head);
			Assert::AreEqual(expectedAnswer, actualAnswer, L"Real test 04 failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void maxGold_Real09()
		{
			char binString[100] = "0000000000202";
			struct node* head = constructTree(binString);
			int expectedAnswer = 0;
			int actualAnswer = MaxGold(head);
			Assert::AreEqual(expectedAnswer, actualAnswer, L"Real test 05 failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void maxGold_Real10()
		{
			char binString[100] = "1010120222222";
			struct node* head = constructTree(binString);
			int expectedAnswer = 5;
			int actualAnswer = MaxGold(head);
			Assert::AreEqual(expectedAnswer, actualAnswer, L"Real test 06 failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void maxGold_Real11()
		{
			char binString[100] = "0101000111000121222222112222222222121222";
			struct node* head = constructTree(binString);
			int expectedAnswer = 5;
			int actualAnswer = MaxGold(head);
			Assert::AreEqual(expectedAnswer, actualAnswer, L"Real test 07 failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void maxGold_Real12()
		{
			char binString[100] = "1111000222000010222212222222222222220121";
			struct node* head = constructTree(binString);
			int expectedAnswer = 13;
			int actualAnswer = MaxGold(head);
			Assert::AreEqual(expectedAnswer, actualAnswer, L"Real test 08 failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void maxGold_Real13()
		{
			char binString[100] = "1212222212222222222222222010222222222222";
			struct node* head = constructTree(binString);
			int expectedAnswer = 15;
			int actualAnswer = MaxGold(head);
			Assert::AreEqual(expectedAnswer, actualAnswer, L"Real test 09 failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void maxGold_Real14()
		{
			char binString[100] = "0020022222220022222222222222222222222220";
			struct node* head = constructTree(binString);
			int expectedAnswer = 0;
			int actualAnswer = MaxGold(head);
			Assert::AreEqual(expectedAnswer, actualAnswer, L"Real test 10 failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void maxGold_Real15()
		{
			char binString[100] = "0101010101010101010101010101010101010101";
			struct node* head = constructTree(binString);
			int expectedAnswer = 7;
			int actualAnswer = MaxGold(head);
			Assert::AreEqual(expectedAnswer, actualAnswer, L"Real test 11 failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void maxGold_Real16()
		{
			char binString[100] = "1010101010101010101010101010101010101010";
			struct node* head = constructTree(binString);
			int expectedAnswer = 15;
			int actualAnswer = MaxGold(head);
			Assert::AreEqual(expectedAnswer, actualAnswer, L"Real test 12 failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void maxGold_Real17()
		{
			char binString[100] = "1000111111111000000000000000000000000000";
			struct node* head = constructTree(binString);
			int expectedAnswer = 10;
			int actualAnswer = MaxGold(head);
			Assert::AreEqual(expectedAnswer, actualAnswer, L"Real test 13 failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void maxGold_Real18()
		{
			char binString[100] = "1000111111111111111111111111111111111111";
			struct node* head = constructTree(binString);
			int expectedAnswer = 11;
			int actualAnswer = MaxGold(head);
			Assert::AreEqual(expectedAnswer, actualAnswer, L"Real test 14 failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void maxGold_Real19()
		{
			char binString[100] = "1111101010101100110011001222222222222222";
			struct node* head = constructTree(binString);
			int expectedAnswer = 15;
			int actualAnswer = MaxGold(head);
			Assert::AreEqual(expectedAnswer, actualAnswer, L"Real test 15 failed", 1, 2, 1, 2);
		};



	};
}
