#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

// Deck = A standard set of 52 cards.
class Deck {
private:
    std::vector<Card> m_cards; // 52 cards
    int nextCardIndex; //card to deal

public:
    Deck();
    void shuffle(); // Randomize
    Card dealCard(); // Deal one
    int cardsRemaining() const;

    // Shoe needs access to the full deck
    const std::vector<Card>& getCards() const; // for shoe to read cards
};

#endif
