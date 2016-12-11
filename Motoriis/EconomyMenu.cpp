#include "EconomyMenu.h"



EconomyMenu::EconomyMenu(ContractManager *cManager)
{
	this->cManager = cManager;
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
	if (this->cManager->getShowMenu())
		this->cManager->setShowMenu(false);
	else
		this->cManager->setShowMenu(true);

	std::cout << this->cManager->getShowMenu() << std::endl;

	return true;
}

