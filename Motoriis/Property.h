#include <string>
#include <vector>
#include "PropertyModifier.h"
#pragma once

using namespace std;

class Property
{
public:
	Property();
	Property(int uid, string identifer, string name, string description, float base);
	~Property();
	void addModifier(PropertyModifier modifier);
	void removeModifier(PropertyModifier modifier);
	float getFinalValue();
	string getIdentifier();
	int getUid() { return this->uid; };

	static Property convertToProperty(string propertyString);
private:
	int uid;
	string identifier;
	string name;
	string description;
	float base;
	vector<PropertyModifier> modifiers;
};

