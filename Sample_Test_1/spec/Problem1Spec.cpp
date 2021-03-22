
#include "stdafx.h";
#include <stdlib.h>;
#include "./../src/Problem1.cpp";

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class Problem1Spec
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
		[TestMethod, Timeout(1000)]
		void Sample1_P1()
		{
			int * ans=sumoftwo(NULL,0, 2);
			if (ans == NULL){

			}
			else{
				Assert::Fail("Failed if nums is Null");
			}
		};

		[TestMethod, Timeout(1000)]
		void Sample2_P1()
		{
			int a[5] = { 1, 2, 3, 4, 5 };
			int* ans = sumoftwo(a,0,-1);
			if(ans == NULL){

			}
			else{
				Assert::Fail("Failed if nums len is <1");
			}
		};
		[TestMethod, Timeout(1000)]
		void Sample3_P1()
		{
			int a[5] = { 15, 20, 13, 44, 5 };
			int len = 5;
			int i1 = 1;
			int i2 = 4;
			int target = 25;
			int* ans = sumoftwo(a,target,len);
			if (ans == NULL){
				Assert::Fail("Got Null ,Where as Answer Array Expected");
			}
			else{
				Assert::AreEqual(i1, ans[0], L"Failed Real 0 for NULL case in P1", 1, 2);
				Assert::AreEqual(i2, ans[1], L"Failed Real 0 for NULL case in P1", 1, 2);
			}
		};

		//Real Cases


	};
}

