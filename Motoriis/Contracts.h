#pragma once
#include "Item.h"
#include "Construct.h"
#include "EconomyManager.h"
#include "SFML\Graphics.hpp"
class Contracts
{
public:
	Contracts();
	~Contracts();
	virtual bool purchase() = 0;
	virtual bool fufill(Construct *construct, EconomyManager* manager) = 0;
	int getRating();
	Item getItem();
	int getCost();
	int getType();
	bool getActive();
	void setActive(bool active);
	bool isComplete();
protected:
	Item item;
	int cost;
	int type;
	int rating;
	bool active = false;
	bool complete = false;
	sf::Time time;
};

