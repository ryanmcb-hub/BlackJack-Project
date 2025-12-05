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

    Shoe::setCutCard();
}

Shoe::Shoe(int numDecks) {
    decks.clear();
    shoeCards.clear();

    // Build the decks
    for (int i = 0; i < numDecks; i++)
        decks.emplace_back();

    // Copy all deck cards into one big list
    for (auto& d : decks)
        for (Card& c : d.getCards())
            shoeCards.emplace_back(c);

    Shoe::shuffleShoe();

    startingCardCount = shoeCards.size();

    Shoe::setCutCard();
}

// Shuffle all cards in the shoe together
void Shoe::shuffleShoe() {
    random_device rd;
    mt19937 rng(rd());
    shuffle(shoeCards.begin(), shoeCards.end(), rng);
}

Card Shoe::dealCard() {
    if (shoeCards.size() == cutCard){
        final = true;

        cout<<endl<<"Cut Card Reached"<<endl<<endl;
    }

    Card top = shoeCards.back();
    shoeCards.pop_back();

    cutCard--; // Decreases Cut Card Index As Cards Are Dealt

    return top;
}

int Shoe::cardsRemaining() {
    return shoeCards.size();
}

void Shoe::setCutCard() {
    int seventyFive = static_cast<size_t>(floor(shoeCards.size() * 0.75));
    int eightyFive = static_cast<size_t>(floor(shoeCards.size() * 0.85));

    random_device rd;
    mt19937 gen(rd());
    
    uniform_int_distribution<> distrib(seventyFive, eightyFive);

    cutCard = distrib(gen);
}

int Shoe::getCutCard() {
    return cutCard;
}
