#include "Blackjack.h"
#include "Player.h"
#include "Shoe.h"

#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

Blackjack::Blackjack(string name) : CardGame(name) {
    m_numDecks = 6;

    m_shoe = Shoe(m_numDecks);

    cout << "Shoe Size: " << m_shoe.cardsRemaining() << endl;
    cout << "Cut Card: " << m_shoe.getCutCard() << endl;
}

Blackjack::Blackjack(string name, int decks) : CardGame(name, decks) {
    m_shoe = Shoe(m_numDecks);
}

Blackjack::Blackjack(string name, int decks, int numPlayers) : CardGame(name, numPlayers, decks) {
    m_shoe = Shoe(m_numDecks);
}

void Blackjack::dealHands(){
    for (int c = 0; c < 2; c++){
        if (c == 0) {
            cout << "Dealing First Card" << endl;
        } else {
            cout << "Dealing Second Card" << endl;
        }
    
        m_dealer.getHand()+=m_shoe.dealCard();


        for (int p = 0; p < m_playerCount; p++) {
            m_players[p].getHand()+=m_shoe.dealCard();
          
            cout << m_players[p].getName() << "'s Cards: " << m_players[p].getHand().cardCount() << endl;
        }
    }   
};

vector<int> Blackjack::checkBlackjacks() {
    vector<int> noBlackjack;

    for (int p = 0; p < m_playerCount; p++) {
        if (m_players[p].getHand().isBlackjack()) {
            float winning;
            float bet = m_players[p].getBet();

            cout << m_players[p].getName() << " Has A Blackjack!" << endl;
            cout << endl << m_players[p].getHand() << endl;
            winning = bet + (bet * 1.5);
            cout << endl << "They Won $" << winning << endl;
            m_players[p] += winning;
        } else {
            noBlackjack.push_back(p);
        }
    }

    bool dealerBlackjack = m_dealer.getHand().isBlackjack();

    if (dealerBlackjack){
        cout << "Dealer Has A Blackjack" << endl;
        for (int p = 0; p < noBlackjack.size(); p++) {
            cout << m_players[noBlackjack[p]].getName() << " Lost Their Bet" << endl;
        }

    }

    return dealerBlackjack ? vector<int>() : noBlackjack;

}

void Blackjack::playGame() {
    char again;

    do
    {
        cout << endl;
        cout << "#######################################################" << endl;
        printGameTitle();
        cout << "#######################################################" << endl;
        cout << endl;
        do
        {
            // Get Bets
            for ( int p = 0; p < m_playerCount; p++) {
                m_players[p].getHand().clearHand();

                int bet;
                do
                {
                    cout << m_players[p].getName() << " Place A Bet (Balance: $" << m_players[p].getBalance() << "): $";
                    cin >> bet;

                    if (cin.fail() || bet < 25 || bet > m_players[p].getBalance())
                    {
                        if (bet > m_players[p].getBalance()){
                            cout << "Bet Too High. Be Less Broke!" << endl;
                        } else {
                            cout << "Bet Must Be A Whole Number Greater Than $25" << endl;
                        }

                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (cin.fail() || bet < 25 || bet > m_players[p].getBalance());

                m_players[p].setBet(bet);
            }

            cout << endl << "Betting Is Closed!" << endl << endl;

            m_dealer.getHand().clearHand();
            dealHands();

            vector<int> continuingPlayerIndexs = checkBlackjacks();

            vector<int> standingPlayers;

            for (int c = 0; c < continuingPlayerIndexs.size(); c++) {
                Player* player = &m_players[continuingPlayerIndexs[c]];

                cout << player->getName() << "'s Turn!" << endl << endl;

                char action;

                do{

                    m_dealer.showUpCard();

                    cout << player->getName() << "'s Cards:" << endl;
                    cout << player->getHand() << endl;

                    do {
                        cout << "Hit or Stand (h or s): ";
                        cin >> action;

                        action = tolower(action);

                        if (cin.fail() || (action != 'h' && action != 's')){
                            cout << "Invalid Option. Enter 'h' or 's'" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    } while (cin.fail() || (action != 'h' && action != 's'));

                    if (action == 'h'){
                        player->getHand()+=(m_shoe.dealCard());
                    }

                } while (!(player->isBusted()) && action != 's');

                if (player -> isBusted()){
                    cout << endl << player->getName() << "'s Cards:" << endl;
                    cout << player->getHand() << endl;

                    cout << player->getName() << " Busted With A Score Of " << player->getHand().getPoints() << "!" << endl;

                    player-> operator-=(player -> getBet());
                } else {
                    standingPlayers.push_back(continuingPlayerIndexs[c]);
                }
            }

            if (!standingPlayers.empty()) {
                m_dealer.play(m_shoe);

                int dealerPoints = m_dealer.getHand().getPoints();
                bool dealerBust = m_dealer.isBusted();

                for (int idx : standingPlayers) {
                    Player* player = &m_players[idx];
                    int playerPoints = player->getHand().getPoints();
                    int bet = player->getBet();

                    cout << endl << player->getName() << " has " << playerPoints << " points. ";

                    if (dealerBust) {
                        cout << "Dealer busted — " << player->getName() << " wins $" << bet << "!" << endl;
                        player->operator+=(bet);
                    } else if (playerPoints > dealerPoints) {
                        cout << player->getName() << " beats dealer (" << dealerPoints << ") — wins $" << bet << "!" << endl;
                        player->operator+=(bet);
                    } else if (playerPoints < dealerPoints) {
                        cout << player->getName() << " loses to dealer (" << dealerPoints << ") — loses $" << bet << "!" << endl;
                        player->operator-=(bet);
                    } else {
                        cout << player->getName() << " pushes with dealer (" << dealerPoints << ") — push, bet returned." << endl;
                        // push = no balance change
                    }
                }
            }
            
            cout << endl << "Play Again? (y/n): ";
            cin >> again;

            again = tolower(again);

            if (again != 'y' && again != 'n')
            {
                cout << "Invalid input. Please enter 'y' or 'n'." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (again != 'y' && again != 'n');
    } while (again != 'n');
};
