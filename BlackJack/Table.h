#pragma once
#include "Wallet.h"
#include "Deck.h"
#include "vector"
#include <thread>
#include <chrono>

class Table
{
	std::vector<Card> _houseHand;
	std::vector<Card> _playerHand;
	int _houseScore;
	int _playerScore;

	Wallet _wallet;
	Deck _deck;
	int _deckIndex;
public: 
	Table() = default;
	Table(int balance);

	void Start();
	void NewRound();
	int PlaceBet();

	int HitOrStay();

	void AddCard(std::vector<Card>& hand, int& deckIndex);

	void Print(string text);
	void Print(int number);
	void PrintHands();

	void ResetHands();
};

