#pragma once
#include "Construct.h"
class OutputConstruct : public Construct
{
public:
	OutputConstruct();
	OutputConstruct(sf::Vector2f position);
	~OutputConstruct();
	sf::ConvexShape draw();
	void calculatePointPosition();
	void transferItem();
	int remove();
};

