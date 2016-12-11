#pragma once
#include "ConstructManager.h"
#include "Menu.h"
#include "Construct.h"
#include "ConstructButton.h"
class ConstructMenu : public Menu
{
public:
	ConstructMenu(ConstructManager *manager);
	~ConstructMenu();
	bool onButton(sf::Vector2f position);
	bool handleClicked();
	int getActive();
private:
	int activeConstruct;
	int state;
	ConstructManager *manager;
};

