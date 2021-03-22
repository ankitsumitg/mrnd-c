#include "stdafx.h"
#include <stdlib.h>
#include "../src/EncodeDecode.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class EncodeDecodeSpec
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



		void compareStrings_ED(char *expected, char * actual) {
			int i = 0;
			while (expected[i] != '\0') {
				Assert::AreEqual(expected[i], actual[i], L"EncodeDecode expected and actual string mismatch, copy test case into main and check the output", 1, 2);
				i++;
			}
			if (actual[i] != '\0') {
				Assert::Fail("Output string not ended with slash 0");
			}
		}

		[TestMethod, Timeout(1000)]
		void EncodeDecode_Sample1()
		{
			//Test encoding
			char *message = "brook";
			char *expectedEncoded = "orobk";
			char *actual = encode(message);
			compareStrings_ED(expectedEncoded, actual);
		}

		[TestMethod, Timeout(1000)]
		void EncodeDecode_Sample2()
		{
			//Test decoding
			char *message = "ecabdf";
			char *expectedDecoded = "abcdef";
			char *actual = encode(message);
			compareStrings_ED(expectedDecoded, actual);
		}


		//Real - 12 , Null , empty etc

		[TestMethod, Timeout(1000)]
		void EncodeDecode_Real1()
		{
			//Test encoding
			char *expectedEncoded = "";
			char *actual = encode(NULL);
			compareStrings_ED(expectedEncoded, actual);

		}


		[TestMethod, Timeout(1000)]
		void EncodeDecode_Real2()
		{
			//Test encoding
			char *expectedEncoded = "";
			char *actual = encode("");
			compareStrings_ED(expectedEncoded, actual);
			char *actual2 = decode("");
			compareStrings_ED(expectedEncoded, actual2);

			char *actual3 = decode(NULL);
			compareStrings_ED(expectedEncoded, actual3);
		}



		[TestMethod, Timeout(1000)]
		void EncodeDecode_Real3()
		{
			//Test encoding
			char *message = "iwillbecomeapirateking";
			char *expectedEncoded = "eampoicreabtlelkiiwnig";
			char *actual = encode(message);
			compareStrings_ED(expectedEncoded, actual);
		}

		[TestMethod, Timeout(1000)]
		void EncodeDecode_Real4()
		{
			//Test encoding
			char *message = "iwillbecomeapirateking";
			char *expectedEncoded = "eampoicreabtlelkiiwnig";
			char *actual = encode(message);
			compareStrings_ED(expectedEncoded, actual);
		}
		[TestMethod, Timeout(1000)]
		void EncodeDecode_Real5()
		{
			//Test encoding
			char *message = "iwillbecomeapirateking";
			char *expectedEncoded = "eampoicreabtlelkiiwnig";
			char *actual = encode(message);
			compareStrings_ED(expectedEncoded, actual);
		}

		[TestMethod, Timeout(1000)]
		void EncodeDecode_Real6()
		{
			//Test encoding
			char *message = "roronoazoro";
			char *expectedEncoded = "onaozroorro";
			char *actual = encode(message);
			compareStrings_ED(expectedEncoded, actual);
		}

		[TestMethod, Timeout(1000)]
		void EncodeDecode_Real7()
		{
			//Test encoding
			char *message = "roronoazoro";
			char *expectedEncoded = "onaozroorro";
			char *actual = encode(message);
			compareStrings_ED(expectedEncoded, actual);
		}


		[TestMethod, Timeout(1000)]
		void EncodeDecode_Real10()
		{
			//Test decoding
			char *message = "iwillbecomeapirateking";
			char *expectedEncoded = "eampoicreabtlelkiiwnig";
			char *actual = decode(expectedEncoded);
			compareStrings_ED(message, actual);
		}

		[TestMethod, Timeout(1000)]
		void EncodeDecode_Real11()
		{
			char *message = "iwillbecomeapirateking";
			char *expectedEncoded = "eampoicreabtlelkiiwnig";
			char *actual = decode(expectedEncoded);
			compareStrings_ED(message, actual);
		}

		[TestMethod, Timeout(1000)]
		void EncodeDecode_Real12()
		{
			//Test decoding
			char *message = "roronoazoro";
			char *expectedEncoded = "onaozroorro";
			char *actual = decode(expectedEncoded);
			compareStrings_ED(message, actual);
		}

		[TestMethod, Timeout(1000)]
		void EncodeDecode_Real13()
		{
			//Test decoding
			char *message = "roronoazoro";
			char *expectedEncoded = "onaozroorro";
			char *actual = decode(expectedEncoded);
			compareStrings_ED(message, actual);
		}
		[TestMethod, Timeout(1000)]
		void EncodeDecode_Real14()
		{
			char *message = "iwillbecomeapirateking";
			char *expectedEncoded = "eampoicreabtlelkiiwnig";
			char *actual = decode(expectedEncoded);
			compareStrings_ED(message, actual);
		}

		[TestMethod, Timeout(1000)]
		void EncodeDecode_Real15()
		{
			//Test decoding
			char *message = "roronoazoro";
			char *expectedEncoded = "onaozroorro";
			char *actual = decode(expectedEncoded);
			compareStrings_ED(message, actual);
		}
	};
}
