#include "stdafx.h"
#include "../src/getFrequencyofWord.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class getFrequencyofWordSpec
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
		void NormalStringFrequency_GFOW()
		{
			char sentences[][100] = { "abababa", "he he", "ab cd ab cd", "    ", "1234 aaaaaaa", "asd324", "yzqwer 23425", "a" };
			char words[][100] = { "ab", "he", "ab cd", " ", "aa", "asd324", "x", "a" };
			int counts[100] = { 3, 2, 2, 4, 6, 1, 0 };
			int sc = 7;
			int si = 0;
			for (si = 0; si < sc; si++){
				int temp_c = count_word_in_str_way_1(sentences[si], words[si]);
				Assert::AreEqual(temp_c, counts[si], L"Error in NormalStringLastword", 1,2);

			}

		}

	};
}
