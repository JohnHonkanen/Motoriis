#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class CsvParser
{
	public:
		CsvParser();
		~CsvParser();
		void open(string file);
		vector<string> parseFile();
		bool isOpen();
		void close();

	private:
		fstream file;
};
