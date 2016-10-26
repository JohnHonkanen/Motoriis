#include "Building.h"

Building::Building(){}
Building::Building(int uid)
{
	this->uid = uid;
	this->logistics = LogisticSystem(uid, 0, 0);
}

Building::Building(int uid, string identifier, string name, int type,
	vector<Property> props, vector<PropertyModifier> mods,
	vector<int> input, vector<int> output, sf::Color color) {
	this->uid = uid;
	this->identifier = identifier;
	this->name = name;
	this->type = type;
	this->properties = props;
	this->color = color;

	vector<PropertyModifier>::iterator it;
	int i = 0;
	for (it = mods.begin(); it < mods.end(); it++, i++) {
		this->attachModifierToProperty(mods.at(i).getAttached(), mods.at(i));
	}

	this->input = input;
	this->output = output;
}
Building::~Building()
{
}

/*
	Adds a property to the building property list
	@param prop	Property to add
*/
void Building::addProperty(Property prop) {
	properties.push_back(prop);
}
/*
	Gets the property value of the property
	@param identifier	Identifier string of property we want to find
*/
float Building::getPropertyValue(string identifier) {
	vector<Property>::iterator it = properties.begin();
	int i = 0;
	bool found = false;
	int value = 0;
	while (!found) {
		if (properties.at(i).getIdentifier() == identifier) {
			found = true;
			value =  properties.at(i).getFinalValue();
		}
		if (it > properties.end())
		{
			found = true;
			value = -1;
		}
		it++;
		i++;
	}

	return value;
}
/*
	Attaches the modifier to the Building property
*/
void Building::attachModifierToProperty(int id, PropertyModifier mod) {
	vector<Property>::iterator it = this->properties.begin();
	int i = 0;
	bool found = false;
	while (!found) {
		if (this->properties.at(i).getUid() == id) {
			found = true;
			this->properties.at(i).addModifier(mod);
		}
		it++;
		i++;
		if (it > this->properties.end())
			found = true;
	}
}
/*
	Updates Logistic system to reflect building space based on 2 properties
*/
void Building::updateLogistics() {
	vector<Property>::iterator it = properties.begin();
	int i = 0;
	int found = 0;
	while (found != 2) {
		if (this->properties.at(i).getIdentifier() == "maxstorage") {
			this->logistics.setMaxStorage(this->properties.at(i).getFinalValue());
			found++;
		}

		if (this->properties.at(i).getIdentifier() == "maxitem") {
			this->logistics.setMaxItems(this->properties.at(i).getFinalValue());
			found++;
		}
	}
}
