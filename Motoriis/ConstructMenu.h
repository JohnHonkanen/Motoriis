#pragma once
#include "Menu.h"
#include "Construct.h"
#include "ConstructButton.h"
class ConstructMenu : public Menu
{
public:
	ConstructMenu();
	~ConstructMenu();
	void draw(sf::RenderWindow *window, sf::View view);
	bool onButton(sf::Vector2f position);
	int getActive();
private:
	int activeConstruct;
	int state;
};

