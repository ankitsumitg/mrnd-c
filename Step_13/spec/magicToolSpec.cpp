#include "stdafx.h"
#include <stdlib.h>
#include "../src/magicTool.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class magicToolSpec
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

		bool isContains(Point* container, int size, Point a) {
			for (int i = 0; i < size; i++) {
				if (container[i].x == a.x && container[i].y == a.y) {
					return true;
				}
			}
			return false;
		}

		void compareResults(result expected, result res) {
			Assert::AreEqual(expected.size, res.size, L"0 Str pairs should be 0", 1, 2);
			
			int boolCount = 0;
			for (int i = 0; i < res.size; i++) {
				bool contains = isContains(expected.selected, expected.size, res.selected[i]);
				if (contains) {
					boolCount += 1;
				}
			}
			Assert::AreEqual(expected.size, boolCount, L"Selected points are not equal", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void magic_tool_basic()
		{
			char pixels[][3] = {
				{ 'r', 'g', 'r' },
				{ 'r', 'g', 'r' },
				{ 'r', 'g', 'r' }
			};

			bool visited[3][3] = {
				{ true, false, false },
				{ true, false, false },
				{ true, false, false }
			};

			Point pivot = { 0, 0 };
			int m = 2;
			int n = 2;
			result res = select_wrapper(&pixels[0][0], m, n, pivot);
			result expected;
			expected.size = 3;
			expected.selected = new Point[3];
			expected.selected[0] = { 0, 0 };
			expected.selected[1] = { 1, 0 };
			expected.selected[2] = { 2, 0 };
			expected.visited = &visited[0][0];
			
			compareResults(expected, res);
		}

		[TestMethod, Timeout(3000)]
		void magic_tool_single()
		{

			char pixels[1][1] = { {'r'} };
			int m = 0;
			int n = 0;

			bool visited[1][1] = { true };

			Point pivot = { 0, 0 };
			
			result res = select_wrapper(&pixels[0][0], m, n, pivot);
			result expected;
			expected.size = 1;
			expected.selected = new Point[1];
			expected.selected[0] = { 0, 0 };
			expected.visited = &visited[0][0];

			Assert::AreEqual(expected.size, res.size, L"0 Str pairs should be 0", 1, 2);

			compareResults(expected, res);
		}

		[TestMethod, Timeout(3000)]
		void magic_tool_null_check()
		{

			result res = select_wrapper(NULL, 1, 1, {0,0});
			result expected;
			expected.size = 0;
			expected.selected = {};
			expected.visited = {};

			compareResults(expected, res);	
		}

		[TestMethod, Timeout(3000)]
		void magic_tool_basic_2()
		{

			char pixels[][4] = {
				{ 'r', 'g', 'r', 'b' },
				{ 'g', 'r', 'r', 'b' },
				{ 'r', 'g', 'b', 'b' }
			};

			bool visited[3][4] = {
				{ false, false, true, false },
				{ false, true, true, false },
				{ false, false, false, false }
			};
			int m = 2;
			int n = 3;

			Point pivot = { 1, 1 };

			result res = select_wrapper(&pixels[0][0], m, n, pivot);
			result expected;
			expected.size = 3;
			expected.selected = new Point[3];
			expected.selected[0] = { 1, 1 };
			expected.selected[1] = { 1, 2 };
			expected.selected[2] = { 0, 2 };
			expected.visited = &visited[0][0];

			compareResults(expected, res);
		}

		[TestMethod, Timeout(3000)]
		void magic_tool_basic_3()
		{

			char pixels[][4] = {
				{ 'r', 'g', 'r', 'b' },
				{ 'g', 'r', 'r', 'b' },
				{ 'r', 'g', 'b', 'b' }
			};

			bool visited[3][4] = {
				{ false, false, false, true },
				{ false, false, false, true },
				{ false, false, true, true }
			};
			int m = 2;
			int n = 3;

			Point pivot = { 2, 3 };

			result res = select_wrapper(&pixels[0][0], m, n, pivot);
			result expected;
			expected.size = 4;
			expected.selected = new Point[4];
			expected.selected[0] = { 0, 3 };
			expected.selected[1] = { 1, 3 };
			expected.selected[2] = { 2, 2 };
			expected.selected[3] = { 2, 3 };
			expected.visited = &visited[0][0];

			compareResults(expected, res);
		}

		[TestMethod, Timeout(3000)]
		void magic_tool_invalid_neg_pivot()
		{

			char pixels[][4] = {
				{ 'r', 'g', 'r', 'b' },
				{ 'g', 'r', 'r', 'b' },
				{ 'r', 'g', 'b', 'b' }
			};

			bool visited[3][4] = {
				{ true, false, false, false },
				{ true, false, false, false },
				{ true, false, false, false }
			};
			int m = 2;
			int n = 3;

			Point pivot = { -1, -1 };

			result res = select_wrapper(&pixels[0][0], m, n, pivot);
			result expected;

			expected.size = 0;
			expected.selected = {};
			expected.visited = {};
			compareResults(expected, res);
		}

		[TestMethod, Timeout(3000)]
		void magic_tool_invalid_exceeding_pivot()
		{

			char pixels[][4] = {
				{ 'r', 'g', 'r', 'b' },
				{ 'g', 'r', 'r', 'b' },
				{ 'r', 'g', 'b', 'b' }
			};

			bool visited[3][4] = {
				{ true, false, false, false },
				{ true, false, false, false },
				{ true, false, false, false }
			};
			int m = 2;
			int n = 3;

			Point pivot = { 10, 1 };

			result res = select_wrapper(&pixels[0][0], m, n, pivot);
			result expected;

			expected.size = 0;
			expected.selected = {};
			expected.visited = {};
			compareResults(expected, res);
		}
	};
}
