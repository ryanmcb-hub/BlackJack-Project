#ifndef MA3_CARD_H
#define MA3_CARD_H

#include <string>
#include <iostream>

class Card {
private:
    std::string m_suit;
    std::string m_rank;
    int m_value;

public:
    Card();
    Card(const std::string &suit, const std::string &rank, const int &value);

    std::string getRank() const;
    std::string getSuit() const;
    int getValue() const;
    void setValue(int value);
    std::string getCard() const;

    // Operator Overloading
    bool operator==(const Card& other) const;

    // Friend function
    friend std::ostream& operator<<(std::ostream& os, const Card& card);
};

#endif // MA3_CARD_H