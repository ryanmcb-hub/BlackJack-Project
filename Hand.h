#ifndef HAND_H
#define HAND_H

#include "Card.h"

#include <vector>

using namespace std;

class Hand
{
private:
    vector<Card> m_hand;
public:
    Hand();

    void clearHand();

    void operator+=(Card card);

    Card getCard(int index);
    vector<Card> getCards();

    int getPoints();

    bool isSoft17();

    bool isBlackjack();
    bool isSoft();

    int cardCount();

    friend ostream& operator<<(ostream& os, Hand& hand);
};

#endif