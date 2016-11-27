#include "ConstructManager.h"


ConstructManager::ConstructManager()
{
	int count = 0;
}

ConstructManager::~ConstructManager()
{
}

void ConstructManager::addToList(Construct* construct) {

	Construct* top = this->checkPosition(construct->getPosition() + sf::Vector2f(0, -10.0f));
	Construct* bottom = this->checkPosition(construct->getPosition() + sf::Vector2f(0, 10.0f));
	Construct* left = this->checkPosition(construct->getPosition() + sf::Vector2f(-10.0f, 0.0f));
	Construct* right = this->checkPosition(construct->getPosition() + sf::Vector2f(10.0f, 0.0f));
	if (top != NULL) {
		construct->top = top;
		top->bottom = construct;
		top->calculatePointPosition();
	}

	if (bottom != NULL) {
		construct->bottom = bottom;
		bottom->top = construct;
		bottom->calculatePointPosition();
	}

	if (left != NULL) {
		construct->left = left;
		left->right = construct;
		left->calculatePointPosition();
	}

	if (right != NULL) {
		construct->right = right;
		right->left = construct;
		right->calculatePointPosition();
	}
	construct->calculatePointPosition();

	
	CLinked* link = new CLinked();
	link->construct = construct;
	link->next = NULL;
	link->prev = this->tail;
	if (this->count == 0) {
		this->head = link;
		this->tail = link;
	}
	else {
		this->tail->next = link;
		this->tail = this->tail->next;

	}
	this->count++;	
}

void ConstructManager::addNetwork(Construct *base)
{
	CLinked* link = new CLinked();
	link->construct = base;
	link->next = NULL;
	link->prev = NULL;

	ConstructNetwork* constructNetwork = new ConstructNetwork(link);
	
	Network* newNetwork = new Network();
	newNetwork->network = constructNetwork;
	newNetwork->next = NULL;
	newNetwork->prev = this->nTail;

	if (this->nHead == NULL) {
		this->nHead = newNetwork;
		this->nTail = newNetwork;
	}
	else {
		this->nTail->next = newNetwork;
		this->nTail = this->nTail->next;
	}

}

void ConstructManager::render(sf::RenderWindow *window, sf::View view) {
	if (this->count == 0)
		return;

	CLinked* current = this->head;
	while (current != NULL) {
		window->draw(current->construct->draw());
		current = current->next;
	}
}

void ConstructManager::update() {
	if (this->count == 0)
		return;

	elasped = clock.getElapsedTime();
	if (elasped.asSeconds() >0.3f) {
		this->runNetwork(this->nHead);
		clock.restart();
	}
	
}

void ConstructManager::runNetwork(Network * current)
{
	if (current == NULL)
		return;
	current->network->setTail();
	this->runNetwork(current->next);

}

Construct* ConstructManager::checkPosition(sf::Vector2f position) {
	Construct* construct = NULL;
	if (this->count == 0) {
		return construct;
	}
	CLinked* current = this->head;
	while (current != nullptr) {
		if (current->construct->getPosition().x == position.x)
			if (current->construct->getPosition().y == position.y) {
				this->count++;
				construct = current->construct;
				if (this->lastChecked != NULL)
					this->changeFlow(this->lastChecked->construct, current->construct);
				this->lastChecked = current;
				return construct;
			}
		current = current->next;
	}
	this->lastChecked = current;
	return construct;
}

CLinked * ConstructManager::getLastChecked()
{
	return this->lastChecked;
}

void ConstructManager::removeLink()
{
	CLinked* remove = this->lastChecked;
	if (remove->construct->getFlow() != 5) {
		remove->construct->removeConnections();
		if (remove->next != NULL)
			remove->next->prev = remove->prev;
		remove->prev->next = remove->next;
		if (remove == this->tail)
			this->tail = remove->prev;
		this->lastChecked = NULL;
		delete remove;
	}
	
}

void ConstructManager::changeFlow(Construct * c1, Construct * c2)
{
	if (c1->top == c2) {
		c1->setFlow(1);
		c2->setFlow(1);
	}	
	else if (c1->right == c2) {
		c1->setFlow(2);
		c2->setFlow(2);
	}
	else if (c1->bottom == c2) {
		c1->setFlow(3);
		c2->setFlow(3);
	}	
	else if (c1->left == c2) {
		c1->setFlow(4);
		c2->setFlow(4);
	}
		
}
