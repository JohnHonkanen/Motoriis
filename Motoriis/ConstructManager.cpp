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
		current->construct->render(window, view);
		current = current->next;
	}
}

void ConstructManager::update() {
	if (this->count == 0)
		return;

	elasped = clock.getElapsedTime();
	if (elasped.asSeconds() > 0.5f) {
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
				this->lastChecked = current;
				return construct;
			}
		current = current->next;
	}
	//Check
	this->lastChecked = current;
	return construct;
}

CLinked * ConstructManager::getLastChecked()
{
	return this->lastChecked;
}

void ConstructManager::removeLink()
{
	if (!this->isConstructing)
		return;
	CLinked* remove = this->lastChecked;
	int removeType = remove->construct->remove();
	if (removeType == 1) {
		if (remove->next != NULL)
			remove->next->prev = remove->prev;

		remove->prev->next = remove->next;

		if (remove == this->tail)
			this->tail = remove->prev;

		this->lastChecked = NULL;
		delete remove;
	}
	else if (removeType == 2) {
		StorageConstruct* construct = dynamic_cast<StorageConstruct*>(remove->construct);
		LinkedStorage* head = construct->getHead();
		this->removeFromNetwork(head->construct);
		LinkedStorage* current = head->next;
		while (current != NULL) {
			this->checkPosition(current->construct->getPosition());
			this->remove();
			current = current->next;
		}
		this->checkPosition(head->construct->getPosition());
		this->remove();
	}
	

}

void ConstructManager::removeFromNetwork(Construct* construct)
{
	Network* current = this->nHead;
	while (current != NULL) {
 		if (current->network->getHeadConstruct() == construct) {
			if (current == this->nHead) {
				if (current == this->nTail) {
					this->nHead = NULL;
					this->nTail = NULL;
					current = NULL;
				}else{
					this->nHead = this->nHead->next;
					current = NULL;
				}
			} else{
				if (current == this->nTail) {
					this->nTail = this->nTail->prev;
					current = NULL;
				}
				else {
					current->prev->next = current->next;
					current->next->prev = current->prev;
					current = NULL;
				}
			}
			delete current;
		}
		else {
			current = current->next;
		}
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

void ConstructManager::addStorageConstruct(sf::Vector2f position)
{

	StorageConstruct* left = new StorageConstruct(position);
	StorageConstruct* right = new StorageConstruct(position + sf::Vector2f(10, 0));
	StorageConstruct* leftBottom = new StorageConstruct(position + sf::Vector2f(0,10));
	StorageConstruct* rightBottom = new StorageConstruct(position + sf::Vector2f(10, 10));

	LinkedStorage* head = new LinkedStorage();
	head->construct = left;
	head->head = head;
	//right
	LinkedStorage* linked = new LinkedStorage();
	linked->construct = right;
	linked->head = head;
	head->next = linked;
	linked->next = new LinkedStorage();
	//rightBottom
	linked = linked->next;
	linked->construct = rightBottom;
	linked->head = head;
	linked->next = new LinkedStorage();
	//leftBottom
	linked = linked->next;
	linked->construct = leftBottom;
	linked->head = head;

	left->setHead(head);
	right->setHead(head);
	leftBottom->setHead(head);
	rightBottom->setHead(head);
	rightBottom->setType(2);


	this->addToList(left);
	this->addToList(right);
	this->addToList(leftBottom);
	this->addToList(rightBottom);
	this->addNetwork(left);
}

void ConstructManager::setConstruct(int construct)
{
	this->construct = construct;
}

void ConstructManager::buildConstruct(sf::Vector2f position, ItemManager manager)
{
	if (!this->isConstructing)
		return;

	if (this->construct != 0) {
		Construct* construct;
		if (this->construct == 1) {
			construct = new Pipe(position);
			this->addToList(construct);
		}
		else if (this->construct == 2) {
			this->addStorageConstruct(position);
		}
		else if (this->construct == 3) {
			Construct *machine = Machine::makeMachine(position, manager);
			this->addToList(machine);
			this->addToList(dynamic_cast<Machine*>(machine)->input1);
			this->addToList(dynamic_cast<Machine*>(machine)->input2);
			this->addToList(dynamic_cast<Machine*>(machine)->output);
			this->addNetwork(machine);
		}
		else if (this->construct == 4) {
			construct = new EndConstruct(position);
			this->addToList(construct);
		}
	}
	
}

void ConstructManager::setConstructing(bool value)
{
	this->isConstructing = value;
}

bool ConstructManager::getConstructing()
{
	return this->isConstructing;
}

sf::RectangleShape ConstructManager::drawHelper(sf::Vector2f position)
{
	sf::RectangleShape shape(sf::Vector2f(10, 10));
	shape.setPosition(position);
	if(this->checkPosition(position) != NULL)
		shape.setFillColor(sf::Color(225, 40, 40, 176));
	else
		shape.setFillColor(sf::Color(225, 225, 225, 176));

	if (this->construct == 1)
		shape.setSize(sf::Vector2f(10, 10));
	else if(this->construct == 2)
		shape.setSize(sf::Vector2f(20, 20));
	else if (this->construct == 3)
		shape.setSize(sf::Vector2f(20, 30));

	return shape;
}

void ConstructManager::remove()
{
	CLinked* remove = this->lastChecked;
	if (remove->next != NULL)
		remove->next->prev = remove->prev;

	remove->prev->next = remove->next;

	if (remove == this->tail)
		this->tail = remove->prev;

	this->lastChecked = NULL;
	delete remove;
}
