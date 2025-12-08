#ifndef GAME_H
#define GAME_H
//#include "Die.h"
#include "Turn.h"

class Game {

protected:
    Turn m_myTurn;
    //Die m_myDie;
    int m_game_score;
    bool m_game_over;

public:
    Game();
    void set_game_score();
    int get_game_score();
    void set_game_over();
    bool reset_game_over();
    void display_rules();
    virtual void play_game();
    //void set_sides();
};

#endif //GAME_H
