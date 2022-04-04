#pragma once


class Wallet
{

	int _balance;

public:
	Wallet();
	Wallet(int startingBalance);
	void PrintBalance();
	int GetBalance();
	void AddBalance(int amount);
	void SubBalance(int amount);
};

