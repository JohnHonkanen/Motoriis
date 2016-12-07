#include "Storage.h"
#include "ItemManager.h"
#include "SFML\Graphics.hpp"
#pragma once

class Construct
{
public:
	Construct();
	~Construct();
	virtual sf::ConvexShape draw() = 0;
	virtual void calculatePointPosition() = 0;
	virtual void transferItem() = 0;
	virtual int remove();
	virtual void render(sf::RenderWindow *window, sf::View view);
	virtual void handleBaseInputs();
	sf::Vector2f getPosition() { return this->position; };
	bool accepts();
	virtual bool addItem(Item *item);
	void setFlow(int flow); //0.No flow 1.top 2.right 3.bottom 4.left
	int getFlow();
	void redirectFlow();
	void removeConnections();
	void setColor(sf::Color color);
	virtual bool accepting();
	int getType();
	void setType(int type);

	Storage storage;
	Construct* top;
	Construct* bottom;
	Construct* left;
	Construct* right;
	Construct* mainOutput = this;

protected:
	sf::Vector2f position;
	vector<sf::Vector2f> points;
	int pointCount;
	int flow = 0;
	float scale;
	sf::Color color;
	bool acceptItems = true;
	int type = 0; //OUTPUT OR INPUT 
};

