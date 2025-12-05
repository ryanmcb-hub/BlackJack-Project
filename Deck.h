#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

using namespace std;

// Deck = A standard set of 52 cards.
class Deck {
private:
    vector<Card> m_cards; // 52 cards

public:
    Deck();
    void shuffleDeck(); // Randomize
    Card dealCard(); // Deal one
    int cardsRemaining();

    // Shoe needs access to the full deck
    vector<Card>& getCards(); // for shoe to read cards
};

#endif
