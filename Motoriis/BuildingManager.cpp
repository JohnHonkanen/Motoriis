#include "BuildingManager.h"

BuildingManager::BuildingManager()
{
}

BuildingManager::~BuildingManager()
{
}

/*
	Finds a Property in the property list
	@param uid Property ID
	@return property
*/
Property BuildingManager::findProperty(int uid) {
	vector<Property>::iterator it = properties.begin();
	int i = 0;
	bool found = false;
	while (!found) {
		if (this->properties.at(i).getUid() == uid) {
			return this->properties.at(i);
		}
		i++;
		it++;
		if (it > this->properties.end())
			found = true;
	}
	return Property();
}
/*
	Finds a Modifier in the modifier list
	@param uid Modifier ID
	@return PropertyModifier
*/
PropertyModifier BuildingManager::findMod(int uid) {
	vector<PropertyModifier>::iterator it = modifiers.begin();
	int i = 0;
	bool found = false;
	while (!found) {
		if (this->modifiers.at(i).getUid() == uid) {
			return this->modifiers.at(i);
		}
		i++;
		it++;
		if (it > this->modifiers.end())
			found = true;
	}
	return PropertyModifier();
}
/*
Finds a Building in the building list
@param uid ID
@return Building
*/
Building BuildingManager::findBuilding(int uid) {
	vector<Building>::iterator it = buildings.begin();
	int i = 0;
	bool found = false;
	while (!found) {
		if (this->buildings.at(i).getUid() == uid) {
			return this->buildings.at(i);
		}
		i++;
		it++;
		if (it > this->buildings.end())
			found = true;
	}
	return Building();
}
/*
Converts a CSV string into a building object
@param buildingString	CSV buidling string
*/
Building BuildingManager::convertToBuilding(string buildingString) {
	string prop[9];
	stringstream ss(buildingString);
	string token;
	int i = 0;
	while (getline(ss, token, ',')) {
		prop[i] = token;
		i++;
	}
	vector<Property> props;
	vector<PropertyModifier> mods;
	vector<int> input;
	vector<int> output;
	int colorText[3];
	stringstream ps(prop[4]);
	stringstream ms(prop[5]);
	stringstream is(prop[6]);
	stringstream os(prop[7]);
	stringstream cs(prop[8]);
	while (getline(ps, token, '.')) {
		Property p = findProperty(stoi(token));
		props.push_back(p);
	}
	while (getline(ms, token, '.')) {
		PropertyModifier m = findMod(stoi(token));
		mods.push_back(m);
	}
	while (getline(is, token, '.')) {
		input.push_back(stoi(token));
	}

	while (getline(os, token, '.')) {
		output.push_back(stoi(token));
	}
	i = 0;
	while (getline(cs, token, '.')) {
		colorText[i] = stoi(token);
		i++;
	}
	return Building(stoi(prop[0]), prop[1], prop[2], stoi(prop[3]), props, mods, input, output, sf::Color(colorText[0], colorText[1], colorText[2], 255));
}
/*
	Populate Modifier List
	@param list CSV mod list
*/
void BuildingManager::populateModifiers(vector<string> list) {
	vector<string>::iterator it;
	int i = 0;
	for (it = list.begin(); it < list.end(); it++, i++) {
		this->modifiers.push_back(PropertyModifier::convertToModifier(list.at(i)));
	}
}
/*
Populate Property List
@param list CSV mod list
*/
void BuildingManager::populateProperties(vector<string> list) {
	vector<string>::iterator it;
	int i = 0;
	for (it = list.begin(); it < list.end(); it++, i++) {
		this->properties.push_back(Property::convertToProperty(list.at(i)));
	}
}
/*
Populate our building list with a CSV buildingList
@param buildingList List of CSV string
*/

void BuildingManager::populateBuildings(vector<string> buildingList) {
	vector<string>::iterator it;
	int i = 0;
	for (it = buildingList.begin(); it < buildingList.end(); it++, i++) {
		this->buildings.push_back(BuildingManager::convertToBuilding(buildingList.at(i)));
	}
}

/*
Renders the Building GUI
*/
void BuildingManager::drawGUI(sf::RenderWindow *window, sf::View view) {

	buttonSize = view.getSize().x / 30;
	yOffset = view.getSize().y * 0.01;
	vector<Building>::iterator it;
	int i = 0;

	for (it = this->buildings.begin(); it < this->buildings.end(); it++, i++) {
		sf::RectangleShape button(sf::Vector2f(buttonSize, buttonSize));
		button.setPosition(view.getCenter().x - view.getSize().x / 2 + buttonSize + ((buttonSize*i)*1.5), view.getCenter().y + view.getSize().y / 2 - buttonSize - yOffset);
		button.setOutlineThickness(0.1);
		button.setFillColor(this->buildings.at(i).getColor());
		window->draw(button);
	}
}

Building BuildingManager::mouseInButton(sf::Vector2f mousepos, sf::View view) {
	buttonSize = view.getSize().x / 30;
	yOffset = view.getSize().y * 0.01;
	vector<Building>::iterator it;
	int i = 0;

	for (it = this->buildings.begin(); it < this->buildings.end(); it++, i++) {
		sf::RectangleShape button(sf::Vector2f(buttonSize, buttonSize));
		button.setPosition(view.getCenter().x - view.getSize().x / 2 + buttonSize + ((buttonSize*i)*1.5), view.getCenter().y + view.getSize().y / 2 - buttonSize - yOffset);
		if (mousepos.x > button.getPosition().x && mousepos.x < button.getPosition().x + button.getSize().x) {
			if (mousepos.y > button.getPosition().y && mousepos.y < button.getPosition().y + button.getSize().y) {
				return this->buildings.at(i);
			}
		}
	}
	return Building();
}
