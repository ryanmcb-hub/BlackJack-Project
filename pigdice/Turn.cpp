#include <iostream>
#include "Turn.h"
#include "Game.h"

Game m_myGame; 

Turn::Turn() { 
	m_choice = '\0';
	m_turn_count = 0;
	m_score_this_turn = 0;
}

void Turn::reset_turn_over() {
	m_turn_over = false;
}

bool Turn::get_turn_over() {
	return m_turn_over;
}

void Turn::reset_score_this_turn() {
	m_score_this_turn = 0;
}

int Turn::get_score_this_turn() {
	return m_score_this_turn;
}

void Turn::set_turn_count() {
	m_turn_count++;
}

int Turn::get_turn_count() {
	return m_turn_count;	
}

void Turn::take_turn() {
	set_turn_count();
	reset_turn_over();
	//std::cout << "\nTurn " << get_turn_count();
	while (!m_turn_over) {
		std::cout << "\nroll or hold? (r/h): ";
		std::cin >> m_choice;

		if (m_choice == 'r') {
			roll();
		} 

		else if (m_choice == 'h') {
			m_turn_over = true;
		}

		else {
			std::cout << "Invalid choice! Try again." << std::endl;
		}
	}
}

void Turn::roll() {
	m_myDie.set_die_value();
	std::cout << "Die: " << m_myDie.get_die_value();

	if (m_myDie.get_die_value() == 1) {
		m_score_this_turn = 0;
		m_turn_over = true;
		std::cout << "\nTurn over. No score." << std::endl;
	}
	else {
		m_score_this_turn += m_myDie.get_die_value();
		m_myGame.set_game_score();
	}
}

void Turn::set_die_sides(int S) {
	m_myDie = Die(S);
}
