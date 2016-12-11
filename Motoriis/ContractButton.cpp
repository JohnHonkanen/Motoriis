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
		rating = "A";
		break;
	case 1:
		rating = "B";
		break;
	case 2:
		rating = "C";
		break;
	default:
		rating = "D";
	}
	if (this->yPos == 0)
		rating += " BUY";
	else
		rating += " SELL";
	sf::Text text(rating, this->font,view.getSize().x*0.1f);
	text.setScale(sf::Vector2f(0.2f,0.2f));
	text.setPosition(this->rect.getPosition());
	window->draw(this->rect);
	window->draw(text);
	text.setString(std::to_string(this->contract->getItem().getAmount())+ " x " + this->contract->getItem().getName());
	text.setPosition(text.getPosition() + sf::Vector2f(0, view.getSize().y*0.05f));
	text.setScale(sf::Vector2f(0.08f, 0.08f));
	window->draw(text);
	if (this->contract->getActive()) {
		if (this->contract->isComplete())
			text.setString("Complete");
		else
		text.setString("ACTIVE");
		text.setPosition(text.getPosition() + sf::Vector2f(0, view.getSize().y*0.1f));
		window->draw(text);
	}
	text.setString("$" + std::to_string(this->contract->getCost()));
	text.setPosition(this->rect.getPosition().x + (this->rect.getSize().x * 0.75f) , this->rect.getPosition().y + (this->rect.getSize().y* 0.9f));
	window->draw(text);
}

void ContractButton::update()
{
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
