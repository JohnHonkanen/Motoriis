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
	Building(int uid, string identifier, string name, int type,
		vector<Property> props, vector<PropertyModifier> mods, 
		vector<int> input, vector<int> output);
	~Building();
	void addProperty(Property prop);
	float getPropertyValue(string name);
	void attachModifierToProperty(int propertyId, PropertyModifier mod);

	void updateLogistics();

	LogisticSystem logistics;
private:
	int uid;
	string identifier;
	string name;
	int type;
	vector<int> input;
	vector<int> output;
	vector<Property> properties;
};

