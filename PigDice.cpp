#include "PigDice.h"

using namespace std;

PigDiceTurn::PigDiceTurn() { 
	m_choice = '\0';
	m_turnCount = 0;
	m_scoreThisTurn = 0;
}

void PigDiceTurn::reset_turn_over() {
	m_turnOver = false;
}

bool PigDiceTurn::get_turn_over() {
	return m_turnOver;
}

void PigDiceTurn::reset_score_this_turn() {
	m_scoreThisTurn = 0;
}

int PigDiceTurn::get_score_this_turn() {
	return m_scoreThisTurn;
}

void PigDiceTurn::set_turn_count() {
	m_turnCount++;
}

int PigDiceTurn::get_turn_count() {
	return m_turnCount;	
}

void PigDiceTurn::take_turn() {
	reset_turn_over();
	//std::cout << "\nTurn " << get_turn_count();

	while (!m_turnOver) {
		std::cout << "\nroll or hold? (r/h): ";
		std::cin >> m_choice;

		if (m_choice == 'r') {
			roll();
		} 

		else if (m_choice == 'h') {
			m_turnOver = true;
		}

		else {
			std::cout << "Invalid choice! Try again." << std::endl;
		}
	}
}

void PigDiceTurn::roll() {
	m_myDie.set_die_value();
	std::cout << "Die: " << m_myDie.get_die_value();

	if (m_myDie.get_die_value() == 1) {
		m_scoreThisTurn = 0;
		m_turnOver = true;
		std::cout << "\nTurn over. No score." << std::endl;
	}
	else {
		m_scoreThisTurn += m_myDie.get_die_value();
	}
}

void PigDiceTurn::set_die_sides(int S) {
	m_myDie = Die(S);
}

PigDice::PigDice(string name) : DiceGame(name) {
	m_gameOver = false;
	m_turns.resize(m_players.size());
}

PigDice::PigDice(string name, int dice) : DiceGame(name, dice) {
	m_gameOver = false;
	m_turns.resize(m_players.size());
}

PigDice::PigDice(string name, int dice, int players) : DiceGame(name, dice, players) {
	m_gameOver = false;
	m_turns.resize(players);
}

void PigDice::set_over() {
	m_gameOver = true;
}

bool PigDice::reset_over() {
	return m_gameOver;
}

void PigDice::displayRules() {
	cout << "Let's Play PIG Dice!" << endl << endl;
    cout << "* See which player will reach 25 points in the fewest turns." << endl;
    cout << "* Turn ends when you hold or roll a 1." << endl;
    cout << "* If you roll a 1, you lose all points for the turn." << endl;
    cout << "* If you hold, you save all points for the turn." << endl << endl;
}

void PigDice::playGame() {
	char again;
	do {
		do
		{
			for (int i = 0; i < m_players.size(); i++)
			{
				m_turns[i].set_turn_count();
				cout << m_players[i].getName() << " (Score:"<< m_players[i].getScore() << ") - TURN " << m_turns[i].get_turn_count() << endl;

				m_turns[i].take_turn();
				m_players[i].setScore(m_players[i].getScore() + m_turns[i].get_score_this_turn());

				cout << "Score for turn: "<<m_turns[i].get_score_this_turn()<<endl;
				cout << m_players[i].getName() << "'s total score: " << m_players[i].getScore() << endl << endl;

				m_turns[i].reset_score_this_turn();
				m_turns[i].reset_turn_over();
			}

			bool checkScore = any_of(m_players.begin(), m_players.end(), [](Player n)
			{
				return n.getScore() >= 25;
			});

			if (checkScore)
			{
				set_over();
			}
		} while (!m_gameOver);

		auto highScore = max_element(m_players.begin(), m_players.end(), [](Player& a, Player& b) {
			return a.getScore() < b.getScore();
		});

		int winnerIndex = distance(m_players.begin(), highScore);

		cout<<"Congratulations "<<m_players[winnerIndex].getName()<<", you're the winner!"<<endl;
		cout<<"You had a final score of "<<m_players[winnerIndex].getScore()<<" points after "<<m_turns[winnerIndex].get_turn_count()<<" turns!"<<endl<<endl;
		cout<<"THANKS FOR PLAYING!" << endl;

		do{
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
}