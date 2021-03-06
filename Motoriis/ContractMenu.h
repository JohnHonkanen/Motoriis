#pragma once
#include "SFML\Audio.hpp"
#include "ContractManager.h"
#include "ContractButton.h"
#include "Construct.h"
#include <iostream>

class ContractMenu : public Menu
{
public:
	ContractMenu(ContractManager *manager, EconomyManager *eManager, Construct *inputs[]);
	~ContractMenu();
	void draw(sf::RenderWindow *window, sf::View view);
	bool onButton(sf::Vector2f position);
	bool handleClicked();
	void update();
private:
	ContractManager *manager;
	Construct *inputs[2];
	ContractButton *oButton;
	sf::Font font;
	EconomyManager *eManager;
	sf::Music success;
};

