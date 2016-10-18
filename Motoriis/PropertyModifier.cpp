#include "PropertyModifier.h"



PropertyModifier::PropertyModifier(int uid, string identifier, string name, string description, float multiplier, bool additive)
{
	this->uid = uid;
	this->identifier = identifier;
	this->name = name;
	this->description = description;
	this->multiplier = multiplier;
	this->additive = additive;
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