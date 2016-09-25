#include "CsvParser.h"

CsvParser::CsvParser()
{
}

CsvParser::~CsvParser()
{

}

void CsvParser::open(string file) {
	this->file.open(file);
}

vector<string> CsvParser::parseFile(){
	string line_;
	vector<string> fileContents;
	while (getline(this->file, line_)) {
		fileContents.insert(fileContents.end(),line_);
	}
	return fileContents;
}

bool CsvParser::isOpen() {
	return(this->file.is_open());
}
void CsvParser::close() {
	this->file.close();
}