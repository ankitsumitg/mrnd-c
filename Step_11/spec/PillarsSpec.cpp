
#include "stdafx.h";
#include <stdlib.h>;
#include "./../src/Pillars.cpp";

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class PillarsSpec
	{
	private:
		TestContext^ testContextInstance;
	public:
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

		int compare_arrays_pillars_spec(int *arr1, int *arr2, int len){
			int i = 0;
			while (i < len){
				if (arr1[i] != arr2[i]){
					return 0;
				}
				i++;
			}
			return 1;
		}
		void testPillars_spec(int *blocks, int n, int m, int *maxpath_exp, int jc_exp, int nopath){
			//No path will be 1 if All are zeros or blocks is NULL
			int jc = 0;
			int *res = pillars_max_jumps(blocks, n, m, &jc);
			int check = 0;

			//If jumps are not null ,Res should not be null ,If null Fail
			if (res == NULL && jc_exp != 0){
				Assert::AreEqual(1, 2, L"Res should not be null Pillars", 1, 2);
			}
			else if (jc_exp == 0 && nopath == 1){
				//As jumps are zero ,Res should be Null ,Or else Call Failing Assert
				if (res != NULL){
					Assert::AreEqual(1, 2, L"Res should be null Pillars", 1, 2);
				}
			}
			else{
				Assert::AreEqual(jc_exp, jc, L"Failed Jump Count case in Pillars", 1, 2);
				if (jc == jc_exp){
					int flag = compare_arrays_pillars_spec(res, maxpath_exp, jc_exp + 1);
					Assert::AreEqual(1, flag, L"Failed Max jump path in Pillars", 1, 2);
				}

			}

		}
		[TestMethod, Timeout(1000)]
		void Sample1_Pillars()
		{
			int jc = 0;
			int n = 3, m = 5;
			int *res = pillars_max_jumps(NULL, n, m, &jc);
			int check = 0;
			if (res == NULL){
				check = 1;
			}
			Assert::AreEqual(1, check, L"Failed sample 0 for NULL case in LL", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Sample2_Pillars()
		{

			const int n = 3, m = 3;
			int blocks[n][m] = {
				{ 2, 1, 7 },
				{ 3, 0, 4 },
				{ 5, 6, 4 }
			};
			const int jc_exp = 4;
			int maxpath_exp[jc_exp + 1] = { 1, 2, 3, 5, 6 };
			int nopath = 0;
			testPillars_spec(&blocks[0][0], n, m, maxpath_exp, jc_exp, nopath);
		};
		[TestMethod, Timeout(1000)]
		void Sample3_Pillars()
		{
			const int n = 5, m = 5;
			int blocks[n][m] = {
				{ 1, 2, 0, 1, 0 },
				{ 0, 0, 0, 9, 0 },
				{ 0, 0, 0, 8, 0 },
				{ 0, 1, 4, 6, 5 },
				{ 0, 0, 2, 3, 4 }, };
			const int jc_exp = 6;
			int maxpath_exp[jc_exp + 1] = { 2, 3, 4, 5, 6, 8, 9 };
			int nopath = 0;
			testPillars_spec(&blocks[0][0], n, m, maxpath_exp, jc_exp, nopath);
		};

		//Real Test Cases

		[TestMethod, Timeout(1000)]
		void Real1_Pillars()
		{
			int nopath = 0;
			const int n = 5, m = 5;
			int blocks[n][m] = {
				{ 1, 2, 0, 1, 0 },
				{ 0, 0, 0, 90, 0 },
				{ 0, 0, 0, 80, 0 },
				{ 0, 1, 4, 60, 5 },
				{ 0, 0, 2, 3, 4 }, };
			const int jc_exp = 6;
			int maxpath_exp[jc_exp + 1] = { 2, 3, 4, 5, 60, 80, 90 };
			testPillars_spec(&blocks[0][0], n, m, maxpath_exp, jc_exp, nopath);
		};
		[TestMethod, Timeout(1000)]
		void Real2_Pillars()
		{
			int nopath = 0;
			const int n = 5, m = 5;
			int blocks[n][m] = {
				{ 1, 2, 3, 0, 0 },
				{ 0, 0, 4, 0, 0 },
				{ 0, 0, 5, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 }, };
			const int jc_exp = 4;
			int maxpath_exp[jc_exp + 1] = { 1, 2, 3, 4, 5 };
			testPillars_spec(&blocks[0][0], n, m, maxpath_exp, jc_exp, nopath);
		};
		[TestMethod, Timeout(1000)]
		void Real3_Pillars()
		{
			int nopath = 0;
			const int n = 5, m = 5;
			int blocks[n][m] = {
				{ 1, 2, 3, 0, 0 },
				{ 0, 0, 4, 0, 0 },
				{ 0, 0, 5, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 }, };
			const int jc_exp = 4;
			int maxpath_exp[jc_exp + 1] = { 1, 2, 3, 4, 5 };
			testPillars_spec(&blocks[0][0], n, m, maxpath_exp, jc_exp, nopath);
		};
		[TestMethod, Timeout(1000)]
		void Real4_Pillars()
		{
			int nopath = 0;
			const int n = 3, m = 3;
			int blocks[n][m] = { { 1, 2, 3 }, { 0, 0, 0 }, { 0, 0, 0 } };
			const int jc_exp = 2;
			int maxpath_exp[jc_exp + 1] = { 1, 2, 3 };
			testPillars_spec(&blocks[0][0], n, m, maxpath_exp, jc_exp, nopath);
		};
		[TestMethod, Timeout(1000)]
		void Real5_Pillars()
		{
			int nopath = 0;
			const int n = 3, m = 3;
			int blocks[n][m] = { { 1, 2, 3 }, { 0, 4, 0 }, { 6, 5, 0 } };
			const int jc_exp = 4;
			int maxpath_exp[jc_exp + 1] = { 1, 2, 4, 5, 6 };
			testPillars_spec(&blocks[0][0], n, m, maxpath_exp, jc_exp, nopath);
		};
		[TestMethod, Timeout(1000)]
		void Real6_Pillars()
		{
			int nopath = 0;
			const int n = 3, m = 3;
			int blocks[n][m] = { { 1, 2, 3 }, { 8, 9, 4 }, { 7, 6, 5 } };
			const int jc_exp = 8;
			int maxpath_exp[jc_exp + 1] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			testPillars_spec(&blocks[0][0], n, m, maxpath_exp, jc_exp, nopath);
		};
		[TestMethod, Timeout(1000)]
		void Real7_Pillars()
		{
			int nopath = 0;
			const int n = 5, m = 5;
			int blocks[n][m] = {
				{ 1, 2, 3, 10, 9 },
				{ 0, 45, 40, 12, 8 },
				{ 0, 50, 0, 9, 7 },
				{ 0, 1, 0, 0, 6 },
				{ 0, 2, 3, 4, 5 }, };
			const int jc_exp = 13;
			int maxpath_exp[jc_exp + 1] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 40, 45, 50 };
			testPillars_spec(&blocks[0][0], n, m, maxpath_exp, jc_exp, nopath);
		};
		[TestMethod, Timeout(1000)]
		void Real8_Pillars()
		{
			int nopath = 0;
			const int n = 5, m = 5;
			int blocks[n][m] = {
				{ 1, 2, 3, 10, 9 },
				{ 2, 45, 40, 12, 8 },
				{ 2, 50, 50, 9, 7 },
				{ 2, 1, 0, 0, 6 },
				{ 0, 2, 3, 4, 5 }, };
			const int jc_exp = 13;
			int maxpath_exp[jc_exp + 1] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 40, 45, 50 };
			testPillars_spec(&blocks[0][0], n, m, maxpath_exp, jc_exp, nopath);
		};
		[TestMethod, Timeout(1000)]
		void Real9_Pillars()
		{
			int nopath = 0;
			const int n = 5, m = 5;
			int blocks[n][m] = {
				{ 1, 2, 3, 10, 9 },
				{ 2, 45, 40, 12, 8 },
				{ 2, 50, 50, 9, 7 },
				{ 2, 1, 0, 0, 6 },
				{ 0, 2, 3, 4, 5 }, };
			const int jc_exp = 13;
			int maxpath_exp[jc_exp + 1] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 40, 45, 50 };
			testPillars_spec(&blocks[0][0], n, m, maxpath_exp, jc_exp, nopath);
		};
		[TestMethod, Timeout(1000)]
		void Real10_Pillars()
		{
			int nopath = 0;
			const int n = 5, m = 5;
			int blocks[n][m] = {
				{ 1, 2, 3, 10, 9 },
				{ 2, 45, 40, 12, 8 },
				{ 2, 50, 50, 9, 7 },
				{ 2, 1, 20, 2, 6 },
				{ 2, 2, 3, 4, 5 }, };
			const int jc_exp = 13;
			int maxpath_exp[jc_exp + 1] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 40, 45, 50 };
			testPillars_spec(&blocks[0][0], n, m, maxpath_exp, jc_exp, nopath);
		};

		[TestMethod, Timeout(1000)]
		void Real11_Pillars()
		{
			int nopath = 1;
			const int n = 10, m = 9;
			int blocks[m][n] = {
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, };
			const int jc_exp = 0;
			int maxpath_exp[jc_exp + 1] = { 1 };
			testPillars_spec(&blocks[0][0], m,n, maxpath_exp, jc_exp, nopath);
		};
		[TestMethod, Timeout(1000)]
		void Real12_Pillars()
		{
			int nopath = 0;
			const int n = 2, m = 1;
			int blocks[m][n] = { { 1, 2 } };
			const int jc_exp = 1;
			int maxpath_exp[jc_exp + 1] = { 1, 2 };
			testPillars_spec(&blocks[0][0], m, n, maxpath_exp, jc_exp, nopath);
		};
		[TestMethod, Timeout(1000)]
		void Real13_Pillars()
		{
			int nopath = 0;
			const int n = 10, m = 9;
			int blocks[m][n] = {
				{ 0, 0, 0, 0, 0, 0, 0, 1, 2, 0 },
				{ 0, 0, 3, 5, 10, 11, 12, 0, 3, 0 },
				{ 0, 0, 0, 0, 0, 14, 13, 0, 4, 0 },
				{ 0, 0, 0, 0, 0, 15, 0, 50, 5, 0 },
				{ 0, 0, 50, 0, 0, 16, 17, 40, 6, 0 },
				{ 0, 0, 40, 0, 0, 0, 18, 30, 7, 0 },
				{ 7, 0, 30, 7, 7, 0, 19, 20, 8, 0 },
				{ 7, 0, 0, 0, 7, 0, 0, 10, 9, 0 },
				{ 7, 7, 7, 7, 7, 0, 0, 0, 0, 0 }, };
			const int jc_exp = 15;
			int maxpath_exp[jc_exp + 1] = { 3, 5, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 30, 40, 50 };
			testPillars_spec(&blocks[0][0], m, n, maxpath_exp, jc_exp, nopath);
		};
		[TestMethod, Timeout(1000)]
		void Real14_Pillars()
		{
			int nopath = 0;
			const int n = 10, m = 9;
			int blocks[m][n] = {
				{ 0, 0, 0, 0, 0, 0, 0, 1, 2, 0 },
				{ 0, 0, 3, 5, 10, 11, 12, 0, 3, 0 },
				{ 0, 0, 0, 0, 0, 14, 13, 0, 4, 0 },
				{ 0, 0, 0, 0, 0, 15, 0, 50, 5, 0 },
				{ 0, 0, 50, 0, 0, 16, 17, 40, 6, 0 },
				{ 0, 0, 40, 0, 0, 0, 18, 30, 7, 0 },
				{ 7, 0, 30, 7, 7, 0, 19, 20, 8, 0 },
				{ 7, 0, 0, 0, 7, 0, 0, 10, 9, 0 },
				{ 7, 7, 7, 7, 7, 0, 0, 0, 0, 0 }, };
			const int jc_exp = 15;
			int maxpath_exp[jc_exp + 1] = { 3, 5, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 30, 40, 50 };
			testPillars_spec(&blocks[0][0], m, n, maxpath_exp, jc_exp, nopath);
		};
		[TestMethod, Timeout(1000)]
		void Real15_Pillars()
		{
			int nopath = 0;
			const int n = 10, m = 9;
			int blocks[m][n] = {
				{ 0, 0, 0, 0, 0, 0, 0, 1, 2, 0 },
				{ 0, 0, 3, 5, 10, 11, 12, 0, 3, 0 },
				{ 1, 0, 0, 0, 0, 14, 13, 0, 4, 0 },
				{ 2, 0, 0, 0, 0, 15, 0, 50, 5, 0 },
				{ 3, 0, 50, 0, 0, 16, 17, 40, 6, 0 },
				{ 4, 0, 40, 0, 0, 0, 18, 30, 7, 0 },
				{ 7, 0, 30, 7, 7, 0, 19, 20, 8, 0 },
				{ 7, 0, 0, 0, 7, 0, 0, 10, 9, 0 },
				{ 7, 7, 7, 7, 7, 0, 0, 0, 0, 0 }, };
			const int jc_exp = 15;
			int maxpath_exp[jc_exp + 1] = { 3, 5, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 30, 40, 50 };
			testPillars_spec(&blocks[0][0], m,n, maxpath_exp, jc_exp, nopath);
		};
		[TestMethod, Timeout(1000)]
		void Real16_Pillars()
		{
			int nopath = 0;
			const int n = 1, m = 10;
			int blocks[m][n] = {
				{ 1 },
				{ 2 },
				{ 3 },
				{ 4 },
				{ 5 },
				{ 0 },
				{ 1 },
				{ 2 },
				{ 3 },
				{ 4 } };
			const int jc_exp = 4;
			int maxpath_exp[jc_exp + 1] = { 1, 2, 3, 4, 5 };
			testPillars_spec(&blocks[0][0], m,n, maxpath_exp, jc_exp, nopath);
		};
		[TestMethod, Timeout(1000)]
		void Real17_Pillars()
		{
			int nopath = 0;
			const int m = 1000, n = 1000;

			int **blocks = (int **)malloc((sizeof(int *))*m);
			blocks[0] = (int *)malloc(sizeof(int) * m * n);
			for (int i = 0; i < m; i++)
				blocks[i] = (*blocks + n * i);
			for (int i = 0; i < m; i++){
				for (int j = 0; j < n; j++){
					blocks[i][j] = 1;
				}
			}
			const int jc_exp = 0;
			int maxpath_exp[jc_exp + 1] = { 1 };
			testPillars_spec(blocks[0], n, m, maxpath_exp, jc_exp, nopath);
		};
		[TestMethod, Timeout(1000)]
		void Real18_Pillars()
		{
			int nopath = 0;
			const int m = 1000, n = 1000;

			int **blocks = (int **)malloc((sizeof(int *))*m);
			blocks[0] = (int *)malloc(sizeof(int) * m * n);
			for (int i = 0; i < m; i++)
				blocks[i] = (*blocks + n * i);
			for (int i = 0; i < m; i++){
				for (int j = 0; j < n; j++){
					blocks[i][j] = 1;
				}
			}
			const int jc_exp = 0;
			int maxpath_exp[jc_exp + 1] = { 1 };
			testPillars_spec(blocks[0], n, m, maxpath_exp, jc_exp, nopath);
		};
		[TestMethod, Timeout(1000)]
		void Real19_Pillars()
		{
			int nopath = 0;
			const int m = 500, n = 500;

			int **blocks = (int **)malloc((sizeof(int *))*m);
			blocks[0] = (int *)malloc(sizeof(int) * m * n);
			for (int i = 0; i < m; i++)
				blocks[i] = (*blocks + n * i);
			for (int i = 0; i < m; i++){
				for (int j = 0; j < n; j++){
					blocks[i][j] = 1;
				}
			}
			const int jc_exp = 0;
			int maxpath_exp[jc_exp + 1] = { 1 };
			testPillars_spec(blocks[0], n, m, maxpath_exp, jc_exp, nopath);
		};

		[TestMethod, Timeout(1000)]
		void Real20_Pillars()
		{
			int nopath = 0;
			const int m = 1000, n = 1000;

			int **blocks = (int **)malloc((sizeof(int *))*m);
			blocks[0] = (int *)malloc(sizeof(int) * m * n);
			for (int i = 0; i < m; i++)
				blocks[i] = (*blocks + n * i);
			for (int i = 0; i < m; i++){
				for (int j = 0; j < n; j++){
					blocks[i][j] = 1;
				}
			}
			//blocks[0][0] = 100;
			const int jc_exp = 0;
			int maxpath_exp[jc_exp + 1] = { 1 };
			testPillars_spec(blocks[0], n, m, maxpath_exp, jc_exp, nopath);
		};
		[TestMethod, Timeout(1000)]
		void Real21_Pillars()
		{
			int nopath = 0;
			const int m = 1000, n = 1000;

			int **blocks = (int **)malloc((sizeof(int *))*m);
			blocks[0] = (int *)malloc(sizeof(int) * m * n);
			for (int i = 0; i < m; i++)
				blocks[i] = (*blocks + n * i);
			for (int i = 0; i < m; i++){
				for (int j = 0; j < n; j++){
					blocks[i][j] = 2;
				}
			}
			blocks[0][0] = 100;
			const int jc_exp = 1;
			int maxpath_exp[jc_exp + 1] = { 2, 100 };
			testPillars_spec(blocks[0], n, m, maxpath_exp, jc_exp, nopath);
		};
		[TestMethod, Timeout(1000)]
		void Real22_Pillars()
		{
			int nopath = 0;
			const int m = 2000, n = 2000;

			int **blocks = (int **)malloc((sizeof(int *))*m);
			blocks[0] = (int *)malloc(sizeof(int) * m * n);
			for (int i = 0; i < m; i++)
				blocks[i] = (*blocks + n * i);
			for (int i = 0; i < m; i++){
				for (int j = 0; j < n; j++){
					blocks[i][j] = 3;
				}
			}
			blocks[0][0] = 100;
			const int jc_exp = 1;
			int maxpath_exp[jc_exp + 1] = { 3, 100 };
			testPillars_spec(blocks[0], n, m, maxpath_exp, jc_exp, nopath);
		};

	};
}

