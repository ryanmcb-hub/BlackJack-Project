#include "Card.h"

using namespace std;

// Default constructor
Card::Card() {
    m_rank = "";
    m_suit = "";
    m_value = 0;
}

// Parameter constructor
Card::Card(const string &suit, const string &rank, const int &value) {
    m_suit = suit;
    m_rank = rank;
    m_value = value;
}

// Getters
string Card::getRank() {
    return m_rank;
}

string Card::getSuit() {
    return m_suit;
}

int Card::getValue() {
    return m_value;
}

// Setter
void Card::setValue(int value) {
    m_value = value;
}

// Returns text like "Ace of Hearts"
// string Card::showCard() const {
//     return m_rank + " of " + m_suit;
// }

// Operator Overloading
bool Card::operator==(const Card& other) const {
    return (m_rank == other.m_rank && m_suit == other.m_suit);
}

// Friend function
ostream& operator<<(ostream& os, const Card& card) {
    os << card.m_rank << " of " << card.m_suit;
    return os;
}