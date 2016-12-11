#pragma once
#include "Menu.h"
#include "ConstructMenu.h"
#include "EconomyMenu.h"
#include "ContractMenu.h"
class MenuNodes {
public:
	Menu *menu;
	MenuNodes *next;
};
class MenuManager
{
public:
	MenuManager();
	MenuManager(ConstructManager *cManager, ContractManager *ctManager, EconomyManager *eManager, Construct *inputs[]);
	~MenuManager();
	void render(sf::RenderWindow *window, sf::View view);
	void update();
	void addMenu(Menu* menu);
	void addHeadMenu(Menu* menu);
	bool intersectsButton(sf::Vector2f position);
	Menu *getFound();
private:
	MenuNodes *head;
	MenuNodes *tail;
	Menu *foundMenu;
};

