#ifndef MA3_CARD_H
#define MA3_CARD_H

#include <string>
#include <iostream>

using namespace std;

class Card {
private:
    string m_suit;
    string m_rank;
    int m_value;

public:
    Card();
    Card(const string &suit, const string &rank, const int &value);

    string getRank();
    string getSuit();
    int getValue();
    void setValue(int value);
    //string getCard();

    // Operator Overloading
    bool operator==(const Card& other) const;

    // Friend function
    friend ostream& operator<<(ostream& os, const Card& card);
};

#endif // MA3_CARD_H