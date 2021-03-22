#include "stdafx.h"
#include "../src/LastOne.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class LastOneSpec
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
		void lastOne_Sample1()
		{
			const int N = 5, M = 5;
			int values[N][M] = {
				{ 2, 1, 0, 2, 1 },
				{ 1, 0, 1, 2, 1 },
				{ 1, 0, 0, 2, 1 }
			};
			int res = lastOne(&values[0][0], 3, 5);
			Assert::AreEqual(2, res, L"Wrong Answer", 1, 2);

		};

		[TestMethod, Timeout(1000)]
		void lastOne_Sample2()
		{
			const int N = 4, M = 4;
			int values[N][M] = {
				{ 2, 1, 0, 1 },
				{ 1, 1, 1, 0 },
				{ 0, 0, 0, 1 },
				{ 2, 1, 1, 0 }
			};
			int res = lastOne(&values[0][0], 4, 4);
			//-1 as the top right 1 cant be converted
			Assert::AreEqual(-1, res, L"Wrong Answer", 1, 2);

		};

		[TestMethod, Timeout(1000)]
		void lastOne_Real01()
		{
			const int N = 4, M = 4;
			int values[N][M] = {
				{ 1, 1, 0, 1 },
				{ 1, 1, 1, 1 },
				{ 0, 0, 0, 1 },
				{ 2, 1, 1, 1 }
			};
			int res = lastOne(&values[0][0], 4, 4);
			Assert::AreEqual(9, res, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void lastOne_Real02()
		{
			const int N = 4, M = 4;
			int values[N][M] = {
				{ 1, 1, 0, 1 },
				{ 1, 1, 2, 1 },
				{ 0, 0, 0, 1 },
				{ 2, 1, 1, 1 }
			};
			int res = lastOne(&values[0][0], 4, 4);
			Assert::AreEqual(3, res, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void lastOne_Real03()
		{
			const int N = 4, M = 4;
			int values[N][M] = {
				{ 1, 1, 1, 1 },
				{ 1, 1, 2, 1 },
				{ 1, 1, 1, 1 },
				{ 2, 1, 1, 1 }
			};
			int res = lastOne(&values[0][0], 4, 4);
			Assert::AreEqual(3, res, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void lastOne_Real04()
		{
			const int N = 4, M = 4;
			int values[N][M] = {
				{ 2, 1, 1, 0 },
				{ 2, 1, 0, 0 },
				{ 2, 1, 1, 0 },
				{ 2, 1, 1, 0 }
			};
			int res = lastOne(&values[0][0], 4, 4);
			Assert::AreEqual(2, res, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void lastOne_Real05()
		{
			const int N = 5, M = 5;
			int values[N][M] = {
				{ 1, 2, 1, 2, 1 },
				{ 2, 1, 2, 1, 2 },
				{ 1, 2, 1, 2, 1 },
				{ 2, 1, 2, 1, 2 },
				{ 1, 2, 1, 2, 1 }
			};
			int res = lastOne(&values[0][0],N, M);
			Assert::AreEqual(1, res, L"Wrong Answer", 1, 2);
		};


		[TestMethod, Timeout(1000)]
		void lastOne_Real06()
		{
			const int N = 5, M = 5;
			int values[N][M] = {
				{ 1, 1, 1, 1, 1 },
				{ 2, 1, 1, 1, 2 },
				{ 1, 1, 1, 1, 1 },
				{ 2, 1, 1, 1, 1 },
				{ 1, 2, 1, 2, 1 }
			};
			int res = lastOne(&values[0][0], N, M);
			Assert::AreEqual(3, res, L"Wrong Answer", 1, 2);
		};


		[TestMethod, Timeout(1000)]
		void lastOne_Real07()
		{
			const int N = 5, M = 5;
			int values[N][M] = {
				{ 0, 0, 0, 0, 0 },
				{ 2, 1, 2, 1, 2 },
				{ 0, 0, 0, 0, 0 },
				{ 2, 1, 1, 1, 2 },
				{ 0 ,0, 0, 0, 0 }
			};
			int res = lastOne(&values[0][0], N, M);
			Assert::AreEqual(2, res, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void lastOne_Real08()
		{
			const int N = 5, M = 5;
			int values[N][M] = {
				{ 0, 0, 0, 0, 0 },
				{ 2, 1, 0, 1, 2 },
				{ 0, 0, 0, 0, 1 },
				{ 2, 1, 1, 0, 1 },
				{ 0, 0, 0, 0, 0 }
			};
			int res = lastOne(&values[0][0], N, M);
			Assert::AreEqual(2, res, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void lastOne_Real09()
		{
			const int N = 1, M = 5;
			int values[N][M] = {
				{ 1, 1, 2, 1, 1 }
			};
			int res = lastOne(&values[0][0], N, M);
			Assert::AreEqual(2, res, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void lastOne_Real10()
		{
			const int N = 1, M = 6;
			int values[N][M] = {
				{ 1, 1, 1,2,1, 1 }
			};
			int res = lastOne(&values[0][0], N, M);
			Assert::AreEqual(3, res, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void lastOne_Big01()
		{
			const int N = 100, M = 100;
			int values[N][M];
			for (int i = 0; i < N; i++){
				for (int j = 0; j < M; j++){
					values[i][j] = 1;
				}
			}
			values[0][0] = 2;
			int res = lastOne(&values[0][0], N, M);
			Assert::AreEqual(198, res, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void lastOne_Big02()
		{
			const int N = 100, M = 100;
			int values[N][M];
			for (int i = 0; i < N; i++){
				for (int j = 0; j < M; j++){
					values[i][j] = 1;
				}
			}
			values[0][0] = 2;
			values[N - 1][M - 1] = 2;
			int res = lastOne(&values[0][0], N, M);
			Assert::AreEqual(99, res, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void lastOne_Big03()
		{
			const int N = 100, M = 100;
			int values[N][M];
			for (int i = 0; i < N; i++){
				for (int j = 0; j < M; j++){
					values[i][j] = 1;
				}
			}
			values[N / 2][M / 2] = 2;
			int res = lastOne(&values[0][0], N, M);
			Assert::AreEqual(100, res, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void lastOne_Big04()
		{
			const int N = 100, M = 100;
			int values[N][M];
			for (int i = 0; i < N; i++){
				for (int j = 0; j < M; j++){
					values[i][j] = 1;
				}
			}
			values[0][0] = 2;
			values[0][M - 1] = 2;
			values[N / 2][M / 2] = 2;
			values[N - 1][0];
			values[N - 1][M - 1] = 2;
			int res = lastOne(&values[0][0], N, M);
			Assert::AreEqual(99, res, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void lastOne_Big05()
		{
			const int N = 100, M = 100;
			int values[N][M];
			for (int i = 0; i < N; i++){
				for (int j = 0; j < M; j++){
					values[i][j] = 2;
				}
			}
			int res = lastOne(&values[0][0], N, M);
			Assert::AreEqual(0, res, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void lastOne_Big06()
		{
			const int N = 100, M = 100;
			int values[N][M];
			for (int i = 0; i < N; i++){
				for (int j = 0; j < M; j++){
					if (j % 2 == 1)
						values[i][j] = 2;
					else
						values[i][j] = 1;
				}
			}
			int res = lastOne(&values[0][0], N, M);
			Assert::AreEqual(1, res, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void lastOne_Big07()
		{
			const int N = 100, M = 100;
			int values[N][M];
			for (int i = 0; i < N; i++){
				for (int j = 0; j < M; j++){
					if (j < M / 2) values[i][j] = 2;
					else values[i][j] = 1;
				}
			}
			int res = lastOne(&values[0][0], N, M);
			Assert::AreEqual(50, res, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void lastOne_Big08()
		{
			const int N = 100, M = 100;
			int values[N][M];
			for (int i = 0; i < N; i++){
				for (int j = 0; j < M; j++){
					values[i][j] = 0;
				}
			}
			int res = lastOne(&values[0][0], N, M);
			Assert::AreEqual(0, res, L"Wrong Answer", 1, 2);
		};

	};
}
