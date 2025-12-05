#ifndef CASINO_H
#define CASINO_H

#include <vector>
#include "Card.h"
#include "Shoe.h"
#include "Player.h"
#include "Dealer.h"

using namespace std;

class Casino {
public:
    Casino();
    void openCasino();

    void displayWelcome(int& selectedGame);
    void displayExit();
    int gameMenu();
};

#endif
