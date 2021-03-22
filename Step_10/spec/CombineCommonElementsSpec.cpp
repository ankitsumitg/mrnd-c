#include "stdafx.h"
#include "./../src/CombineCommonElements.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

extern "C" {
	/*
	Sample equals Function for integers.
	You will use this function while creating a Object node whose value holds address of an int.
	*/
	int equalsIntSpec(void * a, void *b) {
		//As a and b are void *, you need to first convert them to int * and extract the value.
		int aval = *((int *)a);
		int bval = *((int *)b);
		printf("Comparing %d,%d : ", aval, bval);
		if (aval == bval){
			return 1;
		}
		else {
			return 0;
		}
	}
	int equalsFloatSpec(void * a, void *b) {
		//As a and b are void *, you need to first convert them to float * and extract the value.
		int aval = *((int *)a);
		int bval = *((int *)b);
		printf("Comparing %d,%d : ", aval, bval);
		if (aval == bval){
			return 1;
		}
		else {
			return 0;
		}
	}
}


namespace spec
{
	[TestClass]
	public ref class CombineCommonElementsSpec
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




		/*
		Sample function to create a int Object Node from a int pointer and equals function passed.
		*/
		struct ObjectNode * createIntObjectNodeSpec(int *number, int(*equals)(void *, void *)) {
			struct ObjectNode * node = (struct ObjectNode *)malloc(sizeof(struct ObjectNode));
			node->value = (void *)number;
			node->equals = equals;
			return node;
		}

		/*
		Sample function to create a float Object Node from a float pointer and equals function passed.
		*/
		struct ObjectNode * createFloatObjectNodeSpec(float *number, int(*equals)(void *, void *)) {
			struct ObjectNode * node = (struct ObjectNode *)malloc(sizeof(struct ObjectNode));
			node->value = (void *)number;
			node->equals = equals;
			return node;
		}

		[TestMethod(), Timeout(3000)]
		void CombineCommonElementsUsingInts_Test1()
		{


			int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			int arr2[10] = { 6, 7, 8, 9, 10, 30, 40, 50, 10, 20 };
			int len1 = 10;
			int len2 = 10;

			struct ObjectNode ** intvalues1 = (struct ObjectNode **) malloc(sizeof(struct ObjectNode *)*len1);
			struct ObjectNode ** intvalues2 = (struct ObjectNode **) malloc(sizeof(struct ObjectNode *)*len2);
			int i = 0;
			for (i = 0; i<len1; i++){
				intvalues1[i] = createIntObjectNodeSpec(&arr[i], &equalsIntSpec);
			}
			for (i = 0; i<len2; i++){
				intvalues2[i] = createIntObjectNodeSpec(&arr2[i], &equalsIntSpec);
			}


			int expectedcommonLength = 5;
			int indexesOfArray1WhichAreCommon[5] = { 5, 6, 7, 8, 9 };
			struct ObjectNode* expected[5];
			for (int i = 0; i < expectedcommonLength; i++){
				expected[i] = intvalues1[indexesOfArray1WhichAreCommon[i]];
			}
			int commonLength = 0;
			struct ObjectNode ** result = combine_common_elements(intvalues1, intvalues2, len1, len2, &commonLength);
			Assert::AreEqual(expectedcommonLength, commonLength, L"CombineCommonElementsUsingInts_Test1 commonLength check failed, Check if you copied final common len value or not.", 1, 2);
			//Comparing result with expected
			for (int i = 0; i < expectedcommonLength; i++){
				//Only Addresses needs to be compared.
				if (expected[i] != result[i]) {
					//Intentionally failing test.
					Assert::AreEqual(999, 998, L"CombineCommonElementsUsingInts_Test1 Fail, Check Addresses returned.", 1, 2);
				}

				//Checking values are not changed.
				//Void * to a value from array 1
				void * expected = (int *)&arr[indexesOfArray1WhichAreCommon[i]];
				Assert::AreEqual(1, equalsInt1(expected, result[i]->value), L"CombineCommonElementsUsingInts_Test1 Fail, Check Values of Addresses returned, they shouldnt be modified", 1, 2);
			}
			
		};

		[TestMethod(), Timeout(3000)]
		void CombineCommonElementsUsingIntsRepeated_Test2()
		{


			int arr[10] = { 1, 2, 3,  6, 7, 400, 8 , 5, 6, 7 };
			int arr2[10] = { 6, 7, 8, 9, 10, 30, 40, 50, 6, 7 };
			int len1 = 10;
			int len2 = 10;

			struct ObjectNode ** intvalues1 = (struct ObjectNode **) malloc(sizeof(struct ObjectNode *)*len1);
			struct ObjectNode ** intvalues2 = (struct ObjectNode **) malloc(sizeof(struct ObjectNode *)*len2);
			int i = 0;
			for (i = 0; i<len1; i++){
				intvalues1[i] = createIntObjectNodeSpec(&arr[i], &equalsIntSpec);
			}
			for (i = 0; i<len2; i++){
				intvalues2[i] = createIntObjectNodeSpec(&arr2[i], &equalsIntSpec);
			}


			int expectedcommonLength = 3;
			int indexesOfArray1WhichAreCommon[5] = { 3, 4, 6 };
			struct ObjectNode* expected[5];
			for (int i = 0; i < expectedcommonLength; i++){
				expected[i] = intvalues1[indexesOfArray1WhichAreCommon[i]];
			}
			int commonLength = 0;
			struct ObjectNode ** result = combine_common_elements(intvalues1, intvalues2, len1, len2, &commonLength);

			Assert::AreEqual(expectedcommonLength, commonLength, L"CombineCommonElementsUsingIntsRepeated_Test2 commonLength check failed, Check if you copied final common len value or not.", 1, 2);
			//Comparing result with expected
			for (int i = 0; i < expectedcommonLength; i++){
				//Only Addresses needs to be compared.
				if (expected[i] != result[i]) {
					//Intentionally failing test.
					Assert::AreEqual(999, 998, L"CombineCommonElementsUsingIntsRepeated_Test2 Fail, Check Addresses returned.", 1, 2);
				}

				//Checking values are not changed.
				//Void * to a value from array 1
				void * expected = (int *)&arr[indexesOfArray1WhichAreCommon[i]];
				Assert::AreEqual(1, equalsInt1(expected, result[i]->value), L"CombineComCombineCommonElementsUsingIntsRepeated_Test2monElementsUsingInts_Test1 Fail, Check Values of Addresses returned, they shouldnt be modified", 1, 2);
			}

		};

