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
private:
	vector<PropertyModifier> modifiers;
	vector<Property> properties;
	vector<Building> buildings;

};

