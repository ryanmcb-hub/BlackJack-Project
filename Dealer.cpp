#include "Dealer.h"
#include <iostream>

using namespace std;

Dealer::Dealer() : Player("Dealer") {};

Card Dealer::getUpCard() {
    return m_hand.getCard(0);
}

void Dealer::showUpCard() {
    if (m_hand.cardCount() == 0) {
        cout << "Dealer has no cards." << endl;
        return;
    }

    cout << "Dealer's visible card: " << endl << m_hand.getCard(0) << endl <<endl;
}

void Dealer::takeTurn(Shoe* shoe){
    while (m_hand.getPoints() <= 16 || (m_hand.getPoints() == 17 && m_hand.isSoft())) {
        m_hand+=shoe->dealCard();
    };

    cout << "Dealer Cards: " << endl;
    cout<< m_hand << endl;
}
