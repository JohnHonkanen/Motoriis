#pragma once
#include "ButtonObjects.h"
class EconomyButton :
	public ButtonObjects
{
public:
	EconomyButton();
	EconomyButton(float xOffsetMultiplier, std::string texture);
	~EconomyButton();
	void draw(sf::RenderWindow *window, sf::View view);
	void update();
private:
	void createRect(sf::View view);
};

