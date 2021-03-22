#include "stdafx.h"
#include "../src/Consonants_Vowels.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class Consonants_VowelsSpec
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
		void OneLetter_ConsonantsVowels()
		{
			char str[] = "a";
			int consonants;
			int vowels;
			count_vowels_and_consonants(str, &consonants, &vowels);

			Assert::AreEqual(consonants, 0, L"Consonants should be 0", 1,2);

			Assert::AreEqual(vowels, 1, L"Vowels should be 1 for a", 1, 2);
		}

		[TestMethod, Timeout(1000)] 
		void EmptyString_ConsonantsVowels()
		{
			char str[] = "";
			int consonants;
			int vowels;
			count_vowels_and_consonants(str, &consonants, &vowels);

			Assert::AreEqual(consonants, 0, L"Consonants should be 0", 1, 2);

			Assert::AreEqual(vowels, 0, L"Vowels should be 0 for ", 1, 2);
		}
		[TestMethod, Timeout(1000)] 
		void ComplexString_ConsonantsVowels()
		{
			char str[] = "a .?2343 BCDE mu";
			int consonants;
			int vowels;
			count_vowels_and_consonants(str, &consonants, &vowels);

			Assert::AreEqual(consonants, 4, L"Consonants should be 4", 1, 2);

			Assert::AreEqual(vowels, 3, L"Vowels should be 3 for a .? 23 BCDE mu ", 1, 2);
		}
		[TestMethod, Timeout(1000)] 
		void ComplexCapitalLong_ConsonantsVowels()
		{
			char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			int consonants;
			int vowels;
			count_vowels_and_consonants(str, &consonants, &vowels);

			Assert::AreEqual(consonants, 21, L"Consonants should be 21 for A-Z", 1, 2);

			Assert::AreEqual(vowels, 5, L"Vowels should be 5 for A-Z", 1, 2);
		}
		[TestMethod, Timeout(1000)] 
		void NULLstring_ConsonantsVowels()
		{
			char *str = NULL;
			int consonants;
			int vowels;
			count_vowels_and_consonants(str, &consonants, &vowels);

			Assert::AreEqual(consonants, 0, L"Consonants should be 0 for NULL", 1, 2);

			Assert::AreEqual(vowels, 0, L"Vowels should be 0 for NULL", 1, 2);
		}


	};
}
