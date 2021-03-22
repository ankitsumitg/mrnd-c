#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "../src/MeetingPoint.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class MeetingPointSpec
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

		struct CityNode * createCityNode(char name[20]) {
			struct CityNode *newNode = (struct CityNode *)calloc(1,sizeof(CityNode));
			strcpy(newNode->city, name);
			newNode->nextCity = NULL;
			return newNode;
		}

		struct CityNode * createPath(char cities[][20],int len) {
			struct CityNode *head = NULL;

			for (int i = len - 1; i >= 0; i--){
				struct CityNode *newNode = createCityNode(cities[i]);
				newNode->nextCity = head;
				head = newNode;
			}
			return head;
		}


		[TestMethod, Timeout(500)]
		void MeetingPoint_SampleTest01()
		{
			char cities1[][20] = { "K", "L", "N", "O" };
			char cities2[][20] = { "Z", "X", "N", "O" };
			CityNode *deepikaStartCity = createPath(cities1, 4);
			CityNode *mayaStartCity = createPath(cities2, 4);
			int numberOfCitiesMayaShouldTravel = 0;
			CityNode *meet = meetingPoint(deepikaStartCity, mayaStartCity, &numberOfCitiesMayaShouldTravel);

			int gotnull = 0;
			if (meet == NULL){
				gotnull = 1;
			}
			Assert::AreEqual(0, gotnull, L"Should Not Return NULL", 1, 2);
			Assert::AreEqual(0, strcmp(meet->city, "N"), L"Meeting City Comparision ", 1, 2);
			Assert::AreEqual(2, numberOfCitiesMayaShouldTravel, L"NumberOfCitiesMayaShouldTravel", 1, 2);
		};

		[TestMethod, Timeout(500)]
		void MeetingPoint_SampleTest02()
		{
			char cities1[][20] = { "A", "D", "K", "L","M","N","O" };
			char cities2[][20] = { "Z", "X", "Q","P","D","K","L","M","N","O" };
			CityNode *deepikaStartCity = createPath(cities1, 7);
			CityNode *mayaStartCity = createPath(cities2, 10);
			int numberOfCitiesMayaShouldTravel = 0;
			CityNode *meet = meetingPoint(deepikaStartCity, mayaStartCity, &numberOfCitiesMayaShouldTravel);

			int gotnull = 0;
			if (meet == NULL){
				gotnull = 1;
			}
			Assert::AreEqual(0, gotnull, L"Should Not Return NULL", 1, 2);
			Assert::AreEqual(0, strcmp(meet->city, "D"), L"Meeting City Comparision ", 1, 2);
			Assert::AreEqual(4, numberOfCitiesMayaShouldTravel, L"NumberOfCitiesMayaShouldTravel", 1, 2);
		};

		[TestMethod, Timeout(500)]
		void MeetingPoint_SampleTest03()
		{
			char cities1[][20] = { "A", "B", "C", "B", "D", "B", "F" };
			char cities2[][20] = {  "Z", "X", "Y","B","F" };
			CityNode *deepikaStartCity = createPath(cities1, 7);
			CityNode *mayaStartCity = createPath(cities2, 5);
			int numberOfCitiesMayaShouldTravel = 0;
			CityNode *meet = meetingPoint(deepikaStartCity, mayaStartCity, &numberOfCitiesMayaShouldTravel);

			int gotnull = 0;
			if (meet == NULL){
				gotnull = 1;
			}
			Assert::AreEqual(0, gotnull, L"Should Not Return NULL", 1, 2);
			Assert::AreEqual(0, strcmp(meet->city, "B"), L"Meeting City Comparision ", 1, 2);
			Assert::AreEqual(3, numberOfCitiesMayaShouldTravel, L"NumberOfCitiesMayaShouldTravel", 1, 2);
		};

		[TestMethod, Timeout(500)]
		void MeetingPoint_Test04()
		{
			char cities1[][20] = { "KanyaKumari", "Kochi", "Ooty", "Mysore", "Bangalore", "Hyderabad", "Bhopal" };
			char cities2[][20] = { "Tirupati", "Bhimvaram", "Vijayawada", "Vizag", "Hyderabad", "Bhopal" };
			CityNode *deepikaStartCity = createPath(cities1, 7);
			CityNode *mayaStartCity = createPath(cities2, 6);
			int numberOfCitiesMayaShouldTravel = 0;
			CityNode *meet = meetingPoint(deepikaStartCity, mayaStartCity, &numberOfCitiesMayaShouldTravel);

			int gotnull = 0;
			if (meet == NULL){
				gotnull = 1;
			}
			Assert::AreEqual(0, gotnull, L"Should Not Return NULL", 1, 2);
			Assert::AreEqual(0, strcmp(meet->city, "Hyderabad"), L"Meeting City Comparision ", 1, 2);
			Assert::AreEqual(4, numberOfCitiesMayaShouldTravel, L"NumberOfCitiesMayaShouldTravel", 1, 2);
		};

		[TestMethod, Timeout(500)]
		void MeetingPoint_Test05()
		{
			char cities1[][20] = { "A","B","C","D","E","F","G","H" };
			char cities2[][20] = { "Z","Y","E","F","G","H" };
			CityNode *deepikaStartCity = createPath(cities1, 8);
			CityNode *mayaStartCity = createPath(cities2, 6);
			int numberOfCitiesMayaShouldTravel = 0;
			CityNode *meet = meetingPoint(deepikaStartCity, mayaStartCity, &numberOfCitiesMayaShouldTravel);

			int gotnull = 0;
			if (meet == NULL){
				gotnull = 1;
			}

			Assert::AreEqual(0, gotnull, L"Should Not Return NULL", 1, 2);
			Assert::AreEqual(0, strcmp(meet->city, "E"), L"Meeting City Comparision ", 1, 2);
			Assert::AreEqual(2, numberOfCitiesMayaShouldTravel, L"NumberOfCitiesMayaShouldTravel", 1, 2);
		};

		[TestMethod, Timeout(500)]
		void MeetingPoint_Test06_NullCheck()
		{

			CityNode *head = (struct CityNode *)calloc(1, sizeof(CityNode));
			int numberOfCitiesMayaShouldTravel = 0;
			CityNode *meet = meetingPoint(head,NULL, &numberOfCitiesMayaShouldTravel);

			int gotnull = 0;
			if (meet == NULL)	gotnull = 1;

			Assert::AreEqual(1, gotnull, L"Should Return NULL", 1, 2);
			meet = meetingPoint(NULL,head, &numberOfCitiesMayaShouldTravel);
			
			gotnull = 0;
			if (meet == NULL) gotnull = 1;
			Assert::AreEqual(1, gotnull, L"Should Return NULL", 1, 2);
		};

		[TestMethod, Timeout(500)]
		void MeetingPoint_Test07()
		{
			char cities1[][20] = { "A", "B", "A", "B", "A", "B", "A", "B" };
			char cities2[][20] = { "Z", "A", "B", "A", "A", "B" };
			CityNode *deepikaStartCity = createPath(cities1, 8);
			CityNode *mayaStartCity = createPath(cities2, 6);
			int numberOfCitiesMayaShouldTravel = 0;
			CityNode *meet = meetingPoint(deepikaStartCity, mayaStartCity, &numberOfCitiesMayaShouldTravel);

			int gotnull = 0;
			if (meet == NULL){
				gotnull = 1;
			}

			Assert::AreEqual(0, gotnull, L"Should Not Return NULL", 1, 2);
			Assert::AreEqual(0, strcmp(meet->city, "A"), L"Meeting City Comparision ", 1, 2);
			Assert::AreEqual(4, numberOfCitiesMayaShouldTravel, L"NumberOfCitiesMayaShouldTravel", 1, 2);
		};

		[TestMethod, Timeout(500)]
		void MeetingPoint_Test08()
		{
			char cities1[][20] = {"B", "A", "B" };
			char cities2[][20] = {"B", "A", "B" };
			CityNode *deepikaStartCity = createPath(cities1,3);
			CityNode *mayaStartCity = createPath(cities2, 3);
			int numberOfCitiesMayaShouldTravel = 0;
			CityNode *meet = meetingPoint(deepikaStartCity, mayaStartCity, &numberOfCitiesMayaShouldTravel);

			int gotnull = 0;
			if (meet == NULL){
				gotnull = 1;
			}

			Assert::AreEqual(0, gotnull, L"Should Not Return NULL", 1, 2);
			Assert::AreEqual(0, strcmp(meet->city, "B"), L"Meeting City Comparision ", 1, 2);
			Assert::AreEqual(0, numberOfCitiesMayaShouldTravel, L"NumberOfCitiesMayaShouldTravel", 1, 2);
		};

		[TestMethod, Timeout(500)]
		void MeetingPoint_Test09_NullCheck()
		{
			char cities1[][20] = { "B", "A", "B" };
			char cities2[][20] = { "B", "A", "Z" };
			CityNode *deepikaStartCity = createPath(cities1, 3);
			CityNode *mayaStartCity = createPath(cities2, 3);
			int numberOfCitiesMayaShouldTravel = 0;
			CityNode *meet = meetingPoint(deepikaStartCity, mayaStartCity, &numberOfCitiesMayaShouldTravel);

			int gotnull = 0;
			if (meet == NULL){
				gotnull = 1;
			}

			Assert::AreEqual(1, gotnull, L"Should Return NULL", 1, 2);
		};

		[TestMethod, Timeout(500)]
		void MeetingPoint_Test10()
		{
			char cities1[][20] = { "B", "A", "Z" ,"C","A","Z"};
			char cities2[][20] = { "B", "A", "Z" };
			CityNode *deepikaStartCity = createPath(cities1, 6);
			CityNode *mayaStartCity = createPath(cities2, 3);
			int numberOfCitiesMayaShouldTravel = 0;
			CityNode *meet = meetingPoint(deepikaStartCity, mayaStartCity, &numberOfCitiesMayaShouldTravel);

			int gotnull = 0;
			if (meet == NULL){
				gotnull = 1;
			}


			Assert::AreEqual(0, gotnull, L"Should Not Return NULL", 1, 2);
			Assert::AreEqual(0, strcmp(meet->city, "A"), L"Meeting City Comparision ", 1, 2);
			Assert::AreEqual(1, numberOfCitiesMayaShouldTravel, L"NumberOfCitiesMayaShouldTravel", 1, 2);
		};

		[TestMethod, Timeout(500)]
		void MeetingPoint_Test11()
		{
			char cities1[][20] = { "C", "B", "Z" };
			char cities2[][20] = { "Z", "A", "Z" };
			CityNode *deepikaStartCity = createPath(cities1, 3);
			CityNode *mayaStartCity = createPath(cities2, 3);
			int numberOfCitiesMayaShouldTravel = 0;
			CityNode *meet = meetingPoint(deepikaStartCity, mayaStartCity, &numberOfCitiesMayaShouldTravel);

			int gotnull = 0;
			if (meet == NULL){
				gotnull = 1;
			}


			Assert::AreEqual(0, gotnull, L"Should Not Return NULL", 1, 2);
			Assert::AreEqual(0, strcmp(meet->city, "Z"), L"Meeting City Comparision ", 1, 2);
			Assert::AreEqual(2, numberOfCitiesMayaShouldTravel, L"NumberOfCitiesMayaShouldTravel", 1, 2);
		};

		[TestMethod, Timeout(500)]
		void MeetingPoint_Test12()
		{
			char cities1[][20] = { "A", "A", "A","A","A","A","A","A" };
			char cities2[][20] = { "A", "A", "A" };
			CityNode *deepikaStartCity = createPath(cities1, 8);
			CityNode *mayaStartCity = createPath(cities2, 3);
			int numberOfCitiesMayaShouldTravel = 0;
			CityNode *meet = meetingPoint(deepikaStartCity, mayaStartCity, &numberOfCitiesMayaShouldTravel);

			int gotnull = 0;
			if (meet == NULL){
				gotnull = 1;
			}


			Assert::AreEqual(0, gotnull, L"Should Not Return NULL", 1, 2);
			Assert::AreEqual(0, strcmp(meet->city, "A"), L"Meeting City Comparision ", 1, 2);
			Assert::AreEqual(0, numberOfCitiesMayaShouldTravel, L"NumberOfCitiesMayaShouldTravel", 1, 2);
		};

		[TestMethod, Timeout(500)]
		void MeetingPoint_Test13()
		{
			char cities1[][20] = { "A", "A", "A", "A", "A", "A", "B", "A" };
			char cities2[][20] = { "B","A", "A", "A" };
			CityNode *deepikaStartCity = createPath(cities1, 8);
			CityNode *mayaStartCity = createPath(cities2, 4);
			int numberOfCitiesMayaShouldTravel = 0;
			CityNode *meet = meetingPoint(deepikaStartCity, mayaStartCity, &numberOfCitiesMayaShouldTravel);

			int gotnull = 0;
			if (meet == NULL){
				gotnull = 1;
			}


			Assert::AreEqual(0, gotnull, L"Should Not Return NULL", 1, 2);
			Assert::AreEqual(0, strcmp(meet->city, "A"), L"Meeting City Comparision ", 1, 2);
			Assert::AreEqual(3, numberOfCitiesMayaShouldTravel, L"NumberOfCitiesMayaShouldTravel", 1, 2);
		};


		[TestMethod, Timeout(500)]
		void MeetingPoint_Test14()
		{
			char cities1[][20] = { "A", "B", "C", "D", "A", "B", "C", "D", "A", "B", "C", "D", "A", "B", "C", "D" };
			char cities2[][20] = { "B", "C", "D" ,"A", "B", "C", "D" };
			CityNode *deepikaStartCity = createPath(cities1, sizeof(cities1) / sizeof(cities1[0]));
			CityNode *mayaStartCity = createPath(cities2, sizeof(cities2) / sizeof(cities2[0]));
			int numberOfCitiesMayaShouldTravel = 0;
			CityNode *meet = meetingPoint(deepikaStartCity, mayaStartCity, &numberOfCitiesMayaShouldTravel);

			int gotnull = 0;
			if (meet == NULL){
				gotnull = 1;
			}


			Assert::AreEqual(0, gotnull, L"Should Not Return NULL", 1, 2);
			Assert::AreEqual(0, strcmp(meet->city, "B"), L"Meeting City Comparision ", 1, 2);
			Assert::AreEqual(0, numberOfCitiesMayaShouldTravel, L"NumberOfCitiesMayaShouldTravel", 1, 2);
		};

	

		[TestMethod, Timeout(500)]
		void MeetingPoint_Test15()
		{
			char cities1[][20] = { "B", "A", "BCB","A","B" };
			char cities2[][20] = { "A","BCB" };
			CityNode *deepikaStartCity = createPath(cities1, sizeof(cities1) / sizeof(cities1[0]));
			CityNode *mayaStartCity = createPath(cities2, sizeof(cities2) / sizeof(cities2[0]));
			int numberOfCitiesMayaShouldTravel = 0;
			CityNode *meet = meetingPoint(deepikaStartCity, mayaStartCity, &numberOfCitiesMayaShouldTravel);

			int gotnull = 0;
			if (meet == NULL){
				gotnull = 1;
			}


			Assert::AreEqual(1, gotnull, L"Should Not Return NULL", 1, 2);
		};
	};

}