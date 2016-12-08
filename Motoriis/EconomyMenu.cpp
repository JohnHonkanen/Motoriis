#include "EconomyMenu.h"



EconomyMenu::EconomyMenu()
{
	EconomyButton *buyButton = new EconomyButton(0.0f, "Texture/contracts.png");
	this->addButtons(buyButton);
}


EconomyMenu::~EconomyMenu()
{
}

bool EconomyMenu::onButton(sf::Vector2f position)
{
	ButtonList *current = this->head;
	while (current != NULL) {
		if (current->button->intersects(position)) {
			return true;
		}

		current = current->next;
	}
	return false;
}

bool EconomyMenu::handleClicked()
{
	return false;
}

