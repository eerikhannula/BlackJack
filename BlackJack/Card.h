#pragma once

#include "CardNames.h"
#include "Suits.h"
#include <iostream>

using std::string;

class Card
{
private:
	CardNames _name;
	Suits _suit;
	int _value;
	char _symbol;

public:
	Card();
	Card(Suits suit, CardNames name);

	CardNames getName();
	Suits getSuit();
	int getValue();
	char getSymbol();
	string getNameString();
	string getSuitString();
};

