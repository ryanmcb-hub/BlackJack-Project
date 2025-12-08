#include <iostream>
#include "Game.h"
#include "Turn.h"
#include "Die.h"

Die m_myDie;

Game::Game() {
	m_game_over = false;
	m_game_score = 0;
}

void Game::set_game_score() {
	m_game_score += m_myDie.get_die_value();
}

int Game::get_game_score() {
	return m_game_score;
}

void Game::set_game_over() {
	m_game_over = true;
}

bool Game::reset_game_over() {
	return m_game_over;
}

void Game::display_rules() {
	std::cout << "Let's Play PIG Dice!\n";
    std::cout << std::endl;
    std::cout << "* See how many turns it takes you to get to 20.\n";
    std::cout << "* Turn ends when you hold or roll a 1.\n";
    std::cout << "* If you roll a 1, you lose all points for the turn.\n";
    std::cout << "* If you hold, you save all points for the turn.\n";
    std::cout << std::endl;
}

/*void Game::set_sides() {
	while (true) {
		int numSides;
		std::cout << "How many sides? ";
		std::cin >> numSides;
		std::cout << std::endl;

		if (numSides == 2 || numSides == 4 || numSides == 6 || numSides == 8 || numSides == 12) {
			m_myTurn.set_die_sides(numSides);
			//m_myDie = Die(numSides);
			break;
		}
		else {
			std::cout << "Invalid choice. Must be 2, 4, 6, 8 or 12" << std::endl;
			std::cout << std::endl;
		}
	}
}*/

void Game::play_game() {
	
	while(!m_game_over) {
		m_myTurn.take_turn();	
		m_game_score += m_myTurn.get_score_this_turn();
		std::cout << "Score for turn: " << m_myTurn.get_score_this_turn() << std::endl;
		std::cout << "Total score: " << m_game_score << std::endl;
		std::cout << "" << std::endl;
		m_myTurn.reset_score_this_turn();
		if (get_game_score() >= 20) {
				set_game_over(); 
		} 
	}
	std::cout << "You finished with a final score of 20 or more in " << m_myTurn.get_turn_count() << " turns!\n";
}
