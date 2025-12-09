#ifndef DEALER_H
#define DEALER_H
#include "Player.h"
#include "Shoe.h"

class Dealer : public Player {
public:
    Dealer();

    void showUpCard();    

    void play(Shoe& shoe);

    //determine if dealer hits on soft 17 (A+6). dealer stands by default
    void setHitSoft17(bool hit);
    bool getHitSoft17() const;

private:
    bool m_hitSoft17 = false;
};

#endif