#pragma once
#include "Contracts.h"
#include "SFML\Audio.hpp"
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
	int getAdvancedPayment();
private:
	int payment;
	int advancePayment;
	sf::Music success;
};

