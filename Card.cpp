#include "Card.h"

// Default constructor
Card::Card() {
    m_rank = "";
    m_suit = "";
    m_value = 0;
}

// Parameter constructor
Card::Card(const std::string &suit, const std::string &rank, const int &value) {
    m_suit = suit;
    m_rank = rank;
    m_value = value;
}

// Getters
std::string Card::getRank() const {
    return m_rank;
}

std::string Card::getSuit() const {
    return m_suit;
}

int Card::getValue() const {
    return m_value;
}

// Setter
void Card::setValue(int value) {
    m_value = value;
}

// Returns text like "Ace of Hearts"
std::string Card::getCard() const {
    return m_rank + " of " + m_suit;
}

// Operator Overloading
bool Card::operator==(const Card& other) const {
    return (m_rank == other.m_rank && m_suit == other.m_suit);
}

// Friend function
std::ostream& operator<<(std::ostream& os, const Card& card) {
    os << card.m_rank << " of " << card.m_suit;
    return os;
}