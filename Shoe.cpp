#include "Shoe.h"
#include <algorithm>
#include <random>

using namespace std;

//Build shoe
Shoe::Shoe() {
    decks.clear();
    shoeCards.clear();

    // Build the decks
    for (int i = 0; i < 4; i++)
        decks.emplace_back();

    // Copy all deck cards into one big list
    for (auto& d : decks)
        for (const Card& c : d.getCards())
            shoeCards.push_back(c);

    Shoe::shuffleShoe();
}

Shoe::Shoe(int numDecks) {
    decks.clear();
    shoeCards.clear();

    // Build the decks
    for (int i = 0; i < numDecks; i++)
        decks.emplace_back();

    // Copy all deck cards into one big list
    for (auto& d : decks)
        for (const Card& c : d.getCards())
            shoeCards.push_back(c);

        
}

// Shuffle all cards in the shoe together
void Shoe::shuffleShoe() {
    random_device rd;
    mt19937 rng(rd());
    shuffle(shoeCards.begin(), shoeCards.end(), rng);
}

Card Shoe::dealCard() {
    Card top = shoeCards.back();
    shoeCards.pop_back();

    return top;
}

int Shoe::cardsRemaining() {
    return shoeCards.size();
}
