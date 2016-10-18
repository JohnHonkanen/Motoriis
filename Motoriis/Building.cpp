#include "Building.h"

Building::Building(){}
Building::Building(int uid)
{
	this->uid = uid;
	this->logistics = LogisticSystem(uid, 0, 0);
}


Building::~Building()
{
}
/*
	Converts a CSV string into a building object
	@param buildingString	CSV buidling string
*/
Building Building::convertToBuilding(string buildingString) {
	string buildingProp[5];
	stringstream ss(buildingString);
	string token;
	int i = 0;
	while (getline(ss, token, ',')) {
		buildingProp[i] = token;
		i++;
	}
	return Building();
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
