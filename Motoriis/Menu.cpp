#include "Menu.h"



Menu::Menu()
{
}


Menu::~Menu()
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
