#include "Wallet.h"
#include "iostream"

using std::string;

Wallet::Wallet() {

}

Wallet::Wallet(int startingBalance) {
	_balance = startingBalance;
}

int Wallet::GetBalance() {
	return _balance;
}

void Wallet::AddBalance(int amount) {
	_balance += amount;
}

void Wallet::SubBalance(int amount) {
	_balance -= amount;
}

void Wallet::PrintBalance() {
	std::cout << "Your current balance is: " << _balance << " credits." << std::endl;
}