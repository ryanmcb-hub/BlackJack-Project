#include "CardGame.h"
#include <string>
#include <iostream>

using namespace std;

CardGame::CardGame(string name) : Game(name) {
    m_numDecks = 1;
};

CardGame::CardGame(string name, int decks) : Game(name) {
    m_numDecks = decks;
};

CardGame::CardGame(string name, int decks, int players) : Game(name, players) {
    m_numDecks = decks;
};

void CardGame::playGame() {

};

void CardGame::displayRules() {
    cout << "This is a default Card Game" << endl;
    cout << "You should not be here" << endl << endl;
}

void CardGame::dealHands() {

};
