#include "Storage.h"
#include "SFML\Graphics.hpp"
#pragma once

class Construct
{
public:
	Construct();
	~Construct();
	virtual sf::ConvexShape draw() = 0;
	virtual void calculatePointPosition() = 0;
	sf::Vector2f getPosition() { return this->position; };
	void addItem(Item item);
	virtual void transferItem() = 0;
	void setFlow(int flow); //0.No flow 1.top 2.right 3.bottom 4.left
	int getFlow();
	void redirectFlow();
	void removeConnections();

	Storage storage;
	Construct* top;
	Construct* bottom;
	Construct* left;
	Construct* right;

protected:
	sf::Vector2f position;
	vector<sf::Vector2f> points;
	int pointCount;
	int flow = 0;
	float scale;
	sf::Color color;
};

