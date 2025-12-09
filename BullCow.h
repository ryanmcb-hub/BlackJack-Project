#ifndef BULLCOW_H
#define BULLCOW_H

#include "Game.h"

using namespace std;
class BullCow : public Game {
private: 

public:
    BullCow(string name);
    BullCow(string name, int digits);

    void playGame() override;
};

#endif 