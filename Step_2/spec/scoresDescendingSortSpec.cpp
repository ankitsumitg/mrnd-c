#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/scoresDescendingSort.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(scoresDescendingSortSpec)
	{
	public:

		TEST_METHOD(SDinValidInputCheck)
		{
			
			Assert::IsNull(scoresDescendingSort(NULL, 1), L"Array NULL check failed.", LINE_INFO());
			struct student students[1] = { { "stud1", 50 } };
			Assert::IsNull(scoresDescendingSort(students, -2), L"Length less than zero check failed.", LINE_INFO());
		}

		TEST_METHOD(SDsingleElement)
		{
			struct student students[1] = { { "stud1", 50 } };
			scoresDescendingSort(students, 1);
			Assert::AreEqual(50, students[0].score, L"Value at index 0 should be 50", LINE_INFO());
		}

		TEST_METHOD(SDsortedScores)
		{
			struct student students[3] = { { "stud1", 70 }, { "stud2", 60 }, { "stud3", 50 } };
			scoresDescendingSort(students, 3);
			Assert::AreEqual(70, students[0].score, L"Value at index 0 should be 50", LINE_INFO());
			Assert::AreEqual(60, students[1].score, L"Value at index 1 should be 50", LINE_INFO());
			Assert::AreEqual(50, students[2].score, L"Value at index 2 should be 50", LINE_INFO());
		}

		TEST_METHOD(SDsameScores)
		{
			struct student students[3] = { { "stud1", 50 }, { "stud2", 50 }, { "stud3", 50 } };
			scoresDescendingSort(students, 3);
			Assert::AreEqual(50, students[0].score, L"Value at index 0 should be 50", LINE_INFO());
			Assert::AreEqual(50, students[1].score, L"Value at index 1 should be 50", LINE_INFO());
			Assert::AreEqual(50, students[2].score, L"Value at index 2 should be 50", LINE_INFO());
		}

		TEST_METHOD(SDdifferentScores)
		{
			struct student students[3] = { { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } };
			scoresDescendingSort(students, 3);
			Assert::AreEqual(40, students[0].score, L"Value at index 0 should be 40", LINE_INFO());
			Assert::AreEqual(30, students[1].score, L"Value at index 1 should be 30", LINE_INFO());
			Assert::AreEqual(20, students[2].score, L"Value at index 2 should be 20", LINE_INFO());
		}

	};
}