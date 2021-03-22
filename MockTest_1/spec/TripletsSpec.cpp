#include "stdafx.h"
#include <stdlib.h>
#include "../src/Triplets.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

int Compare(const void * a, const void * b) {
	return (*(int*)a - *(int*)b);
}

int Input[1000005];


namespace spec
{
	[TestClass]
	public ref class TripletsSpec
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
		void TripletsSamples()
		{
			int Arr1[6] = {1, 2, 4, 6};
			int len1 = 4;
			long long res1 = findTriplets(Arr1,len1);
			Assert::AreEqual(2LL, res1, L"Wrong Triplet Count", 1, 2);

			int Arr2[6] = { 2, 1, 4, 3, 6 };
			int len2 = 5;
			long long res2 = findTriplets(Arr2, len2);
			Assert::AreEqual(1LL, res2, L"Wrong Triplet Count", 1, 2);


			int Arr3[4] = { 1, 1, 1, 1 };
			int len3 = 4;
			long long res3 = findTriplets(Arr3, len3);
			Assert::AreEqual(4LL, res3, L"Wrong Triplet Count", 1, 2);
		}

	};
}
