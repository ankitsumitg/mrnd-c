#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/studentsCount.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(studentsCountSpec)
	{
	public:

		TEST_METHOD(SCInputCheck)
		{
			int lessCount, moreCount;
			Assert::IsNull(studentsCount(NULL, 1, 1, &lessCount, &moreCount), L"Array NULL check failed.", LINE_INFO());
			int Arr1[1] = { 1 };
			Assert::IsNull(studentsCount(Arr1, -2, 1, &lessCount, &moreCount), L"Length less than zero check failed.", LINE_INFO());
		}
		
		TEST_METHOD(SCsingleElement)
		{
			int Arr1[1] = { 1 }, lessCount, moreCount;
			studentsCount(Arr1, 1, 1, &lessCount, &moreCount);
			Assert::AreEqual(0, lessCount, L"Single element lessCount 0 case failed.", LINE_INFO());
			Assert::AreEqual(0, moreCount, L"Single element moreCount 0 case failed.", LINE_INFO());
			int Arr2[1] = { 1 };
			studentsCount(Arr2, 1, 12, &lessCount, &moreCount);
			Assert::AreEqual(1, lessCount, L"Single element lessCount 1 case failed.", LINE_INFO());
			Assert::AreEqual(0, moreCount, L"Single element moreCount 0 case failed.", LINE_INFO());
			int Arr3[1] = { 111 };
			studentsCount(Arr3, 1, 12, &lessCount, &moreCount);
			Assert::AreEqual(0, lessCount, L"Single element lessCount 0 case failed.", LINE_INFO());
			Assert::AreEqual(1, moreCount, L"Single element moreCount 1 case failed.", LINE_INFO());
		}

		TEST_METHOD(SCsameElements)
		{
			int Arr[4] = { 12, 12, 12, 12 }, lessCount, moreCount;
			studentsCount(Arr, 4, 12, &lessCount, &moreCount);
			Assert::AreEqual(0, lessCount, L"Same elements lessCount 0 case failed.", LINE_INFO());
			Assert::AreEqual(0, moreCount, L"Same elements moreCount 0 case failed.", LINE_INFO());
		}

		TEST_METHOD(SCdifferentElements)
		{
			int Arr[5] = { 10, 20, 30, 40, 50 }, lessCount, moreCount;
			studentsCount(Arr, 5, 30, &lessCount, &moreCount);
			Assert::AreEqual(2, lessCount, L"Score equal to one element case failed.", LINE_INFO());
			Assert::AreEqual(2, moreCount, L"Score equal to one element case failed.", LINE_INFO());
			int Arr1[5] = { 10, 20, 31, 40, 50 };
			studentsCount(Arr1, 5, 30, &lessCount, &moreCount);
			Assert::AreEqual(2, lessCount, L"Score not equal to any element case failed.", LINE_INFO());
			Assert::AreEqual(3, moreCount, L"Score not equal to any element case failed.", LINE_INFO());
		}
	};
}