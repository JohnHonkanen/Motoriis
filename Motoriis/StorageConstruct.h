#pragma once
#include "Construct.h"
#include <iostream>
class LinkedStorage {
public:
	Construct* construct;
	LinkedStorage* head;
	LinkedStorage* next;
};
class StorageConstruct : public Construct
{
public:
	StorageConstruct();
	StorageConstruct(sf::Vector2f position);
	~StorageConstruct();
	sf::ConvexShape draw();
	int remove();
	bool addItem(Item *item);
	bool addItem(Item *item, LinkedStorage *current);
	void calculatePointPosition();
	void transferItem();
	void transferItem(LinkedStorage *current, Construct *output);
	Construct *findOutput(LinkedStorage *current);
	bool accepting();
	bool accepting(LinkedStorage *current);
	void setHead(LinkedStorage* head);
	LinkedStorage* getHead();
private:
	LinkedStorage* head;
};

