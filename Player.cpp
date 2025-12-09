#include "Player.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

//default constructor that prompts for player name
Player::Player() {
    string name;

    cout<<"Enter player name: ";

    // Checks for whitespace and ignores
    if (cin.peek() == '\n') {
        cin.ignore();
    }

    getline(cin, name);

    m_name = name;
    loadBalance(m_name);
}

Player::Player(string name) : m_name(name) {
    loadBalance(m_name);
}

Player::~Player() {

}

string Player::getName() {
    return m_name;
}

void Player::printName() {
    cout << m_name << endl;
}

void Player::setBet(double bet) {
    m_currentBet = bet;
}

int Player::getBet() {
    return m_currentBet;
}

double Player::getBalance(){
    return m_balance;
}

Hand& Player::getHand() {
    return m_hand;
}

bool Player::isBusted() {
    return m_hand.getPoints() > 21;
}

void Player::operator+=(double winnings) {
    m_balance += winnings;
    saveBalance();
}

void Player::operator-=(double bet) {
    m_balance -= bet;
    saveBalance();
}

void Player::loadBalance(const string& name) {
    std::ifstream inputFile("balances.txt");
    if (!inputFile.is_open()) {
        //file doesn't exist yet; keep default balance
        return;
    }

    string line;
    while (std::getline(inputFile, line)) {
        if (line.empty()) continue;

        //format is <name> <balance>

        size_t pos = line.find_last_of(' ');
        if (pos == string::npos) continue;
        string playerName = line.substr(0, pos);
        string balanceStr = line.substr(pos + 1);

        try {
            //convert the balance string to the double balanceStr
            double bal = std::stod(balanceStr);

            if (playerName == name) {
                m_balance = bal;
                inputFile.close();
                return;
            }

        } catch (...) {
            continue;
        }
    }

    inputFile.close();
}

void Player::saveBalance() {
    //map entries and add current player's balance

    std::map<string, double> entries;
    std::ifstream inputFile("balances.txt");
    if (inputFile.is_open()) {
        string line;

        //check all existing entries and load them into the map
        while (std::getline(inputFile, line)) {
            if (line.empty()) continue;
            size_t pos = line.find_last_of(' ');
            if (pos == string::npos) continue;
            string playerName = line.substr(0, pos);
            string balanceStr = line.substr(pos + 1);

            try {
                double bal = std::stod(balanceStr);
                entries[playerName] = bal;
            } catch (...) {
                continue;
            }
        }
        inputFile.close();
    }

    entries[m_name] = m_balance;

    //write all entries back to balances.txt, overwrite it if neccessary (ios::trunc)
    std::ofstream outputFile("balances.txt", std::ios::trunc);
    if (!outputFile.is_open()) {
        std::cerr << "Unable to open balances.txtl!" << std::endl;
        return;
    }

    for (const auto& kv : entries) {
        outputFile << kv.first << " " << kv.second << '\n';
    }

    outputFile.close();
}