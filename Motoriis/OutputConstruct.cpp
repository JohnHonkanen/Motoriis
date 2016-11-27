#include "OutputConstruct.h"



OutputConstruct::OutputConstruct()
{
}

OutputConstruct::OutputConstruct(sf::Vector2f position)
{
	this->position = position;
	this->scale = 2.0f;
	this->calculatePointPosition();
	this->flow = 5;
}


OutputConstruct::~OutputConstruct()
{
}

void OutputConstruct::transferItem() {
	if (this->top != NULL) {
		if (!this->top->storage.hasItem()) {
			this->top->addItem(this->storage.getItem());
			this->top->setFlow(1);
		}
		
	}
	if (this->right != NULL) {
		if (!this->right->storage.hasItem()) {
			this->right->addItem(this->storage.getItem());
			this->right->setFlow(2);
		}
	}

	if (this->bottom != NULL) {
		if (!this->bottom->storage.hasItem()) {
			this->bottom->addItem(this->storage.getItem());
			this->bottom->setFlow(3);
		}
	}

	if (this->left != NULL) {
		if (!this->left->storage.hasItem()) {
			this->left->addItem(this->storage.getItem());
			this->left->setFlow(4);
		}
	}
}

void OutputConstruct::calculatePointPosition() {
	this->points.clear();
	this->pointCount = 0;
	if (this->top != NULL)
	{
		this->points.push_back(this->position + sf::Vector2f(2.0f, 0.0f));
		this->points.push_back(this->position + sf::Vector2f(8.0f, 0.0f));
		this->pointCount += 2;
	}
	else {
		this->points.push_back(this->position + sf::Vector2f(2.0f, 2.0f));
		this->points.push_back(this->position + sf::Vector2f(8.0f, 2.0f));
		this->pointCount += 2;
	}
	if (this->right != NULL) {
		this->points.push_back(this->position + sf::Vector2f(8.0f, 2.0f));
		this->points.push_back(this->position + sf::Vector2f(10.0f, 2.0f));
		this->points.push_back(this->position + sf::Vector2f(10.0f, 8.0f));
		this->points.push_back(this->position + sf::Vector2f(8.0f, 8.0f));
		this->pointCount += 4;
	}

	if (this->bottom != NULL)
	{
		this->points.push_back(this->position + sf::Vector2f(8.0f, 10.0f));
		this->points.push_back(this->position + sf::Vector2f(2.0f, 10.0f));
		this->pointCount += 2;
	}
	else {
		this->points.push_back(this->position + sf::Vector2f(8.0f, 8.0f));
		this->points.push_back(this->position + sf::Vector2f(2.0f, 8.0f));
		this->pointCount += 2;
	}

	if (this->left != NULL) {
		this->points.push_back(this->position + sf::Vector2f(2.0f, 8.0f));
		this->points.push_back(this->position + sf::Vector2f(0.0f, 8.0f));
		this->points.push_back(this->position + sf::Vector2f(0.0f, 2.0f));
		this->points.push_back(this->position + sf::Vector2f(2.0f, 2.0f));

		this->pointCount += 4;
	}
}

sf::ConvexShape OutputConstruct::draw() {
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
	
	shape.setOutlineColor(sf::Color::Black);
	shape.setOutlineThickness(-1.0f);


	return shape;
}