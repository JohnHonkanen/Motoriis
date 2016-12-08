#pragma once
#include "Menu.h"
#include "EconomyButton.h"

class EconomyMenu :
	public Menu
{
public:
	EconomyMenu();
	~EconomyMenu();
	bool onButton(sf::Vector2f position);
	bool handleClicked();
};

