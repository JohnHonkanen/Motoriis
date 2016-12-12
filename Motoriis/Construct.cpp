#include "Construct.h"



Construct::Construct()
{
}


Construct::~Construct()
{
}

int Construct::remove()
{
	this->removeConnections();
	return 1;
}

void Construct::render(sf::RenderWindow * window, sf::View view)
{
	window->draw(this->draw());
}

void Construct::handleBaseInputs()
{
	//Do nothing
}

bool Construct::accepts() {
	return this->acceptItems;
}
bool Construct::addItem(Item *item) {
	if (this->acceptItems && !this->storage.hasItem()) {
		this->color = item->getColor();
		this->storage.storeItem(item);
	}
	else
		return false;
	return true;
	
}

void Construct::setFlow(int flow)
{
	this->flow = flow;
}

int Construct::getFlow()
{
	return this->flow;
}

void Construct::redirectFlow()
{
	if (this->top != NULL && this->flow != 3) {
		if (!this->top->storage.hasItem())
			this->flow = 1;
	}
	else if (this->right != NULL  && this->flow != 4) {
		if(!this->right->storage.hasItem())
			this->flow = 2;
	}
	else if (this->bottom != NULL  && this->flow != 1) {
		if (!this->bottom->storage.hasItem())
			this->flow = 3;
	}
	else if (this->left != NULL && this->flow != 2) {
		if (!this->left->storage.hasItem())
			this->flow = 4;
	}
}

void Construct::removeConnections()
{
	if (this->top != NULL) {
		this->top->bottom = NULL;
		this->top->calculatePointPosition();
	}
		
	if (this->right != NULL) {
		this->right->left = NULL;
		this->right->calculatePointPosition();
	}
		
	if (this->bottom != NULL) {
		this->bottom->top = NULL;
		this->bottom->calculatePointPosition();
	}
		
	if (this->left != NULL) {
		this->left->right = NULL;
		this->left->calculatePointPosition();
	}
		

	delete this;
}

void Construct::setColor(sf::Color color)
{
	this->color = color;
}

bool Construct::accepting()
{
	return !this->storage.hasItem();
}

int Construct::getType()
{
	return this->type;
}

void Construct::setType(int type)
{
	this->type = type;
}

int Construct::getPrice()
{
	return this->price;
}

void Construct::setPrice(int price)
{
	this->price = price;
}
