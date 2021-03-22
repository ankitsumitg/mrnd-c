#include "stdafx.h"
#include <stdlib.h>
#include "./../src/BetweenDays.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class BetweenDaysSpec
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

		struct node * createNode(int num) {
			struct node *newNode = (struct node *)malloc(sizeof(struct node));
			newNode->data= num;
			newNode->next = NULL;
			return newNode;
		}

		void addNode(struct node **head,int data){
			struct node * cur = createNode(data);
			if (*head == NULL){
				*head = cur;
			}
			else{
				struct node *temp = *head;
				cur->next = temp;
				*head = cur;
			}
		}
		
		[TestMethod, Timeout(2000)]
		void Sample1_BetweenDays()
		{
			int days = between_days(NULL, NULL);
			Assert::AreEqual(-1, days, L"Between Dates Null Case Failed", 1, 2);
		};

		//Un Comment below test case for more testing , Make sure you wont corrupt the File 
		//
		
		
		[TestMethod, Timeout(2000)]
		void Sample2_BetweenDays()
		{
			int dates[2][8] = { { 0, 2, 0, 4, 2, 0, 1, 6 }, { 0, 4, 0, 4, 2, 0, 1, 6 } };

			struct node *date1head = NULL, *date2head = NULL;
			for (int i = 7; i >= 0; i--){
				addNode(&date1head, dates[0][i]);
				addNode(&date2head, dates[1][i]);
			}

			int days = between_days(date1head, date2head);
			Assert::AreEqual(1, days, L"Date between 2nd April and 4th April failed", 1, 2);
		};
		

		[TestMethod, Timeout(1000)]
		void Real_BetweenDays1()
		{
			int dates[2][8] = { { 2, 4, 0, 3, 2, 0, 1, 1 }, { 2, 4, 0, 3, 2, 0, 1, 5 } };

			struct node *date1head = NULL, *date2head = NULL;
			for (int i = 7; i >= 0; i--){
				addNode(&date1head, dates[0][i]);
				addNode(&date2head, dates[1][i]);
			}
			//1096+282+82
			int days = between_days(date1head, date2head);
			Assert::AreEqual(1460, days, L"Date between 2nd April and 4th April failed", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_BetweenDays2()
		{
			int dates[2][8] = { { 2, 4, 0, 3, 2, 0, 1, 1 }, { 0, 1, 0, 4, 2, 0, 1, 1 } };

			struct node *date1head = NULL, *date2head = NULL;
			for (int i = 7; i >= 0; i--){
				addNode(&date1head, dates[0][i]);
				addNode(&date2head, dates[1][i]);
			}
			//1096+282+82
			int days = between_days(date1head, date2head);
			Assert::AreEqual(7, days, L"Date between 2nd April and 4th April failed", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_BetweenDays3()
		{
			int dates[2][8] = { { 2, 4, 0, 3, 2, 0, 1, 1 }, { 0, 1, 0, 4, 2, 0, 1, 1 } };

			struct node *date1head = NULL, *date2head = NULL;
			for (int i = 7; i >= 0; i--){
				addNode(&date1head, dates[0][i]);
				addNode(&date2head, dates[1][i]);
			}
			//1096+282+82
			int days = between_days(date1head, date2head);
			Assert::AreEqual(7, days, L"Date between 2nd April and 4th April failed", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_BetweenDays4()
		{
			int dates[2][8] = { { 0, 1, 0, 6, 2, 0, 1, 1 }, { 3, 0, 0, 6, 2, 0, 1, 1 } };

			struct node *date1head = NULL, *date2head = NULL;
			for (int i = 7; i >= 0; i--){
				addNode(&date1head, dates[0][i]);
				addNode(&date2head, dates[1][i]);
			}
			//1096+282+82
			int days = between_days(date1head, date2head);
			Assert::AreEqual(28, days, L"Date between 2nd April and 4th April failed", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_BetweenDays5()
		{
			int dates[2][8] = { { 3, 1, 1, 2, 2, 0, 1, 1 }, { 0, 1, 0, 1, 2, 0, 1, 2 } };

			struct node *date1head = NULL, *date2head = NULL;
			for (int i = 7; i >= 0; i--){
				addNode(&date1head, dates[0][i]);
				addNode(&date2head, dates[1][i]);
			}
			//1096+282+82
			int days = between_days(date1head, date2head);
			Assert::AreEqual(0, days, L"Date between 2nd April and 4th April failed", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_BetweenDays6()
		{
			int dates[2][8] = { { 3, 0, 1, 1, 2, 0, 1, 1 }, { 0, 1, 0, 4, 2, 0, 1, 2 } };

			struct node *date1head = NULL, *date2head = NULL;
			for (int i = 7; i >= 0; i--){
				addNode(&date1head, dates[0][i]);
				addNode(&date2head, dates[1][i]);
			}
			//1096+282+82
			int days = between_days(date1head, date2head);
			Assert::AreEqual(122, days, L"Date between 2nd April and 4th April failed", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_BetweenDays7()
		{
			int dates[2][8] = { { 2, 4, 0, 3, 2, 0, 1, 1 }, { 0, 1, 0, 9, 2, 0, 1, 1 } };

			struct node *date1head = NULL, *date2head = NULL;
			for (int i = 7; i >= 0; i--){
				addNode(&date1head, dates[0][i]);
				addNode(&date2head, dates[1][i]);
			}

			int days = between_days(date1head, date2head);
			Assert::AreEqual(160, days, L"Date between 2nd April and 4th April failed", 1, 2);
		};
		
		[TestMethod, Timeout(1000)]
		void Real_BetweenDays8()
		{
			int dates[2][8] = { { 2, 4, 0, 3, 2, 0, 0, 9 }, { 0, 1, 0, 9, 2, 0, 1, 1 } };

			struct node *date1head = NULL, *date2head = NULL;
			for (int i = 7; i >= 0; i--){
				addNode(&date1head, dates[0][i]);
				addNode(&date2head, dates[1][i]);
			}
			//1096+282+82
			int days = between_days(date1head, date2head);
			Assert::AreEqual(890, days, L"Date between 2nd April and 4th April failed", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_BetweenDays9()
		{
			int dates[2][8] = { { 2, 4, 0, 3, 1, 9, 0, 0 }, { 0, 1, 0, 9, 2, 0, 1, 1 } };

			struct node *date1head = NULL, *date2head = NULL;
			for (int i = 7; i >= 0; i--){
				addNode(&date1head, dates[0][i]);
				addNode(&date2head, dates[1][i]);
			}
			//1096+282+82
			int days = between_days(date1head, date2head);
			Assert::AreEqual(40702, days, L"Date between 2nd April and 4th April failed", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_BetweenDays10()
		{
			int dates[2][8] = { { 2, 4, 0, 1, 1, 8, 0, 0 }, { 0, 1, 0, 9, 2, 0, 1, 6 } };

			struct node *date1head = NULL, *date2head = NULL;
			for (int i = 7; i >= 0; i--){
				addNode(&date1head, dates[0][i]);
				addNode(&date2head, dates[1][i]);
			}
			//1096+282+82
			int days = between_days(date1head, date2head);
			Assert::AreEqual(79112, days, L"Date between 2nd April and 4th April failed", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_BetweenDays11()
		{
			int dates[2][8] = { { 2, 4, 0, 1, 1, 8, 0, 0 }, { 0, 1, 0, 9, 2, 0, 1, 6 } };

			struct node *date1head = NULL, *date2head = NULL;
			for (int i = 7; i >= 0; i--){
				addNode(&date1head, dates[0][i]);
				addNode(&date2head, dates[1][i]);
			}
			//1096+282+82
			int days = between_days(date1head, date2head);
			Assert::AreEqual(79112, days, L"Date between 2nd April and 4th April failed", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_BetweenDays12()
		{
			int dates[2][8] = { { 2, 4, 0, 1, 1, 8, 0, 0 }, { 0, 1, 0, 9, 2, 0, 1, 6 } };

			struct node *date1head = NULL, *date2head = NULL;
			for (int i = 7; i >= 0; i--){
				addNode(&date1head, dates[0][i]);
				addNode(&date2head, dates[1][i]);
			}
			//1096+282+82
			int days = between_days(date1head, date2head);
			Assert::AreEqual(79112, days, L"Date between 2nd April and 4th April failed", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_BetweenDays13()
		{
			int dates[2][8] = { { 2, 4, 0, 1, 1, 8, 0, 0 }, { 0, 1, 0, 9, 2, 0, 1, 6 } };

			struct node *date1head = NULL, *date2head = NULL;
			for (int i = 7; i >= 0; i--){
				addNode(&date1head, dates[0][i]);
				addNode(&date2head, dates[1][i]);
			}
			//1096+282+82
			int days = between_days(date1head, date2head);
			Assert::AreEqual(79112, days, L"Date between 2nd April and 4th April failed", 1, 2);
		};
		[TestMethod, Timeout(2000)]
		void Real_BetweenDays14()
		{
			int dates[2][8] = { { 2, 8, 0, 1, 2,0,1,6 }, { 0, 1, 0, 3, 2, 0, 1, 6 } };

			struct node *date1head = NULL, *date2head = NULL;
			for (int i = 7; i >= 0; i--){
				addNode(&date1head, dates[0][i]);
				addNode(&date2head, dates[1][i]);
			}
			
			int days = between_days(date1head, date2head);
			Assert::AreEqual(32, days, L"Date between 2nd April and 4th April failed", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_BetweenDays15()
		{
			int dates[2][8] = { { 2, 8, 0, 2, 2, 0, 1, 6 }, { 0, 1, 0, 3, 2, 0, 1, 6 } };

			struct node *date1head = NULL, *date2head = NULL;
			for (int i = 7; i >= 0; i--){
				addNode(&date1head, dates[0][i]);
				addNode(&date2head, dates[1][i]);
			}

			int days = between_days(date1head, date2head);
			Assert::AreEqual(1, days, L"Date between 2nd April and 4th April failed", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_BetweenDays16()
		{
			int dates[2][8] = { { 2, 8, 0, 2, 2, 0, 1, 6 }, { 2, 9, 0, 2, 2, 0, 1, 6 } };

			struct node *date1head = NULL, *date2head = NULL;
			for (int i = 7; i >= 0; i--){
				addNode(&date1head, dates[0][i]);
				addNode(&date2head, dates[1][i]);
			}

			int days = between_days(date1head, date2head);
			Assert::AreEqual(0, days, L"Date between 2nd April and 4th April failed", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_BetweenDays17()
		{
			int dates[2][8] = { { 2, 9, 0, 2, 2, 0, 1, 6 }, { 2,9, 0, 2, 2, 0, 1, 6 } };

			struct node *date1head = NULL, *date2head = NULL;
			for (int i = 7; i >= 0; i--){
				addNode(&date1head, dates[0][i]);
				addNode(&date2head, dates[1][i]);
			}

			int days = between_days(date1head, date2head);
			Assert::AreEqual(0, days, L"Date between 2nd April and 4th April failed", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_BetweenDays18()
		{
			int dates[2][8] = { { 3, 0, 0, 6, 2, 0, 1, 1 }, { 0, 1, 0, 6, 2, 0, 1, 1 } };

			struct node *date1head = NULL, *date2head = NULL;
			for (int i = 7; i >= 0; i--){
				addNode(&date1head, dates[0][i]);
				addNode(&date2head, dates[1][i]);
			}
			//1096+282+82
			int days = between_days(date1head, date2head);
			Assert::AreEqual(28, days, L"Date between 2nd April and 4th April failed", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_BetweenDays19()
		{
			int dates[2][8] = { { 0, 1, 0, 1, 2, 0, 1, 2 },{ 3, 1, 1, 2, 2, 0, 1, 1 } };

			struct node *date1head = NULL, *date2head = NULL;
			for (int i = 7; i >= 0; i--){
				addNode(&date1head, dates[0][i]);
				addNode(&date2head, dates[1][i]);
			}
			//1096+282+82
			int days = between_days(date1head, date2head);
			Assert::AreEqual(0, days, L"Date between 2nd April and 4th April failed", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_BetweenDays20()
		{
			int dates[2][8] = { { 0, 1, 0, 4, 2, 0, 1, 2 }, { 3, 0, 1, 1, 2, 0, 1, 1 }};

			struct node *date1head = NULL, *date2head = NULL;
			for (int i = 7; i >= 0; i--){
				addNode(&date1head, dates[0][i]);
				addNode(&date2head, dates[1][i]);
			}
			//1096+282+82
			int days = between_days(date1head, date2head);
			Assert::AreEqual(122, days, L"Date between 2nd April and 4th April failed", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_BetweenDays21()
		{
			int dates[2][8] = { { 0, 1, 0, 4, 2, 0, 1, 2 }, { 3, 0, 1, 1, 2, 0, 1, 1 } };

			struct node *date1head = NULL, *date2head = NULL;
			for (int i = 7; i >= 0; i--){
				addNode(&date1head, dates[0][i]);
				addNode(&date2head, dates[1][i]);
			}
			//1096+282+82
			int days = between_days(date1head, date2head);
			Assert::AreEqual(122, days, L"Date between 2nd April and 4th April failed", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_BetweenDays22()
		{
			int dates[2][8] = { { 0, 1, 0, 9, 2, 0, 1, 6 }, { 2, 4, 0, 1, 1, 8, 0, 0 } };

			struct node *date1head = NULL, *date2head = NULL;
			for (int i = 7; i >= 0; i--){
				addNode(&date1head, dates[0][i]);
				addNode(&date2head, dates[1][i]);
			}
			//1096+282+82
			int days = between_days(date1head, date2head);
			Assert::AreEqual(79112, days, L"Date between 2nd April and 4th April failed", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real_BetweenDays23()
		{
			int dates[2][8] = { { 0, 1, 0, 9, 2, 0, 1, 6 }, { 2, 4, 0, 1, 1, 8, 0, 0 } };

			struct node *date1head = NULL, *date2head = NULL;
			for (int i = 7; i >= 0; i--){
				addNode(&date1head, dates[0][i]);
				addNode(&date2head, dates[1][i]);
			}
			//1096+282+82
			int days = between_days(date1head, date2head);
			Assert::AreEqual(79112, days, L"Date between 2nd April and 4th April failed", 1, 2);
		};
	};
}
