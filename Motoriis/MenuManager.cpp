#include "MenuManager.h"

MenuManager::MenuManager()
{ 
}

MenuManager::MenuManager(ConstructManager *cManager, ContractManager *ctManager, EconomyManager *eManager, Construct *inputs[])
{
	this->addHeadMenu(new ConstructMenu(cManager));
	this->addMenu(new EconomyMenu(ctManager));
	this->addMenu(new ContractMenu(ctManager, eManager, inputs));
}


MenuManager::~MenuManager()
{
}

void MenuManager::render(sf::RenderWindow * window, sf::View view)
{
	MenuNodes *current = this->head;
	while (current != NULL) {
		current->menu->draw(window, view);
		current = current->next;
	}
}

void MenuManager::addMenu(Menu * menu)
{
	MenuNodes *newNode = new MenuNodes();
	newNode->menu = menu;

	if (this->head == NULL) {
		this->head = newNode;
		this->tail = newNode;
	}
	else {
		this->tail->next = newNode;
		this->tail = tail->next;
	}
}

void MenuManager::addHeadMenu(Menu * menu)
{
	MenuNodes *newNode = new MenuNodes();
	newNode->menu = menu;
	this->head = newNode;
	this->tail = newNode;
}

bool MenuManager::intersectsButton(sf::Vector2f position)
{
	MenuNodes *current = this->head;
	while (current != NULL) {
		if (current->menu->onButton(position)) {
			this->foundMenu = current->menu;
			return true;
		}
		current = current->next;
	}
	return false;
}

Menu * MenuManager::getFound()
{
	return this->foundMenu;
}
