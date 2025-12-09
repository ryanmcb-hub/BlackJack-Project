#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include "Shoe.h"

#include <vector>
#include <string>

using namespace std;
class Player {
protected:
    Hand m_hand = Hand(); 

private:
    double m_balance = 250;
    string m_name;
    int m_currentBet = 0;
    void saveBalance();
    void loadBalance(const string& name);

    double m_winnings = 0;
    double m_losses = 0;

public:
    Player();
    Player(string name);
    
    virtual ~Player();

    double getBalance();
    string getName();

    void setBet(double bet);
    int getBet();

    virtual Hand& getHand();

    int getScore();

    void printBalance();
    void printName();

    bool isBusted();

    double getWinnings();
    double getLosses();

    void virtual takeTurn(Card dealerUpCard, Shoe* shoe);

    void win(bool blackjack);
    void lose();

    void operator+=(double amount);
    void operator-=(double amount);
};

#endif