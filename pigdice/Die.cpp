#include <cstdlib>
#include <ctime>
#include <random>
#include <iostream>
#include "Die.h"

Die::Die() { //default constructor
	m_sides = 6;
	m_die_value = 0;
}

Die::Die(int S) {
	m_sides = S;
	m_die_value = 0;
}

void Die::set_die_value() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution <int> dist(1, m_sides);
	m_die_value = dist(gen);
}

int Die::get_die_value() {
	return m_die_value;
}