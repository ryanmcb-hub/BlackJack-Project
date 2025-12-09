#ifndef TURN_H
#define TURN_H
#include "Die.h"

class Turn {

private:
    Die m_myDie;
    char m_choice;
    int m_score_this_turn;
    int m_turn_count;
    bool m_turn_over;

public:
    Turn();
    void reset_turn_over();
    bool get_turn_over();
    void reset_score_this_turn();
    int get_score_this_turn();
    void set_turn_count();
    int get_turn_count();
    void take_turn();
//private:
    void roll();
    void set_die_sides(int S);
};

#endif //TURN_H
