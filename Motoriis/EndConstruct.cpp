#include "EndConstruct.h"



EndConstruct::EndConstruct()
{
}

EndConstruct::EndConstruct(sf::Vector2f position)
{
	this->position = position;
	this->texture.loadFromFile("Texture/shipping.jpg");
}


EndConstruct::~EndConstruct()
{
}

sf::ConvexShape EndConstruct::draw()
{
	return sf::ConvexShape();
}

void EndConstruct::calculatePointPosition()
{
	//DO Nothing
}

void EndConstruct::transferItem()
{
	//Do Nothing
}

void EndConstruct::render(sf::RenderWindow * window, sf::View view)
{
	sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(10,10));
	shape.setPosition(this->position);
	shape.setTexture(&this->texture, false);
	window->draw(shape);
}

bool EndConstruct::addItem(Item * item)
{
	return true;
}
