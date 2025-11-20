#include "Shoe.h"
#include <algorithm>
#include <random>

//Build shoe
Shoe::Shoe(int numDecks)
        : numDecks(numDecks), nextCardIndex(0) {
    buildShoe();
}

// Build all decks, shove cards into shoeCards
void Shoe::buildShoe() {
    decks.clear();
    shoeCards.clear();
    nextCardIndex = 0;

    // Build the decks
    for (int i = 0; i < numDecks; i++)
        decks.emplace_back();

    // Copy all deck cards into one big list
    for (auto& d : decks)
        for (const Card& c : d.getCards())
            shoeCards.push_back(c);
}

// Shuffle all cards in the shoe together
void Shoe::shuffle() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(shoeCards.begin(), shoeCards.end(), rng);
    nextCardIndex = 0;
}

Card Shoe::dealCard() {
    return shoeCards[nextCardIndex++];
}

int Shoe::cardsRemaining() const {
    return shoeCards.size() - nextCardIndex;
}
