//
// Created by rmcbr on 12/1/2025.
//

#ifndef BLACKJACKTEST_CARDGAME_H
#define BLACKJACKTEST_CARDGAME_H

#include <string>
#include <vector>

// Forward declarations
class Card;
class Deck;
class Shoe;

// Abstract base class for any card game
// Right now Card, Deck, and Shoe classes for different games
class CardGame {
protected:
    std::string m_gameName;         // Name of the game (e.g., "Blackjack", "Poker")
    int m_minPlayers;               // Minimum players required
    int m_maxPlayers;               // Maximum players allowed
    int m_numDecks;                 // Number of decks used in this game

public:
    // Constructor - basic game parameters
    CardGame(const std::string& name, int minPlayers, int maxPlayers, int numDecks = 1);

    // Virtual destructor
    virtual ~CardGame() = default;

    // PURE VIRTUAL FUNCTIONS - each game must implement these
    virtual void initializeGame() = 0;          // Set up the game (deal cards, reset scores, etc.)
    virtual void playRound() = 0;               // Play one complete round
    virtual bool isGameOver() const = 0;        // Check if the game has ended
    virtual void displayGameState() const = 0;  // Show current game status to players

    // VIRTUAL FUNCTIONS - can be overridden by specific games
    virtual void shuffleGame();                 // Shuffle decks/shoe for the game
    virtual void resetGame();                   // Reset game to initial state

    // COMMON FUNCTIONALITY - available to all card games
    std::string getGameName() const;            // Get the game's name
    int getMinPlayers() const;                  // Get minimum player count
    int getMaxPlayers() const;                  // Get maximum player count
    int getNumDecks() const;                    // Get number of decks used

    // TEMPLATE METHOD PATTERN - skeleton of how a card game is played
    void playGame();

private:
    // Helper methods for the template method pattern
    void preGameSetup();    // Setup before game starts
    void postGameCleanup(); // Cleanup after game ends
};

#endif // CARDGAME_H