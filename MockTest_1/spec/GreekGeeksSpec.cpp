#include "stdafx.h"
#include <stdlib.h>
#include "../src/GreekGeeks.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class GreekGeeksSpec
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
		void GreekGeekTest01_samples()
		{
			long long result = 0;
			result = countCommonStars(1, 3, 6, 10, 4);
			Assert::AreEqual(0LL, result, L"Failed GreekGeeks Sample 1", 1, 2);
			result = countCommonStars(3, 1, 10, 2, 10);
			Assert::AreEqual(2LL, result, L"Failed GreekGeeks Sample 2", 1, 2);
			result = countCommonStars(1, 5, 5, 6, 5);
			Assert::AreEqual(0LL, result, L"Failed GreekGeeks Sample 2", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void GreekGeekTest02()
		{
			long long start1, end1, start2, end2, p;
			start1 = 6; end1 = 6;
			start2 = 5; end2 = 8;
			p = 9;
			long long result = 0;
			long long expected = 1LL;

			result = countCommonStars(start1,end1,start2,end2,p);
			result = countCommonStars(start1, end1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 1", 1, 2);
			result = countCommonStars(start1, end1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 2", 1, 2);
			result = countCommonStars(end1, start1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 3", 1, 2);
			result = countCommonStars(end1, start1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 4", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void GreekGeekTest03()
		{
			long long start1, end1, start2, end2, p;
			start1 = 1; end1 = 2;
			start2 = 2; end2 = 3;
			p = 5;
			long long result = 0;
			long long expected = 1LL;
			result = countCommonStars(start1, end1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 1", 1, 2);
			result = countCommonStars(start1, end1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 2", 1, 2);
			result = countCommonStars(end1, start1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 3", 1, 2);
			result = countCommonStars(end1, start1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 4", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void GreekGeekTest04()
		{
			long long start1, end1, start2, end2, p;
			start1 = 1; end1 = 2;
			start2 = 3; end2 = 4;
			p = 5;
			long long result = 0;
			long long expected = 0LL;
			result = countCommonStars(start1, end1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 1", 1, 2);
			result = countCommonStars(start1, end1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 2", 1, 2);
			result = countCommonStars(end1, start1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 3", 1, 2);
			result = countCommonStars(end1, start1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 4", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void GreekGeekTest05()
		{
			long long start1, end1, start2, end2, p;
			start1 = 10; end1 = 1000;
			start2 = 1; end2 = 100;
			p = 2;
			long long result = 0;
			long long expected = 91LL;
			result = countCommonStars(start1, end1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 1", 1, 2);
			result = countCommonStars(start1, end1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 2", 1, 2);
			result = countCommonStars(end1, start1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 3", 1, 2);
			result = countCommonStars(end1, start1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 4", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void GreekGeekTest06()
		{
			long long start1, end1, start2, end2, p;
			start1 = 2; end1 = 4;
			start2 = 1; end2 = 2;
			p = 5;
			long long result = 0;
			long long expected = 1LL;
			result = countCommonStars(start1, end1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 1", 1, 2);
			result = countCommonStars(start1, end1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 2", 1, 2);
			result = countCommonStars(end1, start1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 3", 1, 2);
			result = countCommonStars(end1, start1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 4", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void GreekGeekTest07()
		{
			long long start1, end1, start2, end2, p;
			start1 = 5; end1 = 100;
			start2 = 8; end2 = 8;
			p = 8;
			long long result = 0;
			long long expected = 0LL;
			result = countCommonStars(start1, end1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 1", 1, 2);
			result = countCommonStars(start1, end1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 2", 1, 2);
			result = countCommonStars(end1, start1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 3", 1, 2);
			result = countCommonStars(end1, start1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 4", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void GreekGeekTest08()
		{
			long long start1, end1, start2, end2, p;
			start1 = 10; end1 = 100;
			start2 = 20; end2 = 30;
			p = 40;
			long long result = 0;
			long long expected = 11LL;
			result = countCommonStars(start1, end1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 1", 1, 2);
			result = countCommonStars(start1, end1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 2", 1, 2);
			result = countCommonStars(end1, start1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 3", 1, 2);
			result = countCommonStars(end1, start1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 4", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void GreekGeekTest09()
		{
			long long start1, end1, start2, end2, p;
			start1 = 1;		end1 = 1000;
			start2 = 100;	end2 = 1000;
			p = 200;
			long long result = 0;
			long long expected = 900LL;
			result = countCommonStars(start1, end1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 1", 1, 2);
			result = countCommonStars(start1, end1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 2", 1, 2);
			result = countCommonStars(end1, start1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 3", 1, 2);
			result = countCommonStars(end1, start1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 4", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void GreekGeekTest10()
		{
			long long start1, end1, start2, end2, p;
			start1 = 5;		end1 = 9;
			start2 = 1;		end2 = 11;
			p = 7;
			long long result = 0;
			long long expected = 4LL;
			result = countCommonStars(start1, end1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 1", 1, 2);
			result = countCommonStars(start1, end1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 2", 1, 2);
			result = countCommonStars(end1, start1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 3", 1, 2);
			result = countCommonStars(end1, start1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 4", 1, 2);
		}

		//seed - 6,13,10,17,20
		[TestMethod, Timeout(1000)]
		void GreekGeekTest11()
		{
			long long start1, end1, start2, end2, p;
			start1 = 1LL;		end1 = 1000000000000000000LL;
			start2 = 2LL;		end2 = 99999999999999999LL;
			p = 1000000000LL;
			long long result = 0;
			long long expected = 99999999999999997LL;
			result = countCommonStars(start1, end1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 1", 1, 2);
			result = countCommonStars(start1, end1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 2", 1, 2);
			result = countCommonStars(end1, start1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 3", 1, 2);
			result = countCommonStars(end1, start1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 4", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void GreekGeekTest12()
		{
			long long start1, end1, start2, end2, p;
			start1 = 4722316546398LL;		end1 = 36672578279675LL;
			start2 = 796716437180LL;		end2 = 33840047334985LL;
			p = 13411035401708LL;
			long long result = 0;
			long long expected = 29117730788587LL;
			result = countCommonStars(start1, end1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 1", 1, 2);
			result = countCommonStars(start1, end1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 2", 1, 2);
			result = countCommonStars(end1, start1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 3", 1, 2);
			result = countCommonStars(end1, start1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 4", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void GreekGeekTest13()
		{
			long long start1, end1, start2, end2, p;
			start1 = 24648817341102LL;		end1 = 41165114064236LL;
			start2 = 88046848035LL;		end2 = 13602161452932LL;
			p = 10000831349205LL;
			long long result = 0;
			long long expected = 0LL;
			result = countCommonStars(start1, end1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 1", 1, 2);
			result = countCommonStars(start1, end1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 2", 1, 2);
			result = countCommonStars(end1, start1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 3", 1, 2);
			result = countCommonStars(end1, start1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 4", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void GreekGeekTest14()
		{
			long long start1, end1, start2, end2, p;
			start1 = 298248781360904821LL;		end1 = 346420922793050061LL;
			start2 = 237084570581741798LL;		end2 = 726877079564549183LL;
			p = 389611850470532358LL;
			long long result = 0;
			long long expected = 48172141432145241LL;
			result = countCommonStars(start1, end1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 1", 1, 2);
			result = countCommonStars(start1, end1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 2", 1, 2);
			result = countCommonStars(end1, start1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 3", 1, 2);
			result = countCommonStars(end1, start1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 4", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void GreekGeekTest15()
		{
			long long start1, end1, start2, end2, p;
			start1 = 170331212821058551LL;		end1 = 891149660635282032LL;
			start2 = 125964175621755330LL;		end2 = 208256491683509799LL;
			p = 526532153531983174LL;
			long long result = 0;
			long long expected = 37925278862451249LL;
			result = countCommonStars(start1, end1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 1", 1, 2);
			result = countCommonStars(start1, end1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 2", 1, 2);
			result = countCommonStars(end1, start1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 3", 1, 2);
			result = countCommonStars(end1, start1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 4", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void GreekGeekTest16()
		{
			long long start1, end1, start2, end2, p;
			start1 = 1;		end1 = 5;
			start2 = 1;		end2 = 5;
			p = 2;
			long long result = 0;
			long long expected = 4;
			result = countCommonStars(start1, end1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 1", 1, 2);
			result = countCommonStars(start1, end1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 2", 1, 2);
			result = countCommonStars(end1, start1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 3", 1, 2);
			result = countCommonStars(end1, start1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 4", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void GreekGeekTest17()
		{
			long long start1, end1, start2, end2, p;
			start1 = 1;		end1 = 5;
			start2 = 5;		end2 = 5;
			p = 5;
			long long result = 0;
			long long expected = 0;
			result = countCommonStars(start1, end1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 1", 1, 2);
			result = countCommonStars(start1, end1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 2", 1, 2);
			result = countCommonStars(end1, start1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 3", 1, 2);
			result = countCommonStars(end1, start1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 4", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void GreekGeekTest18()
		{
			long long start1, end1, start2, end2, p;
			start1 = 5;		end1 = 5;
			start2 = 5;		end2 = 5;
			p = 7;
			long long result = 0;
			long long expected = 1;
			result = countCommonStars(start1, end1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 1", 1, 2);
			result = countCommonStars(start1, end1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 2", 1, 2);
			result = countCommonStars(end1, start1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 3", 1, 2);
			result = countCommonStars(end1, start1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 4", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void GreekGeekTest19()
		{
			long long start1, end1, start2, end2, p;
			start1 = 4;		end1 = 6;
			start2 = 4;		end2 = 6;
			p = 5;
			long long result = 0;
			long long expected = 2;
			result = countCommonStars(start1, end1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 1", 1, 2);
			result = countCommonStars(start1, end1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 2", 1, 2);
			result = countCommonStars(end1, start1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 3", 1, 2);
			result = countCommonStars(end1, start1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 4", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void GreekGeekTest20()
		{
			long long start1, end1, start2, end2, p;
			start1 = 7;		end1 = 4;
			start2 = 4;		end2 = 6;
			p = 10;
			long long result = 0;
			long long expected = 3;
			result = countCommonStars(start1, end1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 1", 1, 2);
			result = countCommonStars(start1, end1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 2", 1, 2);
			result = countCommonStars(end1, start1, start2, end2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 3", 1, 2);
			result = countCommonStars(end1, start1, end2, start2, p);
			Assert::AreEqual(expected, result, L"Failed GreekGeeks : 4", 1, 2);
		}
	};
}
