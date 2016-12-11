#pragma once
#include "Contracts.h"
class SellContracts :
	public Contracts
{
public:
	SellContracts();
	SellContracts(Item item, int rating, int cost);
	bool fufill(Construct *construct, EconomyManager* manager);
	~SellContracts();
	bool purchase();
private:
};

