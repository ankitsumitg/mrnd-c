#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "../src/ChessPawns.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class ChessPawnsSpec
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

#define ___ '.'
#define _b_ 'b'
#define _w_ 'w'


		[TestMethod, Timeout(1000)]
		void ChessGame_Samples_Test01()
		{
			char board1[8][8] =
			{
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ _b_, _b_, _b_, _b_, _b_, _b_, _b_, _b_ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ _w_, _w_, _w_, _w_, _w_, _w_, _w_, _w_ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
			};
			char colorWon1;
			int minMoves1 = chessGame(board1, &colorWon1);
			Assert::AreEqual(minMoves1, 0, L"Wrong Answer", 1, 2);
			Assert::AreEqual(colorWon1, '\0', L"Wrong Answer", 1, 2);


			char board2[8][8] =
			{
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, _b_, _b_ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, _b_, ___ },
				{ _w_, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
			};
			char colorWon2;
			int minMoves2 = chessGame(board2, &colorWon2);
			Assert::AreEqual(minMoves2, 2, L"Wrong Answer", 1, 2);
			Assert::AreEqual(colorWon2, 'b', L"Wrong Answer", 1, 2);

			char board3[8][8] =
			{
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, _b_, ___, ___, ___, ___ },
				{ ___, ___, ___, _w_, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
			};
			char colorWon3;
			int minMoves3 = chessGame(board3, &colorWon3);
			Assert::AreEqual(minMoves3, 0, L"Wrong Answer", 1, 2);
			Assert::AreEqual(colorWon3, '\0', L"Wrong Answer", 1, 2);
		};


		[TestMethod, Timeout(1000)]
		void ChessGame_Test02()
		{
			char board[8][8] =
			{
				{ _b_, ___, ___, ___, ___, ___, ___, ___ },
				{ _w_, ___, ___, ___, ___, ___, ___, ___ },
				{ _b_, ___, ___, ___, ___, ___, _w_, ___ },
				{ _w_, ___, ___, ___, _w_, ___, ___, ___ },
				{ ___, ___, _w_, ___, ___, ___, ___, _w_ },
				{ ___, ___, ___, ___, ___, _w_, ___, ___ },
				{ ___, _w_, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, _w_, ___, ___, ___ },
			};


			char colorWon;
			int minMoves = chessGame(board, &colorWon);
			Assert::AreEqual(minMoves, 2, L"Wrong Answer", 1, 2);
			Assert::AreEqual(colorWon, 'w', L"Wrong Answer", 1, 2);
		};


		[TestMethod, Timeout(1000)]
		void ChessGame_Test03()
		{
			char board[8][8] =
			{
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ _b_, _b_, _b_, _b_, ___, ___, ___, ___ },
				{ _w_, _w_, _w_, _w_, _b_, _b_, _b_, _b_ },
				{ ___, ___, ___, ___, _w_, _w_, _w_, _w_ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
			};


			char colorWon;
			int minMoves = chessGame(board, &colorWon);
			Assert::AreEqual(minMoves, 0, L"Wrong Answer", 1, 2);
			Assert::AreEqual(colorWon, '\0', L"Wrong Answer", 1, 2);
		};


		[TestMethod, Timeout(1000)]
		void ChessGame_Test04()
		{
			char board[8][8] =
			{
				{ _w_, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, _w_, _b_, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ _b_, ___, ___, ___, ___, ___, ___, ___ },
			};


			char colorWon;
			int minMoves = chessGame(board, &colorWon);
			Assert::AreEqual(minMoves, -1, L"Wrong Answer", 1, 2);
			Assert::AreEqual(colorWon, '\0', L"Wrong Answer", 1, 2);
		};


		[TestMethod, Timeout(1000)]
		void ChessGame_Test05()
		{
			char board[8][8] =
			{
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, _w_, ___, _w_, ___, _w_, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, _b_, ___, _b_, ___, _b_, ___, ___ },
				{ ___, ___, ___, _b_, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
			};


			char colorWon;
			int minMoves = chessGame(board, &colorWon);
			Assert::AreEqual(minMoves, 1, L"Wrong Answer", 1, 2);
			Assert::AreEqual(colorWon, 'b', L"Wrong Answer", 1, 2);
		};


		[TestMethod, Timeout(1000)]
		void ChessGame_Test06()
		{
			char board[8][8] =
			{
				{ ___, ___, _b_, ___, ___, ___, ___, ___ },
				{ ___, ___, _w_, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, _b_, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, _w_, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, _b_, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
			};


			char colorWon;
			int minMoves = chessGame(board, &colorWon);
			Assert::AreEqual(minMoves, 2, L"Wrong Answer", 1, 2);
			Assert::AreEqual(colorWon, 'b', L"Wrong Answer", 1, 2);
		};


		[TestMethod, Timeout(1000)]
		void ChessGame_Test07()
		{
			char board[8][8] =
			{
				{ ___, ___, _b_, _b_, ___, ___, ___, ___ },
				{ ___, _w_, _b_, _w_, _b_, _w_, _b_, _b_ },
				{ ___, ___, ___, ___, ___, _b_, _b_, _b_ },
				{ ___, ___, _w_, _w_, ___, ___, ___, ___ },
				{ ___, _w_, ___, _w_, ___, ___, ___, _w_ },
				{ _w_, _w_, _w_, ___, ___, ___, _w_, ___ },
				{ ___, _w_, ___, ___, ___, ___, _w_, ___ },
				{ _w_, ___, ___, ___, _w_, ___, _w_, ___ },
			};


			char colorWon;
			int minMoves = chessGame(board, &colorWon);
			Assert::AreEqual(minMoves, 1, L"Wrong Answer", 1, 2);
			Assert::AreEqual(colorWon, 'w', L"Wrong Answer", 1, 2);
		};


		[TestMethod, Timeout(1000)]
		void ChessGame_Test08()
		{
			char board[8][8] =
			{
				{ _b_, _b_, ___, ___, ___, ___, _b_, ___ },
				{ _b_, ___, ___, ___, ___, ___, _b_, ___ },
				{ ___, ___, ___, ___, ___, _b_, ___, ___ },
				{ ___, ___, _b_, ___, ___, ___, _b_, _b_ },
				{ ___, _w_, ___, _b_, _w_, _b_, _w_, _b_ },
				{ ___, ___, ___, ___, _w_, ___, ___, ___ },
				{ _w_, _w_, ___, _w_, _w_, _w_, ___, ___ },
				{ ___, ___, ___, ___, _w_, ___, ___, ___ },
			};


			char colorWon;
			int minMoves = chessGame(board, &colorWon);
			Assert::AreEqual(minMoves, 3, L"Wrong Answer", 1, 2);
			Assert::AreEqual(colorWon, 'b', L"Wrong Answer", 1, 2);
		};


		[TestMethod, Timeout(1000)]
		void ChessGame_Test09()
		{
			char board[8][8] =
			{
				{ ___, _b_, ___, _b_, ___, ___, _b_, ___ },
				{ _b_, ___, _b_, ___, ___, ___, ___, _b_ },
				{ ___, ___, ___, _b_, ___, _b_, ___, _b_ },
				{ ___, ___, _b_, ___, _w_, ___, ___, _b_ },
				{ ___, _b_, _b_, _b_, ___, _b_, ___, _b_ },
				{ _b_, ___, _b_, _b_, ___, _b_, ___, _b_ },
				{ _b_, _b_, ___, ___, _b_, _b_, _b_, _b_ },
				{ _w_, ___, _w_, ___, _w_, ___, _w_, _w_ },
			};


			char colorWon;
			int minMoves = chessGame(board, &colorWon);
			Assert::AreEqual(minMoves, 1, L"Wrong Answer", 1, 2);
			Assert::AreEqual(colorWon, 'b', L"Wrong Answer", 1, 2);
		};


		[TestMethod, Timeout(1000)]
		void ChessGame_Test10()
		{
			char board[8][8] =
			{
				{ ___, _b_, _b_, ___, _b_, ___, _b_, ___ },
				{ _b_, ___, ___, _b_, ___, ___, _b_, ___ },
				{ ___, _b_, ___, _b_, _b_, ___, ___, ___ },
				{ _b_, _b_, ___, ___, ___, ___, ___, _b_ },
				{ _b_, _b_, _b_, ___, ___, ___, ___, _b_ },
				{ _b_, ___, ___, _b_, _b_, ___, ___, ___ },
				{ _b_, _b_, ___, _b_, ___, ___, ___, _b_ },
				{ ___, ___, ___, ___, _w_, _w_, _w_, ___ },
			};


			char colorWon;
			int minMoves = chessGame(board, &colorWon);
			Assert::AreEqual(minMoves, 1, L"Wrong Answer", 1, 2);
			Assert::AreEqual(colorWon, 'b', L"Wrong Answer", 1, 2);
		};


		[TestMethod, Timeout(1000)]
		void ChessGame_Test11()
		{
			char board[8][8] =
			{
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, _b_, ___, ___, ___, ___, _b_, ___ },
				{ ___, ___, ___, ___, _w_, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, _w_, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
			};
			char colorWon;
			int minMoves = chessGame(board, &colorWon);
			Assert::AreEqual(minMoves, 3, L"Wrong Answer", 1, 2);
			Assert::AreEqual(colorWon, 'w', L"Wrong Answer", 1, 2);
		};


		[TestMethod, Timeout(1000)]
		void ChessGame_Test12()
		{
			char board[8][8] =
			{
				{ _b_, _b_, _b_, _b_, _b_, _b_, ___, _b_ },
				{ ___, _b_, _b_, ___, _b_, _b_, ___, _b_ },
				{ _w_, _w_, ___, ___, ___, _b_, ___, _w_ },
				{ ___, ___, _w_, _w_, ___, _w_, ___, _w_ },
				{ _b_, ___, _b_, ___, ___, _w_, ___, _w_ },
				{ ___, ___, _b_, ___, ___, _b_, ___, ___ },
				{ _b_, ___, ___, _b_, _w_, ___, ___, _w_ },
				{ _w_, _w_, _w_, _w_, _w_, _w_, _w_, _w_ },
			};

			char colorWon;
			int minMoves = chessGame(board, &colorWon);
			Assert::AreEqual(minMoves, 7, L"Wrong Answer", 1, 2);
			Assert::AreEqual(colorWon, 'w', L"Wrong Answer", 1, 2);
		};


		[TestMethod, Timeout(1000)]
		void ChessGame_Test13()
		{
			char board[8][8] =
			{
				{ ___, _b_, ___, ___, _b_, _b_, _b_, _b_ },
				{ _b_, _b_, ___, ___, ___, _w_, _w_, _b_ },
				{ _b_, ___, ___, _b_, ___, _w_, ___, _b_ },
				{ ___, _b_, ___, _w_, ___, ___, ___, _b_ },
				{ ___, ___, ___, _w_, ___, _w_, _w_, ___ },
				{ _w_, ___, ___, ___, ___, ___, _w_, ___ },
				{ _w_, _b_, ___, _w_, ___, _w_, ___, _w_ },
				{ ___, _w_, _w_, ___, ___, ___, _w_, _w_ },
			};

			char colorWon;
			int minMoves = chessGame(board, &colorWon);
			Assert::AreEqual(minMoves, 7, L"Wrong Answer", 1, 2);
			Assert::AreEqual(colorWon, 'w', L"Wrong Answer", 1, 2);
		};


		[TestMethod, Timeout(1000)]
		void ChessGame_Test14()
		{
			char board[8][8] =
			{
				{ _b_, _b_, ___, ___, _b_, _b_, ___, ___ },
				{ _b_, ___, ___, _w_, ___, _w_, ___, _b_ },
				{ ___, ___, _b_, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, _b_, _b_, ___ },
				{ ___, _b_, ___, ___, _b_, ___, ___, _b_ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, _b_, _b_, ___, _b_, ___ },
				{ _w_, ___, _w_, _w_, _w_, _w_, ___, _w_ },
			};

			char colorWon;
			int minMoves = chessGame(board, &colorWon);
			Assert::AreEqual(minMoves, 1, L"Wrong Answer", 1, 2);
			Assert::AreEqual(colorWon, 'w', L"Wrong Answer", 1, 2);
		};


		[TestMethod, Timeout(1000)]
		void ChessGame_Test15()
		{
			char board[8][8] =
			{
				{ ___, ___, _b_, _b_, ___, ___, ___, ___ },
				{ ___, _b_, ___, _b_, ___, _b_, ___, _b_ },
				{ ___, ___, _b_, ___, _b_, ___, ___, ___ },
				{ ___, ___, _b_, ___, ___, _b_, ___, _b_ },
				{ _w_, _w_, _w_, _b_, _w_, _w_, _b_, ___ },
				{ ___, _b_, _b_, ___, ___, ___, _b_, ___ },
				{ ___, ___, _b_, _b_, _b_, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, _w_, ___ },
			};


			char colorWon;
			int minMoves = chessGame(board, &colorWon);
			Assert::AreEqual(minMoves, 1, L"Wrong Answer", 1, 2);
			Assert::AreEqual(colorWon, 'b', L"Wrong Answer", 1, 2);
		};


		[TestMethod, Timeout(1000)]
		void ChessGame_Test16()
		{
			char board[8][8] =
			{
				{ _b_, _b_, _b_, _b_, ___, _b_, _b_, _b_ },
				{ ___, _b_, ___, ___, ___, ___, ___, _b_ },
				{ _b_, _b_, ___, _b_, ___, ___, ___, _b_ },
				{ _w_, _w_, _w_, _w_, ___, _w_, _w_, ___ },
				{ ___, ___, ___, ___, ___, ___, _w_, _w_ },
				{ _w_, _w_, _w_, ___, ___, _b_, _b_, _b_ },
				{ _w_, ___, _b_, _w_, ___, _b_, _b_, ___ },
				{ _w_, _w_, _w_, _w_, _w_, _w_, _w_, ___ },
			};

			char colorWon;
			int minMoves = chessGame(board, &colorWon);
			Assert::AreEqual(minMoves, 2, L"Wrong Answer", 1, 2);
			Assert::AreEqual(colorWon, 'b', L"Wrong Answer", 1, 2);
		};


		[TestMethod, Timeout(1000)]
		void ChessGame_Test17()
		{
			char board[8][8] =
			{
				{ ___, ___, ___, ___, _b_, _b_, ___, ___ },
				{ _b_, _b_, ___, ___, ___, ___, ___, ___ },
				{ ___, _b_, ___, ___, ___, ___, ___, _b_ },
				{ _w_, _w_, ___, ___, _w_, _w_, _w_, ___ },
				{ ___, ___, ___, _b_, _b_, ___, _b_, ___ },
				{ _b_, ___, ___, ___, _b_, _b_, ___, ___ },
				{ ___, ___, _w_, ___, ___, _w_, _w_, _w_ },
				{ ___, ___, ___, _w_, ___, ___, ___, _w_ },
			};

			char colorWon;
			int minMoves = chessGame(board, &colorWon);
			Assert::AreEqual(minMoves, 2, L"Wrong Answer", 1, 2);
			Assert::AreEqual(colorWon, 'b', L"Wrong Answer", 1, 2);
		};


		[TestMethod, Timeout(1000)]
		void ChessGame_Test18()
		{
			char board[8][8] =
			{
				{ _b_, ___, _b_, ___, ___, ___, _b_, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, _b_ },
				{ ___, _b_, _b_, ___, ___, ___, ___, _b_ },
				{ ___, ___, ___, ___, ___, _w_, ___, ___ },
				{ ___, _w_, ___, _w_, _w_, ___, _w_, ___ },
				{ ___, ___, ___, _w_, ___, _w_, _w_, ___ },
				{ _w_, ___, ___, _w_, _w_, ___, ___, _w_ },
			};

			char colorWon;
			int minMoves = chessGame(board, &colorWon);
			Assert::AreEqual(minMoves, 4, L"Wrong Answer", 1, 2);
			Assert::AreEqual(colorWon, 'w', L"Wrong Answer", 1, 2);
		};


		[TestMethod, Timeout(1000)]
		void ChessGame_Test19()
		{
			char board[8][8] =
			{
				{ _b_, _b_, _b_, _b_, ___, _b_, _b_, _b_ },
				{ _b_, _b_, _b_, _b_, ___, _b_, ___, _b_ },
				{ _b_, ___, _b_, _b_, ___, _b_, _b_, _b_ },
				{ _b_, ___, _b_, _b_, ___, _b_, _w_, _w_ },
				{ _b_, ___, _b_, _b_, ___, _b_, _b_, _b_ },
				{ _b_, ___, _b_, _b_, ___, _b_, _b_, _b_ },
				{ ___, ___, _b_, _w_, ___, _b_, _b_, ___ },
				{ _w_, ___, _w_, _w_, _w_, _w_, _w_, _w_ },
			};

			char colorWon;
			int minMoves = chessGame(board, &colorWon);
			Assert::AreEqual(minMoves, 6, L"Wrong Answer", 1, 2);
			Assert::AreEqual(colorWon, 'b', L"Wrong Answer", 1, 2);
		};


		[TestMethod, Timeout(1000)]
		void ChessGame_Test20()
		{
			char board[8][8] =
			{
				{ ___, _b_, _b_, _b_, _b_, _b_, _b_, ___ },
				{ _b_, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, ___, ___, ___, ___, ___, ___, ___ },
				{ ___, _w_, _w_, _w_, _w_, _w_, _w_, _w_ },
			};

			char colorWon;
			int minMoves = chessGame(board, &colorWon);
			Assert::AreEqual(minMoves, 6, L"Wrong Answer", 1, 2);
			Assert::AreEqual(colorWon, 'b', L"Wrong Answer", 1, 2);
		};
	};

}