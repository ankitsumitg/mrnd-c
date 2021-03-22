#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/isOlder.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(isOlderSpec)
	{
	public:

		TEST_METHOD(isOlderinvalid)
		{
			Assert::AreEqual(-1, isOlder("1000", "15-07-2000"), L"isOlder: invalid input case failed", LINE_INFO());
			Assert::AreEqual(-1, isOlder("15-07-2000", "000"), L"isOlder: invalid input case failed", LINE_INFO());
			Assert::AreEqual(-1, isOlder("15-0A-2000", "15-07-2000"), L"isOlder: invalid input case failed", LINE_INFO());
			Assert::AreEqual(-1, isOlder("15-13-2000", "15-07-2000"), L"isOlder: invalid input case failed", LINE_INFO());
			Assert::AreEqual(-1, isOlder("29-02-2001", "15-07-2000"), L"isOlder: invalid input case failed", LINE_INFO());
		}

		TEST_METHOD(isOlderequal)
		{
			Assert::AreEqual(0, isOlder("15-07-2000", "15-07-2000"), L"isOlder: equal age input case failed", LINE_INFO());
			Assert::AreEqual(0, isOlder("29-02-2000", "29-02-2000"), L"isOlder: equal age input case failed", LINE_INFO());
		}

		TEST_METHOD(isOlderelder)
		{
			Assert::AreEqual(1, isOlder("15-07-1992", "15-07-2000"), L"isOlder: Person one is elder", LINE_INFO());
			Assert::AreEqual(2, isOlder("29-02-2004", "29-02-2000"), L"isOlder: Person two is elder", LINE_INFO());
			Assert::AreEqual(1, isOlder("15-05-2000", "15-07-2000"), L"isOlder: Person one is elder", LINE_INFO());
			Assert::AreEqual(2, isOlder("29-06-2000", "29-02-2000"), L"isOlder: Person two is elder", LINE_INFO());
			Assert::AreEqual(1, isOlder("11-07-2000", "15-07-2000"), L"isOlder: Person one is elder", LINE_INFO());
			Assert::AreEqual(2, isOlder("29-02-2000", "27-02-2000"), L"isOlder: Person two is elder", LINE_INFO());
		}
	};
}