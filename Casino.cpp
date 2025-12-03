#include "Casino.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Casino::openCasino()
{
    int selectedGame = 0;

    do {
        if (selectedGame == 0){
            cout<<"##################################################"<<endl;
            cout<<"#  Welcome To Master Mcbride's Casino Of Horror  #"<<endl;
            cout<<"##################################################"<<endl;
            cout<<endl;
        } else {
            cout<<endl;
            cout<<"#######################################################"<<endl;
            cout<<"#  Welcome Back To Master Mcbride's Casino Of Horror  #"<<endl;
            cout<<"#######################################################"<<endl;
            cout<<endl;
        }

        do
        {
            cout<<"Supported Games Of Horror: "<<endl;
            cout<<"1. Blackjack Of Blashphamy"<<endl;
            cout<<"2. Slot Machine Of Sadness"<<endl;
            cout<<"3. Easy Way Out"<<endl;
            cout<<"Please select a game: ";
            cin >> selectedGame;

            if (cin.fail() || (selectedGame != 1 && selectedGame != 2 && selectedGame != 3))
            {
                cout << "Invalid input. Please enter a number between 1 and 3." << endl<<endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (selectedGame != 1 && selectedGame != 2 && selectedGame != 3);

        if (selectedGame == 1)
        {
            char again;

            do
            {
                cout<<endl;
                cout<<"#######################################################"<<endl;
                cout<<"#  You Have Joined The Blackjack Table Of Blashphamy  #"<<endl;
                cout<<"#######################################################"<<endl;

                do
                {
                    int numPlayers;
                    do
                    {
                        cout<<endl<<"Enter Number Of Players: ";
                        cin >> numPlayers;

                        if (cin.fail() || numPlayers == 0)
                        {
                            cout << "Invalid input. Please enter a number greater than zero." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    } while (cin.fail() || numPlayers == 0);
                    
                    cout<<endl<<"play another round? (y/n): ";
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

        } else if (selectedGame == 2)
        {
            cout<<endl;
            cout<<"################################################"<<endl;
            cout<<"#  You Have Joined The Slot Machine Of Sadness #"<<endl;
            cout<<"################################################"<<endl;
            cout<<endl;

            cout<<"Error Detected! User Is Already Too Sad! Exitting To Main Menu."<<endl;
        } else if (selectedGame == 3)
        {
            cout<<endl;
            cout<<"#################################################"<<endl;
            cout<<"#  You Have Chosen To Exit The Casino Of Horror #"<<endl;
            cout<<"#  I Always Knew You Were A Quitter! Goodbye!   #"<<endl;
            cout<<"#################################################"<<endl;
        }
    } while(selectedGame != 3);
};
