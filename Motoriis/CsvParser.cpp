#include "CsvParser.h"

CsvParser::CsvParser()
{
}

CsvParser::~CsvParser()
{

}
/*
	Opens our file for access
*/
void CsvParser::open(string file) {
	this->file.open(file);
}
/*
	Read file and return a vector string/line
*/
vector<string> CsvParser::parseFile(){
	string line_;
	vector<string> fileContents;
	bool header = true;
	while (getline(this->file, line_)) {
		if (header) {
			header = false;
		} else{
			fileContents.insert(fileContents.end(), line_);
			cout << line_ << endl;
		}
	}
	return fileContents;
}
/*
	Checks if our file is open
*/
bool CsvParser::isOpen() {
	return this->file.is_open();
}
/*
	Close our File Access
*/
void CsvParser::close() {
	this->file.close();
}