#include "stdafx.h"


#include "./../src/NSnipers.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class NSnipersSpec
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
		//
		//You can use the following additional attributes as you write your tests:
		//
		//Use ClassInitialize to run code before running the first test in the class
		//[ClassInitialize()]
		//static void MyClassInitialize(TestContext^ testContext) {};
		//
		//Use ClassCleanup to run code after all tests in a class have run
		//[ClassCleanup()]
		//static void MyClassCleanup() {};
		//
		//Use TestInitialize to run code before running each test
		//[TestInitialize()]
		//void MyTestInitialize() {};
		//
		//Use TestCleanup to run code after each test has run
		//[TestCleanup()]
		//void MyTestCleanup() {};
		//
		#pragma endregion 

		int check_board(int *board, int n){

			int tempboard[16][16];
			int i = 0, j = 0;
			for (i = 0; i < n; i++){
				for (j = 0; j < n; j++){
					tempboard[i][j] = *((board + i*n) + j);
				}
			}

			//Check Rows
			for (i = 0; i < n; i++){
				int oc = 0;
				for (j = 0; j < n; j++){
					if (tempboard[i][j] == 1){
						if (oc == 0){
							oc = 1;
						}
						else{
							return 0;
						}
					}
				}
			}

			//Check Cols

			for (i = 0; i < n; i++){
				int oc = 0;
				for (j = 0; j < n; j++){
					if (tempboard[j][i] == 1){
						if (oc == 0){
							oc = 1;
						}
						else{
							return 0;
						}
					}
				}
			}

			//Check Top Right Triangle

			for (i = 0; i < n; i++){
				int sx = 0;
				int sy = i;
				int oc = 0;
				while (sy < n){
					if (tempboard[sx][sy] == 1){
						if (oc == 0){
							oc = 1;
						}
						else{
							return 0;
						}
					}
					sx++;
					sy++;
				}
			}

			//Check bottom left Traingle

			for (i = 0; i < n; i++){
				int sx = i;
				int sy = 0;
				int oc = 0;
				while (sx < n){
					if (tempboard[sx][sy] == 1){
						if (oc == 0){
							oc = 1;
						}
						else{
							return 0;
						}
					}
					sx++;
					sy++;
				}
			}

			return 1;
		}

		[TestMethod]
		void NullBoard()
		{
			int n = 0;
			int result = solve_nsnipers(NULL, n);
			Assert::AreEqual(0, result, L"1 should be 1", 1,2);
		}
		[TestMethod,Timeout(3000)]
		void ThreeBoard()
		{

			int n = 3;
			int board[3][3];
			int i = 0, j = 0;
			for (i = 0; i < n; i++){
				for (j = 0; j < n; j++){
					board[i][j] = 0;
				}
			}

			int result = solve_nsnipers(&board[0][0], n);
			Assert::AreEqual(0, result, L"3board should be 0", 1,2);
		}
		[TestMethod, Timeout(3000)]
		void FourBoard()
		{

			int n = 4;
			int board[4][4];
			int i = 0, j = 0;
			for (i = 0; i < n; i++){
				for (j = 0; j < n; j++){
					board[i][j] = 0;
				}
			}

			int result = solve_nsnipers(&board[0][0], n);
			Assert::AreEqual(1, result, L"Four board should return 1", 1,2);
			int check = check_board(&board[0][0], n);
			Assert::AreEqual(1, check, L"Fail for 4 board", 1,2);
		}
		[TestMethod,Timeout(5000)]
		void EightBoard()
		{
			int n = 8;
			int board[8][8] = { { 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 }
			};

			int result = solve_nsnipers(&board[0][0], n);
			Assert::AreEqual(1, result, L"1 should be 1", 1,2);
			int check = check_board(&board[0][0], n);
			Assert::AreEqual(1, check, L"Fail for 8 board", 1,2);
		}
		[TestMethod, Timeout(5000)]
		void SixteenBoard()
		{
			int n = 16;
			int board[16][16];
			int i = 0, j = 0;
			for (i = 0; i < n; i++){
				for (j = 0; j < n; j++){
					board[i][j] = 0;
				}
			}

			int result = solve_nsnipers(&board[0][0], n);
			Assert::AreEqual(1, result, L"1 should be 1", 1,2);
			int check = check_board(&board[0][0], n);
			Assert::AreEqual(1, check, L"Fail for 16 board", 1,2);
		}

	};
}
