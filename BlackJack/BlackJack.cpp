// BlackJack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Deck.h"

using std::string;

int main()
{

    Deck d = Deck();

    d.PrintDeck();

    d.Shuffle();

    d.PrintDeck();
}

