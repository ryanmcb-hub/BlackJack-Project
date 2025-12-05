#include "Player.h"
#include <iostream>

using namespace std;

Player::Player() {
    string name;

    cout<<"Enter player name: ";

    // Checks for whitespace and ignores
    if (cin.peek() == '\n') {
        cin.ignore();
    }

    getline(cin, name);

    m_name = name;
}

Player::Player(string name) : m_name(name) {

}

Player::~Player() {

}

string Player::getName() {
    return m_name;
}

void Player::printName() {
    cout<<m_name<<endl;
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
}

void Player::operator-=(double bet) {
    m_balance -= bet;
}