#include "Deck.h"
#include <algorithm>
#include <random>

// 52-card deck
Deck::Deck() : nextCardIndex(0) { //Starts with the top card index at 0.
    static std::vector<std::string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
    static std::vector<std::string> ranks = {
        "Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"
    };

    // Blackjack values corresponding to the rank index
    static std::vector<int> values = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

    // Create all 52 cards by pairing each suit with each rank
    for (const auto& s : suits)
        for (int i = 0; i < ranks.size(); i++)
            m_cards.emplace_back(s, ranks[i], values[i]);
}

// Shuffle the deck using Mersenne Twister
void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(m_cards.begin(), m_cards.end(), rng);
    nextCardIndex = 0;
}

// Deal one card and move the index forward
Card Deck::dealCard() {
    return m_cards[nextCardIndex++];
}

int Deck::cardsRemaining() const {
    return m_cards.size() - nextCardIndex;
}

const std::vector<Card>& Deck::getCards() const {
    return m_cards;
}
