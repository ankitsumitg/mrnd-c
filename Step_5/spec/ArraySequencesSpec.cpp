#include "stdafx.h"
#include "../src/ArraySequences.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class ArraySequencesSpec
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



		int compare_arrays(int *res, int *ans){
			for (int i = 0; i < 6; i++){
				if (res[i] != ans[i]){
					return 0;
				}
			}
			return 1;
		}

		[TestMethod, Timeout(1000)]  
		void Sample1_ArraySequences()
		{

			int *res = find_sequences(NULL, 0);
			int check = 0;
			if (res == NULL){
				check = 1;
			}
			Assert::AreEqual(1, check, L"Null case failed for Array Sequences", 1, 2, 1, 2);
		};



		[TestMethod, Timeout(1000)] 
		void Real_ArraySequences1()
		{
			int input[10] = { 1, 100, 199, 5, 10, 15, 30, 60 };
			int ans[6] = { 0, 2, 3, 5, 5, 7 };
			int len = 8;
			int *res = find_sequences(input, len);
			int check = compare_arrays(res, ans);
			Assert::AreEqual(1, check, L"Real Case failed for ArraysSequences", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]  
		void Real_ArraySequences2()
		{
			int input[10] = { 15, 30, 60, 1, 100, 199, 5, 10, 15 };
			int ans[6] = { 3, 5, 6, 8, 0, 2 };
			int len = 9;
			int *res = find_sequences(input, len);
			int check = compare_arrays(res, ans);
			Assert::AreEqual(1, check, L"Real2 Case failed for ArraysSequences", 1, 2);
		};
		[TestMethod, Timeout(1000)]  
		void Real_ArraySequences3()
		{
			int input[10] = { 15, 30, 60, 1, 100, 199, 5, 10, 15 };
			int ans[6] = { 3, 5, 6, 8, 0, 2 };
			int len = 9;
			int *res = find_sequences(input, len);
			int check = compare_arrays(res, ans);
			Assert::AreEqual(1, check, L"Real2 Case failed for ArraysSequences", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Real_ArraySequences4()
		{
			int input[10] = { 15, 30, 60, 1, 50, 99, 100, 101, 102 };
			int ans[6] = { 3, 5, 5, 8, 0, 2 };
			int len = 9;
			int *res = find_sequences(input, len);
			int check = compare_arrays(res, ans);
			Assert::AreEqual(1, check, L"Real2 Case failed for ArraysSequences", 1, 2);
		};
		[TestMethod, Timeout(1000)] 
		void Real_ArraySequences5()
		{
			int input[10] = { -20, 10, 40, 160, 200, 240 };
			int ans[6] = { 0, 2, 3, 5, 1, 3 };
			int len = 6;
			int *res = find_sequences(input, len);
			int check = compare_arrays(res, ans);
			Assert::AreEqual(1, check, L"Real2 Case failed for ArraysSequences", 1, 2);
		};
		[TestMethod, Timeout(1000)]  
		void Real_ArraySequences6()
		{
			int input[10] = { 1, 5, 9, 13, 17, 29, 41, 53, 106, 212 };
			int ans[6] = { 0, 4, 4, 7, 7, 9 };
			int len = 10;
			int *res = find_sequences(input, len);
			int check = compare_arrays(res, ans);
			Assert::AreEqual(1, check, L"Real2 Case failed for ArraysSequences", 1, 2);
		};

		[TestMethod, Timeout(1000)]  
		void Real_ArraySequences7()
		{
			int input[10] = { 1, 5, 9, 13, 53, 106, 212, 200, 188, 176 };
			int ans[6] = { 0, 3, 6, 9, 4, 6 };
			int len = 10;
			int *res = find_sequences(input, len);
			int check = compare_arrays(res, ans);
			Assert::AreEqual(1, check, L"Real2 Case failed for ArraysSequences", 1, 2);
		};
		[TestMethod, Timeout(1000)]  
		void Real_ArraySequences8()
		{
			int input[10] = { 1, 5, 9, 13, 53, 106, 212, 200, 188, 176 };
			int ans[6] = { 0, 3, 6, 9, 4, 6 };
			int len = 10;
			int *res = find_sequences(input, len);
			int check = compare_arrays(res, ans);
			Assert::AreEqual(1, check, L"Real2 Case failed for ArraysSequences", 1, 2);
		};

		[TestMethod, Timeout(1000)]  
		void Real_ArraySequences9()
		{
			int input[10] = { 10, -10, -30, 10, 20, 40, 10, -20 };
			int ans[6] = { 0, 2, 5, 7, 3, 5 };
			int len = 8;
			int *res = find_sequences(input, len);
			int check = compare_arrays(res, ans);
			Assert::AreEqual(1, check, L"Real2 Case failed for ArraysSequences", 1, 2);
		};
		[TestMethod, Timeout(1000)]  
		void Real_ArraySequences10()
		{
			int input[10] = { -2, 10, 22, 48, 74, 148, 296 };
			int ans[6] = { 0, 2, 2, 4, 4, 6 };
			int len = 7;
			int *res = find_sequences(input, len);;
			int check = compare_arrays(res, ans);
			Assert::AreEqual(1, check, L"Real2 Case failed for ArraysSequences", 1, 2);
		};


		[TestMethod, Timeout(1000)] 
		void Real_ArraySequences11()
		{
			int input[10] = { -10, -30, -50, 100, 50, 25, -100, -225 };
			int ans[6] = { 0, 2, 5, 7, 3, 5 };
			int len = 8;
			int *res = find_sequences(input, len);
			int check = compare_arrays(res, ans);
			Assert::AreEqual(1, check, L"Real2 Case failed for ArraysSequences", 1, 2);
		};
		[TestMethod, Timeout(1000)]  
		void Real_ArraySequences12()
		{
			int input[10] = { 12, 0, -12, 0, 6, 12, 20, 10, 5 };
			int ans[6] = { 0, 2, 3, 5, 6, 8 };
			int len = 9;
			int *res = find_sequences(input, len);
			int check = compare_arrays(res, ans);
			Assert::AreEqual(1, check, L"Real2 Case failed for ArraysSequences", 1, 2);
		};

	};
}
