#include "Dealer.h"
#include "Player.h"
#include <iostream>

using namespace std;

// Dealer::Dealer() : Player::Player("Dealer") {}

void Dealer::showCard() const {
    if (m_hand.empty()) {
        cout << "Dealer has no cards." << endl;
        return;
    }

    const Card& card = m_hand.front();
    cout << "Dealer's visible card: " << card.getRank() << " of " << card.getSuit() << endl;
}
