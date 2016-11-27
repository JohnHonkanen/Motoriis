#include "MenuManager.h"



MenuManager::MenuManager()
{
	this->addMenu(new ConstructMenu());
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
		tail->next = newNode;
		tail = tail->next;
	}
}
