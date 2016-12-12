#include "ContractButton.h"



ContractButton::ContractButton(Contracts *contract, int x, int y)
{
	this->contract = contract;
	this->xPos = x;
	this->yPos = y;
	this->font.loadFromFile("Fonts/Bungee-Regular.ttf");
}


ContractButton::~ContractButton()
{
}

void ContractButton::draw(sf::RenderWindow * window, sf::View view)
{
	this->createRect(view);
	std::string rating;
	switch (this->contract->getRating()) {
	case 0:
		rating = "RANK A";
		break;
	case 1:
		rating = "RANK B";
		break;
	case 2:
		rating = "RANK C";
		break;
	default:
		rating = "RANK D";
	}
	if (this->yPos == 0)
		rating += " BUY";
	else
		rating += " SELL";
	sf::Text text(rating, this->font,view.getSize().x*0.1f);
	text.setScale(sf::Vector2f(0.16f,0.16f));
	text.setPosition(this->rect.getPosition());
	window->draw(this->rect);
	window->draw(text);
	text.setString(this->contract->getItem().getName());
	text.setPosition(text.getPosition() + sf::Vector2f(0, view.getSize().y*0.05f));
	text.setScale(sf::Vector2f(0.095f, 0.095f));
	window->draw(text);
	text.setString(std::to_string(this->contract->getItem().getAmount()));
	text.setPosition(text.getPosition() + sf::Vector2f(view.getSize().x * 0.02f, view.getSize().y*0.05f));
	text.setScale(sf::Vector2f(0.2f, 0.2f));
	window->draw(text);
	text.setString("Units");
	text.setPosition(text.getPosition() + sf::Vector2f(view.getSize().x * 0.03f, view.getSize().y*0.05f));
	text.setScale(sf::Vector2f(0.15f, 0.15f));
	window->draw(text);
	text.setScale(sf::Vector2f(0.1f, 0.1f));
	if (this->contract->getActive()) {
		if (this->contract->isComplete())
			text.setString("Complete");
		else
		text.setString("ACTIVE");
		text.setPosition(text.getPosition() + sf::Vector2f(-view.getSize().x * 0.04f, view.getSize().y*0.1f));
		window->draw(text);

	}
	text.setString("$" + std::to_string(this->contract->getCost()));
	text.setPosition(this->rect.getPosition().x + (this->rect.getSize().x * 0.64f) , this->rect.getPosition().y + (this->rect.getSize().y* 0.9f));
	window->draw(text);
}

void ContractButton::update()
{
}

void ContractButton::update(Contracts *contract)
{
	this->contract = contract;
}

Contracts * ContractButton::getContract()
{
	return this->contract;
}

void ContractButton::createRect(sf::View view)
{
	float buttonSize = view.getSize().x / 25.0f;
	float yOffset = view.getSize().y * 0.01f;
	float positionX = view.getCenter().x - (view.getSize().x * 0.3f) + ((buttonSize * 3 + view.getSize().x*0.1f) * this->xPos);
	float positionY = view.getCenter().y - (view.getSize().y * 0.3f) + ((buttonSize * 4 + + view.getSize().y*0.1f) * this->yPos);
	sf::Vector2f position = sf::Vector2f(positionX, positionY);
	sf::RectangleShape shape = sf::RectangleShape();
	shape.setSize(sf::Vector2f(buttonSize*3, buttonSize*4));
	shape.setPosition(position);
	shape.setFillColor(sf::Color(255,55,0));
	this->rect = shape;
}
