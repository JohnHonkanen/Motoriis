#include "InputEvents.h"



InputEvents::InputEvents()
{
}


InputEvents::~InputEvents()
{
}

void InputEvents::eventControler(unsigned int keyInput)
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


//Output text using if else via SFML

/*

if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
{
std::cout << "Q" << std::endl;
}
else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
std::cout << "A" << std::endl;
}


*/