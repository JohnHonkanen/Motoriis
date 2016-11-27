#include "Construct.h"



Construct::Construct()
{
}


Construct::~Construct()
{
}

void Construct::addItem(Item item) {
	this->color = item.getColor();
	this->storage.storeItem(item);
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
