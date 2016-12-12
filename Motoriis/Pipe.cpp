#include "Pipe.h"



Pipe::Pipe()
{
}


Pipe::~Pipe()
{
}

Pipe::Pipe(sf::Vector2f position) {
	this->position = position;
	this->scale = 2.0f;
	this->calculatePointPosition();
	this->main = this;
	this->price = 15;
}

sf::ConvexShape Pipe::draw() {
	sf::ConvexShape shape;
	shape.setPointCount(this->points.size());
	vector<sf::Vector2f>::iterator it;
	shape.setPointCount(this->pointCount);
	for (int i = 0; i < this->pointCount; i++) {
		shape.setPoint(i, this->points.at(i));
	}
	//Draw Pipe Shape
	if (this->storage.hasItem()) {
		shape.setFillColor(this->color);
	}
	else {
		shape.setFillColor(sf::Color::Transparent);
	}
	if(this->flow == 0)
		shape.setOutlineColor(sf::Color(255, 55, 0));
	else
		shape.setOutlineColor(sf::Color(55, 155, 0));
	shape.setOutlineThickness(-1.0f);


	return shape;
}

void Pipe::calculatePointPosition() {
	this->points.clear();
	this->pointCount = 0;
	if(this->top != NULL)
	{

		this->points.push_back(this->position + sf::Vector2f(3.0f, 0.0f));
		this->points.push_back(this->position + sf::Vector2f(7.0f, 0.0f));
		this->pointCount += 2;
	}
	else{
		this->points.push_back(this->position + sf::Vector2f(3.0f, 3.0f));
		this->points.push_back(this->position + sf::Vector2f(7.0f, 3.0f));
		this->pointCount += 2;
	}
	if (this->right != NULL) {
		this->points.push_back(this->position + sf::Vector2f(7.0f, 3.0f));
		this->points.push_back(this->position + sf::Vector2f(10.0f, 3.0f));
		this->points.push_back(this->position + sf::Vector2f(10.0f, 7.0f));
		this->points.push_back(this->position + sf::Vector2f(7.0f, 7.0f));
		this->pointCount += 4;
	}

	if (this->bottom != NULL)
	{
		this->points.push_back(this->position + sf::Vector2f(7.0f, 10.0f));
		this->points.push_back(this->position + sf::Vector2f(3.0f, 10.0f));
		this->pointCount += 2;
	}
	else {
		this->points.push_back(this->position + sf::Vector2f(7.0f, 7.0f));
		this->points.push_back(this->position + sf::Vector2f(3.0f, 7.0f));
		this->pointCount += 2;
	}
	
	if (this->left != NULL) {
		this->points.push_back(this->position + sf::Vector2f(3.0f, 7.0f));
		this->points.push_back(this->position + sf::Vector2f(0.0f, 7.0f));
		this->points.push_back(this->position + sf::Vector2f(0.0f, 3.0f));
		this->points.push_back(this->position + sf::Vector2f(3.0f, 3.0f));
		
		this->pointCount += 4;
	}
}

void Pipe::transferItem()
{
	if (!this->storage.hasItem()) {
		this->flow = 0;
	}
	else {
		if (this->flow == 1 && this->top != NULL && this->top->accepts()) {
				if (this->top->addItem(this->storage.getItem())) {
					if (this->top->getFlow() == 0)
						this->top->setFlow(1);
					this->storage.removeItem();
				}
		}
		else if (this->flow == 2 && this->right != NULL && this->right->accepts()) {
				if (this->right->addItem(this->storage.getItem())) {
					if (this->right->getFlow() == 0)
						this->right->setFlow(2);
					this->storage.removeItem();
				}
		}
		else if (this->flow == 3 && this->bottom != NULL && this->bottom->accepts()) {
				if (this->bottom->addItem(this->storage.getItem())) {
					if (this->bottom->getFlow() == 0)
						this->bottom->setFlow(3);
					this->storage.removeItem();
				}
		}
		else if (this->flow == 4 && this->left != NULL && this->left->accepts()) {
				if (this->left->addItem(this->storage.getItem())) {
					if (this->left->getFlow() == 0)
						this->left->setFlow(4);
					this->storage.removeItem();
				}
		}
		else {
			this->redirectFlow();
		}
	}
}

