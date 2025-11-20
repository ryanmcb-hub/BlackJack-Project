#include <iostream>
#include "Shoe.h"

int main() {


    Shoe shoe;      // should build a 4-deck shoe Shoe(int numDecks = 4) in shoe.h
    shoe.shuffle(); // Shuffle should be 208 cards

    std::cout << "Decks in shoe: "
              << shoe.decksInShoe() << "\n";

    std::cout << "Total cards: "
              << shoe.cardsRemaining() << "\n\n";

    // Deal a few cards just to test functionality
    for (int i = 0; i < 10; i++) {
        Card c = shoe.dealCard();
        std::cout << c.getCard()
                  << " (value = " << c.getValue() << ")\n";
    }

    std::cout << "\nCards remaining: "
              << shoe.cardsRemaining() << "\n";

    return 0;
}
