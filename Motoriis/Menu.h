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
	virtual void draw(sf::RenderWindow *window, sf::View view) = 0;
	void addButtons(ButtonObjects *button);
protected:
	sf::Vector2f position;
	ButtonList *head;
	ButtonList *tail;
};

