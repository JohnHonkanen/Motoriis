#include "Contracts.h"



Contracts::Contracts()
{
}


Contracts::~Contracts()
{
}

int Contracts::getRating()
{
	return this->rating;
}

Item Contracts::getItem()
{
	return this->item;
}

int Contracts::getCost()
{
	return this->cost;
}

int Contracts::getType()
{
	return this->type;
}

bool Contracts::getActive()
{
	return this->active;
}

void Contracts::setActive(bool active)
{
	this->active = true;
}

bool Contracts::isComplete()
{
	return this->complete;
}

int Contracts::getCurrent()
{
	return this->current;
}
