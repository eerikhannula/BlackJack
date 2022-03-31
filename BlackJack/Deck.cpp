#include "Deck.h"
#include <iostream>

Deck::Deck() {
	InitCards();
};

void Deck::InitCards() {

	for (int i = (int)Suits::CLUBS; i <= (int)Suits::HEARTS; i++) {
		for (int j = (int)CardNames::ACE; j <= (int)CardNames::KING; j++) {
			Card c = Card((Suits)i, (CardNames)j);
			int index = i * 13 + j;
			Cards[index] = c;
			std::cout << c.getNameString() << "\tof\t" << c.getSuitString() << "\tat index of\t" << index << std::endl;
		}
		std::cout << "" << std::endl;
	}
}