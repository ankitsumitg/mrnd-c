#include "stdafx.h"
#include "../src/getSubstring.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class getSubstringSpec
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
		void TC1_SubString()
		{
			char str[] = "abcdefgh";
			int i = 0;
			int j = 2;
			int k;

			for (i = 0; i <= 1; i++){
				for (j = 3; j < 7; j++){
					char *new_str = get_sub_string(str, i, j);
					if (i <= j){
						for (k = i; k <= j; k++){
							Assert::AreEqual(new_str[k - i], str[k], L"Error in NormalString", 1,2);
						}
					}
					else{
						if (new_str != NULL) {
							Assert::AreEqual(1, 2, L"should be null for i > j", 1, 2);
						}
					}
				}
			}
		}

		[TestMethod, Timeout(1000)]
		void TC2_SubString()
		{
			char *str = NULL;
			char *new_str = get_sub_string(str, 0, 2); if (new_str != NULL) {
				Assert::AreEqual(1, 2, L"should be null for nullstring", 1, 2);
			}

		}

		[TestMethod, Timeout(1000)]
		void TC3_SubString()
		{
			char str[] = "abcdefgh.,812639";
			int i = 0;
			int j = 2;
			int k;

			for (i = 0; i <= 8; i++){
				for (j = 5; j < 12; j++){
					char *new_str = get_sub_string(str, i, j);
					if (i <= j){
						for (k = i; k <= j; k++){
							Assert::AreEqual(new_str[k - i], str[k], L"Error in NormalString", 1, 2);
						}
					}
					else{
						//Logger::WriteMessage("I > J ");
						if (new_str != NULL) {
							Assert::AreEqual(1,2, L"should be null for i > j", 1, 2);
						}
					}
				}
			}
		}
		
		[TestMethod, Timeout(1000)]
		void TC4_SubString()
		{
			char str[] = "a          jhas   AB";
			int i = 0;
			int j = 2;
			int k;

			for (i = 0; i <= 1; i++){
				for (j = 3; j < 7; j++){
					char *new_str = get_sub_string(str, i, j);
					if (i <= j){
						for (k = i; k <= j; k++){
							Assert::AreEqual(new_str[k - i], str[k], L"Error in NormalString", 1, 2);
						}
					}
					else{
						if (new_str != NULL) {
							Assert::AreEqual(1, 2, L"should be null for i > j", 1, 2);
						}
					}
				}
			}
		}

	};
}