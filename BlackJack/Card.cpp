#include "Card.h"
#include "iostream"

using std::string;

Card::Card() {

}
Card::Card(Suits suit, CardNames name) {
	_name = name;
	_suit = suit;

	switch (name) {
	case CardNames::ACE:
		_value = 1;
		break;
	case CardNames::JACK:
		_value = 10;
		break;
	case CardNames::QUEEN:
		_value = 10;
		break;
	case CardNames::KING:
		_value = 10;
		break;
	default:
		_value = (int)name + 1;
	}

	switch (suit) {
	case Suits::CLUBS:
		_symbol = 'C';
		break;
	case Suits::DIAMONDS:
		_symbol = 'D';
		break;
	case Suits::SPADES:
		_symbol = 'S';
		break;
	case Suits::HEARTS:
		_symbol = 'H';
		break;
	default:
		_symbol = '?';
	}
}

CardNames Card::getName() {
	return _name;
}

Suits Card::getSuit() {
	return _suit;
}
int Card::getValue() {
	return _value;
}

char Card::getSymbol() {
	return _symbol;
}

string Card::getSuitString() {
	switch (_suit) {
	case (Suits)0:
		return "CLUBS";
	case (Suits)1:
		return "DIAMONDS";
	case (Suits)2:
		return "SPADES";
	case (Suits)3:
		return "HEARTS";
	}
}

string Card::getNameString() {
	switch (_name) {
	case (CardNames)0: return "ACE";
	case (CardNames)1: return "TWO";
	case (CardNames)2: return "THREE";
	case (CardNames)3: return "FOUR";
	case (CardNames)4: return "FIVE";
	case (CardNames)5: return "SIX";
	case (CardNames)6: return "SEVEN";
	case (CardNames)7: return "EIGHT";
	case (CardNames)8: return "NINE";
	case (CardNames)9: return "TEN";
	case (CardNames)10: return "JACK";
	case (CardNames)11: return "QUEEN";
	case (CardNames)12: return "KING";
	}
}

void Card::print() {
	std::cout << getNameString() << "\tof\t" << getSuitString() << std::endl;
}