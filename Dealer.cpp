#include "Dealer.h"
#include "Player.h"
#include <iostream>

void Dealer::showCard() const {
    if (m_hand.empty()) {
        std::cout << "Dealer has no cards." << std::endl;
        return;
    }

    const Card& card = m_hand.front();
    std::cout << "Dealer's visible card: " << card.getRank() << " of " << card.getSuit() << std::endl;
}
