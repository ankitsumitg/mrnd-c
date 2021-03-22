#include "stdafx.h"
#include "./../src/VoidPointers.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class VoidPointersSpec
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
		void typeCastVoidToInt_Test()
		{
			int expected = 10;
			void * ptr = (void *)&expected;
			int actual = typeCastVoidToInt(ptr);
			Assert::AreEqual(expected, actual, L"typeCastVoidToInt_Test 10 failed", 1, 2);
		}

		[TestMethod(), Timeout(3000)]
		void typeCastVoidToInt_Test2()
		{
			int expected = 99923;
			void * ptr = (void *)&expected;
			int actual = typeCastVoidToInt(ptr);
			Assert::AreEqual(expected, actual, L"typeCastVoidToInt_Test 99923 failed", 1, 2);
		}

		[TestMethod(), Timeout(3000)]
		void compareIntTest()
		{
			int a1 = 999;
			int a2 = 998;
			int check = compareInt((void *)&a1, (void *)&a2);
			Assert::AreEqual(1, check, L"999,998 shoudld return 1", 1, 2);
			int a3 = 999;
			int a4 = 999;
			int check2 = compareInt((void *)&a3, (void *)&a4);
			Assert::AreEqual(0, check2, L"999,999 shoudld return 0", 1, 2);
			int a5 = 499;
			int a6 = 998;
			int check3 = compareInt((void *)&a5, (void *)&a6);
			Assert::AreEqual(-1, check3, L"499,998 shoudld return -1", 1, 2);
		}
		
		[TestMethod(), Timeout(3000)]
		void compareFloatTest()
		{
			float a1 = 999.98;
			float a2 = 998.99;
			int check = compareInt((void *)&a1, (void *)&a2);
			Assert::AreEqual(1, check, L"999.98,998.99 shoudld return 1", 1, 2);
			float a3 = 49.999;
			float a4 = 49.999;
			int check2 = compareInt((void *)&a3, (void *)&a4);
			Assert::AreEqual(0, check2, L"49.999,49.999 shoudld return 0", 1, 2);
			float a5 = 0.499;
			float a6 = 45.345;
			int check3 = compareInt((void *)&a5, (void *)&a6);
			Assert::AreEqual(-1, check3, L"0.499,45.345 shoudld return -1", 1, 2);
		}

		[TestMethod(), Timeout(3000)]
		void compareCharTest()
		{
			char a1 = 'z';
			char a2 = 'a';
			int check = compareInt((void *)&a1, (void *)&a2);
			Assert::AreEqual(1, check, L"z,a shoudld return 1", 1, 2);
			char a3 = 'b';
			char a4 = 'b';
			int check2 = compareInt((void *)&a3, (void *)&a4);
			Assert::AreEqual(0, check2, L"b,b shoudld return 0", 1, 2);
			char a5 = 'x';
			char a6 = 'y';
			int check3 = compareInt((void *)&a5, (void *)&a6);
			Assert::AreEqual(-1, check3, L"x,y shoudld return -1", 1, 2);
		}

		[TestMethod(), Timeout(3000)]
		void getGreater_TestUsingInts() {
			int a1 = 999;
			int a2 = 1998;
			void * greater = getGreater((void *)&a1, (void *)&a2, &compareInt);
			if (greater != (void *)&a2) {
				//Intentionally failing test
				Assert::AreEqual(1, 2, L"getGreater when passed 2 ints, is not returning correct address of greater value.Check type casting etc", 1, 2);
			}
			
		}

		[TestMethod(), Timeout(3000)]
		void getGreater_TestUsingFloats() {
			float a1 = 9.99;
			float a2 = 1.998;
			void * greater = getGreater((void *)&a1, (void *)&a2, &compareFloat);
			if (greater != (void *)&a1) {
				//Intentionally failing test
				Assert::AreEqual(1, 2, L"getGreater when passed 2 floats, is not returning correct address of greater value.Check type casting etc", 1, 2);
			}

		}
		

		[TestMethod(), Timeout(30000)]
		void getTwoGreater_TestUsingInts() {
			int a1 = 999;
			int a2 = 1998;
			int a3 = 9999;
			void * greatest = (void *)&a3;
			void * greatest2 = (void *)&a2;
			void ** result = getTwoGreater((void *)&a1, (void *)&a2,(void *)&a3, &compareInt);
			if (result[0] != greatest) {
				//Intentionally failing test
				Assert::AreEqual(1, 2, L"getTWoGreater when passed 3 ints, is not returning correct address of greatest value for result[0].Assign correct addresses", 1, 2);
			}
			if (result[1] != greatest2) {
				//Intentionally failing test
				Assert::AreEqual(1, 2, L"getTWoGreater when passed 3 ints, is not returning correct address of 2nd greatest value for result[0].Assign correct addresses", 1, 2);
			}

		}

		[TestMethod(), Timeout(30000)]
		void getTwoGreater_TestUsingChars() {
			char a1 = 'b';
			char a2 = 'z';
			char a3 = 'a';
			void * greatest = (void *)&a2;
			void * greatest2 = (void *)&a1;
			void ** result = getTwoGreater((void *)&a1, (void *)&a2, (void *)&a3, &compareChar);
			if (result[0] != greatest) {
				//Intentionally failing test
				Assert::AreEqual(1, 2, L"getTWoGreater when passed 3 chars, is not returning correct address of greatest value for result[0].Assign correct addresses", 1, 2);
			}
			if (result[1] != greatest2) {
				//Intentionally failing test
				Assert::AreEqual(1, 2, L"getTWoGreater when passed 3 chars, is not returning correct address of 2nd greatest value for result[0].Assign correct addresses", 1, 2);
			}

		}
		

	};
}
