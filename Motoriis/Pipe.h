#pragma once
#include "Construct.h"
#include <iostream>

class Pipe : public Construct
{
public:
	Pipe();
	~Pipe();
	Pipe(sf::Vector2f position);
	sf::ConvexShape draw();
	void calculatePointPosition();
	void transferItem();

private:
	int pointCount;
};

