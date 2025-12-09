#include "Casino.h"
#include "Game.h"
#include "Blackjack.h"
#include "Slots.h"
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "pigdice/NewGame.h"


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
        cout << "2. Pigdice of Perdition" << endl; 
        cout << "3. Slot Machine Of Sadness" << endl;
        cout << "4. Easy Way Out\n" << endl;
        cout << "Please select a game: ";
        cin >> selected;

        if (cin.fail() || (selected != 1 && selected != 2 && selected != 3 && selected != 4))
        {
            cout << "Invalid input. Please enter a number between 1 and 4." << endl << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (selected != 1 && selected != 2 && selected != 3 && selected != 4);
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
            //cout << "Pig Dice of Perdition\n" << endl;
            activeGame = new NewGame();
        } else if (selectedGame == 3) {
            activeGame = new Slots("Slot Machine Of Sadness");

        } else if (selectedGame == 4) {
            displayExit();
            
            break;
        }

        activeGame -> playGame();

    } while (selectedGame != 3);
};


