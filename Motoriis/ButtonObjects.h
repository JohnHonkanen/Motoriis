#include "SFML\Graphics.hpp"
#pragma once
class ButtonObjects
{
public:
	ButtonObjects();
	~ButtonObjects();
	virtual void draw(sf::RenderWindow *window, sf::View view) = 0;
	virtual void update() = 0;
protected:
	virtual void createRect(sf::View view) = 0;
	float xOffsetMultiplier;
	sf::Text text;
	sf::Vector2f position;
	sf::RectangleShape rect;
	sf::ConvexShape icon;
};

