#include "Table.h"


Table::Table(int balance) {
	_wallet = Wallet(balance);

    Deck _deck = Deck();
    
    Print("Welcome to Eerik's BlackJack table, please have a seat.");
    Start();
}


void Table::Start() {
    while (true)
    {
        string userInput;

        Print("\n\nTo play a round of blackjack, type [play], or to exit, type [exit]\n");

        std::cin >> userInput;
        Print("");

        if (userInput == "exit") {
            exit(0);
        }
        else if (userInput == "play") {
            Print("\nNEW ROUND START.\n");

            NewRound();
        }
        else {
            Print("Sorry, I didn't quite understand you.");
            Start();
        }
    }
}

void Table::NewRound() {
    _wallet.PrintBalance();

    _deck.Shuffle();
    int bet = 0;
    _deckIndex = 0;

    while (true) {
        bet = PlaceBet();
        if (bet <= _wallet.GetBalance() && bet > 0) {
            _wallet.SubBalance(bet);
            break;
        }
        else {
            Print("Invalid bet, try again.");
        }
    }
    AddCard(_houseHand, _deckIndex);
    AddCard(_playerHand, _deckIndex);
    AddCard(_playerHand, _deckIndex);


    while (true) {
        PrintHands();
        if (_playerScore > 21)
        {
            break;
        }
        else if (_playerScore != 21) {
            int choice = HitOrStay();
            if (choice == 0) {
                break;
            }
        }
        else {
            break;
        }
    }

    while (true) {
        if (_houseScore > 17 || _playerScore >= 21) {
            AddCard(_houseHand, _deckIndex);
        }
        else {
            break;
        }
    }

    if (_playerScore == 21) {
        Print("BLACKJACK, you win!");
        _wallet.AddBalance(bet * 2.5);
    }
    else if (_playerScore > _houseScore && _playerScore < 21) {
        Print("You win!");
        _wallet.AddBalance(bet * 2);
    }
    else {
        Print("Better luck next time :(");
    }
    
}

int Table::HitOrStay() {
    Print("[hit], [stay]");
    string input;
    std::cin >> input;

    if (input == "stay") {
        return 0;
    }
    else if (input == "hit") {
        AddCard(_playerHand, _deckIndex);
        return 1;
    }
    else {
        Print("\nInvalid response, try again.\n");
        return 2;
    }
}

int Table::PlaceBet() {
    int bet;
    std::cout << "Place your bet: " << std::endl;
    std::cin >> bet;
    return bet;
}

void Table::AddCard(std::vector<Card>& hand, int& deckIndex) {
    hand.push_back(_deck.Pick(deckIndex++));
}

void Table::Print(string text) {
    std::cout << text << std::endl;
}

void Table::Print(int number) {
    std::cout << number << std::endl;
}

void Table::PrintHands() {

    _houseScore = 0;
    _playerScore = 0;

    std::cout << "Dealer's hand:" << std::flush;
    for (Card card : _houseHand) {
        card.print();
        _houseScore += card.getValue();
    }
    Print(_houseScore);
    Print("");

    std::cout << "Player's hand:" << std::flush;
    for (Card card : _playerHand) {
        card.print();
        _playerScore += card.getValue();

    }
    Print(_playerScore);
    Print("");

}