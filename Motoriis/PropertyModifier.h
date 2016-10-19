#include <string>
#include <sstream>
#pragma once
using namespace std;

class PropertyModifier
{
public:
	PropertyModifier();
	PropertyModifier(int uid, string identifier, string name, string description, float multiplier, bool additive, int attachedTo);
	~PropertyModifier();
	int getUID();
	float getMultiplier();
	bool isAdditive() { return this->additive; };
	int getUid() { return this->uid; };
	int getAttached() { return this->attachedTo; };

	static PropertyModifier convertToModifier(string modifierString);
private:
	int uid;
	string identifier;
	string name;
	string description;
	float multiplier;
	bool additive;
	int attachedTo;
};

