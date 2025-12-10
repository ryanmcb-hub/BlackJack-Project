#include "Player.h"

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

//default constructor that prompts for player name
Player::Player() {
    string name;

    cout << "Enter player name: ";

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

void Player::win(bool blackjack) {
    m_winnings = 0;
    m_losses = 0;

    if (blackjack) {
        m_winnings += m_currentBet * 1.5;
    } else {
        m_winnings += m_currentBet;
    }

    m_balance += m_winnings;
    
    saveBalance();
}

void Player::lose() {
    m_winnings = 0;
    m_losses = 0;

    m_losses += m_currentBet;
    m_balance -= m_losses;

    saveBalance();
}

void Player::takeTurn(Card dealerUpCard, Shoe* shoe) {
    cout << m_name << "'s Turn!" << endl;

    m_winnings = 0;
    m_losses = 0;

    int action;

    do{
        cout << endl << "Dealer's Up Card: " << endl << dealerUpCard << endl <<endl;

        cout<<m_name<<"'s Cards:"<<endl;
        cout<<m_hand<<endl;

        do {
            cout << "1. Hit" << endl;
            cout << "2. Double" << endl;
            cout << "3. Stand" << endl;
            cout << "Choice: ";
            cin >> action;

            if (cin.fail() || (action != 1 && action != 2 && action != 3)){
                cout << "Invalid Option. Enter A Number Between 1 and 3" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (cin.fail() || (action != 1 && action != 2 && action != 3));

        if (action == 1){
            m_hand+=(shoe -> dealCard());
        } else if (action == 2){
            m_currentBet *= 2;
            m_hand+=(shoe -> dealCard());

            cout<<"Bet: "<<m_currentBet<<endl;
        }
    } while (!(isBusted()) && action != 2 && action != 3);

    cout << endl << m_name << "'s Cards:" << endl;
    cout << m_hand << endl;

    if (isBusted()){
        cout << m_name << " Busted With A Score Of " << m_hand.getPoints() << "!" << endl;

        lose();
    }
}

int Player::getScore() {
    return m_score;
}

void Player::setScore(int points) {
    m_score = points;
}

int Player::getPoints() {
    return m_hand.getPoints();
}

double Player::getWinnings() {
    return m_winnings;
}

double Player::getLosses() {
    return m_losses;
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