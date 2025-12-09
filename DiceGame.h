#ifndef DICEGAME_H
#define DICEGAME_H

#include "Game.h"


using namespace std;
class DiceGame : public Game {
protected:
    int m_numDecks;        

public:
    DiceGame(string name);
    DiceGame(string name, int dice);
    DiceGame(string name, int dice, int players);

    void playGame() override;
};

#endif 