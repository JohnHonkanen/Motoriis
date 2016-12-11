#pragma once
#include "Contracts.h"
class BuyContracts :
	public Contracts
{
public:
	BuyContracts();
	BuyContracts(Item item, int rating, int payment, int advance);
	bool fufill(Construct *construct, EconomyManager* manager);
	bool fufill(EconomyManager* manager);
	~BuyContracts();
	bool purchase();
	void addToCurrent(int amount);
	int getCurrent();
	int getAdvancedPayment();
private:
	int payment;
	int advancePayment;
	int current = 0;
};

