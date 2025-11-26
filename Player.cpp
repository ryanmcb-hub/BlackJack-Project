#include "Player.h"
#include <iostream>

Player::Player(const std::string& name) : m_name(name), m_balance(0.0) {

}

double Player::getBalance() {
    return m_balance;
}

void Player::addCard(const Card& card) {
    m_hand.push_back(card);
}

int Player::getHand() const {
    return m_hand.size();
}

void Player::showHandValue() const {
    int totalValue = 0;
    int aceCount = 0;

    for (const auto& card : m_hand) {
        totalValue += card.getValue();

        if (card.getRank() == "Ace") {
            aceCount++;
        }
    }

    while (totalValue > 21 && aceCount > 0) {
        totalValue -= 10;
        aceCount--;
    }
    
    std::cout << m_name << "'s hand value: " << totalValue << std::endl;
}
