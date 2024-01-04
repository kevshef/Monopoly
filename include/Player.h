#ifndef MONOPOLY_PLAYER_H
#define MONOPOLY_PLAYER_H

#include "BankAccount.h" // Include necessary header for BankAccount class
#include <ostream>
#include <ctime>
#include <cstdlib>

// Enum representing different types of players
enum class PlayerType {
    REAL = 0, COMPUTER = 1
};

// Class representing a player in the game
class Player {
private:

    int identifyingNumber; // Unique identifier for the player

    int position; // Current position of the player on the board

    PlayerType type; // Type of player (REAL or COMPUTER)

    BankAccount bankAccount; // Player's bank account

public:

    // Constructor: Initializes the player with a given type and identifier
    Player(PlayerType playerType, int playerNumber);

    // Getter function to retrieve the player's identifier
    int getNumber() const;

    // Getter function to retrieve the player's type (REAL or COMPUTER)
    int getPlayerType() const;

    // Getter function to retrieve the player's current position on the board
    int getPosition() const;

    // Getter function to retrieve the player's current balance
    int getBalance() const;

    // Function to check if the player is still in the game (not bankrupt)
    bool isInGame() const;

    // Function to simulate throwing dice and return the total value
    int throwDice();

    // Function to make a payment from the player to another player
    void pay(Player& recipient, int amount);

    // Function to allow the player to buy a property for a given amount
    bool buy(int amount);

    // Function to set the player's initial balance
    void updateBalance();

    // Function to check if the player is bankrupt
    bool isBankrupt() const;

    // Function to set the player's position on the board
    void setPosition(int newPosition);

};

// Overloaded stream insertion operator to allow printing Player objects to an ostream
std::ostream& operator<<(std::ostream& os, Player& obj);

#endif //MONOPOLY_PLAYER_H