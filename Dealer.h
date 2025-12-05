#ifndef DEALER_H
#define DEALER_H

#include "Player.h"
#include "Shoe.h"

class Dealer : public Player {
public:
    Dealer();

    Card getUpCard();
    void showUpCard();   
    
    void takeTurn(Shoe* shoe);
};

#endif