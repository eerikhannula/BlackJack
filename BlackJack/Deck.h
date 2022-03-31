#pragma once
#include "Card.h"
#include "Suits.h"
#include "CardNames.h"

class Deck
{
	Card Cards[52];

public:
	Deck();

	void InitCards();
};

