#include "ConstructMenu.h"



ConstructMenu::ConstructMenu(ConstructManager *manager)
{
	ConstructButton *pipeButton = new ConstructButton(1.8f, "Texture/pipes.jpg");
	pipeButton->setConstruct(1);
	this->addButtons(pipeButton);
	
	ConstructButton *storageButton = new ConstructButton(1.98f, "Texture/storage.jpg");
	storageButton->setConstruct(2);
	this->addButtons(storageButton);

	ConstructButton *machineButton = new ConstructButton(2.2f, "Texture/machine.jpg");
	machineButton->setConstruct(3);
	this->addButtons(machineButton);

	ConstructButton *endButton = new ConstructButton(2.5f, "Texture/shipping.jpg");
	endButton->setConstruct(4);
	this->addButtons(endButton);

	this->manager = manager;

}

ConstructMenu::~ConstructMenu()
{
}

bool ConstructMenu::onButton(sf::Vector2f position)
{
	ButtonList *current = this->head;
	while (current != NULL) {
		if (current->button->intersects(position)) {
			this->activeConstruct = dynamic_cast<ConstructButton*>(current->button)->getConstruct();
			return true;
		}
			
		current = current->next;
	}
	return false;
}

bool ConstructMenu::handleClicked()
{
	this->manager->setConstruct(this->getActive());
	return false;
}

int ConstructMenu::getActive()
{
	return this->activeConstruct;
}
