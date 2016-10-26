#include <string>
#include <vector>
#include "SFML\Graphics\Color.hpp"
#include "Property.h"
#include "LogisticSystem.h"
#pragma once
using namespace std;
class Building
{
public:
	Building();
	Building(int uid);
	Building(int uid, string identifier, string name, int type,
		vector<Property> props, vector<PropertyModifier> mods, 
		vector<int> input, vector<int> output, sf::Color color);
	~Building();
	void addProperty(Property prop);
	float getPropertyValue(string name);
	sf::Color getColor() { return this->color; };
	int getUid() { return this->uid; };
	int getType() { return this->type; };
	void attachModifierToProperty(int propertyId, PropertyModifier mod);

	void updateLogistics();

	LogisticSystem logistics;
private:
	int uid = 0;
	string identifier;
	string name;
	int type;
	vector<int> input;
	vector<int> output;
	vector<Property> properties;
	sf::Color color;
};

