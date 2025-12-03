#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <vector>
#include "Card.h"
#include "Shoe.h"
#include "Player.h"
#include "Dealer.h"

using namespace std;

class Blackjack {
private:
    Dealer m_dealer;
    vector<Player> m_players;
    Shoe m_shoe;

public:
    Blackjack(int players);
    void playGame();
};

#endif