#include "ContractMenu.h"

ContractMenu::ContractMenu(ContractManager * manager, EconomyManager *eManager, Construct *inputs[])
{
	this->manager = manager;
	this->eManager = eManager;
	this->inputs[0] = inputs[0];
	this->inputs[1] = inputs[1];
	this->font.loadFromFile("Fonts/Bungee-Regular.ttf");
	ContractButton *buy0= new ContractButton(manager->getBuy(0), 0, 0);
	this->addButtons(buy0);
	ContractButton *buy1 = new ContractButton(manager->getBuy(1), 1, 0);
	this->addButtons(buy1);
	ContractButton *buy2 = new ContractButton(manager->getBuy(2), 2, 0);
	this->addButtons(buy2);

	ContractButton *sell0 = new ContractButton(manager->getSell(0), 0, 1);
	this->addButtons(sell0);
	ContractButton *sell1 = new ContractButton(manager->getSell(1), 1, 1);
	this->addButtons(sell1);
	ContractButton *sell2 = new ContractButton(manager->getSell(2), 2, 1);
	this->addButtons(sell2);
}

ContractMenu::~ContractMenu()
{
}

void ContractMenu::draw(sf::RenderWindow * window, sf::View view)
{
	if (this->manager->getShowMenu()) {
		sf::RectangleShape container;
		container.setSize(sf::Vector2f(view.getSize().x * 0.8f, view.getSize().y * 0.8f));
		float xPosition = view.getCenter().x - view.getSize().x * 0.4f;
		float yPosition = view.getCenter().y - view.getSize().y * 0.4f;
		container.setPosition(xPosition, yPosition);
		container.setFillColor(sf::Color(0,0,0, 50));
		container.setOutlineColor(sf::Color(255, 255, 255));
		container.setOutlineThickness(0.5f);

		sf::String title = "Contracts";
		sf::Text text(title, this->font, view.getSize().x / 5);
		text.setColor(sf::Color::White);
		text.setScale(sf::Vector2f(0.1f, 0.1f));
		text.setPosition(container.getPosition());

		window->draw(container);
		window->draw(text);
		ButtonList *current = this->head;
		while (current != NULL) {
			current->button->draw(window, view);
			current = current->next;
		}
		

	}
}

bool ContractMenu::onButton(sf::Vector2f position)
{
	if (!this->manager->getShowMenu())
		return false;

	ButtonList *current = this->head;
	while (current != NULL) {
		if (current->button->intersects(position)) {
			this->oButton = dynamic_cast<ContractButton*>(current->button);
			return true;
		}

		current = current->next;
	}
	return true;
}

bool ContractMenu::handleClicked()
{
	if (this->oButton->getContract()->getType() == 1) {
		for (int i = 0; i < 2; i++) {
			if (!this->inputs[i]->storage.hasItem()) {
				this->oButton->getContract()->fufill(this->inputs[i], eManager);
				return true;
			}
		}
	}
	else {
		std::cout << this->manager->activeBuyContracts[0] << std::endl;
		if (this->oButton->getContract()->getActive())
			return false;

		if (!this->manager->activeBuyContracts[0]) {
			this->oButton->getContract()->setActive(true);
			this->manager->activeBuyContracts[0] = this->oButton->getContract();
			this->eManager->addMoney(dynamic_cast<BuyContracts*>(this->oButton->getContract())->getAdvancedPayment());
		}
		else if (!this->manager->activeBuyContracts[1]) {
			this->oButton->getContract()->setActive(true);
			this->manager->activeBuyContracts[1] = this->oButton->getContract();
			this->eManager->addMoney(dynamic_cast<BuyContracts*>(this->oButton->getContract())->getAdvancedPayment());
		}
	}
	
	return false;
}
