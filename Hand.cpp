#include "Hand.h"

#include <iostream>

using namespace std;

Hand::Hand(){};

void Hand::clearHand() {
    m_hand.clear();
};

void Hand::operator+=(Card card){
    m_hand.push_back(card);
}

Card Hand::getCard(int index) {
    return  m_hand[index];
}

vector<Card> Hand::getCards() {
    return  m_hand;
}

int Hand::cardCount() {
    return m_hand.size();
}

int Hand::getPoints(){
    int total;
    vector<Card*> softAces;

    do {
        softAces.clear();
        total = 0;

        for (int i = 0; i < m_hand.size(); i++){
            if (m_hand[i].getValue() == 11){
                softAces.push_back(&m_hand[i]);
            }

            total += m_hand[i].getValue();
        }

        if (softAces.size() > 0 && total > 21) {
            softAces[0]->setValue(1);
        } else  if (total <=21) {
            break;
        }
    } while (softAces.size() != 0);

    return total;
}

bool Hand::isSoft17() {
    int total = 0;
    int aceCount = 0;

    for (Card& cd : m_hand) {
        if (cd.getRank() == "Ace") {
            total += 11;
            aceCount++;
        } else {
            total += cd.getValue();
        }
    }

    // reduce aces from 11 to 1
    while (total > 21 && aceCount > 0) {
        total -= 10;
        aceCount--;
    }

    return (total == 17 && aceCount > 0);
}

bool Hand::isBlackjack() {
    if (cardCount() == 2 && getPoints() == 21) {
        return true;
    } else {
        return false;
    }
}

ostream& operator<<(ostream& os, Hand& hand) {
    for (int i = 0; i< hand.cardCount(); i++) {
        Card card = hand.getCard(i);

        os << card.getRank() << " of " << card.getSuit()<<endl;
    }
    return os;
};