#include "BaseInput.h"



BaseInput::BaseInput()
{
}


BaseInput::~BaseInput()
{
}

BaseInput::BaseInput(sf::Vector2f position)
{
	this->position = position;
	this->acceptItems = true;
}

sf::ConvexShape BaseInput::draw()
{
	return sf::ConvexShape();
}

void BaseInput::calculatePointPosition()
{
}

void BaseInput::transferItem()
{
	this->main->handleBaseInputs();
}
