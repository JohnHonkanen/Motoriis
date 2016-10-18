#include <string>
#include <vector>
#include "Property.h"
#include "LogisticSystem.h"
#pragma once
using namespace std;
class Building
{
public:
	Building();
	Building(int uid);
	~Building();
	static Building convertToBuilding(string buildingString);
	void addProperty(Property prop);
	float getPropertyValue(string name);

	void updateLogistics();

	LogisticSystem logistics;
private:
	int uid;
	string identifier;
	string name;
	string type;
	vector<Property> properties;
};

