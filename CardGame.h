#ifndef CARDGAME_H
#define CARDGAME_H

#include "Game.h"
#include <string>
#include <vector>

using namespace std;
class CardGame : public Game {
protected:
    int m_numDecks;        

public:
    CardGame(string name);
    CardGame(string name, int decks);
    CardGame(string name, int decks, int players);

    void playGame() override;
    void displayRules() override;
    void virtual dealHands();
};

#endif 