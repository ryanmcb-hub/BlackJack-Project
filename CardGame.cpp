#include "CardGame.h"
#include <string>
#include <iostream>

CardGame::CardGame(string name) : Game(name) {
    m_numDecks = 1;
};

CardGame::CardGame(string name, int decks) : Game(name) {
    m_numDecks = decks;
};

CardGame::CardGame(string name, int players, int decks) : Game(name, players) {
    m_numDecks = decks;
};

void CardGame::playGame() {

};

void CardGame::dealHands() {

};
