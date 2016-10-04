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

void InputEvents::keyboardEvent(unsigned int keyInput)
{

	switch (keyInput)
	{
	case sf::Keyboard::A:
		std::cout << "A" << std::endl;
		break;

	case sf::Keyboard::B:
		std::cout << "B" << std::endl;
		break;

	case sf::Keyboard::C:
		std::cout << "C" << std::endl;
		break;

	case sf::Keyboard::D:
		std::cout << "D" << std::endl;
		break;

	case sf::Keyboard::E:
		std::cout << "E" << std::endl;
		break;

	case sf::Keyboard::F:
		std::cout << "F" << std::endl;
		break;

	case sf::Keyboard::G:
		std::cout << "G" << std::endl;
		break;

	case sf::Keyboard::H:
		std::cout << "H" << std::endl;
		break;

	case sf::Keyboard::I:
		std::cout << "I" << std::endl;
		break;

	case sf::Keyboard::J:
		std::cout << "J" << std::endl;
		break;

	case sf::Keyboard::K:
		std::cout << "K" << std::endl;
		break;

	case sf::Keyboard::L:
		std::cout << "L" << std::endl;
		break;

	case sf::Keyboard::M:
		std::cout << "M" << std::endl;
		break;

	case sf::Keyboard::N:
		std::cout << "N" << std::endl;
		break;

	case sf::Keyboard::O:
		std::cout << "O" << std::endl;
		break;

	case sf::Keyboard::P:
		std::cout << "P" << std::endl;
		break;

	case sf::Keyboard::Q:
		std::cout << "Q" << std::endl;
		break;

	case sf::Keyboard::R:
		std::cout << "R" << std::endl;
		break;

	case sf::Keyboard::S:
		std::cout << "S" << std::endl;
		break;

	case sf::Keyboard::T:
		std::cout << "T" << std::endl;
		break;

	case sf::Keyboard::U:
		std::cout << "U" << std::endl;
		break;

	case sf::Keyboard::V:
		std::cout << "V" << std::endl;
		break;

	case sf::Keyboard::W:
		std::cout << "W" << std::endl;
		break;

	case sf::Keyboard::X:
		std::cout << "X" << std::endl;
		break;

	case sf::Keyboard::Y:
		std::cout << "Y" << std::endl;
		break;

	case sf::Keyboard::Z:
		std::cout << "Z" << std::endl;
		break;

	}
}