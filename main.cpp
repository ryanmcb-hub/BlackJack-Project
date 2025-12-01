#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Shoe.h"

int main() {
    std::cout << "--- Test ---" << std::endl;

    // Basic Card operations | operator overloading and friend function|
    std::cout << "\n1. cards test:" << std::endl;
    Card card1("Hearts", "Ace", 11);
    Card card2("Hearts", "Ace", 11);
    Card card3("Spades", "King", 10);

    std::cout << "Card 1: " << card1 << std::endl;  // Using friend operator
    std::cout << "Card 2: " << card2 << std::endl;
    std::cout << "Card 3: " << card3 << std::endl;

    std::cout << "Card1 == Card2: " << (card1 == card2) << std::endl;  // Using operator
    std::cout << "Card1 == Card3: " << (card1 == card3) << std::endl;

    //  Deck card counts
    std::cout << "\n2. Tdeck test:" << std::endl;
    Deck deck;
    std::cout << "Total cards in a deck: " << deck.cardsRemaining() << std::endl;

    // Draw a few cards
    std::cout << "Drawing 5 cards..." << std::endl;
    for (int i = 0; i < 5; i++) {
        Card drawnCard = deck.dealCard();
        std::cout << "  Drew: " << drawnCard << std::endl;
    }
    std::cout << "Cards remaining in deck: " << deck.cardsRemaining() << std::endl;

    // Shoe with multiple decks
    std::cout << "\n3. shoe test:" << std::endl;
    Shoe shoe4(4);  // 4-deck shoe
    std::cout << "Total cards in 4-deck shoe: " << shoe4.cardsRemaining() << std::endl;

    // Draw some cards from shoe
    std::cout << "Drawing 10 cards from shoe..." << std::endl;
    for (int i = 0; i < 10; i++) {
        Card drawnCard = shoe4.dealCard();
        std::cout << "  Card " << (i+1) << ": " << drawnCard << std::endl;
    }
    std::cout << "Cards remaining in shoe: " << shoe4.cardsRemaining() << std::endl;

    // Different shoe sizes
    std::cout << "\n4. shoe size:" << std::endl;
    Shoe shoe2(2);
    Shoe shoe6(6);
    Shoe shoe8(8);

    std::cout << "2-deck shoe: " << shoe2.cardsRemaining() << " cards" << std::endl;
    std::cout << "6-deck shoe: " << shoe6.cardsRemaining() << " cards" << std::endl;
    std::cout << "8-deck shoe: " << shoe8.cardsRemaining() << " cards" << std::endl;

    std::cout << "\n--- done ---" << std::endl;

    return 0;
}