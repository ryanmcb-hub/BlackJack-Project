#include "Deck.h"
#include <algorithm>
#include <random>

using namespace std;

// 52-card deck
Deck::Deck() { //Starts with the top card index at 0.
    vector<string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
    vector<string> ranks = {
        "Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"
    };

    // Blackjack values corresponding to the rank index
    vector<int> values = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

    // Create all 52 cards by pairing each suit with each rank
    for (const auto& s : suits)
        for (int i = 0; i < ranks.size(); i++)
            m_cards.emplace_back(s, ranks[i], values[i]);
}

// Shuffle the deck using Mersenne Twister
void Deck::shuffleDeck() {
    random_device rd;
    mt19937 rng(rd());
    shuffle(m_cards.begin(), m_cards.end(), rng);
}

// Deal one card and move the index forward
Card Deck::dealCard() {
    Card top = m_cards.back();
    m_cards.pop_back();

    return top;
}

int Deck::cardsRemaining() {
    return m_cards.size();
}

vector<Card>& Deck::getCards() {
    return m_cards;
}
