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
	if (this->head->construct->storage.hasItem()) {
		this->calculatePath(this->head->construct->mainOutput, visitedHead, visitedHead);
	}
}

Construct * ConstructNetwork::getHeadConstruct()
{
	return this->head->construct;
}

void ConstructNetwork::calculatePath(Construct *construct, CLinked *visitedHead, CLinked *visitedTail)
{
	CLinked *newVisit = new CLinked();
	if (construct->top != NULL && !this->checkVisits(construct->top, visitedHead)) {
			newVisit->construct = construct->top;
			newVisit->prev = visitedTail;
			visitedTail->next = newVisit;
			calculatePath(construct->top, visitedHead, visitedTail->next);
	}
	if (construct->right != NULL && !this->checkVisits(construct->right, visitedHead)) {
			newVisit->construct = construct->right;
			newVisit->prev = visitedTail;
			visitedTail->next = newVisit;
			calculatePath(construct->right, visitedHead, visitedTail->next);
	}
	if (construct->bottom != NULL && !this->checkVisits(construct->bottom, visitedHead)) {
			newVisit->construct = construct->bottom;
			newVisit->prev = visitedTail;
			visitedTail->next = newVisit;
			calculatePath(construct->bottom, visitedHead, visitedTail->next);
	}
	if (construct->left != NULL && !this->checkVisits(construct->left, visitedHead)) {
			newVisit->construct = construct->left;
			newVisit->prev = visitedTail;
			visitedTail->next = newVisit;
			calculatePath(construct->left, visitedHead, visitedTail->next);	
	}
	update(construct, visitedTail->prev, this->head);
}

void ConstructNetwork::update(Construct *construct, CLinked *prev, CLinked* head)
{
	if (construct == head->construct->mainOutput || !construct->accepting() || prev == NULL)
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
