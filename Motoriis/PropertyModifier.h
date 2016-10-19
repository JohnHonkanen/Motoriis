#include <string>
#pragma once
using namespace std;

class PropertyModifier
{
public:
	PropertyModifier(int uid, string identifier, string name, string description, float multiplier, bool additive);
	~PropertyModifier();
	int getUID();
	float getMultiplier();
	bool isAdditive() { return this->additive; };

	static PropertyModifier convertToModifier(string modifierString);
private:
	int uid;
	string identifier;
	string name;
	string description;
	float multiplier;
	bool additive;
};

