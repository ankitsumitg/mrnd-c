#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/topKStudents.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(topKStudentsSpec)
	{
	public:

		void swap(int *a, int *b) {
			*a = *a + *b;
			*b = *a - *b;
			*a = *a - *b;
		}

		void sort(int arr[], int len) {
			for (int i = 0; i < len - 1; ++i) {
				for (int j = 0; j < len - i - 1; ++j) {
					if (arr[j] > arr[j + 1]) {
						swap(&arr[j], &arr[j + 1]);
					}
				}
			}
		}

		bool validate(int expected[], int len, struct student **result) {
			int *actual = (int *)malloc(len * sizeof(int));
			for (int i = 0; i < len; ++i) {
				actual[i] = result[i]->score;
			}
			sort(actual, len);
			for (int i = 0; i < len; ++i) {
				if (expected[i] != actual[i]) {
					return false;
				}
			}
			return true;
		}

		TEST_METHOD(TKnegativeKValue)
		{
			struct student students[3] = { { "stud1", 70 }, { "stud2", 60 }, { "stud3", 50 } };
			struct student **result = topKStudents(students, 3, -3);
			bool isValid = false;
			if (result == NULL) {
				isValid = true;
			}
			Assert::AreEqual(true, isValid, L"Negative K value case failed.", LINE_INFO());
		}

		TEST_METHOD(TKzeroKValue)
		{
			struct student students[3] = { { "stud1", 70 }, { "stud2", 60 }, { "stud3", 50 } };
			struct student **result = topKStudents(students, 3, 0);
			bool isValid = false;
			if (result == NULL) {
				isValid = true;
			}
			Assert::AreEqual(true, isValid, L"K value zero case failed.", LINE_INFO());
		}

		TEST_METHOD(TKGreaterThanLength)
		{
			struct student students[3] = { { "stud1", 60 }, { "stud2", 70 }, { "stud3", 50 } };
			struct student **result = topKStudents(students, 3, 5);
			int exp[] = { 50, 60, 70 };
			Assert::IsTrue(validate(exp, 3, result), L"K greater than length case failed.", LINE_INFO());
		}

		TEST_METHOD(TKValue1)
		{
			struct student students[3] = { { "stud1", 50 }, { "stud2", 60 }, { "stud3", 70 } };
			struct student **result = topKStudents(students, 3, 1);
			Assert::AreEqual(70, result[0]->score, L"K value 1 case failed.", LINE_INFO());
		}

		TEST_METHOD(positiveKValue)
		{
			struct student students[3] = { { "stud1", 50 }, { "stud2", 60 }, { "stud3", 70 } };
			struct student **result = topKStudents(students, 3, 2);
			int exp[] = { 60, 70 };
			Assert::IsTrue(validate(exp, 2, result), L"K value 2 case failed.", LINE_INFO());

			struct student students1[6] = { { "stud1", 30 }, { "stud2", 10 }, { "stud3", 60 }, { "stud4", 50 }, { "stud5", 20 }, { "stud6", 40 } };
			struct student **result1 = topKStudents(students1, 6, 3);
			int exp1[] = { 40, 50, 60 };
			Assert::IsTrue(validate(exp1, 3, result1), L"K value 3 case failed.", LINE_INFO());
		}

	};
}