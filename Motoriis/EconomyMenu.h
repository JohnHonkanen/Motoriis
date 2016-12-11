#pragma once
#include "Menu.h"
#include "EconomyButton.h"
#include "ContractManager.h"
#include <iostream>

class EconomyMenu :
	public Menu
{
public:
	EconomyMenu(ContractManager *cManager);
	~EconomyMenu();
	bool onButton(sf::Vector2f position);
	bool handleClicked();
private:
	ContractManager *cManager;
};

