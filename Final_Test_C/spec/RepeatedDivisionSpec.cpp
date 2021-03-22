#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "../src/RepeatedDivision.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class RepeatedDivisionSpec
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
		void RepeatedDivision_Samples()
		{
			int res;
			res = RepeatedDivision(6);
			Assert::AreEqual(res, 4, L"Wrong Answer", 1, 2);

			res = RepeatedDivision(10);
			Assert::AreEqual(res,8, L"Wrong Answer", 1, 2);
		};
		
		[TestMethod, Timeout(1000)]
		void RepeatedDivision_Test01()
		{
			int res;
			res = RepeatedDivision(32);
			Assert::AreEqual(res, 32, L"Wrong Answer", 1, 2);
			res = RepeatedDivision(33);
			Assert::AreEqual(res, 32, L"Wrong Answer", 1, 2);
			res = RepeatedDivision(35);
			Assert::AreEqual(res, 32, L"Wrong Answer", 1, 2);
			res = RepeatedDivision(40);
			Assert::AreEqual(res, 32, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void RepeatedDivision_Test02()
		{
			int res;
			res = RepeatedDivision(128);
			Assert::AreEqual(res, 128, L"Wrong Answer", 1, 2);
			res = RepeatedDivision(145);
			Assert::AreEqual(res, 128, L"Wrong Answer", 1, 2);
			res = RepeatedDivision(174);
			Assert::AreEqual(res, 128, L"Wrong Answer", 1, 2);
			res = RepeatedDivision(169);
			Assert::AreEqual(res, 128, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void RepeatedDivision_Test03()
		{
			int res;
			res = RepeatedDivision(1);
			Assert::AreEqual(res, 1, L"Wrong Answer", 1, 2);
			res = RepeatedDivision(1);
			Assert::AreEqual(res, 1, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void RepeatedDivision_Test04()
		{
			int res;
			res = RepeatedDivision(259);
			Assert::AreEqual(res, 256, L"Wrong Answer", 1, 2);
			res = RepeatedDivision(255);
			Assert::AreEqual(res, 128, L"Wrong Answer", 1, 2);
			res = RepeatedDivision(222);
			Assert::AreEqual(res, 128, L"Wrong Answer", 1, 2);
			res = RepeatedDivision(225);
			Assert::AreEqual(res, 128, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void RepeatedDivision_Test05()
		{
			int res;
			res = RepeatedDivision(7777);
			Assert::AreEqual(res, 4096, L"Wrong Answer", 1, 2);
			res = RepeatedDivision(7778);
			Assert::AreEqual(res, 4096, L"Wrong Answer", 1, 2);
			res = RepeatedDivision(7779);
			Assert::AreEqual(res, 4096, L"Wrong Answer", 1, 2);
			res = RepeatedDivision(7780);
			Assert::AreEqual(res, 4096, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void RepeatedDivision_Test06()
		{
			int res;
			res = RepeatedDivision(8000);
			Assert::AreEqual(res, 4096, L"Wrong Answer", 1, 2);
			res = RepeatedDivision(8100);
			Assert::AreEqual(res, 4096, L"Wrong Answer", 1, 2);
			res = RepeatedDivision(8200);
			Assert::AreEqual(res, 8192, L"Wrong Answer", 1, 2);
			res = RepeatedDivision(8300);
			Assert::AreEqual(res, 8192, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void RepeatedDivision_Test07()
		{
			int res;
			res = RepeatedDivision(1147483642);
			Assert::AreEqual(res, 1073741824, L"Wrong Answer", 1, 2);

			res = RepeatedDivision(1147483647);
			Assert::AreEqual(res, 1073741824, L"Wrong Answer", 1, 2);

			res = RepeatedDivision(1147423648);
			Assert::AreEqual(res, 1073741824, L"Wrong Answer", 1, 2);
			res = RepeatedDivision(1147483648);
			Assert::AreEqual(res, 1073741824, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void RepeatedDivision_Test08()
		{
			int res;
			res = RepeatedDivision(1073741824);
			Assert::AreEqual(res, 1073741824, L"Wrong Answer", 1, 2);
			res = RepeatedDivision(1073741850);
			Assert::AreEqual(res, 1073741824, L"Wrong Answer", 1, 2);
			res = RepeatedDivision(1073741832);
			Assert::AreEqual(res, 1073741824, L"Wrong Answer", 1, 2);
			res = RepeatedDivision(1073791824);
			Assert::AreEqual(res, 1073741824, L"Wrong Answer", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void RepeatedDivision_Test09()
		{
			int res;
			res = RepeatedDivision(2147483642);
			Assert::AreEqual(res, 1073741824, L"Wrong Answer", 1, 2);

			res = RepeatedDivision(2147483647);
			Assert::AreEqual(res, 1073741824, L"Wrong Answer", 1, 2);

			res = RepeatedDivision(2147423648);
			Assert::AreEqual(res, 1073741824, L"Wrong Answer", 1, 2);
			res = RepeatedDivision(1147483648);
			Assert::AreEqual(res, 1073741824, L"Wrong Answer", 1, 2);
		};
	};

}