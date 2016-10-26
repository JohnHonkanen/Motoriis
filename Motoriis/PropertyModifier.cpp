#include "PropertyModifier.h"


PropertyModifier::PropertyModifier(){}
PropertyModifier::PropertyModifier(int uid, string identifier, string name, string description, float multiplier, bool additive, int attachedTo)
{
	this->uid = uid;
	this->identifier = identifier;
	this->name = name;
	this->description = description;
	this->multiplier = multiplier;
	this->additive = additive;
	this->attachedTo = attachedTo;
}


PropertyModifier::~PropertyModifier()
{
}

int PropertyModifier::getUID() {
	return this->uid;
}

float PropertyModifier::getMultiplier() {
	return this->multiplier;
}

PropertyModifier PropertyModifier::convertToModifier(string modifierString) {
	string prop[7];
	stringstream ss(modifierString);
	string token;
	int i = 0;
	while (getline(ss, token, ',')) {
		prop[i] = token;
		i++;
	}
	return PropertyModifier(stoi(prop[0]), prop[1], prop[2], prop[3], stof(prop[4]), stoi(prop[5]), stoi(prop[6]));
}