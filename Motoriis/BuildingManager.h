#pragma once
#include "Building.h"
#include "Property.h"
#include "PropertyModifier.h"

#include <vector>

class BuildingManager
{
public:
	BuildingManager();
	~BuildingManager();
	void populateBuildings(vector<string> BuildingList);
	void populateProperties(vector<string> propertyList);
	void populateModifiers(vector<string> modifierList);

	Building convertToBuilding(string buildingString);
	Property findProperty(int uid);
	PropertyModifier findMod(int uid);
	Building findBuilding(int uid);

private:
	vector<PropertyModifier> modifiers;
	vector<Property> properties;
	vector<Building> buildings;

};

