#include "stdafx.h"
#include "../src/Snake.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class SnakeSpec
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

		int compare(int** output, int** expectedOutput){
			if (expectedOutput == NULL){
				if (output == NULL)	return 1;
				return 0;
			}
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 100; j++){
					if (output[i][j] != expectedOutput[i][j])	return 0;
				}
			}
			return 1;
		}

		void fillExpectedOutput(int** expectedOutput, int number, int x, int y, int direction){
			if (number == 0)	return;
			expectedOutput[x][y] = number;
			if ((x == 0) && (direction == 0))	return fillExpectedOutput(expectedOutput, number - 1, 1, y, direction);
			if ((x == 1) && (direction == 0))	return fillExpectedOutput(expectedOutput, number - 1, 2, y, direction);
			if ((x == 2) && (direction == 0))	return fillExpectedOutput(expectedOutput, number - 1, 2, y + 1, 1);
			if ((x == 2) && (direction == 1))	return fillExpectedOutput(expectedOutput, number - 1, 1, y, direction);
			if ((x == 1) && (direction == 1))	return fillExpectedOutput(expectedOutput, number - 1, 0, y, direction);
			if ((x == 0) && (direction == 1))	return fillExpectedOutput(expectedOutput, number - 1, 0, y + 1, 0);
			return;
		}

		[TestMethod, Timeout(1000)]
		void Sample_Snake()
		{
			int check = 0;
			Assert::AreEqual(0, check, L"Sample test failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Real_Snake01()
		{
			int len = -1;
			int** expectedOutput = NULL;
			int** Output = initialSnakePosition(len);
			int finalAnswer = compare(Output, expectedOutput);
			Assert::AreEqual(1, finalAnswer, L"Real Case failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Real_Snake02()
		{
			int len = 0;
			int** expectedOutput = NULL;
			int** Output = initialSnakePosition(len);
			int finalAnswer = compare(Output, expectedOutput);
			Assert::AreEqual(1, finalAnswer, L"Real Case failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Real_Snake03()
		{
			int len = 301;
			int** expectedOutput = NULL;
			int** Output = initialSnakePosition(len);
			int finalAnswer = compare(Output, expectedOutput);
			Assert::AreEqual(1, finalAnswer, L"Real Case failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Real_Snake04()
		{
			int len = 1;
			int** expectedOutput = (int**)calloc(3,sizeof(int*));
			for (int i = 0; i < 3; i++){
				expectedOutput[i] = (int*)calloc(100,sizeof(int));
			}
			expectedOutput[0][0] = 1;
			int** Output = initialSnakePosition(len);
			int finalAnswer = compare(Output, expectedOutput);
			Assert::AreEqual(1, finalAnswer, L"Real Case failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Real_Snake05()
		{
			int len = 2;
			int** expectedOutput = (int**)calloc(3, sizeof(int*));
			for (int i = 0; i < 3; i++){
				expectedOutput[i] = (int*)calloc(100, sizeof(int));
			}
			expectedOutput[0][0] = 2;
			expectedOutput[1][0] = 1;
			int** Output = initialSnakePosition(len);
			int finalAnswer = compare(Output, expectedOutput);
			Assert::AreEqual(1, finalAnswer, L"Real Case failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Real_Snake06()
		{
			int len = 3;
			int** expectedOutput = (int**)calloc(3, sizeof(int*));
			for (int i = 0; i < 3; i++){
				expectedOutput[i] = (int*)calloc(100, sizeof(int));
			}
			expectedOutput[0][0] = 3;
			expectedOutput[1][0] = 2;
			expectedOutput[2][0] = 1;
			int** Output = initialSnakePosition(len);
			int finalAnswer = compare(Output, expectedOutput);
			Assert::AreEqual(1, finalAnswer, L"Real Case failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Real_Snake07()
		{
			int len = 4;
			int** expectedOutput = (int**)calloc(3, sizeof(int*));
			for (int i = 0; i < 3; i++){
				expectedOutput[i] = (int*)calloc(100, sizeof(int));
			}
			expectedOutput[0][0] = 4;
			expectedOutput[1][0] = 3;
			expectedOutput[2][0] = 2;
			expectedOutput[2][1] = 1;
			int** Output = initialSnakePosition(len);
			int finalAnswer = compare(Output, expectedOutput);
			Assert::AreEqual(1, finalAnswer, L"Real Case failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Real_Snake08()
		{
			int len = 5;
			int** expectedOutput = (int**)calloc(3, sizeof(int*));
			for (int i = 0; i < 3; i++){
				expectedOutput[i] = (int*)calloc(100, sizeof(int));
			}
			expectedOutput[0][0] = 5;
			expectedOutput[1][0] = 4;
			expectedOutput[2][0] = 3;
			expectedOutput[2][1] = 2;
			expectedOutput[1][1] = 1;
			int** Output = initialSnakePosition(len);
			int finalAnswer = compare(Output, expectedOutput);
			Assert::AreEqual(1, finalAnswer, L"Real Case failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Real_Snake09()
		{
			int len = 6;
			int** expectedOutput = (int**)calloc(3, sizeof(int*));
			for (int i = 0; i < 3; i++){
				expectedOutput[i] = (int*)calloc(100, sizeof(int));
			}
			expectedOutput[0][0] = 6;
			expectedOutput[1][0] = 5;
			expectedOutput[2][0] = 4;
			expectedOutput[2][1] = 3;
			expectedOutput[1][1] = 2;
			expectedOutput[0][1] = 1;
			int** Output = initialSnakePosition(len);
			int finalAnswer = compare(Output, expectedOutput);
			Assert::AreEqual(1, finalAnswer, L"Real Case failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Real_Snake10()
		{
			int len = 17;
			int** expectedOutput = (int**)calloc(3, sizeof(int*));
			for (int i = 0; i < 3; i++){
				expectedOutput[i] = (int*)calloc(100, sizeof(int));
			}
			fillExpectedOutput(expectedOutput, len, 0, 0, 0);
			int** Output = initialSnakePosition(len);
			int finalAnswer = compare(Output, expectedOutput);
			Assert::AreEqual(1, finalAnswer, L"Real Case failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Real_Snake11()
		{
			int len = 29;
			int** expectedOutput = (int**)calloc(3, sizeof(int*));
			for (int i = 0; i < 3; i++){
				expectedOutput[i] = (int*)calloc(100, sizeof(int));
			}
			fillExpectedOutput(expectedOutput, len, 0, 0, 0);
			int** Output = initialSnakePosition(len);
			int finalAnswer = compare(Output, expectedOutput);
			Assert::AreEqual(1, finalAnswer, L"Real Case failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Real_Snake12()
		{
			int len = 61;
			int** expectedOutput = (int**)calloc(3, sizeof(int*));
			for (int i = 0; i < 3; i++){
				expectedOutput[i] = (int*)calloc(100, sizeof(int));
			}
			fillExpectedOutput(expectedOutput, len, 0, 0, 0);
			int** Output = initialSnakePosition(len);
			int finalAnswer = compare(Output, expectedOutput);
			Assert::AreEqual(1, finalAnswer, L"Real Case failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Real_Snake13()
		{
			int len = 74;
			int** expectedOutput = (int**)calloc(3, sizeof(int*));
			for (int i = 0; i < 3; i++){
				expectedOutput[i] = (int*)calloc(100, sizeof(int));
			}
			fillExpectedOutput(expectedOutput, len, 0, 0, 0);
			int** Output = initialSnakePosition(len);
			int finalAnswer = compare(Output, expectedOutput);
			Assert::AreEqual(1, finalAnswer, L"Real Case failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Real_Snake14()
		{
			int len = 298;
			int** expectedOutput = (int**)calloc(3, sizeof(int*));
			for (int i = 0; i < 3; i++){
				expectedOutput[i] = (int*)calloc(100, sizeof(int));
			}
			fillExpectedOutput(expectedOutput, len, 0, 0, 0);
			int** Output = initialSnakePosition(len);
			int finalAnswer = compare(Output, expectedOutput);
			Assert::AreEqual(1, finalAnswer, L"Real Case failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Real_Snake15()
		{
			int len = 298;
			int** expectedOutput = (int**)calloc(3, sizeof(int*));
			for (int i = 0; i < 3; i++){
				expectedOutput[i] = (int*)calloc(100, sizeof(int));
			}
			fillExpectedOutput(expectedOutput, len, 0, 0, 0);
			int** Output = initialSnakePosition(len);
			int finalAnswer = compare(Output, expectedOutput);
			Assert::AreEqual(1, finalAnswer, L"Real Case failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Real_Snake16()
		{
			int len = 299;
			int** expectedOutput = (int**)calloc(3, sizeof(int*));
			for (int i = 0; i < 3; i++){
				expectedOutput[i] = (int*)calloc(100, sizeof(int));
			}
			fillExpectedOutput(expectedOutput, len, 0, 0, 0);
			int** Output = initialSnakePosition(len);
			int finalAnswer = compare(Output, expectedOutput);
			Assert::AreEqual(1, finalAnswer, L"Real Case failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Real_Snake17()
		{
			int len = 299;
			int** expectedOutput = (int**)calloc(3, sizeof(int*));
			for (int i = 0; i < 3; i++){
				expectedOutput[i] = (int*)calloc(100, sizeof(int));
			}
			fillExpectedOutput(expectedOutput, len, 0, 0, 0);
			int** Output = initialSnakePosition(len);
			int finalAnswer = compare(Output, expectedOutput);
			Assert::AreEqual(1, finalAnswer, L"Real Case failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Real_Snake18()
		{
			int len = 300;
			int** expectedOutput = (int**)calloc(3, sizeof(int*));
			for (int i = 0; i < 3; i++){
				expectedOutput[i] = (int*)calloc(100, sizeof(int));
			}
			fillExpectedOutput(expectedOutput, len, 0, 0, 0);
			int** Output = initialSnakePosition(len);
			int finalAnswer = compare(Output, expectedOutput);
			Assert::AreEqual(1, finalAnswer, L"Real Case failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Real_Snake19()
		{
			int len = 300;
			int** expectedOutput = (int**)calloc(3, sizeof(int*));
			for (int i = 0; i < 3; i++){
				expectedOutput[i] = (int*)calloc(100, sizeof(int));
			}
			fillExpectedOutput(expectedOutput, len, 0, 0, 0);
			int** Output = initialSnakePosition(len);
			int finalAnswer = compare(Output, expectedOutput);
			Assert::AreEqual(1, finalAnswer, L"Real Case failed", 1, 2, 1, 2);
		};
	};
}
