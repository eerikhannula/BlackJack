#pragma once
#include "Card.h"
#include "Suits.h"
#include "CardNames.h"

class Deck
{
	const static int _deckSize = 52;
	Card Cards[_deckSize];

public:
	Deck();
	void InitCards();

	void Shuffle();

	void PrintDeck();
};

