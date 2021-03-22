#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "../src/ChessMoves.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class ChessMovesSpec
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
		
		[TestMethod, Timeout(1000)]
		void ChessMoves_Samples()
		{
			long long int sourceX, sourceY;
			long long int destX, destY;
			long long int res;
			char piece;


			piece = 'B';
			sourceX = sourceY = 5;
			destX = destY = 1;
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, piece);
			Assert::AreEqual(res, 1LL, L"Wrong Answer", 1, 2);


			piece = 'B';
			sourceX = sourceY = 5;
			destX = 5; destY = 4;
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, piece);
			Assert::AreEqual(res, -1LL, L"Wrong Answer", 1, 2);


			piece = 'R';
			sourceX = sourceY = 5;
			destX = 5; destY = 3;
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, piece);
			Assert::AreEqual(res, 1LL, L"Wrong Answer", 1, 2);


			piece = 'K';
			sourceX = sourceY = 5;
			destX = 5; destY = 1;
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, piece);
			Assert::AreEqual(res, 4LL, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void ChessMoves_Test01()
		{
			long long int sourceX, sourceY;
			long long int destX, destY;
			long long int res;
			sourceX = 3;  sourceY = 3;
			destX = 2;  destY = 4;

			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'B');
			Assert::AreEqual(res, 1LL, L"Wrong Answer1", 1, 2);
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'R');
			Assert::AreEqual(res, 2LL, L"Wrong Answer2", 1, 2);
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'K');
			Assert::AreEqual(res, 1LL, L"Wrong Answer3", 1, 2);
		};
		
		[TestMethod, Timeout(1000)]
		void ChessMoves_Test02()
		{
			long long int sourceX, sourceY;
			long long int destX, destY;
			long long int res;
			sourceX = 1;  sourceY = 3;
			destX = 1;  destY = 5;

			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'B');
			Assert::AreEqual(res, 2LL, L"Wrong Answer1", 1, 2);
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'R');
			Assert::AreEqual(res, 1LL, L"Wrong Answer2", 1, 2);
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'K');
			Assert::AreEqual(res, 2LL, L"Wrong Answer3", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void ChessMoves_Test03()
		{
			long long int sourceX, sourceY;
			long long int destX, destY;
			long long int res;
			sourceX = 1;  sourceY = 6;
			destX = 1;  destY = 2;

			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'B');
			Assert::AreEqual(res, 2LL, L"Wrong Answer1", 1, 2);
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'R');
			Assert::AreEqual(res, 1LL, L"Wrong Answer2", 1, 2);
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'K');
			Assert::AreEqual(res, 4LL, L"Wrong Answer3", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void ChessMoves_Test04()
		{
			long long int sourceX, sourceY;
			long long int destX, destY;
			long long int res;
			sourceX = 4;  sourceY = 3;
			destX = 1;  destY = 6;

			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'B');
			Assert::AreEqual(res, 1LL, L"Wrong Answer1", 1, 2);
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'R');
			Assert::AreEqual(res, 2LL, L"Wrong Answer2", 1, 2);
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'K');
			Assert::AreEqual(res, 3LL, L"Wrong Answer3", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void ChessMoves_Test05()
		{
			long long int sourceX, sourceY;
			long long int destX, destY;
			long long int res;
			sourceX = 1;  sourceY = 5;
			destX = 6;  destY = 4;

			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'B');
			Assert::AreEqual(res, 2LL, L"Wrong Answer1", 1, 2);
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'R');
			Assert::AreEqual(res, 2LL, L"Wrong Answer2", 1, 2);
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'K');
			Assert::AreEqual(res, 5LL, L"Wrong Answer3", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void ChessMoves_Test06()
		{
			long long int sourceX, sourceY;
			long long int destX, destY;
			long long int res;
			sourceX = 1;  sourceY = 2;
			destX = 3;  destY = 2;

			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'B');
			Assert::AreEqual(res, 2LL, L"Wrong Answer1", 1, 2);
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'R');
			Assert::AreEqual(res, 1LL, L"Wrong Answer2", 1, 2);
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'K');
			Assert::AreEqual(res, 2LL, L"Wrong Answer3", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void ChessMoves_Test07()
		{
			long long int sourceX, sourceY;
			long long int destX, destY;
			long long int res;
			sourceX = 1;  sourceY = 8;
			destX = 1;  destY = 1;

			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'B');
			Assert::AreEqual(res, -1LL, L"Wrong Answer1", 1, 2);
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'R');
			Assert::AreEqual(res, 1LL, L"Wrong Answer2", 1, 2);
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'K');
			Assert::AreEqual(res, 7LL, L"Wrong Answer3", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void ChessMoves_Test08()
		{
			long long int sourceX, sourceY;
			long long int destX, destY;
			long long int res;
			sourceX = 8;  sourceY = 1;
			destX = 8;  destY = 8;

			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'B');
			Assert::AreEqual(res, -1LL, L"Wrong Answer1", 1, 2);
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'R');
			Assert::AreEqual(res, 1LL, L"Wrong Answer2", 1, 2);
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'K');
			Assert::AreEqual(res, 7LL, L"Wrong Answer3", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void ChessMoves_Test09()
		{
			long long int sourceX, sourceY;
			long long int destX, destY;
			long long int res;
			sourceX = 8;  sourceY = 8;
			destX = 8;  destY = 8;

			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'B');
			Assert::AreEqual(res, 0LL, L"Wrong Answer1", 1, 2);
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'R');
			Assert::AreEqual(res, 0LL, L"Wrong Answer2", 1, 2);
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'K');
			Assert::AreEqual(res, 0LL, L"Wrong Answer3", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void ChessMoves_Test10()
		{
			long long int sourceX, sourceY;
			long long int destX, destY;
			long long int res;
			sourceX = 8;  sourceY = 8;
			destX = 8;  destY = 8;

			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'B');
			Assert::AreEqual(res, 0LL, L"Wrong Answer1", 1, 2);
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'R');
			Assert::AreEqual(res, 0LL, L"Wrong Answer2", 1, 2);
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'K');
			Assert::AreEqual(res, 0LL, L"Wrong Answer3", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void ChessMoves_Test11()
		{
			long long int sourceX, sourceY;
			long long int destX, destY;
			long long int res;
			sourceX = 1;  sourceY = 1;
			destX = 100000000000000000;  destY = 100000000000000000;

			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'B');
			Assert::AreEqual(res, 1LL, L"Wrong Answer1", 1, 2);
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'R');
			Assert::AreEqual(res, 2LL, L"Wrong Answer2", 1, 2);
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'K');
			Assert::AreEqual(res, 99999999999999999LL, L"Wrong Answer3", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void ChessMoves_Test12()
		{
			long long int sourceX, sourceY;
			long long int destX, destY;
			long long int res;
			sourceX = 1225;  sourceY = 2684;
			destX = 236598798LL;  destY = 65897000000;

			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'B');
			Assert::AreEqual(res, -1LL, L"Wrong Answer1", 1, 2);
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'R');
			Assert::AreEqual(res, 2LL, L"Wrong Answer2", 1, 2);
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'K');
			Assert::AreEqual(res, 65896997316, L"Wrong Answer3", 1, 2);
		};


		[TestMethod, Timeout(1000)]
		void ChessMoves_Test13()
		{
			long long int sourceX, sourceY;
			long long int destX, destY;
			long long int res;
			sourceX = 325897;  sourceY = 12213323;
			destX = 6556498;  destY = 100000000000000000;

			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'B');
			Assert::AreEqual(res, 2LL, L"Wrong Answer1", 1, 2);
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'R');
			Assert::AreEqual(res, 2LL, L"Wrong Answer2", 1, 2);
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'K');
			Assert::AreEqual(res, 99999999987786677LL, L"Wrong Answer3", 1, 2);

		};

		[TestMethod, Timeout(1000)]
		void ChessMoves_Test14()
		{
			long long int sourceX, sourceY;
			long long int destX, destY;
			long long int res;
			sourceX = 2365984;  sourceY = 324654;
			destX = 654989765498;  destY = 56498516798;

			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'B');
			Assert::AreEqual(res, 2LL, L"Wrong Answer1", 1, 2);
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'R');
			Assert::AreEqual(res, 2LL, L"Wrong Answer2", 1, 2);
			res = minimumPieceMoves(sourceX, sourceY, destX, destY, 'K');
			Assert::AreEqual(res, 654987399514LL, L"Wrong Answer3", 1, 2);
		};
	};

}