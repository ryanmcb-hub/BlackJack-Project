#ifndef DEALER_H
#define DEALER_H
#include "Player.h"

class Dealer : public Player {
public:
    Dealer() : Player("Dealer") {}

    void showCard() const;
    
};





#endif