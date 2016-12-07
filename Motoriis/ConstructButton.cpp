#include "ConstructButton.h"



ConstructButton::ConstructButton()
{
}
ConstructButton::ConstructButton(float xOffsetMultiplier)
{
	this->xOffsetMultiplier = xOffsetMultiplier;
}

ConstructButton::ConstructButton(float xOffsetMultiplier, string texture)
{
	this->xOffsetMultiplier = xOffsetMultiplier;
	this->texture.loadFromFile(texture);
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

int ConstructButton::getConstruct()
{
	return this->constructId;
}

void ConstructButton::createRect(sf::View view)
{

	float buttonSize = view.getSize().x/25.0f;
	float yOffset = view.getSize().y * 0.01f;
	sf::Vector2f position = sf::Vector2f(view.getCenter().x - (view.getSize().x / this->xOffsetMultiplier) + buttonSize + ((buttonSize)*1.5), view.getCenter().y + view.getSize().y / 2 - buttonSize - yOffset);
	sf::RectangleShape shape = sf::RectangleShape();
	shape.setSize(sf::Vector2f(buttonSize, buttonSize));
	shape.setPosition(position);
	//shape.setFillColor(sf::Color(255,55,0));
	shape.setTexture(&this->texture);

	this->rect = shape;
}

void ConstructButton::draw(sf::RenderWindow *window, sf::View view) {
	this->createRect(view);
	window->draw(this->rect);
}
