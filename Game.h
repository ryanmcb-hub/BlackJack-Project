#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include <vector>
#include <string>

using namespace std;

class Game {
protected:
    string m_gameName;
    int m_playerCount;
    vector<Player> m_players;
    
public:
    Game(string name);
    Game(string name, int numPlayers);

    void virtual playGame();
    void virtual displayRules();
    void printGameTitle();
};

#endif