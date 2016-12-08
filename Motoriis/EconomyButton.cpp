#include "EconomyButton.h"



EconomyButton::EconomyButton()
{
}

EconomyButton::EconomyButton(float xOffsetMultiplier, std::string texture)
{
	this->texture.loadFromFile(texture);
	this->xOffsetMultiplier = xOffsetMultiplier;
}


EconomyButton::~EconomyButton()
{
}

void EconomyButton::draw(sf::RenderWindow * window, sf::View view)
{
	this->createRect(view);
	window->draw(this->rect);
}

void EconomyButton::update()
{
}

void EconomyButton::createRect(sf::View view)
{
	float buttonSize = view.getSize().x / 25.0f;
	float positionY = view.getCenter().y - view.getSize().y / 2;
	sf::RectangleShape shape = sf::RectangleShape();
	shape.setSize(sf::Vector2f(buttonSize*2.0f, buttonSize));
	shape.setPosition(sf::Vector2f(view.getCenter().x + view.getSize().x/2 - shape.getSize().x, positionY));
	shape.setTexture(&this->texture);

	this->rect = shape;
}
