#include "Game.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

Game::Game(string name) {
    m_gameName = name;

    int players;
    do {
        cout << endl << "How Many Players: ";
        cin >> players;

        if (cin.fail() || players < 1) {
            cout << "Invalid input. Please enter a number greater than 1." << endl<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (players < 1);

    m_playerCount = players;

    for (int i = 0; i < m_playerCount; i++) {
        m_players.push_back(Player());
    }
}

Game::Game(string name, int numPlayers) {
    m_gameName = name;
    m_playerCount = numPlayers;

    if (m_playerCount == 1) {
        if (name == "The Game"){
            m_players.push_back(Player("User"));
        } else {
            cout << endl << "Single Player Only Game" << endl;

            m_players.push_back(Player());
        }
    } else {
        for (int i = 0; i < m_playerCount; i++) {
            m_players.push_back(Player());
        }
    }
}

void Game::playGame(){
    cout << endl << "Congrats " << m_players[0].getName() << " You Have Lost 'The Game'"<<endl;
};

void Game::displayRules() {
    cout << "This is The Game" << endl << endl;
}

void Game::printGameTitle() {
    cout << "#  You Have Joined The " << m_gameName << "  #" << endl;
}
