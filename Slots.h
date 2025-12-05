#ifndef SLOTS_H
#define SLOTS_H

#include "Game.h"
#include <vector>

using namespace std;

class Slots : public Game {
private:

public:
    Slots(string name);

    void playGame() override;
};

#endif