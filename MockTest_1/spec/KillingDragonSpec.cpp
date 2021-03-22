#include "stdafx.h"
#include "../src/killingDragons.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class KillingDragonsSpec
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



		
		static unsigned long int nextr = 1;
		static unsigned long int itr = 0;
		static unsigned long int RANDMAX = 1e5;
		int Rand() {
			nextr = (nextr * 1103515245 + 12345) % INT_MAX;
			return (unsigned int)(nextr) % RANDMAX;
		}

		void sRand(unsigned int seed) {
			nextr = seed;
			itr = 0;
		}

		[TestMethod, Timeout(500)]
		void KillingDragonsInvalid()
		{

			long* dragonPower = (long*)calloc(1, sizeof(long));
			long* energyPortion = (long*)calloc(1, sizeof(long));
			dragonPower[0] = 1;
			energyPortion[0] = 1;
			int res = canSavePrincess(NULL, energyPortion, 1);

			Assert::AreEqual(-1, res, L"Simple Case 1 Failed for Killing Dragon", 1, 2, 1, 2);

			dragonPower[0] = 1;
			energyPortion[0] = 2;
			res = canSavePrincess(dragonPower, NULL, 1);
			Assert::AreEqual(-1, res, L"Simple Case 1 Failed for Killing Dragon", 1, 2, 1, 2);


			dragonPower[0] = 2;
			energyPortion[0] = 1;
			res = canSavePrincess(dragonPower, energyPortion, -1);
			Assert::AreEqual(-1, res, L"Simple Case 1 Failed for Killing Dragon", 1, 2, 1, 2);


		};

		[TestMethod, Timeout(500)]
		void KillingDragonsSamples()
		{

			long dragonPower1[] = { 1, 5, 7 };
			long energyPortion1[] = { 2, 6, 3 };

			int res1 = canSavePrincess(dragonPower1, energyPortion1, sizeof(dragonPower1)/sizeof(dragonPower1[0]));

			Assert::AreEqual(-1, res1, L"Simple Case 1 Failed for Killing Dragon", 1, 2, 1, 2);

			long dragonPower2[] = { 5,10,12,4 };
			long energyPortion2[] = { 20,2,1,15 };

			int res2 = canSavePrincess(dragonPower2, energyPortion2, sizeof(dragonPower2) / sizeof(dragonPower2[0]));

			Assert::AreEqual(4, res2, L"Simple Case 1 Failed for Killing Dragon", 1, 2, 1, 2);



			long dragonPower3[] = { 7,10,6};
			long energyPortion3[] = { 8, 9, 7 };

			int res3 = canSavePrincess(dragonPower3, energyPortion3, sizeof(dragonPower3) / sizeof(dragonPower3[0]));

			Assert::AreEqual(1, res3, L"Simple Case 1 Failed for Killing Dragon", 1, 2, 1, 2);


		};
		[TestMethod, Timeout(500)]
		void Simple1_KillingDragons()
		{

			long* dragonPower = (long*)calloc(1, sizeof(long));
			long* energyPortion = (long*)calloc(1, sizeof(long));
			dragonPower[0] = 1;
			energyPortion[0] = 1;
			int res = canSavePrincess(dragonPower, energyPortion, 1);
			
			Assert::AreEqual(1, res, L"Simple Case 1 Failed for Killing Dragon", 1, 2, 1, 2);
			
			dragonPower[0] = 1;
			energyPortion[0] = 2;
			res = canSavePrincess(dragonPower, energyPortion, 1);
			Assert::AreEqual(1, res, L"Simple Case 1 Failed for Killing Dragon", 1, 2, 1, 2);
			

			dragonPower[0] = 2;
			energyPortion[0] = 1;
			res = canSavePrincess(dragonPower, energyPortion, 1);
			Assert::AreEqual(-1, res, L"Simple Case 1 Failed for Killing Dragon", 1, 2, 1, 2);


		};


		[TestMethod, Timeout(500)]
		void Simple2_KillingDragons()
		{

			long dragonPower[5] = { 1, 2, 3, 4, 5 };
			long energyPortion[5] = { 5, 4, 3, 2, 1 };
			
			int index = 0;
			int res = 0;

			for (index = 2; index <= 5; index++){
				res = canSavePrincess(dragonPower, energyPortion, index);
				Assert::AreEqual(1, res, L"Simple Case 2 Failed for Killing Dragon", 1, 2, 1, 2);

			}


		};
		[TestMethod, Timeout(500)]
		void Simple3_KillingDragons()
		{

			long dragonPower[5] = { 1, 3, 5, 4, 2 };
			long energyPortion[5] = { 2, 2, 4, 4, 3};

			int index = 0;
			int res = 0;

			res = canSavePrincess(dragonPower, energyPortion, 2);
			Assert::AreEqual(1, res, L"Simple Case 3 Failed for Killing Dragon", 1, 2, 1, 2);


			res = canSavePrincess(dragonPower, energyPortion, 3);
			Assert::AreEqual(-1, res, L"Simple Case 3 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 4);
			Assert::AreEqual(-1, res, L"Simple Case 3 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 5);
			Assert::AreEqual(4, res, L"Simple Case 3 Failed for Killing Dragon", 1, 2, 1, 2);

		};


		[TestMethod, Timeout(500)]
		void Simple4_KillingDragons()
		{

			long dragonPower[100];
			long energyPortion[100];
			int index = 0;
			int res = 0;
			int actualAns = 0;

			srand(13);
			for (index = 0; index < 100; index++)
				dragonPower[index] = rand() % 100;
			
			srand(17);
			for (index = 0; index < 100; index++)
				energyPortion[index] = rand() % 100;

			res = canSavePrincess(dragonPower, energyPortion, 50);
			Assert::AreEqual(10, res, L"Simple Case 4 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 75);
			Assert::AreEqual(-1, res, L"Simple Case 4 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 100);
			Assert::AreEqual(10, res, L"Simple Case 4 Failed for Killing Dragon", 1, 2, 1, 2);

		};

		[TestMethod, Timeout(500)]
		void Simple5_KillingDragons()
		{

			long dragonPower[100];
			long energyPortion[100];
			int index = 0;
			int res = 0;
			int actualAns = 0;

			srand(7);
			for (index = 0; index < 100; index++)
				dragonPower[index] = rand() % 1000;

			srand(5);
			for (index = 0; index < 100; index++)
				energyPortion[index] = rand() % 1000;

			res = canSavePrincess(dragonPower, energyPortion, 50);
			Assert::AreEqual(2, res, L"Simple Case 5 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 75);
			Assert::AreEqual(2, res, L"Simple Case 5 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 100);
			Assert::AreEqual(100, res, L"Simple Case 5 Failed for Killing Dragon", 1, 2, 1, 2);

		};

		[TestMethod, Timeout(500)]
		void Medium1_KillingDragons()
		{

			long dragonPower[300];
			long energyPortion[300];
			int index = 0;
			int res = 0;
			int actualAns = 0;

			srand(7);
			for (index = 0; index < 300; index++)
				dragonPower[index] = rand() % 100;

			srand(2);
			for (index = 0; index < 300; index++)
				energyPortion[index] = rand() % 100;

			res = canSavePrincess(dragonPower, energyPortion, 100);
			Assert::AreEqual(3, res, L"Medium Case 1 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 150);
			Assert::AreEqual(3, res, L"Medium Case 1 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 300);
			Assert::AreEqual(255, res, L"Medium Case 1 Failed for Killing Dragon", 1, 2, 1, 2);

		};

		[TestMethod, Timeout(500)]
		void Medium2_KillingDragons()
		{

			long dragonPower[300];
			long energyPortion[300];
			int index = 0;
			int res = 0;
			int actualAns = 0;

			srand(170);
			for (index = 0; index < 300; index++)
				dragonPower[index] = rand() % 1000;

			srand(160);
			for (index = 0; index < 300; index++)
				energyPortion[index] = rand() % 1000;

			res = canSavePrincess(dragonPower, energyPortion, 100);
			Assert::AreEqual(7, res, L"Medium Case 2 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 200);
			Assert::AreEqual(-1, res, L"Medium Case 2 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 300);
			Assert::AreEqual(197, res, L"Medium Case 2 Failed for Killing Dragon", 1, 2, 1, 2);

		};

		[TestMethod, Timeout(500)]
		void Medium3_KillingDragons()
		{

			long dragonPower[400];
			long energyPortion[400];
			int index = 0;
			int res = 0;
			int actualAns = 0;

			srand(205);
			for (index = 0; index < 400; index++)
				dragonPower[index] = rand() % 500;

			srand(210);
			for (index = 0; index < 400; index++)
				energyPortion[index] = rand() % 500;

			res = canSavePrincess(dragonPower, energyPortion, 300);
			Assert::AreEqual(-1, res, L"Medium Case 3 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 350);
			Assert::AreEqual(-1, res, L"Medium Case 3 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 400);
			Assert::AreEqual(223, res, L"Medium Case 3 Failed for Killing Dragon", 1, 2, 1, 2);

		};

		[TestMethod, Timeout(500)]
		void Medium4_KillingDragons()
		{

			long dragonPower[400];
			long energyPortion[400];
			int index = 0;
			int res = 0;
			int actualAns = 0;

			srand(165);
			for (index = 0; index < 400; index++)
				dragonPower[index] = rand() % 1000;

			srand(160);
			for (index = 0; index < 400; index++)
				energyPortion[index] = rand() % 1000;

			res = canSavePrincess(dragonPower, energyPortion, 300);
			Assert::AreEqual(-1, res, L"Medium Case 4 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 350);
			Assert::AreEqual(141, res, L"Medium Case 4 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 400);
			Assert::AreEqual(141, res, L"Medium Case 4 Failed for Killing Dragon", 1, 2, 1, 2);

		};


		
		[TestMethod, Timeout(500)]
		void Medium5_KillingDragons()
		{

			long dragonPower[500];
			long energyPortion[500];
			int index = 0;
			int res = 0;
			int actualAns = 0;

			srand(255);
			for (index = 0; index < 500; index++)
				dragonPower[index] = rand() % 100;

			srand(250);
			for (index = 0; index < 500; index++)
				energyPortion[index] = rand() % 100;

			res = canSavePrincess(dragonPower, energyPortion, 350);
			Assert::AreEqual(28, res, L"Medium Case 5 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 400);
			Assert::AreEqual(-1, res, L"Medium Case 5 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 500);
			Assert::AreEqual(407, res, L"Medium Case  Failed for Killing Dragon", 1, 2, 1, 2);

		};

		[TestMethod, Timeout(500)]
		void Medium6_KillingDragons()
		{

			long dragonPower[500];
			long energyPortion[500];
			int index = 0;
			int res = 0;
			int actualAns = 0;

			srand(250);
			for (index = 0; index < 500; index++)
				dragonPower[index] = rand() % 1000;

			srand(256);
			for (index = 0; index < 500; index++)
				energyPortion[index] = rand() % 1000;

			res = canSavePrincess(dragonPower, energyPortion, 350);
			Assert::AreEqual(107, res, L"Medium Case 6 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 400);
			Assert::AreEqual(107, res, L"Medium Case 6 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 500);
			Assert::AreEqual(478, res, L"Medium Case  Failed for Killing Dragon", 1, 2, 1, 2);

		};

		[TestMethod, Timeout(500)]
		void Medium7_KillingDragons()
		{

			long dragonPower[750];
			long energyPortion[750];
			int index = 0;
			int res = 0;
			int actualAns = 0;

			srand(335);
			for (index = 0; index < 750; index++)
				dragonPower[index] = rand() % 500;

			srand(333);
			for (index = 0; index < 750; index++)
				energyPortion[index] = rand() % 500;

			res = canSavePrincess(dragonPower, energyPortion, 550);
			Assert::AreEqual(9, res, L"Medium Case 7 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 650);
			Assert::AreEqual(-1, res, L"Medium Case 7 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 750);
			Assert::AreEqual(-1, res, L"Medium Case 7 Failed for Killing Dragon", 1, 2, 1, 2);

		};


		[TestMethod, Timeout(500)]
		void Medium8_KillingDragons()
		{

			long dragonPower[750];
			long energyPortion[750];
			int index = 0;
			int res = 0;
			int actualAns = 0;

			srand(250);
			for (index = 0; index < 750; index++)
				dragonPower[index] = rand() % 1000;

			srand(256);
			for (index = 0; index < 750; index++)
				energyPortion[index] = rand() % 1000;

			res = canSavePrincess(dragonPower, energyPortion, 550);
			Assert::AreEqual(-1, res, L"Medium Case 8 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 650);
			Assert::AreEqual(524, res, L"Medium Case 8 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 750);
			Assert::AreEqual(524, res, L"Medium Case 8 Failed for Killing Dragon", 1, 2, 1, 2);

		};


		[TestMethod, Timeout(500)]
		void Large1_KillingDragons()
		{

			long dragonPower[1000];
			long energyPortion[1000];
			int index = 0;
			int res = 0;
			int actualAns = 0;

			srand(37);
			for (index = 0; index < 1000; index++)
				dragonPower[index] = rand() % 500;

			srand(41);
			for (index = 0; index < 1000; index++)
				energyPortion[index] = rand() % 500;

			res = canSavePrincess(dragonPower, energyPortion, 800);
			Assert::AreEqual(475, res, L"Large Case 1 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 900);
			Assert::AreEqual(475, res, L"Large Case 1 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 1000);
			Assert::AreEqual(-1, res, L"Large Case 1 Failed for Killing Dragon", 1, 2, 1, 2);

		};


		[TestMethod, Timeout(500)]
		void Large2_KillingDragons()
		{

			long dragonPower[1000];
			long energyPortion[1000];
			int index = 0;
			int res = 0;
			int actualAns = 0;

			srand(47);
			for (index = 0; index < 1000; index++)
				dragonPower[index] = rand() % 1000;

			srand(41);
			for (index = 0; index < 1000; index++)
				energyPortion[index] = rand() % 1000;

			res = canSavePrincess(dragonPower, energyPortion, 800);
			Assert::AreEqual(33, res, L"Large Case 2 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 900);
			Assert::AreEqual(812, res, L"Large Case 2 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 1000);
			Assert::AreEqual(812, res, L"Large Case 2 Failed for Killing Dragon", 1, 2, 1, 2);

		};

		[TestMethod, Timeout(500)]
		void Large3_KillingDragons()
		{

			long dragonPower[10000];
			long energyPortion[10000];
			int index = 0;
			int res = 0;
			int actualAns = 0;

			srand(11);
			for (index = 0; index < 10000; index++)
				dragonPower[index] = rand() % 500;

			srand(50);
			for (index = 0; index < 10000; index++)
				energyPortion[index] = rand() % 500;

			res = canSavePrincess(dragonPower, energyPortion, 5000);
			Assert::AreEqual(3337, res, L"Large Case 3 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 7500);
			Assert::AreEqual(-1, res, L"Large Case 3 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 10000);
			Assert::AreEqual(7187, res, L"Large Case 3 Failed for Killing Dragon", 1, 2, 1, 2);

		};

		[TestMethod, Timeout(500)]
		void Large4_KillingDragons()
		{

			long dragonPower[10000];
			long energyPortion[10000];
			int index = 0;
			int res = 0;
			int actualAns = 0;

			srand(210);
			for (index = 0; index < 10000; index++)
				dragonPower[index] = rand() % 1000;

			srand(5);
			for (index = 0; index < 10000; index++)
				energyPortion[index] = rand() % 1000;

			res = canSavePrincess(dragonPower, energyPortion, 5000);
			Assert::AreEqual(1952, res, L"Large Case 4 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 7500);
			Assert::AreEqual(-1, res, L"Large Case 4 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 10000);
			Assert::AreEqual(7187, res, L"Large Case 4 Failed for Killing Dragon", 1, 2, 1, 2);

		};


		[TestMethod, Timeout(500)]
		void Large5_KillingDragons()
		{

			long dragonPower[100000];
			long energyPortion[100000];
			int index = 0;
			int res = 0;
			int actualAns = 0;

			srand(510);
			for (index = 0; index < 100000; index++)
				dragonPower[index] = rand() % 500;

			srand(255);
			for (index = 0; index < 100000; index++)
				energyPortion[index] = rand() % 500;

			res = canSavePrincess(dragonPower, energyPortion, 50000);
			Assert::AreEqual(-1, res, L"Large Case 5 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 75000);
			Assert::AreEqual(51820, res, L"Large Case 5 Failed for Killing Dragon", 1, 2, 1, 2);

			res = canSavePrincess(dragonPower, energyPortion, 100000);
			Assert::AreEqual(-1, res, L"Large Case 5 Failed for Killing Dragon", 1, 2, 1, 2);

		};

	};

}