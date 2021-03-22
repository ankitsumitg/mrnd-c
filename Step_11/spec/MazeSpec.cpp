#include "stdafx.h"
#include "./../src/Maze.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class MazeSpec
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
		[TestMethod(), Timeout(3000)]
		void Maze_InvalidSize()
		{
			int maze[4][4] = {
				{ 1, 0, 0, 0 },
				{ 0, 0, 0, 1 },
				{ 0, 0, 0, 0 },
				{ 1, 1, 1, 1 }
			};

			int m = -4, n = 4;
			int x1 = 0, y1 = 0, x2 = 2, y2 = 2;
			Assert::AreEqual(0, path_exists((int*)maze, m, n, x1, y1, x2, y2), L"Error at Invalid Size", 1, 2);

			m = 0, n = 4;
			x1 = 0, y1 = 0, x2 = 2, y2 = 2;
			Assert::AreEqual(0, path_exists((int*)maze, m, n, x1, y1, x2, y2), L"Error at Invalid Size", 1, 2);

			m = 0, n = -4;
			x1 = 0, y1 = 0, x2 = 2, y2 = 2;
			Assert::AreEqual(0, path_exists((int*)maze, m, n, x1, y1, x2, y2), L"Error at Invalid Size", 1, 2);
			;
		}
		
		[TestMethod(), Timeout(3000)]
		void Invalid_Co_ordinates()
		{
			int maze[4][3] = {
				{ 1, 0, 0 },
				{ 0, 1, 0 },
				{ 0, 1, 1 },
				{ 1, 1, 1 }
			};

			int m = 4, n = 3;
			int x1 = -5, y1 = 0, x2 = 2, y2 = 2;
			Assert::AreEqual(0, path_exists(&maze[0][0], m, n, x1, y1, x2, y2), L"Error at Invalid Co-ordinates", 1, 2);

			x1 = 1, y1 = 0, x2 = 2, y2 = 3;
			Assert::AreEqual(0, path_exists(&maze[0][0], m, n, x1, y1, x2, y2), L"Error at Invalid Co-ordinates", 1, 2);
			
		}
		
		[TestMethod(), Timeout(3000)]
		void Maze_6x1()
		{
			int maze[6][1] = {
				{ 1 },
				{ 1 },
				{ 1 },
				{ 1 },
				{ 0 },
				{ 1 },
			};

			int m = 6, n = 1;
			int x1 = 0, y1 = 0, x2 = 3, y2 = 0;
			Assert::AreEqual(1, path_exists((int*)maze, m, n, x1, y1, x2, y2), L"Error for 6x1 Maze", 1, 2);

			x1 = 0, y1 = 0, x2 = 5, y2 = 0;
			Assert::AreEqual(0, path_exists((int*)maze, m, n, x1, y1, x2, y2), L"Error for 6x1 Maze", 1, 2);
			
		}
		
		[TestMethod(), Timeout(3000)]
		void Maze_1x20()
		{
			int maze[1][20] = {
				{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
			};

			int m = 1, n = 20;
			int x1 = 0, y1 = 0, x2 = 0, y2 = 8;
			Assert::AreEqual(1, path_exists((int*)maze, m, n, x1, y1, x2, y2), L"Error for 1x20 Maze", 1, 2);

			x1 = 0, y1 = 0, x2 = 0, y2 = 17;
			Assert::AreEqual(0, path_exists((int*)maze, m, n, x1, y1, x2, y2), L"Error for 1x20 Maze", 1, 2);
			
		}

		
		[TestMethod(), Timeout(3000)]
		void Maze_6x6()
		{
			int maze[6][6] = {
				{ 1, 0, 0, 0, 0, 0 },
				{ 1, 1, 1, 1, 0, 0 },
				{ 0, 0, 0, 1, 0, 0 },
				{ 1, 0, 0, 1, 1, 1 },
				{ 0, 0, 0, 1, 0, 1 },
				{ 0, 0, 0, 1, 1, 1 }
			};

			int m = 6, n = 6;
			int x1 = 0, y1 = 0, x2 = 5, y2 = 5;
			Assert::AreEqual(1, path_exists((int*)maze, m, n, x1, y1, x2, y2), L"Error for 6x6 Maze", 1, 2);
			
		}


		[TestMethod(), Timeout(3000)]
		void Maze_3x5()
		{
			int maze[3][5] = {
				{ 1, 0, 0, 0, 1 },
				{ 1, 1, 0, 1, 1 },
				{ 0, 1, 1, 1, 0 }
			};

			int m = 3, n = 5;
			int x1 = 0, y1 = 0, x2 = 0, y2 = 4;
			Assert::AreEqual(1, path_exists((int*)maze, m, n, x1, y1, x2, y2), L"Error for 3x5 Maze", 1, 2);


			x1 = 0, y1 = 0, x2 = 2, y2 = 2;
			Assert::AreEqual(1, path_exists((int*)maze, m, n, x1, y1, x2, y2), L"Error for 3x5 Maze", 1,2);


			x1 = 1, y1 = 0, x2 = 2, y2 = 3;
			Assert::AreEqual(1, path_exists((int*)maze, m, n, x1, y1, x2, y2), L"Error for 3x5 Maze", 1,2);


			x1 = 0, y1 = 0, x2 = 2, y2 = 3;
			Assert::AreEqual(1, path_exists((int*)maze, m, n, x1, y1, x2, y2), L"Error for 3x5 Maze", 1,2);

			x1 = 0, y1 = 0, x2 = 1, y2 = 2;
			Assert::AreEqual(0, path_exists((int*)maze, m, n, x1, y1, x2, y2), L"Error for 3x5 Maze", 1,2);
			
						
		}
		

	};
}
