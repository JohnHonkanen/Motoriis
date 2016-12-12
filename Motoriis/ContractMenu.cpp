#include "ContractMenu.h"

ContractMenu::ContractMenu(ContractManager * manager, EconomyManager *eManager, Construct *inputs[])
{
	this->success.openFromFile("Sounds/buy_1.wav");
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
		//Active Inputs
		text.setString("1) TOP");
		if (this->manager->getActiveInput() == 0)
			text.setColor(sf::Color::Green);
		else
			text.setColor(sf::Color::White);
		text.setPosition(container.getPosition() + sf::Vector2f(container.getSize().x *0.9f, 0));
		window->draw(text);
		text.setString("2) Bottom");
		if (this->manager->getActiveInput() == 1)
			text.setColor(sf::Color::Green);
		else
			text.setColor(sf::Color::White);
		text.setPosition(text.getPosition() + sf::Vector2f(-container.getSize().x *0.05f, container.getSize().y * 0.05f));
		window->draw(text);
		//TIMER PART
		text.setColor(sf::Color::White);
		sf::Text timer("Renews in "+ std::to_string(this->manager->getSecondsLeft()) + " SECONDS", this->font, view.getSize().x *0.15f);
		timer.setColor(sf::Color::White);
		timer.setScale(sf::Vector2f(0.1f, 0.1f));
		sf::FloatRect bounds = timer.getLocalBounds();
		timer.setPosition(container.getPosition() + sf::Vector2f(container.getSize().x * 0.4f, 0));
		window->draw(timer);
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
		if (!this->inputs[this->manager->getActiveInput()]->storage.hasItem()) {
			this->oButton->getContract()->fufill(this->inputs[this->manager->getActiveInput()], eManager);
			this->success.play();
			return true;
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
			this->success.play();
		}
		else if (!this->manager->activeBuyContracts[1]) {
			this->oButton->getContract()->setActive(true);
			this->manager->activeBuyContracts[1] = this->oButton->getContract();
			this->eManager->addMoney(dynamic_cast<BuyContracts*>(this->oButton->getContract())->getAdvancedPayment());
			this->success.play();
		}
	}
	
	return false;
}

void ContractMenu::update()
{
	ButtonList *current = this->head;
	for (int i = 0; i < 3; i++) {
	 	dynamic_cast<ContractButton*>(current->button)->update(this->manager->getBuy(i));
		current = current->next;
	}
	for (int i = 0; i < 3; i++) {
		dynamic_cast<ContractButton*>(current->button)->update(this->manager->getSell(i));
		current = current->next;
	}
}
