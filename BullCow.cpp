#include "BullCow.h"

Code::Code(){
}

void Code::setSecret(){
    vector<int> digits = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    for (int i = 0; i < 4; i++) {
        random_device rd;
        mt19937 rng(rd());
        uniform_int_distribution<size_t> distribution(0, digits.size() - 1);

        int index = distribution(rng);

        m_secret.push_back(digits[index]);
        digits.erase(digits.begin() + index);
    };
}

vector<int> Code::getSecret(){
    return m_secret;
}

void Code::clearSecret() {
    m_secret.clear();
}

void Guess::setGuess() {
    m_guessCount++;

    do {
        clearGuess();
        
        string guess;
        cout << "Enter guess #" << m_guessCount << ": ";
        cin >> guess;

        for ( char c : guess ) {
            if (isdigit(c)){
                m_playerGuess.push_back(c - '0');
            };
                
        }
        
        if (cin.fail() || m_playerGuess.size() != 4) {
            cout << "Invalid Guess! Try again.";
            cin.clear();    
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (cin.fail() || m_playerGuess.size() != 4);
};

vector<int> Guess::getGuess() {
    return m_playerGuess;
};

void Guess::clearGuess() {
    m_playerGuess.clear();
};

void Guess::setGuessCount() {
    m_guessCount = 0;
};

int Guess::getGuessCount() {
    return m_guessCount;
};

void BullTurn::setResults(vector<int> secret, vector<int> guess) {
    clearResults();

    for (int i = 0; i < guess.size(); i++) {
        if (secret[i] == guess[i]) {
            m_results.bulls++;
        } else {
            for (int j = 0; j < secret.size(); j++) {
                if (secret[i] == guess[j]) {
                    m_results.cows++;
                }
            }
        }
    }
    
};

Results BullTurn::getResults() {
    return m_results;
};

void BullTurn::clearResults() {
    m_results.bulls = 0;
    m_results.cows = 0;
};

BullCow::BullCow(string name) : Game(name, 1) {};

void BullCow::displayRules() {
    cout << "Let's play Bulls and Cows!" << endl << endl;

    cout << "The computer has generated a secret non-repeating 4 digit" << endl;
    cout << "code you will try to guess the code in as few attempts as possible." << endl;

    cout << "After each guess you will get a feedback message indicating how many digits in" << endl;
    cout << "the guess matched the same digit and position in the secret code ('Bulls') and how many" << endl;
    cout << "digits matched digits in the secret code, but are not in the matching position ('Cows')." << endl;
    cout << "To win the bet you might guess it in less that 15 guesses." << endl << endl;
}

void BullCow::playGame() {
    do {
        int bet;
        do
        {
            cout << m_players[0].getName() << " Place A Bet (Balance: $" << m_players[0].getBalance() << "): $";
            cin >> bet;

            if (cin.fail() || bet < 25 || bet > m_players[0].getBalance())
            {
                if (bet > m_players[0].getBalance()){
                    cout << "Bet Too High. Be Less Broke!" << endl;
                } else {
                    cout << "Bet Must Be A Whole Number Greater Than $25" << endl;
                }

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (cin.fail() || bet < 25 || bet > m_players[0].getBalance());

        m_players[0].setBet(bet);

        m_code.setSecret();
        m_guess.setGuessCount();

        m_gameOver = false;

        do {
            m_turn.clearResults();

            m_guess.setGuess();
            m_turn.setResults(m_code.getSecret(), m_guess.getGuess());
            m_results = m_turn.getResults();

            cout << "RESULTS -> " << m_results.bulls << " Bull(s) " << m_results.cows << " Cow(s)" << endl;
            m_gameOver = m_results.bulls == 4 || m_guess.getGuessCount() >= 15;
        } while (!m_gameOver);

        if (m_results.bulls == 4){
            m_players[0].win(false);

            cout << endl << "Congratulations! You broke the code in " << m_guess.getGuessCount() << " guesses." << endl << endl;
        } else {
            m_players[0].lose();

            cout << endl << "You lost! The code was: ";
            vector<int> code = m_code.getSecret();
            for (int i = 0; i < code.size(); i++) {
                cout << code[i];
            }
            cout << endl << endl;
        }

        m_code.clearSecret();

        cout << "Thanks for playing!" << endl << endl;

        m_again = ' ';

        while (m_again != 'y' && m_again != 'n') {
            cout << "Play again? (y/n): ";
            cin >> m_again;
        }
    } while (m_again == 'y');
};
