#include "MenuManager.h"

MenuManager::MenuManager(ConstructManager *cManager)
{
	this->addMenu(new ConstructMenu(cManager));
	this->addMenu(new EconomyMenu());
}


MenuManager::~MenuManager()
{
}

void MenuManager::render(sf::RenderWindow * window, sf::View view)
{
	MenuNodes *current = this->head;
	while (current != NULL) {
		current->menu->draw(window, view);
		current = current->next;
	}
}

void MenuManager::addMenu(Menu * menu)
{
	MenuNodes *newNode = new MenuNodes();
	newNode->menu = menu;

	if (head == NULL) {
		this->head = newNode;
		this->tail = newNode;
	}
	else {
		this->tail->next = newNode;
		this->tail = tail->next;
	}
}

bool MenuManager::intersectsButton(sf::Vector2f position)
{
	MenuNodes *current = this->head;
	while (current != NULL) {
		if (current->menu->onButton(position)) {
			this->foundMenu = current->menu;
			return true;
		}
		current = current->next;
	}
	return false;
}

Menu * MenuManager::getFound()
{
	return this->foundMenu;
}
