#include "Property.h"



Property::Property(int uid, string identifer, string name, string description, float base)
{
	this->uid = uid;
	this->identifier = identifer;
	this->name = name;
	this->description = description;
	this->base = base;
}


Property::~Property()
{
}

void Property::addModifier(PropertyModifier modifier) {
	this->modifiers.push_back(modifier);
}

void Property::removeModifier(PropertyModifier modifier) {
	vector<PropertyModifier>::iterator it = this->modifiers.begin();
	int i = 0;
	bool exit = false;
	while (!exit) {
		if (i < this->modifiers.size()) {
			if (this->modifiers.at(i).getUID() == modifier.getUID()) {
				this->modifiers.erase(it);
				exit = true;
			}else{
				it++, i++;
			}
		}
		else {
			exit = true;
		}
	}
}

float Property::getFinalValue() {
	vector<PropertyModifier>::iterator it = this->modifiers.begin();
	int i = 0;
	float finalValue = this->base;
	float multiplicativeModifier = 1;
	vector<PropertyModifier> additive;
	vector<PropertyModifier> multiplicative;
	for (it = this->modifiers.begin(); it < this->modifiers.end(); it++, i++) {
		if (this->modifiers.at(i).isAdditive()) {
			finalValue += this->modifiers.at(i).getMultiplier();
		}else{
			multiplicativeModifier *= this->modifiers.at(i).getMultiplier();
		}
	}
	finalValue *= multiplicativeModifier;
	return finalValue;
}

string Property::getIdentifier() {
	return this->identifier;
}
