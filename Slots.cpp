#include "Slots.h"

#include <iostream>

using namespace std;

Slots::Slots(string name) : Game (name, 1) {};

void Slots::playGame() {
    cout<<endl;
    cout<<"#################################################"<<endl;
    printGameTitle();
    cout<<"#################################################"<<endl;
    cout<<endl;

    cout<<"Error Detected! "<<m_players[0].getName()<<" Is Already Too Sad! Exiting To Main Menu."<<endl;
};