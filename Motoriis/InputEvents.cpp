#include "InputEvents.h"

InputEvents::InputEvents()
{
}


InputEvents::~InputEvents()
{
}

int InputEvents::mouseEvent() {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		return 1;
	}

	return 0;
}

sf::Vector2i InputEvents::mousePosition(sf::RenderWindow *window) {
	return sf::Mouse::getPosition(*window);
}

bool InputEvents::getMouseDrag() {
	return this->mouseDrag;
}

void InputEvents::setMouseDrag(bool status) {
	this->mouseDrag = status;
}

sf::Vector2f InputEvents::getStartDrag() {
	return this->startDrag;
}
void InputEvents::setStartDrag(sf::Vector2f position) {
	this->startDrag = position;
}

sf::RectangleShape InputEvents::getOverlay() {
	return this->overlay;
}

void InputEvents::updateOverlay(sf::Vector2f currentPosition) {
	overlay = sf::RectangleShape(currentPosition-this->startDrag);
	overlay.setFillColor(sf::Color::Transparent);
	overlay.setOutlineThickness(0.5);
	overlay.setOutlineColor(sf::Color::Red);
	overlay.setPosition(this->startDrag);
}

void InputEvents::resetOverlay() {
	overlay = sf::RectangleShape(sf::Vector2f(0,0));
}



