#include "DiceGame.h"
#include <string>
#include <iostream>

DiceGame::DiceGame(string name) : Game(name) {
};

DiceGame::DiceGame(string name, int dice) : Game(name) {
};

DiceGame::DiceGame(string name, int dice, int players) : Game(name, players) {
};

void DiceGame::playGame() {

};

void DiceGame::displayRules() {
    cout << "This is a default Dice Game" << endl;
    cout << "You should not be here" << endl << endl;
}