		[TestMethod(), Timeout(3000)]
		void CCEIntsRepeatedDiffLen_Test2()
		{


			int arr[5] = { 50, 50, 1, 6, 2};
			int arr2[10] = { 6, 6, 6, 9, 50, 50, 50, 50, 50 };
			int len1 = 5;
			int len2 = 10;

			struct ObjectNode ** intvalues1 = (struct ObjectNode **) malloc(sizeof(struct ObjectNode *)*len1);
			struct ObjectNode ** intvalues2 = (struct ObjectNode **) malloc(sizeof(struct ObjectNode *)*len2);
			int i = 0;
			for (i = 0; i<len1; i++){
				intvalues1[i] = createIntObjectNodeSpec(&arr[i], &equalsIntSpec);
			}
			for (i = 0; i<len2; i++){
				intvalues2[i] = createIntObjectNodeSpec(&arr2[i], &equalsIntSpec);
			}


			int expectedcommonLength = 2;
			int indexesOfArray1WhichAreCommon[2] = { 0, 3 };
			struct ObjectNode* expected[2];
			for (int i = 0; i < expectedcommonLength; i++){
				expected[i] = intvalues1[indexesOfArray1WhichAreCommon[i]];
			}
			int commonLength = 0;
			struct ObjectNode ** result = combine_common_elements(intvalues1, intvalues2, len1, len2, &commonLength);

			Assert::AreEqual(expectedcommonLength, commonLength, L"CCEIntsRepeatedDiffLen_Test2 commonLength check failed, Check if you copied final common len value or not.", 1, 2);
			//Comparing result with expected
			for (int i = 0; i < expectedcommonLength; i++){
				//Only Addresses needs to be compared.
				if (expected[i] != result[i]) {
					//Intentionally failing test.
					Assert::AreEqual(999, 998, L"CCEIntsRepeatedDiffLen_Test2 Fail, Check Addresses returned.", 1, 2);
				}

				//Checking values are not changed.
				//Void * to a value from array 1
				void * expected = (int *)&arr[indexesOfArray1WhichAreCommon[i]];
				Assert::AreEqual(1, equalsInt1(expected, result[i]->value), L"CCEIntsRepeatedDiffLen_Test2 Fail, Check Values of Addresses returned, they shouldnt be modified", 1, 2);
			}

		};

		[TestMethod(), Timeout(3000)]
		void CCEFloatsRepeatedDiffLen_Test2()
		{


			float arr[4] = { 4.5, 5.0, 6.1, 6.1 };
			float arr2[6] = { 6.1, 6, 6, 9, 50, 50 };
			int len1 = 4;
			int len2 = 6;

			struct ObjectNode ** intvalues1 = (struct ObjectNode **) malloc(sizeof(struct ObjectNode *)*len1);
			struct ObjectNode ** intvalues2 = (struct ObjectNode **) malloc(sizeof(struct ObjectNode *)*len2);
			int i = 0;
			for (i = 0; i<len1; i++){
				intvalues1[i] = createFloatObjectNodeSpec(&arr[i], &equalsFloatSpec);
			}
			for (i = 0; i<len2; i++){
				intvalues2[i] = createFloatObjectNodeSpec(&arr2[i], &equalsFloatSpec);
			}


			int expectedcommonLength = 1;
			int indexesOfArray1WhichAreCommon[1] = { 2 };
			struct ObjectNode* expected[1];
			for (int i = 0; i < expectedcommonLength; i++){
				expected[i] = intvalues1[indexesOfArray1WhichAreCommon[i]];
			}
			int commonLength = 0;
			struct ObjectNode ** result = combine_common_elements(intvalues1, intvalues2, len1, len2, &commonLength);
			Assert::AreEqual(expectedcommonLength, commonLength, L"CCEFloatsRepeatedDiffLen_Test2 commonLength check failed, Check if you copied final common len value or not.", 1, 2);
			//Comparing result with expected
			for (int i = 0; i < expectedcommonLength; i++){
				//Only Addresses needs to be compared.
				if (expected[i] != result[i]) {
					//Intentionally failing test.
					Assert::AreEqual(999, 998, L"CCEFloatsRepeatedDiffLen_Test2 Fail, Check Addresses returned.", 1, 2);
				}

				//Checking values are not changed.
				//Void * to a value from array 1
				void * expected = (int *)&arr[indexesOfArray1WhichAreCommon[i]];
				Assert::AreEqual(1, equalsInt1(expected, result[i]->value), L"CCEFloatsRepeatedDiffLen_Test2 Fail, Check Values of Addresses returned, they shouldnt be modified", 1, 2);
			}

		};
	};
}
