#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Motoriis/CsvParser.h"
#include "../Motoriis/CsvParser.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(CsvParserTest)
	{
	public:
		TEST_METHOD(openFile)
		{
			CsvParser parser;
			string filename = "csv/ItemDatabase.csv";
			parser.open(filename);
			Assert::AreEqual(true, parser.isOpen());
			parser.close();
			Assert::AreEqual(false, parser.isOpen());
		}
		TEST_METHOD(readFile) {
			CsvParser parser;
			string filename = "csv/ItemDatabase.csv";
			vector<string> contents;
			parser.open(filename);
			contents = parser.parseFile();
			Assert::AreEqual((string) "1,Food 1,1,F0001,FF0011", contents.at(1));
			parser.close();
		}
	};
}