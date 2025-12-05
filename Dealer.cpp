#include "Dealer.h"
#include "Player.h"
#include <iostream>

using namespace std;

Dealer::Dealer() : Player("Dealer") {}

void Dealer::showUpCard() {
    if (m_hand.cardCount() == 0) {
        cout << "Dealer has no cards." << endl;
        return;
    }

    cout << "Dealer's visible card: " <<endl<< m_hand.getCard(0) << endl <<endl;
}
