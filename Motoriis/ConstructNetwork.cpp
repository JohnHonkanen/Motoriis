#include "ConstructNetwork.h"



ConstructNetwork::ConstructNetwork()
{
}

ConstructNetwork::ConstructNetwork(CLinked * head)
{
	this->head = head;
	this->setTail();
}


ConstructNetwork::~ConstructNetwork()
{
}

void ConstructNetwork::setTail()
{
	CLinked *visitedHead = new CLinked();
	visitedHead->construct = this->head->construct;
	visitedHead->prev = NULL;
	visitedHead->next = NULL;
	this->calculatePath(this->head->construct, visitedHead, visitedHead);
}

void ConstructNetwork::calculatePath(Construct *construct, CLinked *visitedHead, CLinked *visitedTail)
{
	CLinked *newVisit = new CLinked();
	if (construct->top != NULL && !this->checkVisits(construct->top, visitedHead)) {
		newVisit->construct = construct->top;
		newVisit->prev = visitedTail;
		visitedTail->next = newVisit;
		if (construct->getFlow() != 0 || construct->top->getFlow() != 0)
			calculatePath(construct->top, visitedHead, visitedTail->next);
	}
	if (construct->right != NULL && !this->checkVisits(construct->right, visitedHead)) {
		newVisit->construct = construct->right;
		newVisit->prev = visitedTail;
		visitedTail->next = newVisit;
		if (construct->getFlow() != 0 || construct->right->getFlow() != 0)
			calculatePath(construct->right, visitedHead, visitedTail->next);
	}
	if (construct->bottom != NULL && !this->checkVisits(construct->bottom, visitedHead)) {
		newVisit->construct = construct->bottom;
		newVisit->prev = visitedTail;
		visitedTail->next = newVisit;
		if (construct->getFlow() != 0 || construct->bottom->getFlow() != 0)
			calculatePath(construct->bottom, visitedHead, visitedTail->next);
	}
	if (construct->left != NULL && !this->checkVisits(construct->left, visitedHead)) {
		newVisit->construct = construct->left;
		newVisit->prev = visitedTail;
		visitedTail->next = newVisit;
		if (construct->getFlow() != 0 || construct->left->getFlow() != 0)
			calculatePath(construct->left, visitedHead, visitedTail->next);
			
	}
	update(construct, visitedTail->prev, this->head);
}

void ConstructNetwork::update(Construct *construct, CLinked *prev, CLinked* head)
{
	if (construct == head->construct || construct->storage.hasItem())
		return;

	prev->construct->transferItem();

	update(prev->construct, prev->prev, head);
}

bool ConstructNetwork::checkVisits(Construct *construct, CLinked *current) {
	if (current == NULL) {
		return false;
	}

	if (construct == current->construct) {
		return true;
	}
	return this->checkVisits(construct, current->next);
}
