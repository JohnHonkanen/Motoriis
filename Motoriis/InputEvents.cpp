#include "InputEvents.h"

InputEvents::InputEvents()
{
}


InputEvents::~InputEvents()
{
}
/*
	Get our mouse event
	@return	If mouse is clicked or not
*/
int InputEvents::mouseEvent() {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		return 1;
	}

	return 0;
}
/*
	Finds our mouse position relative to the window
	@param *window	Window to check our position to
*/
sf::Vector2i InputEvents::mousePosition(sf::RenderWindow *window) {
	return sf::Mouse::getPosition(*window);
}
/*
	Checks if we have if mouse is held
*/
bool InputEvents::getMouseDrag() {
	return this->mouseDrag;
}
/*
	Sets our mouse drag
	@status	True or False
*/
void InputEvents::setMouseDrag(bool status) {
	this->mouseDrag = status;
}
/*
	Gets position where we started our drag
*/
sf::Vector2f InputEvents::getStartDrag() {
	return this->startDrag;
}
/*
	Sets position where we start to drag from
*/
void InputEvents::setStartDrag(sf::Vector2f position) {
	int roundValue = 10;
	int x = position.x;
	int y = position.y;
	int remainX = x % roundValue;
	int remainY = y % roundValue;
	float roundX, roundY;
	//Round X
	if (remainX != 0)
		roundX = x - remainX;
	else
		roundX = x;
	//Round Y
	if (remainY != 0)
		roundY = y - remainY;
	else
		roundY = y;

	this->startDrag = sf::Vector2f(roundX, roundY);
}
/*
	Return an overlay based on mouse drag coordinates
*/
sf::RectangleShape InputEvents::getOverlay() {
	return this->overlay;
}
/*
	Updates our overlay rectangle shape
*/
void InputEvents::updateOverlay(sf::Vector2f currentPosition) {
	int roundValue = 10;
	int x = currentPosition.x;
	int y = currentPosition.y;
	int remainX = x % roundValue;
	int remainY = y % roundValue;
	float roundX, roundY;
	//Round X
	if (remainX != 0)
		roundX = x + (roundValue - remainX);
	else
		roundX = x;
	//Round Y
	if (remainY != 0)
		roundY = y + (roundValue - remainY);
	else
		roundY = y;

	overlay = sf::RectangleShape(sf::Vector2f(roundX, roundY)-this->startDrag);
	overlay.setFillColor(sf::Color::Transparent);
	overlay.setOutlineThickness(0.5);
	overlay.setOutlineColor(sf::Color::Red);
	overlay.setPosition(this->startDrag);
}
/*
	Resets our overlay to a 0, 0 value
*/
void InputEvents::resetOverlay() {
	overlay = sf::RectangleShape(sf::Vector2f(0,0));
}
/*
	Keyboard control
*/
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