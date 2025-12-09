#include "Dealer.h"
#include <iostream>

using namespace std;

Dealer::Dealer() : Player("Dealer") {};

void Dealer::showUpCard() {
    if (m_hand.cardCount() == 0) {
        cout << "Dealer has no cards." << endl;
        return;
    }

    cout << "Dealer's visible card: " << endl << m_hand.getCard(0) << endl <<endl;
}

void Dealer::play(Shoe& shoe) {
    if (m_hand.cardCount() == 0) {
        cout << "Dealer has no cards to play." << endl;
        return;
    }

    cout << "Dealer reveals hole card:" << endl;
    cout << m_hand << endl;

    int points = m_hand.getPoints();

    while (points < 17 || (points == 17 && m_hitSoft17 && m_hand.isSoft17())) {
        Card c = shoe.dealCard();
        m_hand += c;
        points = m_hand.getPoints();
        cout << "Dealer hits: " << c << " (Total: " << points << ")" << endl;
    }

    if (m_hand.getPoints() >= 17 && m_hand.getPoints() <= 21) {
        cout << "Dealer stands with " << m_hand.getPoints() << " points." << endl;
    } else if (m_hand.getPoints() > 21) {
        cout << "Dealer busts with " << m_hand.getPoints() << " points." << endl;
    }
}

void Dealer::takeTurn(Shoe* shoe){
    while (m_hand.getPoints() <= 16 || (m_hand.getPoints() == 17 && m_hand.isSoft())) {
        m_hand+=shoe->dealCard();
    };

    cout << "Dealer Cards: " << endl;
    cout<< m_hand << endl;
}
