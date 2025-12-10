#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "CardGame.h"
#include "Card.h"
#include "Shoe.h"
#include "Player.h"
#include "Dealer.h"

#include <vector>

using namespace std;

class Blackjack : public CardGame {
private:
    Dealer m_dealer;
    Shoe m_shoe;
    int m_cutCard;

public:
    Blackjack(string name);
    Blackjack(string name, int decks);
    Blackjack(string name, int decks, int players);

    void playGame() override;
    void dealHands() override;
    void displayRules() override;

    vector<Player*> checkBlackjacks(vector<Player*>* winners, vector<Player*>* losers);
};

#endif