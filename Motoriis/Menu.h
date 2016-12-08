#pragma once
#include "ButtonObjects.h"

class ButtonList {
public:
	ButtonObjects *button;
	ButtonList *next;
};

class Menu
{
public:
	Menu();
	~Menu();
	virtual void draw(sf::RenderWindow *window, sf::View view);
	virtual bool onButton(sf::Vector2f position) = 0;
	virtual bool handleClicked() = 0;
	void addButtons(ButtonObjects *button);
protected:
	sf::Vector2f position;
	ButtonList *head;
	ButtonList *tail;
};

