#include "Casino.h"
#include "Game.h"
#include "Blackjack.h"
#include "Slots.h"
#include "PigDice.h"
#include "BullCow.h"

#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

Casino::Casino(){};

void Casino::displayWelcome(int& selectedGame) {
    if (selectedGame == 0){
        cout << "##################################################" << endl;
        cout << "#  Welcome To Master Mcbride's Casino Of Horror  #" << endl;
        cout << "##################################################" << endl;
        cout << endl;
    } else {
        cout << endl;
        cout << "#######################################################" << endl;
        cout << "#  Welcome Back To Master Mcbride's Casino Of Horror  #" << endl;
        cout << "#######################################################" << endl;
        cout << endl;
    }
}

int Casino::gameMenu(){
    int selected;
    do
    {
        cout << "Supported Games Of Horror: " << endl;
        cout << "1. Blackjack Of Blashphamy" << endl;
        cout << "2. Pig Dice Of Purgatory" << endl; 
        cout << "3. Bull And Cow Of Cowardice" << endl; 
        cout << "4. Slot Machine Of Sadness" << endl;
        cout << "5. Easy Way Out\n" << endl;
        cout << "Please select a game: ";
        cin >> selected;

        if (cin.fail() || (selected != 1 && selected != 2 && selected != 3 && selected != 4 && selected != 5))
        {
            cout << "Invalid input. Please enter a number between 1 and 5." << endl << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (selected != 1 && selected != 2 && selected != 3 && selected != 4 && selected != 5);
    return selected;
} 

void Casino::displayExit() {
    cout << endl;
    cout << "##################################################" << endl;
    cout << "#  You Have Chosen To Exit The Casino Of Horror  #" << endl;
    cout << "#  I Always Knew You Were A Quitter!   Goodbye!  #" << endl;
    cout << "##################################################" << endl;
}

void Casino::openCasino() {
    int selectedGame = 0;
    Game* activeGame = new Game("The Game", 1); // By reading this comment, you have lost 'The Game'

    do {
        displayWelcome(selectedGame);

        selectedGame = gameMenu();

        if (selectedGame == 1) {
            activeGame = new Blackjack("Blackjack Table Of Blashphamy");

        } else if (selectedGame == 2) {
            activeGame = new PigDice("Pig Dice Of Purgatory");

        } else if (selectedGame == 3) {
            activeGame = new BullCow("Bull And Cow Of Cowardice");

        } else if (selectedGame == 4) {
            activeGame = new Slots("Slot Machine Of Sadness");

        } else if (selectedGame == 5) {
            displayExit();
            
            break;
        }

        activeGame -> displayRules();
        activeGame -> playGame();

    } while (selectedGame != 5);
};


