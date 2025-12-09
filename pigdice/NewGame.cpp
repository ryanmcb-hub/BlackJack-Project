#include <string>
#include <iostream>
#include "NewGame.h"
#include "Turn.h"

NewGame::NewGame() {
    m_playerScore[0] = 0;
    m_playerScore[1] = 0;
    m_playersName[0] = "";
    m_playersName[1] = "";
    m_game_score = 0;
    m_gameOver = false;
    m_tog = false;
}

void NewGame::display_rules() {
    std::cout << "Lets Play PIG Dice!\n";
    std::cout << std::endl;
    std::cout << "* See which player will reach 50 points in the fewest turns.\n";
    std::cout << "* Turn ends when you hold or roll a 1.\n";
    std::cout << "* If you roll a 1, you lose all points for the turn.\n";
    std::cout << "* If you hold, you save all points for the turn.\n";
}

void NewGame::play_game() {
    std::cout << "Enter player1's name: ";
    std::cin >> m_playersName[0];
    std::cout << "Enter player2's name: ";
    std::cin >> m_playersName[1];
    std::cout << std::endl;

    while(!m_gameOver) {
        //I had to look this up, I wasn't sure how to do it
        int current = m_tog ? 1 : 0;

        std::cout << m_playersName[current] << " (Score:" << m_playerScore[current] << ") - TURN " << m_myTurn.get_turn_count() << std::endl;
        m_myTurn.take_turn();

        m_playerScore[current] += m_myTurn.get_score_this_turn();
        m_game_score = m_playerScore[current];

        std::cout << "Score for turn: " << m_myTurn.get_score_this_turn() << std::endl;
        std::cout << "Total score: " << m_game_score << std::endl;
        std::cout << "" << std::endl;

        m_myTurn.reset_score_this_turn();

        if (get_game_score() >= 50) {
            set_game_over();
            break;
        }

        m_tog = !m_tog;
    }
    std::cout << "Congratulations " << m_playersName[m_tog ? 1 : 0] << " you're the winner!" << std::endl;
    std::cout << "You had a final score of " << get_game_score() << " points after " << m_myTurn.get_turn_count() << " turns!\n" << std::endl;
    std::cout << "THANKS FOR PLAYING!" << std::endl;
}

NewGame::~NewGame() {
    delete[] m_playerScore;
    delete[] m_playersName;
}


