#include "ConstructMenu.h"



ConstructMenu::ConstructMenu()
{
	ConstructButton *pipeButton = new ConstructButton(1.8f);
	pipeButton->setConstruct(1);
	this->addButtons(pipeButton);

	ConstructButton *edit = new ConstructButton(1.98f);
	edit->setConstruct(0);
	this->addButtons(edit);

	ConstructButton *remove = new ConstructButton(2.2f);
	remove->setConstruct(-1);
	this->addButtons(remove);

}


ConstructMenu::~ConstructMenu()
{
}

void ConstructMenu::draw(sf::RenderWindow *window, sf::View view)
{
	ButtonList *current = this->head;
	while (current != NULL) {
		current->button->draw(window, view);
		current = current->next;
	}
}
