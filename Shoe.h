#ifndef SHOE_H
#define SHOE_H

#include <vector>
#include "Deck.h"

// Shoe = multiple decks combined into one pile.
// According from looking online Blackjack commonly uses 2, 4, 6, or 8 decks.

class Shoe {
private:
    int numDecks;
    std::vector<Deck> decks;         // All decks
    std::vector<Card> shoeCards;     // All cards from all decks merged
    int nextCardIndex;               // Dealing pointer

public:
    Shoe(int numDecks = 4); // Default = 4-deck shoe Maybe add something that can change this later?

    void buildShoe();
    void shuffle(); // Shuffle cards together
    Card dealCard(); // Deal from shoe

    int cardsRemaining() const;
    int decksInShoe() const { return numDecks; }
};

#endif
