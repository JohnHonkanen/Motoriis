#include "ButtonObjects.h"



ButtonObjects::ButtonObjects()
{
}


ButtonObjects::~ButtonObjects()
{
}

bool ButtonObjects::intersects(sf::Vector2f position)
{
	if (position.x > this->rect.getPosition().x && position.x < this->rect.getPosition().x + this->rect.getSize().x)
		if (position.y > this->rect.getPosition().y && position.y < this->rect.getPosition().y + this->rect.getSize().y)
			return true;
	return false;
}
