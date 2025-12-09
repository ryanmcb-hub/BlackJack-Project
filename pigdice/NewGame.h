#ifndef NEWGAME_H
#define NEWGAME_H
#include <string>
#include "Game.h"
#include "Turn.h"

class NewGame : public Game {

private:
    std::string m_playersName[2];
    Turn m_playerTurn[2];
    int m_playerScore[2];
    bool m_gameOver;
    bool m_tog;

public:
    NewGame();
    ~NewGame();
    void display_rules();
    void play_game();

};

#endif //NEWGAME_H
