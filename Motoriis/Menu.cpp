#include "Menu.h"



Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow * window, sf::View view)
{
	ButtonList *current = this->head;
	while (current != NULL) {
		current->button->draw(window, view);
		current = current->next;
	}
}

void Menu::update()
{
}

void Menu::addButtons(ButtonObjects *button)
{
	ButtonList *newNode = new ButtonList();
	newNode->button = button;

	if (head == NULL) {
		this->head = newNode;
		this->tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = tail->next;
	}
}
