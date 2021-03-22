#include "stdafx.h"
#include "../src/nPrime.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class nPrimeSpec
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



		[TestMethod, Timeout(1000)]
		void nPrimeBfTest()
		{
			int* Arr;
			Arr = nPrimeBruteForce(10);
			int output[4] = { 2, 3, 5, 7 };
			for (int i = 0; i < 4; i++)
			{
				Assert::AreEqual(Arr[i], output[i], L"Valid input should return prime list", 1,2 );
			}

			int* Arr2;
			Arr2 = nPrimeBruteForce(100);
			int output1[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
			for (int i = 0; i < 25; i++)
			{
				Assert::AreEqual(output1[i], Arr2[i], L"Valid input should return prime list", 1, 2);
			}
		};

		[TestMethod, Timeout(1000)]
		void nPrimeEvenRemovedTest()
		{
			
			int* Arr2;
			Arr2 = nPrimeEvenRemoved(100);
			int output1[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
			
			for (int i = 0; i < 25; i++)
			{
				Assert::AreEqual(output1[i], Arr2[i], L"Valid input should return prime list", 1, 2);
			}
		};

		[TestMethod, Timeout(1000)]
		void nPrimeOptimizedTest()
		{

			
			int output1[168] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73,
				79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179,
				181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
				283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401,
				409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521,
				523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643,
				647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769,
				773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907,
				911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997 };

			int numberOfTimes = 7000;
			for (int i = 0; i < numberOfTimes; i++){
				int* Arr2;
				Arr2 = nPrimeOptimized(1000);
				for (int i = 0; i < 168; i++)
				{
					Assert::AreEqual(output1[i], Arr2[i], L"nPrimeOptimizedTest Failed", 1, 2);
				}
			}
		};

	};
}
