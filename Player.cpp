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

void Player::win(bool blackjack) {
    if (blackjack) {
        m_winnings += m_currentBet * 1.5;
    } else {
        m_winnings += m_currentBet;
    }

    m_balance += m_winnings;
}

void Player::lose() {
    m_losses -= m_currentBet;
    
    m_balance -= m_losses;
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
    return m_hand.getPoints();
}

double Player::getWinnings() {
    return m_winnings;
}

double Player::getLosses() {
    return m_losses;
}

void Player::operator+=(double amount) {
    m_balance += amount;
}

void Player::operator-=(double amount) {
    m_balance -= amount;
}