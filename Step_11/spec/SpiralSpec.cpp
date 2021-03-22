#include "stdafx.h"
#include "./../src/Spiral.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class SpiralSpec
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
		void generate_array(int **input_array, int rows, int columns, int seq)
		{
			int k = 0;
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < columns; j++)
					input_array[i][j] = (k++)*seq;
		}

		[TestMethod(), Timeout(3000)]
		void Spiral_ArraySizeInvalid()
		{

			int rows = 5, columns = 3;
			int **input_array = (int **)malloc(rows * sizeof(int *));
			for (int i = 0; i < rows; i++)
				input_array[i] = (int *)malloc(columns * sizeof(int));



			generate_array((int**)input_array, rows, columns, 1);

			int *output_array = spiral(-rows, columns, (int**)input_array);


			Assert::IsTrue(output_array == NULL, L"Should return NULL when rows is negative");
			
			output_array = spiral(rows, -columns, (int**)input_array);

			Assert::IsTrue(output_array == NULL, L"Should return NULL when columns is negative");
			

			output_array = spiral(-rows, -columns, (int**)input_array);

			Assert::IsTrue(output_array == NULL, L"Should return NULL when both rows and columns are negative");
			


			generate_array((int**)input_array, 0, 0, 1);
			output_array = spiral(0, 0, (int**)input_array);

			Assert::IsTrue(output_array == NULL, L"Should return NULL when both rows and columns are negative");
			
		};


		[TestMethod(), Timeout(3000)]
		void Spiral_ArrayIsNull()
		{
			int *output_array = spiral(5, 5, NULL);
			Assert::IsTrue(output_array == NULL, "output_array must be NULL when the input array is NULL");
		}

		[TestMethod(), Timeout(3000)]
		void Spiral_5x5()
		{
			int rows = 5, columns = 5;
			int **input_array = (int **)malloc(rows * sizeof(int *));
			for (int i = 0; i < rows; i++)
				input_array[i] = (int *)malloc(columns * sizeof(int));
			
			generate_array((int**)input_array, rows, columns, 1);

			int *output_array = spiral(rows, columns, (int**)input_array);

			Assert::AreEqual(0, output_array[0], L"Failed for Spiral 5x5 matrix", 1,2);
			Assert::AreEqual(24, output_array[8], L"Failed for Spiral 5x5 matrix", 1,2);
			Assert::AreEqual(21, output_array[11], L"Failed for Spiral 5x5 matrix", 1,2);
			Assert::AreEqual(8, output_array[18], L"Failed for Spiral 5x5 matrix", 1,2);
			Assert::AreEqual(14, output_array[6], L"Failed for Spiral 5x5 matrix", 1,2);
			Assert::AreEqual(6, output_array[16], L"Failed for Spiral 5x5 matrix", 1,2);
			Assert::AreEqual(12, output_array[24], L"Failed for Spiral 5x5 matrix", 1,2);

			
		}

		[TestMethod(), Timeout(3000)]
		void Spiral_5x15()
		{
			int rows = 5, columns = 15;
			int **input_array = (int **)malloc(rows * sizeof(int *));
			for (int i = 0; i < rows; i++)
				input_array[i] = (int *)malloc(columns * sizeof(int));

			generate_array((int**)input_array, rows, columns, 2);

			int *output_array = spiral(rows, columns, (int**)input_array);

			Assert::AreEqual(0, output_array[0], L"Failed for Spiral 5x15 matrix", 1,2);
			Assert::AreEqual(10, output_array[5], L"Failed for Spiral 5x15 matrix", 1,2);
			Assert::AreEqual(18, output_array[9], L"Failed for Spiral 5x15 matrix", 1,2);
			Assert::AreEqual(26, output_array[13], L"Failed for Spiral 5x15 matrix", 1,2);
			Assert::AreEqual(116, output_array[50], L"Failed for Spiral 5x15 matrix", 1,2);
			Assert::AreEqual(100, output_array[58], L"Failed for Spiral 5x15 matrix", 1,2);
			Assert::AreEqual(98, output_array[59], L"Failed for Spiral 5x15 matrix", 1,2);
			Assert::AreEqual(78, output_array[71], L"Failed for Spiral 5x15 matrix", 1,2);
			Assert::AreEqual(82, output_array[73], L"Failed for Spiral 5x15 matrix", 1,2);
			Assert::AreEqual(84, output_array[74], L"Failed for Spiral 5x15 matrix", 1,2);

			
		}

		[TestMethod(), Timeout(3000)]
		void Spiral_1x1()
		{
			int rows = 1, columns = 1;
			int **input_array = (int **)malloc(rows * sizeof(int *));

			for (int i = 0; i < rows; i++)
				input_array[i] = (int *)malloc(columns * sizeof(int));

			generate_array((int**)input_array, rows, columns, 1);

			int *output_array = spiral(rows, columns, (int**)input_array);
			Assert::AreEqual(0, output_array[0], L"Failed for Spiral 1x1 matrix", 1,2);

			

		}

		[TestMethod(), Timeout(3000)]
		void Spiral_10x1()
		{
			int rows = 10, columns = 1;

			int **input_array = (int **)malloc(rows * sizeof(int *));

			for (int i = 0; i < rows; i++)
				input_array[i] = (int *)malloc(columns * sizeof(int));
			
			generate_array((int**)input_array, rows, columns, -12);

			int *output_array = spiral(rows, columns, (int**)input_array);

			Assert::AreEqual(0, output_array[0], L"Failed for Spiral 10x1 matrix", 1,2);
			Assert::AreEqual(-36, output_array[3], L"Failed for Spiral 10x1 matrix", 1,2);
			Assert::AreEqual(-72, output_array[6], L"Failed for Spiral 10x1 matrix", 1,2);
			Assert::AreEqual(-96, output_array[8], L"Failed for Spiral 10x1 matrix", 1,2);
			Assert::AreEqual(-108, output_array[9], L"Failed for Spiral 10x1 matrix", 1,2);
			
			

		}
	};
}
