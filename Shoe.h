#ifndef SHOE_H
#define SHOE_H

#include <vector>
#include "Deck.h"

using namespace std;

// Shoe = multiple decks combined into one pile.

class Shoe {
private:
    int numDecks;
    vector<Deck> decks;         
    vector<Card> shoeCards;
    int startingCardCount;     
    int cutCard;   
    bool final = false;           

public:
    Shoe();
    Shoe(int numDecks); 

    void buildShoe(int numDecks);
    void setCutCard();
    int getCutCard();
    void shuffleShoe(); 
    Card dealCard();

    int cardsRemaining();
    int decksInShoe();
};

#endif
