#include "Machine.h"



Machine::Machine()
{
}


Machine::~Machine()
{
}

Machine::Machine(sf::Vector2f position)
{
	this->position = position;
}

Machine::Machine(sf::Vector2f position, ItemManager manager)
{
	this->position = position;
	this->manager = manager;
}

Machine * Machine::makeMachine(sf::Vector2f position, ItemManager manager)
{
	Machine *machine = new Machine(position + sf::Vector2f(0,10), manager);
	machine->input1 = new BaseInput(position);
	dynamic_cast<BaseInput*>(machine->input1)->main = machine;
	machine->input2 = new BaseInput(position + sf::Vector2f(0,20));
	dynamic_cast<BaseInput*>(machine->input2)->main = machine;
	machine->output = new BaseInput(position + sf::Vector2f(10, 10));
	dynamic_cast<BaseInput*>(machine->output)->main = machine;
	machine->mainOutput = machine->output;
	machine->output->setFlow(5);
	return machine;
}

sf::ConvexShape Machine::draw()
{
	return sf::ConvexShape();
}

void Machine::calculatePointPosition()
{
	//Do nothing
}

void Machine::transferItem()
{
	if (!this->input1->storage.hasItem() || !this->input2->storage.hasItem())
		return;
	else {
		Item *outputItem;
		if(this->input1->storage.getItem()->getUID() == this->input2->storage.getItem()->getUID()) {
			if(this->input1->storage.hasItem())
				outputItem = this->input1->storage.getItem();
			else
				outputItem = this->input2->storage.getItem();
		}
		else {
			outputItem = &this->manager.findItem(2); // BlueBerry Ice Cream
		}
		this->input1->storage.removeItem();
		this->input2->storage.removeItem();
		this->output->storage.removeItem();
		this->output->storage.storeItem(outputItem);
		if (this->output->top != NULL) {
			if (!this->output->top->storage.hasItem()) {
				this->output->top->addItem(this->output->storage.getItem());
				this->output->top->setFlow(1);
			}

		}
		if (this->output->right != NULL) {
			if (!this->output->right->storage.hasItem()) {
				this->output->right->addItem(this->output->storage.getItem());
				this->output->right->setFlow(2);
			}
		}

		if (this->output->bottom != NULL) {
			if (!this->output->bottom->storage.hasItem()) {
				this->output->bottom->addItem(this->output->storage.getItem());
				this->output->bottom->setFlow(3);
			}
		}

		if (this->output->left != NULL) {
			if (!this->output->left->storage.hasItem()) {
				this->output->left->addItem(this->output->storage.getItem());
				this->output->left->setFlow(4);
			}
		}
	}
}

void Machine::render(sf::RenderWindow * window, sf::View view)
{
	sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(20,30));
	shape.setPosition(this->position - sf::Vector2f(0,10));
	shape.setFillColor(sf::Color(55, 55, 255));
	shape.setOutlineColor(sf::Color(55, 55, 255));
	shape.setOutlineThickness(-1.0f);
	window->draw(shape);
	sf::RectangleShape inputs = sf::RectangleShape(sf::Vector2f(10, 10));
	inputs.setPosition(this->position - sf::Vector2f(0, 10));
	
	inputs.setOutlineColor(sf::Color(55, 55, 55));
	inputs.setOutlineThickness(-1.0f);
	if (input1->storage.hasItem())
		inputs.setFillColor(input1->storage.getItem()->getColor());
	else {
		inputs.setFillColor(sf::Color(100, 100, 100, 255));
	}
	window->draw(inputs);
	inputs.setPosition(this->position + sf::Vector2f(0, 10));
	if (input2->storage.hasItem())
		inputs.setFillColor(input2->storage.getItem()->getColor());
	else {
		inputs.setFillColor(sf::Color(100, 100, 100, 255));
	}
	window->draw(inputs);
	inputs.setPosition(this->position + sf::Vector2f(10, 0));
	inputs.setOutlineColor(sf::Color(255, 55, 55));
	if (output->storage.hasItem())
		inputs.setFillColor(output->storage.getItem()->getColor());
	else {
		inputs.setFillColor(sf::Color(100, 100, 100, 255));
	}
	window->draw(inputs);
}

void Machine::handleBaseInputs()
{
	this->transferItem();
}
