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
        m_dealer.getHand()+=m_shoe.dealCard();


        for (int p = 0; p < m_playerCount; p++) {
            m_players[p].getHand()+=m_shoe.dealCard();
        }
    }   
};

vector<Player*> Blackjack::checkBlackjacks(vector<Player*>* winners, vector<Player*>* losers) {
    vector<Player*> noBlackjack;

    for (int p = 0; p < m_playerCount; p++) {
        Player* player = &m_players[p];
        if (player -> getHand().isBlackjack()) {
            float winning;
            float bet = player -> getBet();

            cout<<player -> getName()<<" Has Blackjack!"<<endl;

            player -> win(true);
            winners->push_back(player);
        } else {
            noBlackjack.push_back(player);
        }
    }

    bool dealerBlackjack = m_dealer.getHand().isBlackjack();

    if (dealerBlackjack){
        cout<<"Dealer Has Blackjack"<<endl;
       
        losers -> insert(losers -> end(), noBlackjack.begin(), noBlackjack.end());
    }

    return dealerBlackjack ? vector<Player*>() : noBlackjack;

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

            vector<Player*> wins;
            vector<Player*> loses;
            vector<Player*> pushes;

            vector<Player*> continuingPlayerIndexs = checkBlackjacks(&wins, &loses);

            vector<int> standingPlayers;

            for (int c = 0; c < continuingPlayerIndexs.size(); c++) {
                continuingPlayerIndexs[c] -> takeTurn(m_dealer.getUpCard(), &m_shoe);

                if (continuingPlayerIndexs[c] -> isBusted()){
                    continuingPlayerIndexs.erase(continuingPlayerIndexs.begin() + c);
                }
            }

            if (continuingPlayerIndexs.size() > 0) {
                m_dealer.takeTurn(&m_shoe);

                for (int o = 0; o < continuingPlayerIndexs.size(); o++) {
                    continuingPlayerIndexs[o];

                    if (m_dealer.isBusted() || m_dealer.getScore() < continuingPlayerIndexs[o] -> getScore()) {
                        wins.push_back(continuingPlayerIndexs[o]);

                        continuingPlayerIndexs[o] -> win(false);
                    } else if (m_dealer.getScore() > continuingPlayerIndexs[o] -> getScore()) {
                        loses.push_back(continuingPlayerIndexs[o]);
                    } else {
                        pushes.push_back(continuingPlayerIndexs[o]);
                    }
                }

                for (int e = 0; e < m_players.size(); e++) {
                    Player* player = &m_players[e];
                    bool won = find(wins.begin(), wins.end(), player) != wins.end();
                    bool lost = find(loses.begin(), loses.end(), player) != loses.end();
                    bool push = find(pushes.begin(), pushes.end(), player) != pushes.end();

                    if (won) {
                        cout<<player -> getName()<<" Won $" << player -> getWinnings()<<endl;
                    } else if (lost) {
                        player -> lose();

                        cout<<player -> getName()<<" Lost $" << player -> getLosses()<<endl;
                    } else if (push) {
                        cout << player -> getName() <<" Pushed" << endl;
                    } else {
                        cout<<player -> getName()<<" Broke The Game! Congrats!"<<endl;
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
