#ifndef PIGDICE_H
#define PIGDICE_H
#include "Die.h"
#include "DiceGame.h"

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

class PigDiceTurn {

private:
    Die m_myDie;
    char m_choice;
    int m_scoreThisTurn;
    int m_turnCount;
    bool m_turnOver;

public:
    PigDiceTurn();
    void reset_turn_over();
    bool get_turn_over();
    void reset_score_this_turn();
    int get_score_this_turn();
    void set_turn_count();
    int get_turn_count();
    void take_turn();
    void roll();
    void set_die_sides(int S);
};

class PigDice : public DiceGame {

protected:
    vector<PigDiceTurn> m_turns;
    //Die m_myDie;
    vector<int> m_scores;
    bool m_gameOver;

public:
    PigDice(string name);
    PigDice(string name, int dice);
    PigDice(string name, int dice, int players);
    void set_over();
    bool reset_over();
    void displayRules() override;
    void playGame() override;
};

#endif
