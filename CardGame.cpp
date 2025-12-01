#include "CardGame.h"
#include <iostream>

// Constructor - initialize game parameters
CardGame::CardGame(const std::string& name, int minPlayers, int maxPlayers, int numDecks)
    : m_gameName(name), m_minPlayers(minPlayers), m_maxPlayers(maxPlayers), m_numDecks(numDecks) {
}

// Default implementation of shuffle - can be overridden
void CardGame::shuffleGame() {
    std::cout << "Shuffling for " << m_gameName << "..." << std::endl;
}

// Default implementation of reset - can be overridden
void CardGame::resetGame() {
    std::cout << "Resetting " << m_gameName << "..." << std::endl;
}

// Get the games name
std::string CardGame::getGameName() const {
    return m_gameName;
}

// Get minimum num players
int CardGame::getMinPlayers() const {
    return m_minPlayers;
}

// Get maximum num players
int CardGame::getMaxPlayers() const {
    return m_maxPlayers;
}

// Get number of decks used in game
int CardGame::getNumDecks() const {
    return m_numDecks;
}

// Pre-game setup
void CardGame::preGameSetup() {
    std::cout << "=== Pre-game setup for " << m_gameName << " ===" << std::endl;
    std::cout << "Players: " << m_minPlayers << "-" << m_maxPlayers << std::endl;
    std::cout << "Decks: " << m_numDecks << std::endl;
    shuffleGame();  // Shuffle as part of setup
}

// Post-game cleanup
void CardGame::postGameCleanup() {
    std::cout << "=== Post-game cleanup for " << m_gameName << " ===" << std::endl;
    resetGame();  // Reset as part of cleanup
}

// Template method - defines the skeleton for playing any card game
void CardGame::playGame() {
    std::cout << "\n=== Starting " << m_gameName << " ===" << std::endl;
    
    // 1 - Pre-game setup
    preGameSetup();
    
    // 2 - Game-specific initialization
    initializeGame();
    
    // 3 - Main game loop
    while (!isGameOver()) {
        displayGameState();
        playRound();
    }
    
    // 4 - Post-game cleanup
    postGameCleanup();
    std::cout << "=== " << m_gameName << " finished ===\n" << std::endl;
}