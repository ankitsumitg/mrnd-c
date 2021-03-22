#include "stdafx.h"
#include <stdlib.h>
#include "../src/MiniLeaderboard.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class MiniLeaderboardSpec
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



		void compareStrings_Leaderboard(char *expected, char * actual) {
			int i = 0;
			while (expected[i] != '\0') {
				Assert::AreEqual(expected[i],actual[i], L"Leaderboard expected and actual string mismatch, copy test case into main and check the output", 1, 2);
				i++ ;
			}
			if (actual[i] != '\0') {
				Assert::Fail("Output string not ended with slash 0");
			}
		}

		[TestMethod, Timeout(1000)]
		void MiniLeaderboard_Sample1()
		{
			char *s1 = "abc,3\nbca,4\n";
			char *s2 = "bca,99\n";
			char *s3 = "cca,100\n";
			char * expected = "bca,4,99,0,103\n"
				              "cca,0,0,100,100\n"
							  "abc,3,0,0,3\n";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}

		[TestMethod, Timeout(1000)]
		void MiniLeaderboard_Sample2()
		{
			char *s1 = "abc,3\nbca,4\naaa,12\naab,56\nccc,100\n";
			char *s2 = "bca,99\nccc,100\n";
			char *s3 = "";
			char * expected = "ccc,100,100,0,200\n"
				              "bca,4,99,0,103\n"
							  "aab,56,0,0,56\n"
							  "aaa,12,0,0,12\n"
							  "abc,3,0,0,3\n";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}

		//Real - 28 , Empty Strings -4, Simple- 8 (Less than 5 students), Medium - 4( 10-15 students)
		//Hard - 10 (2Test cases repeated 5 times) (Out of 28, 5 should test alphabatical)

		[TestMethod, Timeout(1000)]
		void MiniLeaderboard_Real1()
		{
			char *s1 = "";
			char *s2 = "";
			char *s3 = "";
			char * expected = "";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}

		[TestMethod, Timeout(1000)]
		void MiniLeaderboard_Real2()
		{
			char *s1 = NULL;
			char *s2 = NULL;
			char *s3 = "";
			char * expected = "";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}
		[TestMethod, Timeout(1000)]
		void MiniLeaderboard_Real3()
		{
			char *s1 = "";
			char *s2 = "";
			char *s3 = "";
			char * expected = "";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}

		[TestMethod, Timeout(1000)]
		void MiniLeaderboard_Real4()
		{
			char *s1 = NULL;
			char *s2 = NULL;
			char *s3 = NULL;
			char * expected = "";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}

		[TestMethod, Timeout(1000)]
		void MiniLeaderboard_Real5()
		{
			char *s1 = "bbc,3\nbca,4\n";
			char *s2 = "bca,99\n";
			char *s3 = "cca,100\n";
			char * expected = "bca,4,99,0,103\n"
				"cca,0,0,100,100\n"
				"bbc,3,0,0,3\n";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}

		[TestMethod, Timeout(1000)]
		void MiniLeaderboard_Real6()
		{
			char *s1 = "bbc,3\nbca,4\naaa,12\naab,56\nccc,100\n";
			char *s2 = "bca,99\nccc,100\n";
			char *s3 = "ccc,0\n";
			char * expected = "ccc,100,100,0,200\n"
				"bca,4,99,0,103\n"
				"aab,56,0,0,56\n"
				"aaa,12,0,0,12\n"
				"bbc,3,0,0,3\n";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}

		[TestMethod, Timeout(1000)]
		void MiniLeaderboard_Real7()
		{
			char *s1 = "bbc,3\nbca,4\n";
			char *s2 = "bca,99\n";
			char *s3 = "cca,100\n";
			char * expected = "bca,4,99,0,103\n"
				"cca,0,0,100,100\n"
				"bbc,3,0,0,3\n";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}

		[TestMethod, Timeout(1000)]
		void MiniLeaderboard_Real8()
		{
			char *s1 = "bbc,3\nbca,4\naaa,12\naab,56\nccc,100\n";
			char *s2 = "bca,99\nccc,100\n";
			char *s3 = "ccc,0\n";
			char * expected = "ccc,100,100,0,200\n"
				"bca,4,99,0,103\n"
				"aab,56,0,0,56\n"
				"aaa,12,0,0,12\n"
				"bbc,3,0,0,3\n";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}
		



		[TestMethod, Timeout(1000)]
		void MiniLeaderboard_Real9_AlphaSort()
		{
			char *s1 = "abc,3\n";
			char *s2 = "bbb,3\n";
			char *s3 = "aaa,3\nabc,0\n";
			char * expected = "aaa,0,0,3,3\n"
				"abc,3,0,0,3\n"
				"bbb,0,3,0,3\n";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}


		[TestMethod, Timeout(1000)]
		void MiniLeaderboard_Real10_AlphaSort()
		{
			char *s1 = "abc,3\n";
			char *s2 = "bbb,3\n";
			char *s3 = "aaa,3\nabc,0\n";
			char * expected = "aaa,0,0,3,3\n"
				"abc,3,0,0,3\n"
				"bbb,0,3,0,3\n";
			char *actual = mini_leaderboard(s1, s2, s3);
			//compareStrings_Leaderboard(expected, actual);
		}

		[TestMethod, Timeout(1000)]
		void MiniLeaderboard_Real11()
		{
			char *s1 = "bbc,3\nbca,4\naaa,12\naab,56\nccc,100\n";
			char *s2 = "bca,99\nccc,100\n";
			char *s3 = "ccc,0\nbca,0\nbbc,0\nbcb,0\n";
			char * expected = "ccc,100,100,0,200\n"
				"bca,4,99,0,103\n"
				"aab,56,0,0,56\n"
				"aaa,12,0,0,12\n"
				"bbc,3,0,0,3\n"
				"bcb,0,0,0,0\n";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}

		[TestMethod, Timeout(1000)]
		void MiniLeaderboard_Real12()
		{
			char *s1 = "bbc,3\nbca,4\naaa,12\naab,56\nccc,100\n";
			char *s2 = "bca,99\nccc,100\n";
			char *s3 = "ccc,0\nbca,0\nbbc,0\nbcb,0\n";
			char * expected = "ccc,100,100,0,200\n"
				"bca,4,99,0,103\n"
				"aab,56,0,0,56\n"
				"aaa,12,0,0,12\n"
				"bbc,3,0,0,3\n"
				"bcb,0,0,0,0\n";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}

		//Medium - 4


		//Hard - 10
		[TestMethod, Timeout(1000)]
		void MiniLeaderboard_Real13_Hard1()
		{
			char *s1 =
				"aaa,13\naab,24\naac,100\n"
				"aba,3\nabb,78\nabc,20\n"
				"aca,2\nacb,0\nacc,51\n"
				"baa,63\nbab,41\nbac,100\n"
				"bba,13\nbbc,60\n"
				"bca,3\nbcb,43\nbcc,0\n"
				"caa,63\ncab,24\n"
				"cba,43\ncbb,14\ncbc,10\n"
				"cca,13\nccb,43\nccc,1\n";

			char *s2 =
				"aaa,3\naab,4\naac,100\n"
				"aba,3\nabb,0\nabc,10\n"
				"aca,33\nacb,43\nacc,1\n"
				"baa,1\nbab,4\nbac,100\n"
				"bba,2\nbbb,100\n"
				"bca,33\nbcb,43\nbcc,1\n"
				"caa,3\ncab,100\n"
				"cba,4\ncbb,54\ncbc,10\n"
				"cca,33\nccb,43\nccc,1\n";
			char *s3 =
				"aaa,3\naab,4\naac,100\n"
				"aba,3\nabb,4\n"
				"aca,33\nacb,43\nacc,1\n"
				"baa,3\nbab,4\nbac,99\n"
				"bba,3\nbbb,4\nbbc,10\n"
				"bca,33\nbcb,93\nbcc,1\n"
				"caa,98\ncab,4\n"
				"cba,3\ncbb,4\ncbc,95\n"
				"cca,33\nccb,43\nccc,1\n";

			char * expected =
				"aac,100,100,100,300\n"
				"bac,100,100,99,299\n"
				"bcb,43,43,93,179\n"
				"caa,63,3,98,164\n"
				"ccb,43,43,43,129\n"
				"cab,24,100,4,128\n"
				"cbc,10,10,95,115\n"
				"bbb,0,100,4,104\n"
				"acb,0,43,43,86\n"
				"abb,78,0,4,82\n"
				"cca,13,33,33,79\n"
				"cbb,14,54,4,72\n"
				"bbc,60,0,10,70\n"
				"bca,3,33,33,69\n"
				"aca,2,33,33,68\n"
				"baa,63,1,3,67\n"
				"acc,51,1,1,53\n"
				"cba,43,4,3,50\n"
				"bab,41,4,4,49\n"
				"aab,24,4,4,32\n"
				"abc,20,10,0,30\n"
				"aaa,13,3,3,19\n"
				"bba,13,2,3,18\n"
				"aba,3,3,3,9\n"
				"ccc,1,1,1,3\n"
				"bcc,0,1,1,2\n";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}
		
		//Hard - 10
		[TestMethod, Timeout(1000)]
		void MiniLeaderboard_Real14_Hard2()
		{
			char *s1 =
				"aaa,13\naab,24\naac,100\n"
				"aba,3\nabb,78\nabc,20\n"
				"aca,2\nacb,0\nacc,51\n"
				"baa,63\nbab,41\nbac,100\n"
				"bba,13\nbbc,60\n"
				"bca,3\nbcb,43\nbcc,0\n"
				"caa,63\ncab,24\n"
				"cba,43\ncbb,14\ncbc,10\n"
				"cca,13\nccb,43\nccc,1\n";

			char *s2 =
				"aaa,3\naab,4\naac,100\n"
				"aba,3\nabb,0\nabc,10\n"
				"aca,33\nacb,43\nacc,1\n"
				"baa,1\nbab,4\nbac,100\n"
				"bba,2\nbbb,100\n"
				"bca,33\nbcb,43\nbcc,1\n"
				"caa,3\ncab,100\n"
				"cba,4\ncbb,54\ncbc,10\n"
				"cca,33\nccb,43\nccc,1\n";
			char *s3 =
				"aaa,3\naab,4\naac,100\n"
				"aba,3\nabb,4\n"
				"aca,33\nacb,43\nacc,1\n"
				"baa,3\nbab,4\nbac,99\n"
				"bba,3\nbbb,4\nbbc,10\n"
				"bca,33\nbcb,93\nbcc,1\n"
				"caa,98\ncab,4\n"
				"cba,3\ncbb,4\ncbc,95\n"
				"cca,33\nccb,43\nccc,1\n";

			char * expected =
				"aac,100,100,100,300\n"
				"bac,100,100,99,299\n"
				"bcb,43,43,93,179\n"
				"caa,63,3,98,164\n"
				"ccb,43,43,43,129\n"
				"cab,24,100,4,128\n"
				"cbc,10,10,95,115\n"
				"bbb,0,100,4,104\n"
				"acb,0,43,43,86\n"
				"abb,78,0,4,82\n"
				"cca,13,33,33,79\n"
				"cbb,14,54,4,72\n"
				"bbc,60,0,10,70\n"
				"bca,3,33,33,69\n"
				"aca,2,33,33,68\n"
				"baa,63,1,3,67\n"
				"acc,51,1,1,53\n"
				"cba,43,4,3,50\n"
				"bab,41,4,4,49\n"
				"aab,24,4,4,32\n"
				"abc,20,10,0,30\n"
				"aaa,13,3,3,19\n"
				"bba,13,2,3,18\n"
				"aba,3,3,3,9\n"
				"ccc,1,1,1,3\n"
				"bcc,0,1,1,2\n";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}
		//Hard - 10
		[TestMethod, Timeout(1000)]
		void MiniLeaderboard_Real15_Hard3()
		{
			char *s1 =
				"aaa,13\naab,24\naac,100\n"
				"aba,3\nabb,78\nabc,20\n"
				"aca,2\nacb,0\nacc,51\n"
				"baa,63\nbab,41\nbac,100\n"
				"bba,13\nbbc,60\n"
				"bca,3\nbcb,43\nbcc,0\n"
				"caa,63\ncab,24\n"
				"cba,43\ncbb,14\ncbc,10\n"
				"cca,13\nccb,43\nccc,1\n";

			char *s2 =
				"aaa,3\naab,4\naac,100\n"
				"aba,3\nabb,0\nabc,10\n"
				"aca,33\nacb,43\nacc,1\n"
				"baa,1\nbab,4\nbac,100\n"
				"bba,2\nbbb,100\n"
				"bca,33\nbcb,43\nbcc,1\n"
				"caa,3\ncab,100\n"
				"cba,4\ncbb,54\ncbc,10\n"
				"cca,33\nccb,43\nccc,1\n";
			char *s3 =
				"aaa,3\naab,4\naac,100\n"
				"aba,3\nabb,4\n"
				"aca,33\nacb,43\nacc,1\n"
				"baa,3\nbab,4\nbac,99\n"
				"bba,3\nbbb,4\nbbc,10\n"
				"bca,33\nbcb,93\nbcc,1\n"
				"caa,98\ncab,4\n"
				"cba,3\ncbb,4\ncbc,95\n"
				"cca,33\nccb,43\nccc,1\n";

			char * expected =
				"aac,100,100,100,300\n"
				"bac,100,100,99,299\n"
				"bcb,43,43,93,179\n"
				"caa,63,3,98,164\n"
				"ccb,43,43,43,129\n"
				"cab,24,100,4,128\n"
				"cbc,10,10,95,115\n"
				"bbb,0,100,4,104\n"
				"acb,0,43,43,86\n"
				"abb,78,0,4,82\n"
				"cca,13,33,33,79\n"
				"cbb,14,54,4,72\n"
				"bbc,60,0,10,70\n"
				"bca,3,33,33,69\n"
				"aca,2,33,33,68\n"
				"baa,63,1,3,67\n"
				"acc,51,1,1,53\n"
				"cba,43,4,3,50\n"
				"bab,41,4,4,49\n"
				"aab,24,4,4,32\n"
				"abc,20,10,0,30\n"
				"aaa,13,3,3,19\n"
				"bba,13,2,3,18\n"
				"aba,3,3,3,9\n"
				"ccc,1,1,1,3\n"
				"bcc,0,1,1,2\n";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}
		//Hard - 10
		[TestMethod, Timeout(1000)]
		void MiniLeaderboard_Real16_Hard4()
		{
			char *s1 =
				"aaa,13\naab,24\naac,100\n"
				"aba,3\nabb,78\nabc,20\n"
				"aca,2\nacb,0\nacc,51\n"
				"baa,63\nbab,41\nbac,100\n"
				"bba,13\nbbc,60\n"
				"bca,3\nbcb,43\nbcc,0\n"
				"caa,63\ncab,24\n"
				"cba,43\ncbb,14\ncbc,10\n"
				"cca,13\nccb,43\nccc,1\n";

			char *s2 =
				"aaa,3\naab,4\naac,100\n"
				"aba,3\nabb,0\nabc,10\n"
				"aca,33\nacb,43\nacc,1\n"
				"baa,1\nbab,4\nbac,100\n"
				"bba,2\nbbb,100\n"
				"bca,33\nbcb,43\nbcc,1\n"
				"caa,3\ncab,100\n"
				"cba,4\ncbb,54\ncbc,10\n"
				"cca,33\nccb,43\nccc,1\n";
			char *s3 =
				"aaa,3\naab,4\naac,100\n"
				"aba,3\nabb,4\n"
				"aca,33\nacb,43\nacc,1\n"
				"baa,3\nbab,4\nbac,99\n"
				"bba,3\nbbb,4\nbbc,10\n"
				"bca,33\nbcb,93\nbcc,1\n"
				"caa,98\ncab,4\n"
				"cba,3\ncbb,4\ncbc,95\n"
				"cca,33\nccb,43\nccc,1\n";

			char * expected =
				"aac,100,100,100,300\n"
				"bac,100,100,99,299\n"
				"bcb,43,43,93,179\n"
				"caa,63,3,98,164\n"
				"ccb,43,43,43,129\n"
				"cab,24,100,4,128\n"
				"cbc,10,10,95,115\n"
				"bbb,0,100,4,104\n"
				"acb,0,43,43,86\n"
				"abb,78,0,4,82\n"
				"cca,13,33,33,79\n"
				"cbb,14,54,4,72\n"
				"bbc,60,0,10,70\n"
				"bca,3,33,33,69\n"
				"aca,2,33,33,68\n"
				"baa,63,1,3,67\n"
				"acc,51,1,1,53\n"
				"cba,43,4,3,50\n"
				"bab,41,4,4,49\n"
				"aab,24,4,4,32\n"
				"abc,20,10,0,30\n"
				"aaa,13,3,3,19\n"
				"bba,13,2,3,18\n"
				"aba,3,3,3,9\n"
				"ccc,1,1,1,3\n"
				"bcc,0,1,1,2\n";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}
		//Hard - 10
		[TestMethod, Timeout(1000)]
		void MiniLeaderboard_Real17_Hard5()
		{
			char *s1 =
				"aaa,13\naab,24\naac,100\n"
				"aba,3\nabb,78\nabc,20\n"
				"aca,2\nacb,0\nacc,51\n"
				"baa,63\nbab,41\nbac,100\n"
				"bba,13\nbbc,60\n"
				"bca,3\nbcb,43\nbcc,0\n"
				"caa,63\ncab,24\n"
				"cba,43\ncbb,14\ncbc,10\n"
				"cca,13\nccb,43\nccc,1\n";

			char *s2 =
				"aaa,3\naab,4\naac,100\n"
				"aba,3\nabb,0\nabc,10\n"
				"aca,33\nacb,43\nacc,1\n"
				"baa,1\nbab,4\nbac,100\n"
				"bba,2\nbbb,100\n"
				"bca,33\nbcb,43\nbcc,1\n"
				"caa,3\ncab,100\n"
				"cba,4\ncbb,54\ncbc,10\n"
				"cca,33\nccb,43\nccc,1\n";
			char *s3 =
				"aaa,3\naab,4\naac,100\n"
				"aba,3\nabb,4\n"
				"aca,33\nacb,43\nacc,1\n"
				"baa,3\nbab,4\nbac,99\n"
				"bba,3\nbbb,4\nbbc,10\n"
				"bca,33\nbcb,93\nbcc,1\n"
				"caa,98\ncab,4\n"
				"cba,3\ncbb,4\ncbc,95\n"
				"cca,33\nccb,43\nccc,1\n";

			char * expected =
				"aac,100,100,100,300\n"
				"bac,100,100,99,299\n"
				"bcb,43,43,93,179\n"
				"caa,63,3,98,164\n"
				"ccb,43,43,43,129\n"
				"cab,24,100,4,128\n"
				"cbc,10,10,95,115\n"
				"bbb,0,100,4,104\n"
				"acb,0,43,43,86\n"
				"abb,78,0,4,82\n"
				"cca,13,33,33,79\n"
				"cbb,14,54,4,72\n"
				"bbc,60,0,10,70\n"
				"bca,3,33,33,69\n"
				"aca,2,33,33,68\n"
				"baa,63,1,3,67\n"
				"acc,51,1,1,53\n"
				"cba,43,4,3,50\n"
				"bab,41,4,4,49\n"
				"aab,24,4,4,32\n"
				"abc,20,10,0,30\n"
				"aaa,13,3,3,19\n"
				"bba,13,2,3,18\n"
				"aba,3,3,3,9\n"
				"ccc,1,1,1,3\n"
				"bcc,0,1,1,2\n";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}

		//Hard + alpha - 5
		[TestMethod, Timeout(1000)]
		void MiniLeaderboard_Real18_Hard6()
		{
			char *s1 =
				"aaa,13\naab,24\naac,100\n"
				"aba,3\nabc,20\n"
				"aca,2\nacb,0\nacc,48\n"
				"baa,63\nbab,41\nbac,100\n"
				"bba,13\nbbc,60\n"
				"bca,3\nbcb,100\nbcc,0\n"
				"caa,63\ncab,24\n"
				"cba,43\ncbb,14\ncbc,10\n"
				"ccb,43\nccc,1\n";

			char *s2 =
				"aaa,3\naab,4\naac,100\n"
				"aba,3\nabb,76\nabc,10\n"
				"aca,33\nacb,43\nacc,1\n"
				"baa,1\nbab,5\nbac,100\n"
				"bba,2\nbbb,100\n"
				"bca,33\nbcb,100\nbcc,1\n"
				"caa,3\ncab,100\n"
				"cba,4\ncbb,54\ncbc,10\n"
				"cca,47\nccb,43\nccc,1\n";
			char *s3 =
				"aaa,3\naab,4\naac,100\n"
				"aba,3\nabb,4\n"
				"aca,33\nacb,43\nacc,1\n"
				"baa,3\nbab,4\nbac,100\n"
				"bba,3\nbbb,4\nbbc,10\n"
				"bca,33\nbcb,100\nbcc,2\n"
				"caa,98\ncab,4\n"
				"cba,3\ncbb,4\ncbc,95\n"
				"cca,33\nccb,43\nccc,1\n";
		
			char * expected = 
                 "aac,100,100,100,300\n"
				 "bac,100,100,100,300\n"
				 "bcb,100,100,100,300\n"
				 "caa,63,3,98,164\n"
				 "ccb,43,43,43,129\n"
				 "cab,24,100,4,128\n"
				 "cbc,10,10,95,115\n"
				 "bbb,0,100,4,104\n"
				 "acb,0,43,43,86\n"
				 "abb,0,76,4,80\n"
				 "cca,0,47,33,80\n"
				 "cbb,14,54,4,72\n"
				 "bbc,60,0,10,70\n"
				 "bca,3,33,33,69\n"
				 "aca,2,33,33,68\n"
				 "baa,63,1,3,67\n"
				 "acc,48,1,1,50\n"
				 "bab,41,5,4,50\n"
				 "cba,43,4,3,50\n"
				 "aab,24,4,4,32\n"
				 "abc,20,10,0,30\n"
				 "aaa,13,3,3,19\n"
				 "bba,13,2,3,18\n"
				 "aba,3,3,3,9\n"
				 "bcc,0,1,2,3\n"
				 "ccc,1,1,1,3\n";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}
		[TestMethod, Timeout(1000)]
		void MiniLeaderboard_Real19_Hard7()
		{
			char *s1 =
				"aaa,13\naab,24\naac,100\n"
				"aba,3\nabc,20\n"
				"aca,2\nacb,0\nacc,48\n"
				"baa,63\nbab,41\nbac,100\n"
				"bba,13\nbbc,60\n"
				"bca,3\nbcb,100\nbcc,0\n"
				"caa,63\ncab,24\n"
				"cba,43\ncbb,14\ncbc,10\n"
				"ccb,43\nccc,1\n";

			char *s2 =
				"aaa,3\naab,4\naac,100\n"
				"aba,3\nabb,76\nabc,10\n"
				"aca,33\nacb,43\nacc,1\n"
				"baa,1\nbab,5\nbac,100\n"
				"bba,2\nbbb,100\n"
				"bca,33\nbcb,100\nbcc,1\n"
				"caa,3\ncab,100\n"
				"cba,4\ncbb,54\ncbc,10\n"
				"cca,47\nccb,43\nccc,1\n";
			char *s3 =
				"aaa,3\naab,4\naac,100\n"
				"aba,3\nabb,4\n"
				"aca,33\nacb,43\nacc,1\n"
				"baa,3\nbab,4\nbac,100\n"
				"bba,3\nbbb,4\nbbc,10\n"
				"bca,33\nbcb,100\nbcc,2\n"
				"caa,98\ncab,4\n"
				"cba,3\ncbb,4\ncbc,95\n"
				"cca,33\nccb,43\nccc,1\n";

			char * expected =
				"aac,100,100,100,300\n"
				"bac,100,100,100,300\n"
				"bcb,100,100,100,300\n"
				"caa,63,3,98,164\n"
				"ccb,43,43,43,129\n"
				"cab,24,100,4,128\n"
				"cbc,10,10,95,115\n"
				"bbb,0,100,4,104\n"
				"acb,0,43,43,86\n"
				"abb,0,76,4,80\n"
				"cca,0,47,33,80\n"
				"cbb,14,54,4,72\n"
				"bbc,60,0,10,70\n"
				"bca,3,33,33,69\n"
				"aca,2,33,33,68\n"
				"baa,63,1,3,67\n"
				"acc,48,1,1,50\n"
				"bab,41,5,4,50\n"
				"cba,43,4,3,50\n"
				"aab,24,4,4,32\n"
				"abc,20,10,0,30\n"
				"aaa,13,3,3,19\n"
				"bba,13,2,3,18\n"
				"aba,3,3,3,9\n"
				"bcc,0,1,2,3\n"
				"ccc,1,1,1,3\n";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}
		[TestMethod, Timeout(1000)]
		void MiniLeaderboard_Real20_Hard8()
		{
			char *s1 =
				"aaa,13\naab,24\naac,100\n"
				"aba,3\nabc,20\n"
				"aca,2\nacb,0\nacc,48\n"
				"baa,63\nbab,41\nbac,100\n"
				"bba,13\nbbc,60\n"
				"bca,3\nbcb,100\nbcc,0\n"
				"caa,63\ncab,24\n"
				"cba,43\ncbb,14\ncbc,10\n"
				"ccb,43\nccc,1\n";

			char *s2 =
				"aaa,3\naab,4\naac,100\n"
				"aba,3\nabb,76\nabc,10\n"
				"aca,33\nacb,43\nacc,1\n"
				"baa,1\nbab,5\nbac,100\n"
				"bba,2\nbbb,100\n"
				"bca,33\nbcb,100\nbcc,1\n"
				"caa,3\ncab,100\n"
				"cba,4\ncbb,54\ncbc,10\n"
				"cca,47\nccb,43\nccc,1\n";
			char *s3 =
				"aaa,3\naab,4\naac,100\n"
				"aba,3\nabb,4\n"
				"aca,33\nacb,43\nacc,1\n"
				"baa,3\nbab,4\nbac,100\n"
				"bba,3\nbbb,4\nbbc,10\n"
				"bca,33\nbcb,100\nbcc,2\n"
				"caa,98\ncab,4\n"
				"cba,3\ncbb,4\ncbc,95\n"
				"cca,33\nccb,43\nccc,1\n";

			char * expected =
				"aac,100,100,100,300\n"
				"bac,100,100,100,300\n"
				"bcb,100,100,100,300\n"
				"caa,63,3,98,164\n"
				"ccb,43,43,43,129\n"
				"cab,24,100,4,128\n"
				"cbc,10,10,95,115\n"
				"bbb,0,100,4,104\n"
				"acb,0,43,43,86\n"
				"abb,0,76,4,80\n"
				"cca,0,47,33,80\n"
				"cbb,14,54,4,72\n"
				"bbc,60,0,10,70\n"
				"bca,3,33,33,69\n"
				"aca,2,33,33,68\n"
				"baa,63,1,3,67\n"
				"acc,48,1,1,50\n"
				"bab,41,5,4,50\n"
				"cba,43,4,3,50\n"
				"aab,24,4,4,32\n"
				"abc,20,10,0,30\n"
				"aaa,13,3,3,19\n"
				"bba,13,2,3,18\n"
				"aba,3,3,3,9\n"
				"bcc,0,1,2,3\n"
				"ccc,1,1,1,3\n";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}
		[TestMethod, Timeout(1000)]
		void MiniLeaderboard_Real21_Hard9()
		{
			char *s1 =
				"aaa,13\naab,24\naac,100\n"
				"aba,3\nabc,20\n"
				"aca,2\nacb,0\nacc,48\n"
				"baa,63\nbab,41\nbac,100\n"
				"bba,13\nbbc,60\n"
				"bca,3\nbcb,100\nbcc,0\n"
				"caa,63\ncab,24\n"
				"cba,43\ncbb,14\ncbc,10\n"
				"ccb,43\nccc,1\n";

			char *s2 =
				"aaa,3\naab,4\naac,100\n"
				"aba,3\nabb,76\nabc,10\n"
				"aca,33\nacb,43\nacc,1\n"
				"baa,1\nbab,5\nbac,100\n"
				"bba,2\nbbb,100\n"
				"bca,33\nbcb,100\nbcc,1\n"
				"caa,3\ncab,100\n"
				"cba,4\ncbb,54\ncbc,10\n"
				"cca,47\nccb,43\nccc,1\n";
			char *s3 =
				"aaa,3\naab,4\naac,100\n"
				"aba,3\nabb,4\n"
				"aca,33\nacb,43\nacc,1\n"
				"baa,3\nbab,4\nbac,100\n"
				"bba,3\nbbb,4\nbbc,10\n"
				"bca,33\nbcb,100\nbcc,2\n"
				"caa,98\ncab,4\n"
				"cba,3\ncbb,4\ncbc,95\n"
				"cca,33\nccb,43\nccc,1\n";

			char * expected =
				"aac,100,100,100,300\n"
				"bac,100,100,100,300\n"
				"bcb,100,100,100,300\n"
				"caa,63,3,98,164\n"
				"ccb,43,43,43,129\n"
				"cab,24,100,4,128\n"
				"cbc,10,10,95,115\n"
				"bbb,0,100,4,104\n"
				"acb,0,43,43,86\n"
				"abb,0,76,4,80\n"
				"cca,0,47,33,80\n"
				"cbb,14,54,4,72\n"
				"bbc,60,0,10,70\n"
				"bca,3,33,33,69\n"
				"aca,2,33,33,68\n"
				"baa,63,1,3,67\n"
				"acc,48,1,1,50\n"
				"bab,41,5,4,50\n"
				"cba,43,4,3,50\n"
				"aab,24,4,4,32\n"
				"abc,20,10,0,30\n"
				"aaa,13,3,3,19\n"
				"bba,13,2,3,18\n"
				"aba,3,3,3,9\n"
				"bcc,0,1,2,3\n"
				"ccc,1,1,1,3\n";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}
		[TestMethod, Timeout(1000)]
		void MiniLeaderboard_Real22_Hard10()
		{
			char *s1 =
				"aaa,13\naab,24\naac,100\n"
				"aba,3\nabc,20\n"
				"aca,2\nacb,0\nacc,48\n"
				"baa,63\nbab,41\nbac,100\n"
				"bba,13\nbbc,60\n"
				"bca,3\nbcb,100\nbcc,0\n"
				"caa,63\ncab,24\n"
				"cba,43\ncbb,14\ncbc,10\n"
				"ccb,43\nccc,1\n";

			char *s2 =
				"aaa,3\naab,4\naac,100\n"
				"aba,3\nabb,76\nabc,10\n"
				"aca,33\nacb,43\nacc,1\n"
				"baa,1\nbab,5\nbac,100\n"
				"bba,2\nbbb,100\n"
				"bca,33\nbcb,100\nbcc,1\n"
				"caa,3\ncab,100\n"
				"cba,4\ncbb,54\ncbc,10\n"
				"cca,47\nccb,43\nccc,1\n";
			char *s3 =
				"aaa,3\naab,4\naac,100\n"
				"aba,3\nabb,4\n"
				"aca,33\nacb,43\nacc,1\n"
				"baa,3\nbab,4\nbac,100\n"
				"bba,3\nbbb,4\nbbc,10\n"
				"bca,33\nbcb,100\nbcc,2\n"
				"caa,98\ncab,4\n"
				"cba,3\ncbb,4\ncbc,95\n"
				"cca,33\nccb,43\nccc,1\n";

			char * expected =
				"aac,100,100,100,300\n"
				"bac,100,100,100,300\n"
				"bcb,100,100,100,300\n"
				"caa,63,3,98,164\n"
				"ccb,43,43,43,129\n"
				"cab,24,100,4,128\n"
				"cbc,10,10,95,115\n"
				"bbb,0,100,4,104\n"
				"acb,0,43,43,86\n"
				"abb,0,76,4,80\n"
				"cca,0,47,33,80\n"
				"cbb,14,54,4,72\n"
				"bbc,60,0,10,70\n"
				"bca,3,33,33,69\n"
				"aca,2,33,33,68\n"
				"baa,63,1,3,67\n"
				"acc,48,1,1,50\n"
				"bab,41,5,4,50\n"
				"cba,43,4,3,50\n"
				"aab,24,4,4,32\n"
				"abc,20,10,0,30\n"
				"aaa,13,3,3,19\n"
				"bba,13,2,3,18\n"
				"aba,3,3,3,9\n"
				"bcc,0,1,2,3\n"
				"ccc,1,1,1,3\n";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}

		[TestMethod, Timeout(1000)]
		void MiniLeaderboard23_Real23_Medium1()
		{
			char *s1 =
				"aac,100\n"
				"aba,3\nabc,20\n"
				"aca,2\nacb,0\n";

			char *s2 =
				"cab,100\n"
				"cca,47\nccb,43\nccc,0\n";
			char *s3 =
				"aaa,3\naab,5\naac,100\n"
				"aba,3\nabb,4\n"
				"cca,33\nccc,1\n";

			char * expected =
				"aac,100,0,100,200\n"
				"cab,0,100,0,100\n"
				"cca,0,47,33,80\n"
				"ccb,0,43,0,43\n"
				"abc,20,0,0,20\n"
				"aba,3,0,3,6\n"
				"aab,0,0,5,5\n"
				"abb,0,0,4,4\n"
				"aaa,0,0,3,3\n"
				"aca,2,0,0,2\n"
				"ccc,0,0,1,1\n"
				"acb,0,0,0,0\n";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}
		[TestMethod, Timeout(1000)]
		void MiniLeaderboard23_Real24_Medium2()
		{
			char *s1 =
				"aac,100\n"
				"aba,3\nabc,20\n"
				"aca,2\nacb,0\n";

			char *s2 =
				"cab,100\n"
				"cca,47\nccb,43\nccc,0\n";
			char *s3 =
				"aaa,3\naab,5\naac,100\n"
				"aba,3\nabb,4\n"
				"cca,33\nccc,1\n";

			char * expected =
				"aac,100,0,100,200\n"
				"cab,0,100,0,100\n"
				"cca,0,47,33,80\n"
				"ccb,0,43,0,43\n"
				"abc,20,0,0,20\n"
				"aba,3,0,3,6\n"
				"aab,0,0,5,5\n"
				"abb,0,0,4,4\n"
				"aaa,0,0,3,3\n"
				"aca,2,0,0,2\n"
				"ccc,0,0,1,1\n"
				"acb,0,0,0,0\n";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}
		[TestMethod, Timeout(1000)]
		void MiniLeaderboard23_Real25_Medium3()
		{
			char *s1 =
				"aac,100\n"
				"aba,3\nabc,20\n"
				"aca,2\nacb,0\n";

			char *s2 =
				"cab,100\n"
				"cca,47\nccb,43\nccc,0\n";
			char *s3 =
				"aaa,3\naab,5\naac,100\n"
				"aba,3\nabb,4\n"
				"cca,33\nccc,1\n";

			char * expected =
				"aac,100,0,100,200\n"
				"cab,0,100,0,100\n"
				"cca,0,47,33,80\n"
				"ccb,0,43,0,43\n"
				"abc,20,0,0,20\n"
				"aba,3,0,3,6\n"
				"aab,0,0,5,5\n"
				"abb,0,0,4,4\n"
				"aaa,0,0,3,3\n"
				"aca,2,0,0,2\n"
				"ccc,0,0,1,1\n"
				"acb,0,0,0,0\n";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}
		[TestMethod, Timeout(1000)]
		void MiniLeaderboard23_Real26_Medium4()
		{
			char *s1 =
				"aac,100\n"
				"aba,3\nabc,20\n"
				"aca,2\nacb,0\n";

			char *s2 =
				"cab,100\n"
				"cca,47\nccb,43\nccc,0\n";
			char *s3 =
				"aaa,3\naab,5\naac,100\n"
				"aba,3\nabb,4\n"
				"cca,33\nccc,1\n";

			char * expected =
				"aac,100,0,100,200\n"
				"cab,0,100,0,100\n"
				"cca,0,47,33,80\n"
				"ccb,0,43,0,43\n"
				"abc,20,0,0,20\n"
				"aba,3,0,3,6\n"
				"aab,0,0,5,5\n"
				"abb,0,0,4,4\n"
				"aaa,0,0,3,3\n"
				"aca,2,0,0,2\n"
				"ccc,0,0,1,1\n"
				"acb,0,0,0,0\n";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}
		[TestMethod, Timeout(1000)]
		void MiniLeaderboard23_Rea27_Medium5()
		{
			char *s1 =
				"aac,100\n"
				"aba,3\nabc,20\n"
				"aca,2\nacb,0\n";

			char *s2 =
				"cab,100\n"
				"cca,47\nccb,43\nccc,0\n";
			char *s3 =
				"aaa,3\naab,5\naac,100\n"
				"aba,3\nabb,4\n"
				"cca,33\nccc,1\n";

			char * expected =
				"aac,100,0,100,200\n"
				"cab,0,100,0,100\n"
				"cca,0,47,33,80\n"
				"ccb,0,43,0,43\n"
				"abc,20,0,0,20\n"
				"aba,3,0,3,6\n"
				"aab,0,0,5,5\n"
				"abb,0,0,4,4\n"
				"aaa,0,0,3,3\n"
				"aca,2,0,0,2\n"
				"ccc,0,0,1,1\n"
				"acb,0,0,0,0\n";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}
		[TestMethod, Timeout(1000)]
		void MiniLeaderboard23_Real28_Medium6()
		{
			char *s1 =
				"aac,100\n"
				"aba,3\nabc,20\n"
				"aca,2\nacb,0\n";

			char *s2 =
				"cab,100\n"
				"cca,47\nccb,43\nccc,0\n";
			char *s3 =
				"aaa,3\naab,5\naac,100\n"
				"aba,3\nabb,4\n"
				"cca,33\nccc,1\n";

			char * expected =
				"aac,100,0,100,200\n"
				"cab,0,100,0,100\n"
				"cca,0,47,33,80\n"
				"ccb,0,43,0,43\n"
				"abc,20,0,0,20\n"
				"aba,3,0,3,6\n"
				"aab,0,0,5,5\n"
				"abb,0,0,4,4\n"
				"aaa,0,0,3,3\n"
				"aca,2,0,0,2\n"
				"ccc,0,0,1,1\n"
				"acb,0,0,0,0\n";
			char *actual = mini_leaderboard(s1, s2, s3);
			compareStrings_Leaderboard(expected, actual);
		}
	};
}
