#pragma once
#include "Construct.h"
class BaseInput :
	public Construct
{
public:
	BaseInput();
	~BaseInput();
	BaseInput(sf::Vector2f position);
	sf::ConvexShape draw();
	void calculatePointPosition();
	void transferItem();
	Construct* main;
};

