#include "Card.h"

// Default blank card
Card::Card() : m_suit(""), m_rank(""), m_value(0) {}


// constructor
Card::Card(const std::string& suit, const std::string& rank, int value)
        : m_suit(suit), m_rank(rank), m_value(value) {}

std::string Card::getSuit() const { 
        return m_suit;
}

std::string Card::getRank() const { 
        return m_rank; 
}

int Card::getValue() const { return m_value; }

void Card::setValue(int value) { m_value = value; }

// card display (EX:"9 of Diamonds")
std::string Card::getCard() const {
    return m_rank + " of " + m_suit;
}
