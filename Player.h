#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"

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

public:
    Player();
    Player(string name);
    virtual ~Player();

    double getBalance();
    string getName();

    void setBet(double bet);
    int getBet();

    virtual Hand& getHand();

    void printBalance();
    void printName();

    bool isBusted();

    void operator+=(double winnings);
    void operator-=(double bet);
};

#endif