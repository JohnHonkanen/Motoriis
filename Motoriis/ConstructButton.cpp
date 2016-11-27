#include "ConstructButton.h"



ConstructButton::ConstructButton()
{
}
ConstructButton::ConstructButton(float xOffsetMultiplier)
{
	this->xOffsetMultiplier = xOffsetMultiplier;
}

ConstructButton::~ConstructButton()
{
}

void ConstructButton::update()
{
}

void ConstructButton::setConstruct(int constructID)
{
	this->constructId = constructID;
}

void ConstructButton::createRect(sf::View view)
{

	float buttonSize = 15.0f;
	float yOffset = view.getSize().y * 0.01f;
	sf::Vector2f position = sf::Vector2f(view.getCenter().x - (view.getSize().x / this->xOffsetMultiplier) + buttonSize + ((buttonSize)*1.5), view.getCenter().y + view.getSize().y / 2 - buttonSize - yOffset);
	sf::RectangleShape shape = sf::RectangleShape();
	shape.setSize(sf::Vector2f(buttonSize, buttonSize));
	shape.setPosition(position);
	if(this->constructId == -1)
		shape.setFillColor(sf::Color(255, 10, 19));
	else if (this->constructId == 0)
		shape.setFillColor(sf::Color(111,0,241));
	else
		shape.setFillColor(sf::Color(255,55,0));

	this->rect = shape;
}

void ConstructButton::draw(sf::RenderWindow *window, sf::View view) {
	this->createRect(view);
	window->draw(this->rect);
}
