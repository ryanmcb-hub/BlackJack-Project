
#ifndef BLACKJACKTEST_CARD_H
#define BLACKJACKTEST_CARD_H

#include <string>

class Card {
private:
    std::string m_suit; // Hearts, Diamonds, Clubs, Spades
    std::string m_rank;  // Ace, 2–10, Jack, Queen, King
    int m_value; // Blackjack value (Ace=11 unless changed later)

public:
    Card(); //constructor
    Card(const std::string& suit, const std::string& rank, int value);

    //getters
    std::string getSuit() const;
    std::string getRank() const;
    int getValue() const;

    // Used if the game later changes Ace from 11 to 1
    void setValue(int value);


    std::string getCard() const; // Should be "Rank of Suit"
};

#endif
