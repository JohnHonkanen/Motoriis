#pragma once
#include "Building.h"
#include "Property.h"
#include "PropertyModifier.h"
#include <SFML/Graphics.hpp>
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
	void drawGUI(sf::RenderWindow *window, sf::View view);
	int mouseInButton(sf::Vector2f mousepos);

	bool plotting = false;
	bool construct = false;
	int isBuilding = 0;

private:
	vector<PropertyModifier> modifiers;
	vector<Property> properties;
	vector<Building> buildings;

	float buttonSize = 15.0;
	float yOffset = 5;
	sf::RectangleShape pipeButton;
	sf::RectangleShape storageButton;
};

