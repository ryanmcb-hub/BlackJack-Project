#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Card.h"

class Player {
protected:
    std::vector<Card> m_hand; 

private:
    double m_balance;
    std::string m_name;

public:
    Player(const std::string& name);
    virtual ~Player();
    
    double getBalance(); //ideally retrive this from a text file
    void clearBalance(); //wipes out balance after game over

    void addCard(const Card& card); //add card to hand vector
    int getHand() const; 
    void showHandValue() const; //calculate and show hand value
    void clearHand(); //should be obvious :)

};

#endif