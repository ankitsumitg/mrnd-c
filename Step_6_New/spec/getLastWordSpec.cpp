#include "stdafx.h"
#include "../src/getLastWord.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class getLastWordSpec
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
		void TC1_LastWord()
		{
			char sentences[][100] = { "abc is a word", "he he", "   ", "d ab   ", "  x", "asd324", "", "a" };
			char ans[][100] = { "word", "he", "", "ab", "x", "asd324", "", "a" };
			int sc = 8;
			int si = 0;
			for (si = 0; si < sc; si++){
				char *new_str = get_last_word(sentences[si]);
				int k = 0;
				for (k = 0; new_str[k] != '\0'; k++){
					Assert::AreEqual(new_str[k], ans[si][k], L"Error in NormalString", 1,2);
				}
			}

		}
	};
}
