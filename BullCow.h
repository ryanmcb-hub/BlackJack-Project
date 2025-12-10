#ifndef BULLCOW_H
#define BULLCOW_H

#include <algorithm>
#include <random>
#include <vector> 
#include "Game.h"

using namespace std;

class Code {
  private:
    vector<int> m_secret;
  public:
    Code();
    vector<int> getSecret();
    void setSecret();
    void clearSecret();
};

class Guess {
    private:
      vector<int> m_playerGuess;
      int m_guessCount=0;
    public:
        void setGuess();
        std::vector<int> getGuess();
        void clearGuess();
        void setGuessCount();
        int getGuessCount();
};

struct Results {
    int bulls{};
    int cows{};
};

class BullTurn {
    private:
        Results m_results;
     public:
        void setResults(std::vector<int> secret,std::vector<int> guess);
        Results getResults();
        void clearResults();
};

class BullCow : public Game {
    private:
        Code m_code;
        Guess m_guess;
        BullTurn m_turn;
        Results m_results;
        char m_again;
        int m_guessCount{};
        bool m_gameOver{};
    public:
        BullCow(string name);
        void displayRules();
        void playGame();
};

#endif 