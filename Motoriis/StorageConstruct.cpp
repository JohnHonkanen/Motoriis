#include "StorageConstruct.h"



StorageConstruct::StorageConstruct()
{
}

StorageConstruct::StorageConstruct(sf::Vector2f position)
{
	this->main = this;
	this->position = position;
	this->scale = 2.0f;
	this->calculatePointPosition();
	this->flow = -1;
	this->acceptItems = true;
	this->states[0].loadFromFile("Texture/storage_1.png");
	this->states[1].loadFromFile("Texture/storage_2.png");
	this->states[2].loadFromFile("Texture/storage_3.png");
	this->states[3].loadFromFile("Texture/storage_4.png");
	this->price = 50;
}


StorageConstruct::~StorageConstruct()
{
}

sf::ConvexShape StorageConstruct::draw()
{
	sf::ConvexShape shape;
	shape.setPointCount(this->points.size());
	vector<sf::Vector2f>::iterator it;
	shape.setPointCount(this->pointCount);
	for (int i = 0; i < this->pointCount; i++) {
		shape.setPoint(i, this->points.at(i));
	}
	//Draw Shape
	if (this->storage.hasItem()) {
		shape.setFillColor(this->color);
	}
	else {
		shape.setFillColor(sf::Color::Transparent);
	}
	if(this->type == 0)
		shape.setOutlineColor(sf::Color(255, 55, 0));
	else if(this->type == 1)
		shape.setOutlineColor(sf::Color(0, 255, 15));
	else if (this->type == 2)
		shape.setOutlineColor(sf::Color(255, 255, 0));

	shape.setOutlineThickness(-0.5f);
	shape.setTexture(NULL, false);
	if (this->storage.hasItem()) {
		if (this->storage.getItem()->getAmount() == 0)
			shape.setTexture(NULL, false);
		else if (this->storage.getItem()->getAmount() >= 1 && this->storage.getItem()->getAmount() < 2) {
			shape.setTexture(&this->states[0], false);
		}
		else if (this->storage.getItem()->getAmount() >= 2 && this->storage.getItem()->getAmount() < 5) {
			shape.setTexture(&this->states[1], false);
		}
		else if (this->storage.getItem()->getAmount() >= 5 && this->storage.getItem()->getAmount() < 10) {
			shape.setTexture(&this->states[2], false);
		}
		else if (this->storage.getItem()->getAmount() == 10) {
			shape.setTexture(&this->states[3], false);
		}
	}

	return shape;
}

int StorageConstruct::remove()
{
	return 2;
}

bool StorageConstruct::addItem(Item *item)
{
	return this->addItem(item, this->head);
}

bool StorageConstruct::addItem(Item *item, LinkedStorage *current)
{
	if (current == NULL)
		return false;
	if (!current->construct->storage.hasItem())
	{
		current->construct->setColor(item->getColor());
		current->construct->storage.storeItem(item);
		return true;
	}
	else if (current->construct->storage.getItem()->getAmount() < 10 && current->construct->storage.getItem()->getUID() == item->getUID()) {
		current->construct->storage.getItem()->addAmount(1);
		return true;
	}
	this->addItem(item, current->next);
}

void StorageConstruct::calculatePointPosition()
{
	this->points.clear();
	this->pointCount = 0;
	this->points.push_back(this->position + sf::Vector2f(0.0f, 0.0f));
	this->points.push_back(this->position + sf::Vector2f(10.0f, 0.0f));
	this->points.push_back(this->position + sf::Vector2f(10.0f, 10.0f));
	this->points.push_back(this->position + sf::Vector2f(0.0f, 10.0f));
	this->pointCount = 4;
}

void StorageConstruct::transferItem()
{
	Construct *output = NULL;
	output = findOutput(this->head);
	if (output != NULL)
		this->transferItem(this->head, output);
}

void StorageConstruct::transferItem(LinkedStorage * current, Construct *output)
{
	if (current == NULL)
		return;

	if (current->construct->storage.hasItem()) {
		if (output->top != NULL) {
			if (!output->top->storage.hasItem() && output->top->getFlow() != -1) {
				if (output->top->addItem(current->construct->storage.getItem())) {
					output->top->setFlow(1);
					current->construct->storage.getItem()->reduceAmount(1);
					if(current->construct->storage.getItem()->getAmount() <= 0)
						current->construct->storage.removeItem();
				}
				
			}

		}
		if (output->right != NULL) {
			if (!output->right->storage.hasItem() && output->right->getFlow() != -1) {
				if (output->right->addItem(current->construct->storage.getItem())) {
					output->right->setFlow(2);
					current->construct->storage.getItem()->reduceAmount(1);
					if (current->construct->storage.getItem()->getAmount() <= 0)
						current->construct->storage.removeItem();
				}
				
			}
		}

		if (output->bottom != NULL) {
			if (!output->bottom->storage.hasItem() && output->bottom->getFlow() != -1) {
				if (output->bottom->addItem(current->construct->storage.getItem())) {
					output->bottom->setFlow(3);
					current->construct->storage.getItem()->reduceAmount(1);
					if (current->construct->storage.getItem()->getAmount() <= 0)
						current->construct->storage.removeItem();
				}
				
			}
		}

		if (output->left != NULL) {
			if (!output->left->storage.hasItem() && output->left->getFlow() != -1) {
				if (output->left->addItem(current->construct->storage.getItem())) {
					output->left->setFlow(4);
					current->construct->storage.getItem()->reduceAmount(1);
					if (current->construct->storage.getItem()->getAmount() <= 0)
						current->construct->storage.removeItem();
				}
				
			}
		}
	}
	else {
		this->transferItem(current->next, output);
	}
}

Construct* StorageConstruct::findOutput(LinkedStorage * current)
{
	if (current == NULL)
		return NULL;

	if (current->construct->getType() == 2) {
		return current->construct;
	}
	findOutput(current->next);
}

bool StorageConstruct::accepting()
{
	return accepting(this->head);
}

bool StorageConstruct::accepting(LinkedStorage * current)
{
	if(current == NULL)
		return false;

	if (!current->construct->storage.hasItem())
		return true;

	if (current->construct->storage.getItem()->getAmount() < 10)
	{
		return true;
	}
	accepting(current->next);
}

void StorageConstruct::setHead(LinkedStorage * head)
{
	this->head = head;
}

LinkedStorage * StorageConstruct::getHead()
{
	return this->head;
}
