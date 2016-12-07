#pragma once
#include "Construct.h"
#include <iostream>
class CLinked
{
public:
	Construct* construct;
	CLinked* next;
	CLinked* prev;
};

class ConstructNetwork
{
public:
	ConstructNetwork();
	ConstructNetwork(CLinked *head);
	~ConstructNetwork();
	void calculatePath(Construct *construct, CLinked *visitedHead, CLinked *visitedTail);
	void update(Construct *construct, CLinked *last, CLinked* head);
	void setTail();
	Construct* getHeadConstruct();
private:
	bool checkVisits(Construct *construct, CLinked *head);
	CLinked* head;
	CLinked* tail;
};

